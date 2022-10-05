#include "libft.h"
#include <ctype.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	assert(ft_isalpha(argv[1][0]) == isalpha(argv[1][0]));
}
