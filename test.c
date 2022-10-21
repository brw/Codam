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

int	main()
{
	assert(ft_isalpha('a') == isalpha('a'));
	assert(ft_isalpha('m') == isalpha('m'));
	assert(ft_isalpha('z') == isalpha('z'));
	assert(ft_isalpha(' ') == isalpha(' '));
	assert(ft_isalpha('0') == isalpha('0'));
	assert(ft_isalpha(EOF) == isalpha(EOF));

	assert(ft_isdigit('0') == isdigit('0'));
	assert(ft_isdigit('9') == isdigit('9'));
	assert(ft_isdigit('\0') == isdigit('\0'));
	assert(ft_isdigit(' ') == isdigit(' '));
	assert(ft_isdigit(EOF) == isdigit(EOF));

	assert(ft_toupper('a') == toupper('a'));
	assert(ft_toupper('A') == toupper('A'));
	assert(ft_toupper(';') == toupper(';'));

	assert(ft_tolower('A') == tolower('A'));
	assert(ft_tolower('a') == tolower('a'));
	assert(ft_tolower(';') == tolower(';'));

	assert(ft_isalnum('a') == isalnum('a'));
	assert(ft_isalnum('0') == isalnum('0'));
	assert(ft_isalnum('z') == isalnum('z'));
	assert(ft_isalnum('9') == isalnum('9'));
	assert(ft_isalnum('\0') == isalnum('\0'));
	assert(ft_isalnum(' ') == isalnum(' '));
	assert(ft_isalnum(EOF) == isalnum(EOF));

	assert(ft_isascii(0) == isascii(0));
	assert(ft_isascii(127) == isascii(127));
	assert(ft_isascii(128) == isascii(128));
	assert(ft_isascii(-1) == isascii(-1));
	assert(ft_isascii(1000) == isascii(1000));

	assert(ft_isprint('a') == isprint('a'));
	assert(ft_isprint(' ') == isprint(' '));
	assert(ft_isprint('~') == isprint('~'));
	assert(ft_isprint('\0') == isprint('\0'));
	assert(ft_isprint(127) == isprint(127));

	char	strlen_str1[] = "Hello World!";
	char	strlen_str2[] = "";
	assert(ft_strlen(strlen_str1) == strlen(strlen_str1));
	assert(ft_strlen(strlen_str2) == strlen(strlen_str2));

	char	strchr_str1[] = "Hello World!";
	char	strchr_str2[] = "";
	char	strchr_str3[] = "Test";
	char	strchr_str4[] = "Test\0Te\0st";
	char	strchr_c1 = 'o';
	char	strchr_c2 = '\0';
	assert(ft_strchr(strchr_str1, strchr_c1) == strchr(strchr_str1, strchr_c1));
	assert(ft_strchr(strchr_str2, strchr_c1) == strchr(strchr_str2, strchr_c1));
	assert(ft_strchr(strchr_str3, strchr_c1) == strchr(strchr_str3, strchr_c1));
	assert(ft_strchr(strchr_str4, strchr_c1) == strchr(strchr_str4, strchr_c1));
	assert(ft_strchr(strchr_str1, strchr_c2) == strchr(strchr_str1, strchr_c2));
	assert(ft_strchr(strchr_str2, strchr_c2) == strchr(strchr_str2, strchr_c2));
	assert(ft_strchr(strchr_str3, strchr_c2) == strchr(strchr_str3, strchr_c2));
	assert(ft_strchr(strchr_str4, strchr_c2) == strchr(strchr_str4, strchr_c2));

	assert(ft_strrchr(strchr_str1, strchr_c1) == strrchr(strchr_str1, strchr_c1));
	assert(ft_strrchr(strchr_str2, strchr_c1) == strrchr(strchr_str2, strchr_c1));
	assert(ft_strrchr(strchr_str3, strchr_c1) == strrchr(strchr_str3, strchr_c1));
	assert(ft_strrchr(strchr_str4, strchr_c1) == strrchr(strchr_str4, strchr_c1));
	assert(ft_strrchr(strchr_str1, strchr_c2) == strrchr(strchr_str1, strchr_c2));
	assert(ft_strrchr(strchr_str2, strchr_c2) == strrchr(strchr_str2, strchr_c2));
	assert(ft_strrchr(strchr_str3, strchr_c2) == strrchr(strchr_str3, strchr_c2));
	assert(ft_strrchr(strchr_str4, strchr_c2) == strrchr(strchr_str4, strchr_c2));

	char	strncmp_str1[] = "Hello World!";
	char	strncmp_str2[] = "Hello!";
	char	strncmp_str3[] = "Hello";
	char	strncmp_str4[] = "";
	assert(sign(ft_strncmp(strncmp_str1, strncmp_str2, 20)) == sign(strncmp(strncmp_str1, strncmp_str2, 20)));
	assert(sign(ft_strncmp(strncmp_str1, strncmp_str3, 20)) == sign(strncmp(strncmp_str1, strncmp_str3, 20)));
	assert(sign(ft_strncmp(strncmp_str1, strncmp_str4, 20)) == sign(strncmp(strncmp_str1, strncmp_str4, 20)));
	assert(sign(ft_strncmp(strncmp_str1, strncmp_str2, 5)) == sign(strncmp(strncmp_str1, strncmp_str2, 5)));
	assert(sign(ft_strncmp(strncmp_str1, strncmp_str2, 6)) == sign(strncmp(strncmp_str1, strncmp_str2, 6)));
	assert(sign(ft_strncmp(strncmp_str1, strncmp_str2, 7)) == sign(strncmp(strncmp_str1, strncmp_str2, 7)));
	assert(sign(ft_strncmp(strncmp_str1, strncmp_str2, 0)) == sign(strncmp(strncmp_str1, strncmp_str2, 0)));

	char	memset_str1[] = "Hello World!";
	char	memset_str2[] = "Hello World!";
	assert(ft_memset(memset_str1, 'o', 6) == memset(memset_str1, 'o', 6));
	assert(ft_memset(memset_str2, 'o', (0)) == memset(memset_str2, 'o', (0)));

	char	bzero_str1[] = "Hello World!";
	char	bzero_str2[] = "Hello World!";
	ft_bzero(bzero_str1, 6);
	bzero(bzero_str2, 6);
	assert(!strcmp(bzero_str1, bzero_str2));

	char	memcpy_str1[] = "Hello World!";
	char	memcpy_str2[] = "Test123";
	char	memcpy_str3[] = "Test123";
	ft_memcpy(memcpy_str2, memcpy_str1, 6);
	memcpy(memcpy_str3, memcpy_str1, 6);
	assert(!strcmp(memcpy_str2, memcpy_str3));
	ft_memcpy(memcpy_str2, memcpy_str1, 0);
	memcpy(memcpy_str3, memcpy_str1, 0);
	assert(!strcmp(memcpy_str2, memcpy_str3));

	char	memcmp_str1[20] = "Hello World!";
	char	memcmp_str2[20] = "Hello!";
	char	memcmp_str3[20] = "Hello";
	char	memcmp_str4[20] = "";
	assert(sign(ft_memcmp(memcmp_str1, memcmp_str2, 20)) == sign(memcmp(memcmp_str1, memcmp_str2, 20)));
	assert(sign(ft_memcmp(memcmp_str1, memcmp_str3, 20)) == sign(memcmp(memcmp_str1, memcmp_str3, 20)));
	assert(sign(ft_memcmp(memcmp_str1, memcmp_str4, 20)) == sign(memcmp(memcmp_str1, memcmp_str4, 20)));
	assert(sign(ft_memcmp(memcmp_str1, memcmp_str2, 5)) == sign(memcmp(memcmp_str1, memcmp_str2, 5)));
	assert(sign(ft_memcmp(memcmp_str1, memcmp_str2, 6)) == sign(memcmp(memcmp_str1, memcmp_str2, 6)));
	assert(sign(ft_memcmp(memcmp_str1, memcmp_str2, 7)) == sign(memcmp(memcmp_str1, memcmp_str2, 7)));
	assert(sign(ft_memcmp(memcmp_str1, memcmp_str2, 0)) == sign(memcmp(memcmp_str1, memcmp_str2, 0)));

	char	memmove_str1[] = "Hello World!";
	char	memmove_str2[] = "Test123";
	char	memmove_str3[] = "Test123";
	char	memmove_str4[] = "Hello World!";
	char	memmove_str5[] = "Hello World!";
	char	memmove_str6[] = "Hello World!";
	char	memmove_str7[] = "Hello World!";
	ft_memmove(memmove_str2, memmove_str1, 6);
	memmove(memmove_str3, memmove_str1, 6);
	assert(!strcmp(memmove_str2, memmove_str3));
	ft_memmove(memmove_str2, memmove_str1, 0);
	memmove(memmove_str3, memmove_str1, 0);
	assert(!strcmp(memmove_str2, memmove_str3));
	ft_memmove(memmove_str4, memmove_str4 + 4, 6);
	memmove(memmove_str5, memmove_str5 + 4, 6);
	assert(!strcmp(memmove_str4, memmove_str5));
	ft_memmove(memmove_str6 + 4, memmove_str6, 6);
	memmove(memmove_str7 + 4, memmove_str7, 6);
	assert(!strcmp(memmove_str6, memmove_str7));

	char	strlcpy_str1[] = "Hello World!";
	char	strlcpy_str2[] = "Test123";
	char	strlcpy_str3[] = "Test123";
	ft_strlcpy(strlcpy_str2, strlcpy_str1, 6);
	strlcpy(strlcpy_str3, strlcpy_str1, 6);
	assert(!strcmp(strlcpy_str2, strlcpy_str3));
	ft_strlcpy(strlcpy_str2, strlcpy_str1, 0);
	strlcpy(strlcpy_str3, strlcpy_str1, 0);
	assert(!strcmp(strlcpy_str2, strlcpy_str3));

	char	strnstr_haystack[] = "Hello World!\0Hellooo";
	char	strnstr_needle1[] = "Hello";
	char	strnstr_needle2[] = "";
	char	strnstr_needle3[] = "!";
	char	strnstr_needle4[] = "Helloo";
	char	strnstr_needle5[] = "World!";
	assert(ft_strnstr(strnstr_haystack, strnstr_needle1, 15) == strnstr(strnstr_haystack, strnstr_needle1, 15));
	assert(ft_strnstr(strnstr_haystack, strnstr_needle1, 4) == strnstr(strnstr_haystack, strnstr_needle1, 4));
	assert(ft_strnstr(strnstr_haystack, strnstr_needle1, 5) == strnstr(strnstr_haystack, strnstr_needle1, 5));
	assert(ft_strnstr(strnstr_haystack, strnstr_needle1, 6) == strnstr(strnstr_haystack, strnstr_needle1, 6));
	assert(ft_strnstr(strnstr_haystack, strnstr_needle2, 15) == strnstr(strnstr_haystack, strnstr_needle2, 15));
	assert(ft_strnstr(strnstr_haystack, strnstr_needle3, 15) == strnstr(strnstr_haystack, strnstr_needle3, 15));
	assert(ft_strnstr(strnstr_haystack, strnstr_needle4, 15) == strnstr(strnstr_haystack, strnstr_needle4, 15));
	assert(ft_strnstr(strnstr_haystack, strnstr_needle5, 15) == strnstr(strnstr_haystack, strnstr_needle5, 15));
	assert(ft_strnstr(strnstr_haystack, strnstr_needle5, 10) == strnstr(strnstr_haystack, strnstr_needle5, 10));

    char  *atoi_str[] = { "12345+6789", "-12345-6789", "  12345", "  -12345", "  +12345", "  - 12345", "  + 12345", "abc12345", "abc+12345", "abc-12345", " \t\n\f\v\r 12345", " +-12345", " =-12345" };
    for (size_t i = 0; i < sizeof(atoi_str) / sizeof(atoi_str[0]); i++)
        assertf(ft_atoi(atoi_str[i]) == atoi(atoi_str[i]), "Failed with input: %s", atoi_str[i]);

    void    *p;
    char    zero[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    p = ft_calloc(2, 4);
    assert(!memcmp(p, zero, 8));
    free(p);

    char    strdup_src1[] = "Hello World!";
    char    strdup_src2[] = "";
    char    *strdup_dest1;
    char    *strdup_dest2;
    char    *strdup_dest3;
    char    *strdup_dest4;
    strdup_dest1 = ft_strdup(strdup_src1);
    strdup_dest2 = strdup(strdup_src1);
    assert(!strcmp(strdup_dest1, strdup_dest2));
    free(strdup_dest1);
    free(strdup_dest2);
    strdup_dest3 = ft_strdup(strdup_src2);
    strdup_dest4 = strdup(strdup_src2);
    assert(!strcmp(strdup_dest3, strdup_dest4));
    free(strdup_dest3);
    free(strdup_dest4);

    char    substr_str1[] = "Hello World!";
    char    substr_str2[] = "";
    assert(!strcmp(ft_substr(substr_str1, 0, 5), "Hello"));
    assert(!strcmp(ft_substr(substr_str1, 2, SIZE_MAX), substr_str1 + 2));
    assert(!strcmp(ft_substr(substr_str1, 0, 0), ""));
    assert(!strcmp(ft_substr(substr_str1, 20, 0), ""));
    assert(!strcmp(ft_substr(substr_str1, 20, 20), ""));
    assert(!strcmp(ft_substr(substr_str2, 0, 5), ""));
    assert(!strcmp(ft_substr(substr_str2, 2, SIZE_MAX), ""));
    assert(!strcmp(ft_substr(substr_str2, 0, 0), ""));
    assert(!strcmp(ft_substr(substr_str2, 20, 0), ""));
    assert(!strcmp(ft_substr(substr_str2, 20, 20), ""));

    char    strjoin_str1[] = "Hello";
    char    strjoin_str2[] = " ";
    char    strjoin_str3[] = "World!";
    assert(!strcmp(ft_strjoin(strjoin_str1, strjoin_str3), "HelloWorld!"));
    assert(!strcmp(ft_strjoin(ft_strjoin(strjoin_str1, strjoin_str2), strjoin_str3), "Hello World!"));
    assert(!strcmp(ft_strjoin(strjoin_str1, ""), "Hello"));
    assert(!strcmp(ft_strjoin("", strjoin_str1), "Hello"));
    assert(!strcmp(ft_strjoin("", ""), ""));
}
