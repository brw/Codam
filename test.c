#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>

#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define log_error(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define assertf(A, M, ...) if(!(A)) {log_error(M, ##__VA_ARGS__); assert(A); }

int	sign(int x)
{
	return ((x > 0) - (x < 0));
}

void	test_isalpha()
{
	assert(sign(ft_isalpha('a')) == sign(isalpha('a')));
	assert(sign(ft_isalpha('m')) == sign(isalpha('m')));
	assert(sign(ft_isalpha('z')) == sign(isalpha('z')));
	assert(sign(ft_isalpha(' ')) == sign(isalpha(' ')));
	assert(sign(ft_isalpha('0')) == sign(isalpha('0')));
	assert(sign(ft_isalpha(EOF)) == sign(isalpha(EOF)));
}

void	test_isdigit()
{
	assert(sign(ft_isdigit('0')) == sign(isdigit('0')));
	assert(sign(ft_isdigit('9')) == sign(isdigit('9')));
	assert(sign(ft_isdigit('\0')) == sign(isdigit('\0')));
	assert(sign(ft_isdigit(' ')) == sign(isdigit(' ')));
	assert(sign(ft_isdigit(EOF)) == sign(isdigit(EOF)));
}

void	test_toupper()
{
	assert(ft_toupper('a') == toupper('a'));
	assert(ft_toupper('A') == toupper('A'));
	assert(ft_toupper(';') == toupper(';'));
}

void	test_tolower()
{
	assert(ft_tolower('A') == tolower('A'));
	assert(ft_tolower('a') == tolower('a'));
	assert(ft_tolower(';') == tolower(';'));
}

void	test_isalnum()
{
	assert(sign(ft_isalnum('a')) == sign(isalnum('a')));
	assert(sign(ft_isalnum('0')) == sign(isalnum('0')));
	assert(sign(ft_isalnum('z')) == sign(isalnum('z')));
	assert(sign(ft_isalnum('9')) == sign(isalnum('9')));
	assert(sign(ft_isalnum('\0')) == sign(isalnum('\0')));
	assert(sign(ft_isalnum(' ')) == sign(isalnum(' ')));
	assert(sign(ft_isalnum(EOF)) == sign(isalnum(EOF)));
}

void	test_isascii()
{
	assert(sign(ft_isascii(0)) == sign(isascii(0)));
	assert(sign(ft_isascii(127)) == sign(isascii(127)));
	assert(sign(ft_isascii(128)) == sign(isascii(128)));
	assert(sign(ft_isascii(-1)) == sign(isascii(-1)));
	assert(sign(ft_isascii(1000)) == sign(isascii(1000)));
}

void	test_isprint()
{
	assert(sign(ft_isprint('a')) == sign(isprint('a')));
	assert(sign(ft_isprint(' ')) == sign(isprint(' ')));
	assert(sign(ft_isprint('~')) == sign(isprint('~')));
	assert(sign(ft_isprint('\0')) == sign(isprint('\0')));
	assert(sign(ft_isprint(127)) == sign(isprint(127)));
}

void	test_strlen()
{
	char	str1[] = "Hello World!";
	char	str2[] = "";
	assert(ft_strlen(str1) == strlen(str1));
	assert(ft_strlen(str2) == strlen(str2));
}

