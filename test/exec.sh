#!/bin/bash

MINISHELL="./Minishell"
BASH="/bin/bash --posix"
TMP_DIR=".tmp_test_exec"
CMDS=(
    "echo Hello"
    "pwd"
    "whoami"
    "date"
    "ls"
    "uname -a"
    "true"
    "false"
    "exit"
    "env"
    "id"
)

# Préparation
mkdir -p "$TMP_DIR"
SUCCESS=0
FAIL=0

echo "=== TEST: simple commands comparison with bash --posix ==="

for CMD in "${CMDS[@]}"; do
    echo -n "Test: $CMD ... "

    # Bash output
    echo "$CMD" | $BASH > "$TMP_DIR/bash_out" 2>&1
    BASH_RET=$?

    # Minishell output
    echo "$CMD" | $MINISHELL > "$TMP_DIR/minishell_out" 2>&1
    MINI_RET=$?

    # Comparaison
    if diff -q "$TMP_DIR/bash_out" "$TMP_DIR/minishell_out" > /dev/null && [ $BASH_RET -eq $MINI_RET ]; then
        echo "✅"
        ((SUCCESS++))
    else
        echo "❌"
        echo "  ➤ Bash return:      $BASH_RET"
        echo "  ➤ Minishell return: $MINI_RET"
        echo "  ➤ Diff output:"
        diff "$TMP_DIR/bash_out" "$TMP_DIR/minishell_out" | sed 's/^/    /'
        ((FAIL++))
    fi
done

echo "=== Résumé: $SUCCESS réussi(s), $FAIL échoué(s) ==="

# Nettoyage
rm -rf "$TMP_DIR"
