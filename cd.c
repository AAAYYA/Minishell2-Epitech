/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** cd
*/

#include "includes/mysh.h"
#include <errno.h>

void call(minish_t *msh, char **env)
{
    char *temp = getcwd(NULL, 0);
    my_cd(msh, env);
    if (msh->old_cd != NULL)
        free(msh->old_cd);
    msh->old_cd = temp;
}

char *search(char **env)
{
    char *home;
    int i = 0;

    for (i = 0; env[i] != NULL; i++) {
        if (!(my_strncmp(env[i], "HOME=", 5))) {
            home = &env[i][5];
        }
    }
    return home;
}

int errors(char *path)
{
    if (errno == ENOTDIR) {
        write(2, path, my_strlen(path));
        write(2, ": Not a directory\n", 18);
        return 84;
    }
    if (errno == ENOENT) {
        write(2, path, my_strlen(path));
        write(2, ": No such file or directory\n", 28);
        return 81;
    }
    if (errno == EACCES) {
        write(2, path, my_strlen(path));
        write(2, ": Permission denied\n", 20);
        return 84;
    }
    return 0;
}

int my_cd(minish_t *msh, char **env)
{
    char *home = search(env);
    char *path = msh->comm[1];
    char *temp = getcwd(NULL, 0);
    int ret = 0;
    if (path == NULL || !(my_strncmp(path, "~", my_strlen("~")))) {
        ret = chdir(home);
        path = home;
    } else if (!(my_strncmp(path, "-", my_strlen("-")))) {
        ret = chdir(msh->old_cd);
        path = msh->old_cd;
    } else
        ret = chdir(path);
    if (ret != 0) {
        errors(path);
        chdir(temp);
    } else {
        free(msh->old_cd);
        msh->old_cd = temp;
    }
    return ret;
}
