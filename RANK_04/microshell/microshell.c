#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int error_msg(char *str) 
{
    while (*str)
        write(2, str++, 1);
    return (1);
}

int cd(char **av, int i) 
{
    if (i != 2)
        return error_msg("error: cd: bad arguments\n"); 
    else if (chdir(av[1]) == -1)
        return error_msg("error: cd: cannot change directory to "), error_msg(av[1]), error_msg("\n");
    return (0); 
}

int execute_command(char **av, char **env, int i) 
{
    int fd[2];
    int status;
    int is_pipe = av[i] && !strcmp(av[i], "|");

    if (is_pipe && pipe(fd) == -1)
        return error_msg("error: fatal\n"); 

    int pid = fork();
    if (!pid) 
    {
        av[i] = 0;
        if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return error_msg("error: fatal\n");
        execve(*av, av, env);
        return (error_msg("error: cannot execute "), error_msg(*av), error_msg("\n"));
    }

    waitpid(pid, &status, 0);
    if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return error_msg("error: fatal\n"); 
    return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **env) 
{
    int    i = 0;
    int    status = 0;

    if (ac > 1) 
    {
        while (av[i] && av[++i]) 
        {
            av += i;
            i = 0; 
            while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
                i++;
            if (!strcmp(*av, "cd"))
                status = cd(av, i);
            else if (i)
                status = execute_command(av, env, i);
        }
    }
    return (status);
}

// Code commente

/*// Inclusion de bibliothèques standard nécessaires.
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// Déclaration de la fonction error_msg pour afficher des messages d'erreur.
int error_msg(char *str) 
{
    // Écrit chaque caractère de la chaîne de caractères sur le flux d'erreur standard.
    while (*str)
        write(2, str++, 1);
    return (1);
}

// Déclaration de la fonction cd pour changer de répertoire.
int cd(char **av, int i) 
{
    // Vérifie le nombre d'arguments. S'il est différent de 2, affiche une erreur.
    if (i != 2)
        return error_msg("error: cd: bad arguments\n"); 
    else if (chdir(av[1]) == -1)
        // Si chdir échoue, affiche un message d'erreur.
        return error_msg("error: cd: cannot change directory to "), error_msg(av[1]), error_msg("\n");
    return (0); 
}

// Déclaration de la fonction execute_command pour exécuter les commandes.
int execute_command(char **av, char **env, int i) 
{
    // Création de descripteurs de fichier pour le pipe.
    int fd[2];
    int status;
    // Vérifie si un pipe est présent.
    int is_pipe = av[i] && !strcmp(av[i], "|");

    // Crée un pipe en cas de besoin et gère les erreurs.
    if (is_pipe && pipe(fd) == -1)
        return error_msg("error: fatal\n"); 

    // Crée un processus enfant.
    int pid = fork();
    if (!pid) 
    {
        // Dans le processus enfant, modifie les descripteurs de fichier si nécessaire et exécute la commande.
        av[i] = 0;
        if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return error_msg("error: fatal\n");
        execve(*av, av, env);
        // Si execve échoue, affiche un message d'erreur.
        return (error_msg("error: cannot execute "), error_msg(*av), error_msg("\n"));
    }

    // Attend la fin du processus enfant.
    waitpid(pid, &status, 0);
    if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return error_msg("error: fatal\n"); 
    return (WIFEXITED(status) && WEXITSTATUS(status));
}

// Point d'entrée principal du programme.
int main(int ac, char **av, char **env) 
{
    int    i = 0;
    int    status = 0;

    // Traite les arguments de la ligne de commande.
    if (ac > 1) 
    {
        while (av[i] && av[++i]) 
        {
            av += i;
            i = 0; 
            // Parcourt les arguments jusqu'à un pipe ou un point-virgule.
            while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
                i++;
            // Appelle la fonction cd ou execute_command en fonction de la commande.
            if (!strcmp(*av, "cd"))
                status = cd(av, i);
            else if (i)
                status = execute_command(av, env, i);
        }
    }
    return (status);
}*/
