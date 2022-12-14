#ifndef MY_H_
# define MY_H_

#include <stdarg.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

void    my_putchar_e(char c);
int     my_putstr_e(char *str);
void    my_putchar(char c);
int     my_putstr(char *str);
void    my_put_nbr(int nb);
void    my_put_nbr2(unsigned int nb);
void    my_put_nbr_base(unsigned int nb, char *base);
void    my_strascii(char *str);
int     my_getnbr(char *str);
char    *my_revstr(char *str);
int     my_strlen(char *str);
void    my_printf_flags(char *str, va_list ap, int count);
void    my_printf(char *str, ...);
int     my_strcmp(char *str1, char *str2);
char    *my_epur_str(char *str);
void    add_arg(char *av, char **arg);
char    **malloc_arg(char *av, int j);
char    **recup_arg(char *av, int l);
int     create_env2(char *str, char **env, int i);
int     create_env(char *str, char **env, int i);
void    print_env(char **env);
char    *cp_env(char *environ);
char    **get_env(char **environ);
void    error_perm_denied(char *av);
void    error_not_a_directory(char *av);
void    error_no_such_file_or_dir(char *av);
void    error_command_not_found(char *av);
char    **recup_arg_abs(char *str);
int     my_exec_abs(char *str, char **env);
void    add_env_path(char *path, char **env_path);
char    **recup_env_path_2(char *path);
char    **recup_env_path(char **env, char **env_path);
int     my_exec(char *av, char **env);
void    modif_pwd2(char *path, char **env, int i);
int     modif_pwd(char *path, char **env);
int	my_exec_cd_2(char *path, char **env);
void    copy_exec_cd_path(char *path, char *str, int j);
int     my_exec_cd(char *str, char **env);
int     main(int ac, char **av, char **environ);
char    *my_realloc(char *str);
void    prompt(void);
void    ctrl_d(void);
void    add_path(char *av, char **arg);
void    recup_path_2(char *path, char **env_path, char *av);
char    *recup_path(char *av, int *l, char **env_path);
char    *recup_pwd(char **env);
int     setenv_novoid(char *str, char **env);
int     setenv_void(char *str, char **env);
int     my_setenv2(char *str, char **env, int nb_arg);
int     my_setenv(char *str, char **env);
int     cmd2(char *str, char **env);
int     cmd(char *str, char **env);
char    *get_my_line(char buf, char *str, char **env, int *pos);
int     start_minishell(char **env);
void    sighandler(int signum);
int     my_unsetenv2(char *str, char **env);
int     my_unsetenv(char *str, char **env);
void	my_exit(void);

#endif
