#include <stdio.h>
#include <string.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

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
		ft_strcpy(strs1[i], strs[i]);
		printf("MY: %s\n", strs1[i]);
		i++;
	}

	i = 0;
    while (i < 4)
    {
        strcpy(strs2[i], strs[i]);
        printf("ORIG: %s\n", strs1[i]);
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
//    char *str1 = "1232";
//    char *str2 = "1236";
//    printf("MY: %d\n", ft_strcmp(str1, str2));
//    printf("MY: %d\n", ft_strcmp("1232", "1236"));
//    printf("ORIG: %d\n", strcmp(str1, str2));
//    printf("ORIG: %d\n", strcmp("1232", "1236"));
    printf("MY: %d\n", ft_strcmp("\200", "\0"));
    printf("ORIG: %d\n", strcmp("\200", "\0"));

	//ft_write
	printf("------------FT_WRITE--------------\n");
	i = 0;
	while (i < 4)
	{
		ft_write(1, strs[i], ft_strlen(strs[i]));
		ft_write(1, "\n", 1);
		i++;
	}
	return (0);
}

