#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>

int main(void)
{
    pid_t pid;
    int status;
    pid_t shell_pgid;

    // Le shell se met en process group
    shell_pgid = getpid();
    setpgid(shell_pgid, shell_pgid);
    // Prend le contrôle du terminal
    tcsetpgrp(STDIN_FILENO, shell_pgid);

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        // --- Enfant ---
        // Nouveau process group (pgid = pid)
        setpgid(0, 0);

        // Donne le contrôle du terminal à l'enfant
        tcsetpgrp(STDIN_FILENO, getpid());

        // Restaure les signaux par défaut
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        signal(SIGTSTP, SIG_DFL);

        // Exécute cat
        execlp("cat", "cat", NULL);
        perror("execlp");
        exit(1);
    }
    else
    {
        // --- Parent (le shell) ---
        // Met l’enfant dans son propre groupe
        setpgid(pid, pid);

        // Attend que l’enfant se termine
        waitpid(pid, &status, 0);

        // Quand il est fini → reprendre le contrôle du terminal
        tcsetpgrp(STDIN_FILENO, shell_pgid);

        if (WIFSIGNALED(status))
            printf("child killed by signal %d\n", WTERMSIG(status));
    }
    return 0;
}
