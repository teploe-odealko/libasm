#include <stdio.h>
#include <string.h>
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
	char strs[4][30] = {"", "a", "abc", "abcdefghigklmnopqrstuvwxyz"};
	char strs1[4][30] = {"", "_", "___", "__________________________"};

	while (i < 4)
	{
		printf("len of \"%s\" is %zu\n", strs[i], ft_strlen(strs[i]));
		i++;
	}
	//ft_strcpy
	printf("------------FT_STRCPY--------------\n");
	i = 0;
	while (i < 4)
	{
		ft_strcpy(strs1[i], strs[i]);
		printf("dst: %s\n", strs1[i]); 
		i++;
	}		

	//ft_strcmp
	
	printf("------------FT_STRCMP--------------\n");
	i = 0;
	while (i < 4)
	{
		printf("str1: %s\nstr2: %s\nres: %d\n\n",
			strs[i],
			strs1[i],
			ft_strcmp(strs[i], strs1[i]));
		i++;
	}
	printf("cmp: %d\n", ft_strcmp("gnf", "abc"));
	
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

