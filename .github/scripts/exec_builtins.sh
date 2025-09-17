#!/bin/bash

BIN_MINISHELL=Minishell
BIN_BASH=bash

DIR_TMP=".github/tmp"

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

    # export without args (list), not possible cause not same formating
    # "export"                        # shows environment variables
)


# Commands that need multiple steps
MULTI_CMDS=(
    # cd variations
    "cd ..;pwd"                     # go up one dir
    "cd /;pwd"                      # go to root
    "cd \$HOME;pwd"                 # go home
    "cd;pwd"                        # cd without arg → home
    "cd nosuchdir;pwd"              # invalid path

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
    "echo \$SHLVL;./$BIN_MINISHELL -c 'echo \$SHLVL'"
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
