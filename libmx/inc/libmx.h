#ifndef ULIB_LIBMX_H
#define ULIB_LIBMX_H

#include <wchar.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <malloc/malloc.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
}              t_list;

/* Utils Pack */
void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void(*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);

/* My Func */
int mx_get_hex_digits_count(unsigned long num);
int mx_intlen(int num);
bool mx_is_whitespace(char chr);
void str_swap(char **str1, char **str2);
bool mx_isupper(char chr);
int mx_atoi(const char *str);


/* Strings Pack */
int mx_strlen(const char *string);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char*src, int len);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_strcmp(char *s1, char *s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);

char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

/* My Func */
char *mx_strncat(char *s1, const char *s2, int num);
char *mx_delete_trailing(char *string, char chr);
int mx_strncmp(char *s1, char *s2, int n);
char  *mx_m_read_line(char delim, const char *filename, const int fd, int skip);
bool mx_isdigit(int c);
bool mx_is_number(char *num);
char *mx_makestring(char **parts, size_t parts_count);
bool mx_check_str_int(char *num);
long long mx_atoll(const char *str);

/* Memory Pack */
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

/* My Func */
void *mx_malloc(size_t n);
void mx_free(void * p);
size_t mx_malloc_size(void *p);

/* List Pack */
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool(*cmp)(void*, void*));

/* Compare Pack */ // ToDo: Make multiCompare
bool compare_base(void *x, void *y);
bool compare_string(char *x, char *y);

#endif
