#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 4096

// Fonction utilitaire pour trouver la ligne correspondant à l'utilisateur
char *find_home_in_passwd(const char *username)
{
    int fd = open("/etc/passwd", O_RDONLY);
    if (fd == -1)
        return NULL;

    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
    close(fd);
    if (bytes_read <= 0)
        return NULL;
    
    buffer[bytes_read] = '\0';

    // On découpe ligne par ligne
    char *line = strtok(buffer, "\n");
    while (line)
    {
        if (strncmp(line, username, strlen(username)) == 0 && line[strlen(username)] == ':')
        {
            // Format : user:x:uid:gid:gecos:home:shell
            // On cherche le 6e champ (home)
            int field = 0;
            char *p = line;
            while (*p && field < 5)
            {
                if (*p == ':')
                    field++;
                p++;
            }
            if (field == 5)
            {
                char *home_start = p;
                char *home_end = strchr(home_start, ':');
                if (!home_end)
                    home_end = home_start + strlen(home_start);
                size_t len = home_end - home_start;
                char *home = malloc(len + 1);
                if (!home)
                    return NULL;
                strncpy(home, home_start, len);
                home[len] = '\0';
                return home;
            }
        }
        line = strtok(NULL, "\n");
    }
    return NULL;
}

int main(void)
{
    char *home = getenv("HOME");

    if (!home)
    {
        char *user = getenv("USER");
        if (!user)
            user = getenv("LOGNAME");
        if (user)
            home = find_home_in_passwd(user);
    }

    if (home)
    {
        printf("HOME = %s\n", home);
        // free(home); // seulement si alloué par find_home_in_passwd
    }
    else
        write(2, "Impossible de trouver le HOME\n", 31);

    return 0;
}
