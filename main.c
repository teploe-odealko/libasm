#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, const void *buf, size_t nbyte);
char    *ft_strdup(const char *s1);

int	main(void)
{
	int	i;
	//ft_strlen
	printf("------------FT_STRLEN--------------\n");
	i = 0;
	char strs[5][30] = {"", "a", "abc", "abcdefghigklmnopqrstuvwxyz"};
	while (i < 4)
	{
		printf("%d)\nlen of \"%s\" is\nMY: %zu\nORIG: %zu\n", i, strs[i], ft_strlen(strs[i]), strlen(strs[i]));
		i++;
	}
//    printf("NULL: %zu", ft_strlen(NULL));

	printf("------------FT_STRCPY--------------\n");
	char strs1[4][30] = {"", "_", "___", "__________________________"};
    char strs2[4][30] = {"", "_", "___", "__________________________"};

    i = 0;
	while (i < 4)
	{
		;
		printf("MY: %s\n", ft_strcpy(strs1[i], strs[i]));
		i++;
	}

	i = 0;
    while (i < 4)
    {

        printf("ORIG: %s\n", strcpy(strs2[i], strs[i]));
        i++;
    }
//    printf("%s\n", strcpy(strs1[0], NULL));

	printf("------------FT_STRCMP--------------\n");
	i = 0;
	while (i < 4)
	{
		printf("str1: %s\nstr2: %s\nMY: %d\nORIG: %d\n\n",
			strs2[i],
			strs1[i],
			ft_strcmp(strs[i], strs1[i]),
            strcmp(strs[i], strs1[i]));
		i++;
	}
    printf("str1: %s\nstr2: %s\nMY: %d\nORIG: %d\n\n",
           "text",
           "string",
           ft_strcmp("text", "string"),
           strcmp("text", "string"));

    printf("str1: %s\nstr2: %s\nMY: %d\nORIG: %d\n\n",
           "string",
           "text",
           ft_strcmp("string", "text"),
           strcmp("string", "text"));
    printf("MY: %d\n", ft_strcmp("\200", "\0"));
    printf("ORIG: %d\n", strcmp("\200", "\0"));

	printf("------------FT_WRITE--------------\n");
	i = 0;
	while (i < 4)
	{
		ft_write(1, strs[i], ft_strlen(strs[i]));
		ft_write(1, "\n", 1);
		i++;
	}
    write(-1, "\n", 1);
	printf("trying to write to -1 fd: ERRNO is %d\n", errno);
    ft_write(-1, "\n", 1);
    printf("trying to ft_write to -1 fd: ERRNO is %d\n", errno);


    printf("------------FT_READ--------------\n");
    char buf[10];
    write(1, "Orig read: Insert value: ", 25);
    read(0, buf, 10);
    printf("\nvalue in buf: %s\n", buf);

    write(1, "ft_read: Insert value: ", 23);
    ft_read(0, buf, 10);
    printf("\nvalue in buf: %s\n", buf);

    printf("------------FT_STRDUP--------------\n");
    printf("MY: %s\n", ft_strdup(""));
    printf("ORIG: %s\n\n", strdup(""));
    printf("MY: %s\n", ft_strdup("123123"));
    printf("ORIG: %s\n\n", strdup("123123"));
    printf("MY: %s\n", ft_strdup("12345678901234567890"));
    printf("ORIG: %s\n\n", strdup("12345678901234567890"));
	return (0);
}