void	test_strchr_and_strrchr()
{
	char	str1[] = "Hello World!";
	char	str2[] = "";
	char	str3[] = "Test";
	char	str4[] = "Test\0Te\0st";
	char	c1 = 'o';
	char	c2 = '\0';
	assert(ft_strchr(str1, c1) == strchr(str1, c1));
	assert(ft_strchr(str2, c1) == strchr(str2, c1));
	assert(ft_strchr(str3, c1) == strchr(str3, c1));
	assert(ft_strchr(str4, c1) == strchr(str4, c1));
	assert(ft_strchr(str1, c2) == strchr(str1, c2));
	assert(ft_strchr(str2, c2) == strchr(str2, c2));
	assert(ft_strchr(str3, c2) == strchr(str3, c2));
	assert(ft_strchr(str4, c2) == strchr(str4, c2));

	assert(ft_strrchr(str1, c1) == strrchr(str1, c1));
	assert(ft_strrchr(str2, c1) == strrchr(str2, c1));
	assert(ft_strrchr(str3, c1) == strrchr(str3, c1));
	assert(ft_strrchr(str4, c1) == strrchr(str4, c1));
	assert(ft_strrchr(str1, c2) == strrchr(str1, c2));
	assert(ft_strrchr(str2, c2) == strrchr(str2, c2));
	assert(ft_strrchr(str3, c2) == strrchr(str3, c2));
	assert(ft_strrchr(str4, c2) == strrchr(str4, c2));
}

void	test_strncmp()
{
	char	str1[20] = "Hello World!";
	char	str2[20] = "Hello!";
	char	str3[20] = "Hello";
	char	str4[20] = "";
	assert(sign(ft_strncmp(str1, str2, 20)) == sign(strncmp(str1, str2, 20)));
	assert(sign(ft_strncmp(str1, str3, 20)) == sign(strncmp(str1, str3, 20)));
	assert(sign(ft_strncmp(str1, str4, 20)) == sign(strncmp(str1, str4, 20)));
	assert(sign(ft_strncmp(str1, str2, 5)) == sign(strncmp(str1, str2, 5)));
	assert(sign(ft_strncmp(str1, str2, 6)) == sign(strncmp(str1, str2, 6)));
	assert(sign(ft_strncmp(str1, str2, 7)) == sign(strncmp(str1, str2, 7)));
	assert(sign(ft_strncmp(str1, str2, 0)) == sign(strncmp(str1, str2, 0)));
}

void	test_memset()
{
	char	str1[] = "Hello World!";
	char	str2[] = "Hello World!";
	assert(ft_memset(str1, 'o', 6) == memset(str1, 'o', 6));
	assert(ft_memset(str2, 'o', (0)) == memset(str2, 'o', (0)));
}

void	test_bzero()
{
	char	str1[] = "Hello World!";
	char	str2[] = "Hello World!";
	ft_bzero(str1, 6);
	bzero(str2, 6);
	assert(!strcmp(str1, str2));
}

void	test_memcpy()
{
	char	str1[] = "Hello World!";
	char	str2[] = "Test123";
	char	str3[] = "Test123";
	ft_memcpy(str2, str1, 6);
	memcpy(str3, str1, 6);
	assert(!strcmp(str2, str3));
	ft_memcpy(str2, str1, 0);
	memcpy(str3, str1, 0);
	assert(!strcmp(str2, str3));
}

void	test_memcmp()
{
	char	str1[20] = "Hello World!";
	char	str2[20] = "Hello!";
	char	str3[20] = "Hello";
	char	str4[20] = "";
	assert(sign(ft_memcmp(str1, str2, 20)) == sign(memcmp(str1, str2, 20)));
	assert(sign(ft_memcmp(str1, str3, 20)) == sign(memcmp(str1, str3, 20)));
	assert(sign(ft_memcmp(str1, str4, 20)) == sign(memcmp(str1, str4, 20)));
	assert(sign(ft_memcmp(str1, str2, 5)) == sign(memcmp(str1, str2, 5)));
	assert(sign(ft_memcmp(str1, str2, 6)) == sign(memcmp(str1, str2, 6)));
	assert(sign(ft_memcmp(str1, str2, 7)) == sign(memcmp(str1, str2, 7)));
	assert(sign(ft_memcmp(str1, str2, 0)) == sign(memcmp(str1, str2, 0)));
}

