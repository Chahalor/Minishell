BIN_MINISHELL=Minishell
BIN_BASH=bash

DIR_TMP=".github/tmp"

CMDS=(
	"echo 'Hello from Minishell' | tr '[:lower:]' '[:upper:]'"
	"ls -l | grep '^d'"
	"pwd | rev"
)

NB_FAIL=0
NB_SUCCESS=0

mkdir -p "$DIR_TMP"

for cmd in "${CMDS[@]}"; do
	echo "Running command: $cmd"
	./"$BIN_MINISHELL" -c "$cmd" > "$DIR_TMP/output_minishell.txt"
	"$BIN_BASH" -c "$cmd" > "$DIR_TMP/output_bash.txt"
	if diff "$DIR_TMP/output_minishell.txt" "$DIR_TMP/output_bash.txt"; then
		NB_SUCCESS=$((NB_SUCCESS + 1))
	else
		NB_FAIL=$((NB_FAIL + 1))
		echo "Test failed for command: <$cmd>"
	fi
	rm "$DIR_TMP/output_minishell.txt" "$DIR_TMP/output_bash.txt"
done

echo "Summary:"
echo " - Successful tests: $NB_SUCCESS"
echo " - Failed tests: $NB_FAIL"
exit $NB_FAIL