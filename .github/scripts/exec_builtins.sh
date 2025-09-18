#!/bin/bash

BIN_MINISHELL=minishell
BIN_BASH=bash
DIR_TMP=".github/tmp"

NB_FAIL=0
NB_SUCCESS=0

BLUE="\033[0;34m"
NC="\033[0m"

# Commands that run alone
SINGLE_CMDS=(
	# echo variations
	"echo ''"                       # empty string
	"echo '   '"                    # spaces only
	"echo Hello World"
	"echo -n 'No newline'"
	"echo -n ''"                    # -n with empty string
	"echo \$HOME"                   # environment variable expansion
	"echo \$SHLVL"                  # should print shell nesting level

	# pwd
	"pwd"

	# env, not possible cause not same formating
	# "env"

	# unset without var
	"unset"                         # should not crash, maybe print error
)


# Commands that need multiple steps
MULTI_CMDS=(
	# cd variations
	"cd ..;pwd"                     # go up one dir
	"cd /;pwd"                      # go to root
	"cd \$HOME;pwd"                 # go home
	"cd;pwd"                        # cd without arg → home

	# export/unset variations
	"export TEST_VAR=42;echo \$TEST_VAR"      # define + print
	"export EMPTY_VAR=;echo \$EMPTY_VAR"      # define empty
	"unset TEST_VAR;echo \$TEST_VAR"          # unset var
	"unset DOES_NOT_EXIST;echo \$?"           # unset non-existing

	# chained export updates
	"export VAR1=hello;export VAR1=world;echo \$VAR1"

	# test multiple vars
	"export A=foo;export B=bar;echo \$A \$B"
	"unset A;unset B;echo \$A \$B"

	# check SHLVL increment
	# "echo \$SHLVL;./$BIN_MINISHELL -c 'echo \$SHLVL'"

	"export A=l ; \$A's' \"-\"\"l\""
	"echo \"ab\" \"c\"\"d\""
	"export VAR=\"a b\" ; echo \$VAR ; echo \"\$VAR\""
	"echo \$UNSET ; echo \"\$UNSET\" ; echo '\$UNSET'"
	"echo \"quotes: \"double\" and 'single'\""
)

function test
{
	declare -n CMDS=$1
	debug=$2
	_nb_fail=0
	_nb_success=0

	echo "running ${#CMDS[@]} tests for $1:"
	for cmd in "${CMDS[@]}"; do
		IFS=";" read -ra PARTS <<< "$cmd"

		# echo "Running command: $cmd"
		./"${BIN_MINISHELL}" -c "${PARTS[@]}" > "$DIR_TMP/output_minishell.txt"
		find .github/tmp -type f -name "test*.txt" -exec rm {} \;
		"$BIN_BASH" -c "${cmd}" > "$DIR_TMP/output_bash.txt"

		if [ "$debug" = true ]; then
			echo "==============================="
			cat "${DIR_TMP}/output_minishell.txt"
			cat "${DIR_TMP}/output_bash.txt"
			echo "==============================="
		fi
		if diff <(cat -e "$DIR_TMP/output_minishell.txt") <(cat -e "$DIR_TMP/output_bash.txt"); then
			NB_SUCCESS=$((NB_SUCCESS + 1))
			_nb_success=$((_nb_success + 1))
		else
			NB_FAIL=$((NB_FAIL + 1))
			_nb_fail=$((_nb_fail + 1))
			echo -e "Test failed for command: <${BLUE}${cmd}${NC}>"
		fi
		rm "$DIR_TMP/output_minishell.txt" "$DIR_TMP/output_bash.txt"
	done
	echo "  - Success: $_nb_success | Fail: $_nb_fail"
	find .github/tmp -type f -name "test*.txt" -exec rm {} \;
}

mkdir -p "$DIR_TMP"

echo "$0: start tests"

test SINGLE_CMDS false
test MULTI_CMDS false

echo "Summary:"
echo " - Total tests: $((NB_SUCCESS + NB_FAIL))"
echo "  - Successful tests: ${NB_SUCCESS}"
echo "  - Failed tests: ${NB_FAIL}"

exit $NB_FAIL
