#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/uio.h>  // pour writev

int main() {
    char *tab[] = {
        "Bonjour, ",
        "mon ",
        "seigneur !\n"
    };
    int n = sizeof(tab) / sizeof(tab[0]);

    // Préparation des iovec
    struct iovec iov[n];
    for (int i = 0; i < n; i++) {
        iov[i].iov_base = tab[i];
        iov[i].iov_len = strlen(tab[i]);
    }

    // writev pour écrire toutes les chaînes en un seul appel
    ssize_t nb = writev(STDOUT_FILENO, iov, n);
    if (nb == -1) {
        perror("writev");
        return 1;
    }

    return 0;
}
