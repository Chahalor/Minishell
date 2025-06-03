#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd;

    // Nom du fichier temporaire
    const char *filename = "/tmp/mon_fichier_temporaire_secure2";

    // Créer le fichier avec des permissions très restrictives : rw-------
    fd = open(filename, O_RDWR | O_CREAT | O_EXCL, 0600);
    if (fd < 0) {
        write(2, "Erreur lors de la création du fichier\n", 39);
        return 1;
    }

    // À ce stade, seul ce processus peut lire/écrire dans le fichier.
    // Les autres ne peuvent pas l'ouvrir (ni même le modifier).

    // Exemple d'écriture
    write(fd, "Donnees temporaires", 19);

    close(fd);

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		write(2, "Erreur lors de l'ouverture du fichier\n", 39);
		return 1;
	}

	// Lire le contenu du fichier
	char buffer[20];
	ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read < 0) {
		write(2, "Erreur lors de la lecture du fichier\n", 39);
		close(fd);
		return 1;
	}
	buffer[bytes_read] = '\0'; // Terminer la chaîne

	// Afficher le contenu lu
	write(1, buffer, bytes_read);

	close(fd);
	unlink(filename); // Supprimer le fichier temporaire

    return 0;
}