void	test_memmove()
{
	char	str1[] = "Hello World!";
	char	str2[] = "Test123";
	char	str3[] = "Test123";
	char	str4[] = "Hello World!";
	char	str5[] = "Hello World!";
	char	str6[] = "Hello World!";
	char	str7[] = "Hello World!";
	ft_memmove(str2, str1, 6);
	memmove(str3, str1, 6);
	assert(!strcmp(str2, str3));
	ft_memmove(str2, str1, 0);
	memmove(str3, str1, 0);
	assert(!strcmp(str2, str3));
	ft_memmove(str4, str4 + 4, 6);
	memmove(str5, str5 + 4, 6);
	assert(!strcmp(str4, str5));
	ft_memmove(str6 + 4, str6, 6);
	memmove(str7 + 4, str7, 6);
	assert(!strcmp(str6, str7));
}

void	test_strlcpy()
{
	char	str1[] = "Hello World!";
	char	str2[] = "Test123";
	char	str3[] = "Test123";
	ft_strlcpy(str2, str1, 6);
	strlcpy(str3, str1, 6);
	assert(!strcmp(str2, str3));
	ft_strlcpy(str2, str1, 0);
	strlcpy(str3, str1, 0);
	assert(!strcmp(str2, str3));
}

void	test_strlcat()
{
	char	dest1[13] = "Hello";
	char	dest2[13] = "Hello";
	char	dest3[13] = "Hello";
	char	dest4[13] = "Hello";
	char	dest5[20] = "Hello";
	char	dest6[20] = "Hello";
	char	src1[] = " World!";
	assert(ft_strlcat(dest1, src1, 0) == strlcat(dest2, src1, 0));
	assert(ft_strlcat(dest1, src1, 4) == strlcat(dest2, src1, 4));
	assert(ft_strlcat(dest1, src1, 13) == strlcat(dest2, src1, 13));
	assert(ft_strlcat(dest3, src1, 10) == strlcat(dest4, src1, 10));
	assert(ft_strlcat(dest5, src1, 20) == strlcat(dest6, src1, 20));
}

void	test_strnstr()
{
	char	haystack[] = "Hello World!\0Hellooo";
	char	needle1[] = "Hello";
	char	needle2[] = "";
	char	needle3[] = "!";
	char	needle4[] = "Helloo";
	char	needle5[] = "World!";
	assert(ft_strnstr(haystack, needle1, 15) == strnstr(haystack, needle1, 15));
	assert(ft_strnstr(haystack, needle1, 4) == strnstr(haystack, needle1, 4));
	assert(ft_strnstr(haystack, needle1, 5) == strnstr(haystack, needle1, 5));
	assert(ft_strnstr(haystack, needle1, 6) == strnstr(haystack, needle1, 6));
	assert(ft_strnstr(haystack, needle2, 15) == strnstr(haystack, needle2, 15));
	assert(ft_strnstr(haystack, needle3, 15) == strnstr(haystack, needle3, 15));
	assert(ft_strnstr(haystack, needle4, 15) == strnstr(haystack, needle4, 15));
	assert(ft_strnstr(haystack, needle5, 15) == strnstr(haystack, needle5, 15));
	assert(ft_strnstr(haystack, needle5, 10) == strnstr(haystack, needle5, 10));
}

void	test_atoi()
{
	char  *str[] = { "12345+6789", "-12345-6789", "  12345", "  -12345", "  +12345", "  - 12345", "  + 12345", "abc12345", "abc+12345", "abc-12345", " \t\n\f\v\r 12345", " +-12345", " =-12345" };
	for (size_t i = 0; i < sizeof(str) / sizeof(str[0]); i++)
		assertf(ft_atoi(str[i]) == atoi(str[i]), "Failed with input: %s", str[i]);
}

