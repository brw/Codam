#include "../libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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

	char strlen_str1[] = "Hello World!";
	char strlen_str2[] = "";
	assert(ft_strlen(strlen_str1) == strlen(strlen_str1));
	assert(ft_strlen(strlen_str2) == strlen(strlen_str2));

	char strchr_str1[] = "Hello World!";
	char strchr_str2[] = "";
	char strchr_str3[] = "Test";
	char strchr_str4[] = "Test\0Test";
	char strchr_c1 = 'o';
	char strchr_c2 = '\0';
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

	char strncmp_str1[] = "Hello World!";
	char strncmp_str2[] = "Hello!";
	char strncmp_str3[] = "Hello";
	char strncmp_str4[] = "";
	assert(ft_strncmp(strncmp_str1, strncmp_str2, 20) == strncmp(strncmp_str1, strncmp_str2, 20));
	assert(ft_strncmp(strncmp_str1, strncmp_str3, 20) == strncmp(strncmp_str1, strncmp_str3, 20));
	assert(ft_strncmp(strncmp_str1, strncmp_str4, 20) == strncmp(strncmp_str1, strncmp_str4, 20));
	assert(ft_strncmp(strncmp_str1, strncmp_str2, 5) == strncmp(strncmp_str1, strncmp_str2, 5));
	assert(ft_strncmp(strncmp_str1, strncmp_str2, 6) == strncmp(strncmp_str1, strncmp_str2, 6));
	assert(ft_strncmp(strncmp_str1, strncmp_str2, 7) == strncmp(strncmp_str1, strncmp_str2, 7));
	assert(ft_strncmp(strncmp_str1, strncmp_str2, 0) == strncmp(strncmp_str1, strncmp_str2, 0));

	char memset_str1[] = "Hello World!";
	assert(ft_memset(memset_str1, 'o', 6) == memset(memset_str1, 'o', 6));
}
