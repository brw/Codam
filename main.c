#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main()
{
	// ft_isalpha
	assert(ft_isalpha('a'));
	assert(ft_isalpha('m'));
	assert(ft_isalpha('z'));
	assert(!ft_isalpha(' '));
	assert(!ft_isalpha('0'));
	assert(!ft_isalpha(EOF));

	// ft_isdigit
	assert(ft_isdigit('0'));
	assert(ft_isdigit('9'));
	assert(!ft_isdigit('\0'));
	assert(!ft_isdigit(' '));
	assert(!ft_isdigit(EOF));

	// ft_toupper
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('A') == 'A');
	assert(ft_toupper(';') == ';');

	// ft_tolower
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('a') == 'a');
	assert(ft_tolower(';') == ';');

	// ft_isalnum
	assert(ft_isalnum('a'));
	assert(ft_isalnum('0'));
	assert(ft_isalnum('z'));
	assert(ft_isalnum('9'));
	assert(!ft_isalnum('\0'));
	assert(!ft_isalnum(' '));
	assert(!ft_isalnum(EOF));

	// ft_isascii
	assert(ft_isascii(0));
	assert(ft_isascii(127));
	assert(!ft_isascii(128));
	assert(!ft_isascii(-1));
	assert(!ft_isascii(1000));

	// ft_isprint
	assert(ft_isprint('a'));
	assert(ft_isprint(' '));
	assert(ft_isprint('~'));
	assert(!ft_isprint('\0'));
	assert(!ft_isprint(127));

	// ft_strlen
	char strlen_str1[] = "Hello World!";
	char strlen_str2[] = "";
	assert(ft_strlen(strlen_str1) == strlen(strlen_str1));
	assert(ft_strlen(strlen_str2) == strlen(strlen_str2));
}