void	test_calloc()
{
	void    *p;
	char    zero[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	p = ft_calloc(2, 4);
	assert(!memcmp(p, zero, 8));
	free(p);
}

void	test_strdup()
{
	char    src1[] = "Hello World!";
	char    src2[] = "";
	char    *dest1;
	char    *dest2;
	char    *dest3;
	char    *dest4;
	dest1 = ft_strdup(src1);
	dest2 = strdup(src1);
	assert(!strcmp(dest1, dest2));
	free(dest1);
	free(dest2);
	dest3 = ft_strdup(src2);
	dest4 = strdup(src2);
	assert(!strcmp(dest3, dest4));
	free(dest3);
	free(dest4);
}

void	test_substr()
{
	char    str1[] = "Hello World!";
	char    str2[] = "";
	assert(!strcmp(ft_substr(str1, 0, 5), "Hello"));
	assert(!strcmp(ft_substr(str1, 2, SIZE_MAX), str1 + 2));
	assert(!strcmp(ft_substr(str1, 0, 0), ""));
	assert(!strcmp(ft_substr(str1, 20, 0), ""));
	assert(!strcmp(ft_substr(str1, 20, 20), ""));
	assert(!strcmp(ft_substr(str2, 0, 5), ""));
	assert(!strcmp(ft_substr(str2, 2, SIZE_MAX), ""));
	assert(!strcmp(ft_substr(str2, 0, 0), ""));
	assert(!strcmp(ft_substr(str2, 20, 0), ""));
	assert(!strcmp(ft_substr(str2, 20, 20), ""));
}

void	test_strjoin()
{
	char    str1[] = "Hello";
	char    str2[] = " ";
	char    str3[] = "World!";
	assert(!strcmp(ft_strjoin(str1, str3), "HelloWorld!"));
	assert(!strcmp(ft_strjoin(ft_strjoin(str1, str2), str3), "Hello World!"));
	assert(!strcmp(ft_strjoin(str1, ""), "Hello"));
	assert(!strcmp(ft_strjoin("", str1), "Hello"));
	assert(!strcmp(ft_strjoin("", ""), ""));
}

void	test_strtrim()
{
	char    str1[] = "ttestHello World!testt";
	char    str2[] = "eessesetesetestHello World!";
	char    str3[] = "Hello World!esetetestsetess";
	char    str4[] = "";
	char    str5[] = "        ";
	char    set1[] = "est";
	char    set2[] = "";
	char    set3[] = " ";
	assert(!strcmp(ft_strtrim(str1, set1), "Hello World!"));
	assert(!strcmp(ft_strtrim(str2, set1), "Hello World!"));
	assert(!strcmp(ft_strtrim(str3, set1), "Hello World!"));
	assert(!strcmp(ft_strtrim(str1, set2), str1));
	assert(!strcmp(ft_strtrim(str4, set1), str4));
	assert(!strcmp(ft_strtrim(str4, set2), str4));
	assert(!strcmp(ft_strtrim(str4, set3), str4));
	assert(!strcmp(ft_strtrim(str5, set1), str5));
	assert(!strcmp(ft_strtrim(str5, set2), str5));
	assert(!strcmp(ft_strtrim(str5, set3), ""));
}

void	test_split()
{
}

void	test_itoa()
{
	assert(!strcmp(ft_itoa(0), "0"));
	assert(!strcmp(ft_itoa(123), "123"));
	assert(!strcmp(ft_itoa(-123), "-123"));
	assert(!strcmp(ft_itoa(INT_MIN), "-2147483648"));
	assert(!strcmp(ft_itoa(INT_MAX), "2147483647"));
}

int	main()
{
	test_isalpha();
	test_isdigit();
	test_toupper();
	test_tolower();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_strchr_and_strrchr();
	test_strncmp();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memcmp();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	// size_t	i;
	// char	**arr;
	// arr = ft_split("  ", ' ');
	// i = 0;
	// while (arr[i] != NULL)
	// {
	// 	printf("ar[%lu]: %s\n", i, arr[i]);
	// 	i++;
	// }
	// printf("ar[%lu]: %s\n", i, arr[i]);
	// char	strlcat_str1[] = "Hello";
	// char	strlcat_str2[] = "World!";
	// printf("ft_strlcat: %lu\n", strlcat(NULL, strlcat_str2, 0));
}
