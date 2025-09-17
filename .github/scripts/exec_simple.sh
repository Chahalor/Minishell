#!/bin/bash

BIN_MINISHELL=Minishell
BIN_BASH=bash

DIR_TMP=".github/tmp"

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

NB_FAIL=0
NB_SUCCESS=0

mkdir -p "$DIR_TMP"

# Run single-command tests
for cmd in "${SINGLE_CMDS[@]}"; do
    echo "Running single: $cmd"
    ./"$BIN_MINISHELL" -c "$cmd" > "$DIR_TMP/output_minishell.txt"
    "$BIN_BASH" -c "$cmd" > "$DIR_TMP/output_bash.txt"
    if diff "$DIR_TMP/output_minishell.txt" "$DIR_TMP/output_bash.txt"; then
        NB_SUCCESS=$((NB_SUCCESS + 1))
    else
        NB_FAIL=$((NB_FAIL + 1))
        echo "❌ Test failed for: <$cmd>"
    fi
    rm "$DIR_TMP/output_minishell.txt" "$DIR_TMP/output_bash.txt"
done

# Run multi-command tests
for seq in "${MULTI_CMDS[@]}"; do
    IFS=";" read -ra CMDS <<< "$seq"

    echo "Running multi: $seq"

    # Minishell: pass commands separately
    ./"$BIN_MINISHELL" -c "${CMDS[@]}" > "$DIR_TMP/output_minishell.txt"

    # Bash: join with &&
    bash_cmd=$(printf ' %s &&' "${CMDS[@]}" | sed 's/&&$//')
    "$BIN_BASH" -c "$bash_cmd" > "$DIR_TMP/output_bash.txt"

    if diff "$DIR_TMP/output_minishell.txt" "$DIR_TMP/output_bash.txt"; then
        NB_SUCCESS=$((NB_SUCCESS + 1))
    else
        NB_FAIL=$((NB_FAIL + 1))
        echo "❌ Test failed for: <$seq>"
    fi
    rm "$DIR_TMP/output_minishell.txt" "$DIR_TMP/output_bash.txt"
done

echo "Summary:"
echo " - Successful tests: $NB_SUCCESS"
echo " - Failed tests: $NB_FAIL"

exit $NB_FAIL
