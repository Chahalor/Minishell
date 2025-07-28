#!/bin/bash

MINISHELL="./Minishell"
BASH="/bin/bash --posix"
TMP_DIR=".tmp_test_redir_out"
CMDS=(
    "echo Hello > out.txt"
    "ls > out.txt"
    "pwd > out.txt"
    "date > out.txt"
    "whoami > out.txt"
    "uname -a > out.txt"
    "env > out.txt"
)

# Préparation
mkdir -p "$TMP_DIR"
SUCCESS=0
FAIL=0

echo "=== TEST: redirection de sortie > ==="

for CMD in "${CMDS[@]}"; do
    echo -n "Test: $CMD ... "

    # Bash
    (
        cd "$TMP_DIR"
        echo "$CMD" | $BASH > /dev/null 2>&1
        BASH_RET=$?
        cp out.txt bash_out.txt
    )

    # Minishell
    (
        cd "$TMP_DIR"
        rm -f out.txt
        echo "$CMD" | $MINISHELL > /dev/null 2>&1
        MINI_RET=$?
        cp out.txt minishell_out.txt
    )

    # Comparaison
    if diff -q "$TMP_DIR/bash_out.txt" "$TMP_DIR/minishell_out.txt" > /dev/null && [ $BASH_RET -eq $MINI_RET ]; then
        echo "✅"
        ((SUCCESS++))
    else
        echo "❌"
        echo "  ➤ Bash return:      $BASH_RET"
        echo "  ➤ Minishell return: $MINI_RET"
        echo "  ➤ Diff output:"
        diff "$TMP_DIR/bash_out.txt" "$TMP_DIR/minishell_out.txt" | sed 's/^/    /'
        ((FAIL++))
    fi
done

echo "=== Résumé: $SUCCESS réussi(s), $FAIL échoué(s) ==="

# Nettoyage
rm -rf "$TMP_DIR"
