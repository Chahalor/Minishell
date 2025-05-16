#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char *find_home_in_passwd(const char *user)
{
    int  fd = open("/etc/passwd", O_RDONLY);
    if (fd < 0) return NULL;

    char buf[1024];
    ssize_t n;
    while ((n = read(fd, buf, sizeof(buf)-1)) > 0) {
        buf[n] = '\0';
        char *line = strtok(buf, "\n");
        while (line) {
            if (strncmp(line, user, strlen(user))==0 && line[strlen(user)]==':') {
                // skip fields jusqu'au 6ème (home)
                char *p = line;
                for (int i = 0; i < 5 && p; ++i)
                    p = strchr(p+1, ':');
                if (p) {
                    char *home = strdup(p+1);
                    char *nl = strchr(home, ':');
                    if (nl) *nl = '\0';
                    close(fd);
                    return home;
                }
            }
            line = strtok(NULL, "\n");
        }
    }
    close(fd);
    return NULL;
}

int main(void)
{
    char *home = NULL;//getenv("HOME");
    if (!home) {
        char *user = getenv("USER");
        if (user)
            home = find_home_in_passwd(user);
    }
    if (home)
        printf("Home: %s\n", home);
    else
        printf("Home introuvable\n");
    return 0;
}
