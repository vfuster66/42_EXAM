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