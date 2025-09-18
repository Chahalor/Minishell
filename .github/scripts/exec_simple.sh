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
	"echo 'Hello from Minishell'"
	"echo -n 'No newline here'"
	"echo Hello World"
	"echo \$HOME"

	# ls variations
	"ls"
	"ls -l"
	"ls -a"
	"ls -la"

	# pwd
	"pwd"

	# which
	"which ls"

	# external commands
	"date"
	"whoami"
	"uname -a"
	"id"
	"true"
	"false"
)

# Commands that need multiple steps
MULTI_CMDS=(
	"cd ..;pwd"
	"cd /;pwd"
	"cd \$HOME;pwd"
	"export TEST_VAR=42;echo \$TEST_VAR"
	"unset TEST_VAR;echo \$TEST_VAR"
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
