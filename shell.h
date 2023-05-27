#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <ctype.h>
#include <errno.h>

#define STORAGE_SIZE 1024
extern char **environ;


char *my_strcpy(char *destt, const char *srcc);
char **split_string(char *strr, const char *str_separatorr, int *num_of_wordss);
char *read_input();
size_t get_strlen(const char *strr);
void free_words(char **wordss, int num_of_wordss);

/* File management */
int file_exists(const char *patht);
char *get_dir_path(const char *patht, const char *cmdd);
char *get_path_copy();

/*forking*/
int execute_by_forking(char **arr_of_wordss, char *user_promptt,
char *sh_namee, int cntt, int nn);
char *get_full_path(const char *cmdd);
void exec_cmd_with_execve(char *cmdd, char **arr_of_wordss);
void wait_kid_process(pid_t pid, int *statuss);
void execute_bin_ls(char **arr_of_wordss);

/* String manipulation */
char *my_strcat(char *destt, const char *srcc);
char *my_strdup(const char *s);
int my_strcmp(const char *firstt, const char *secondd);
int my_atoi(const char *stringg);

/*Get line*/
ssize_t my_getline(char **the_storage_ptrr, size_t *size_of_storagee,
FILE *read_stream);
int read_from_input(char *char_to_readd);
void *my_realloc(void *old_ptrr, size_t sizee);
void update_buff(char **buff_ptrr, size_t *buff_sizee, char *bufferr, size_t idx);
void *my_memcpy(void *destinationn, const void *sourcee, size_t num_of_bytes);


/**handle exit , setenv, unsetenv*/
int handle_various_cmds(char **arr_of_wordss, char *user_promptt,
char *sh_namee, int cntt, int nn);
void handle_the_env(void);
int my_setenv(const char *env_namee, const char *env_valuee,
		int env_overwrite_val);
int my_unsetenv(const char *env_namee);

/*handle cd*/
void my_cd(char **arr_of_wordss);

/*cd helper functions*/
char *env_vars(const char *env_namee, char **env_pointerr);
void isError(const char *msgg);
char *get_dir(const char *initial_pathh);
char *handle_cwd();
void switch_current_directory(const char *directoryy);

/*String comparison function*/
int my_strncmp(const char *st1, const char *st2, size_t number);

/*execute multiple commands*/
int exec_multi_cmds(char *user_promptt, char *sh_namee, int cntt);

void p_the_err(char *cntt, char *sh_namee, char *cmdd, char *msg);
int is_valid_word(char *strr);
char *intToString(int num);
void handle_sig(int sig);
void handle_exit_with_status(char **arr_of_wordss, char *user_promptt,
char *sh_namee, int cntr, int nn);
void ex_err(char **arr_of_wordss, int cntr, char *sh_namee);
int my_isdig(int c);
#endif
