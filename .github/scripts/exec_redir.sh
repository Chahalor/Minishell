# !/bin/bash
BIN_MINISHELL=minishell
BIN_BASH=bash
DIR_TMP=".github/tmp"

NB_FAIL=0
NB_SUCCESS=0

BLUE="\033[0;34m"
NC="\033[0m"

CMDS_PIPES=(
	"echo 'Hello from Minishell'"
	"ls -l"
	"pwd"
	"ls -l | grep \"Aug\" | cat -e"
	"printf \"%s\\n\" one two | wc -l"
	"cat /etc/passwd | grep root | wc -l"
	"echo \"This is a test\" | tr a-z A-Z"
	"echo \"apple banana cherry\" | tr ' ' '\\n' | sort"
	"echo \"apple banana cherry\" | tr ' ' '\\n' | sort | tr a-z A-Z"
	"ls | ls | ls | ls | ls | ls | ls | ls | ls | ls | ls | ls"
)

CMDS_GREATER=(
	"echo 'Hello from Minishell' > $DIR_TMP/test1.txt; cat -e $DIR_TMP/test1.txt"
	"ls -l > $DIR_TMP/test2.txt; cat -e $DIR_TMP/test2.txt"
	"pwd > $DIR_TMP/test3.txt; cat -e $DIR_TMP/test3.txt"
	"echo 'First line' > $DIR_TMP/test4.txt; echo 'Second line' >> $DIR_TMP/test4.txt; cat -e $DIR_TMP/test4.txt"
	"printf \"%s\\n\" one two three > $DIR_TMP/test5.txt; cat -e $DIR_TMP/test5.txt"
	"cat /etc/passwd | grep root > $DIR_TMP/test6.txt; cat -e $DIR_TMP/test6.txt"
	"echo \"This is a test\" | tr a-z A-Z > $DIR_TMP/test7.txt; cat -e $DIR_TMP/test7.txt"
	"echo \"apple banana cherry\" | tr ' ' '\\n' | sort > $DIR_TMP/test8.txt; cat -e $DIR_TMP/test8.txt"
	"echo \"apple banana cherry\" | tr ' ' '\\n' | sort | tr a-z A-Z > $DIR_TMP/test9.txt; cat -e $DIR_TMP/test9.txt"
)

CMDS_DGREATER=(
	"echo 'Hello from Minishell' >> $DIR_TMP/test1.txt; cat -e $DIR_TMP/test1.txt"
	"ls -l >> $DIR_TMP/test2.txt; ls -lA >> $DIR_TMP/test2.txt; cat -e $DIR_TMP/test2.txt"
	"pwd >> $DIR_TMP/test3.txt; cat -e $DIR_TMP/test3.txt"
	"echo 'First line' >> $DIR_TMP/test4.txt; echo 'Second line' >> $DIR_TMP/test4.txt; cat -e $DIR_TMP/test4.txt"
	"printf \"%s\\n\" one two three >> $DIR_TMP/test5.txt; cat -e $DIR_TMP/test5.txt"
	"cat /etc/passwd | grep root >> $DIR_TMP/test6.txt; cat -e $DIR_TMP/test6.txt"
	"echo \"This is a test\" | tr a-z A-Z >> $DIR_TMP/test7.txt ; cat -e $DIR_TMP/test7.txt"
)

CMDS_LOWER=(
	"pwd > ${DIR_TMP}/input.txt ; cat -e < ${DIR_TMP}/input.txt"
	"echo 'Hello from Minishell' > ${DIR_TMP}/input.txt ; cat -e < ${DIR_TMP}/input.txt"
	"ls -l > ${DIR_TMP}/input.txt ; cat -e < ${DIR_TMP}/input.txt"
	"printf \"%s\\n\" one two three > ${DIR_TMP}/input.txt ; cat -e < ${DIR_TMP}/input.txt"
	"cat /etc/passwd | grep root > ${DIR_TMP}/input.txt ; cat -e < ${DIR_TMP}/input.txt"
	"echo \"This is a test\" | tr a-z A-Z > ${DIR_TMP}/input.txt ; cat -e < ${DIR_TMP}/input.txt"

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

test CMDS_PIPES false
test CMDS_GREATER false
test CMDS_DGREATER false
test CMDS_LOWER false

echo "Summary:"
echo " - Total tests: $((NB_SUCCESS + NB_FAIL))"
echo "  - Successful tests: ${NB_SUCCESS}"
echo "  - Failed tests: ${NB_FAIL}"
exit $NB_FAIL