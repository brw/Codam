#include <assert.h>
#include <ft_printf.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

void	test_printf(char *fmt, ...)
{
	int		a;
	int		b;
	va_list	args1;
	va_list	args2;

	setbuf(stdout, NULL);
	va_start(args1, fmt);
	va_start(args2, fmt);
	a = vprintf(fmt, args1);
	printf("\n");
	b = ft_vprintf(fmt, args2);
	printf("\n");
	printf("printf:    %d\nft_printf: %d\n\n", a, b);
	assert(a == b);
	va_end(args1);
	va_end(args2);
}

int	main(void)
{
	test_printf("%c", 'a');
	test_printf("Test %c Test", 'a');
	test_printf("");
	test_printf("%s", "");
	test_printf("\n");
	test_printf("%s", "\n");
	test_printf("%s %Test %s Test %s", "Hello", "World", "!");
	test_printf("%d", 0);
	test_printf("%d", 1);
	test_printf("%d", -1);
	test_printf("%d", INT_MIN);
	test_printf("%d", INT_MAX);
	test_printf("%i", 0);
	test_printf("%i", 1);
	test_printf("%i", -1);
	test_printf("%i", INT_MIN);
	test_printf("%i", INT_MAX);
	test_printf("%u", 0);
	test_printf("%u", 1);
	test_printf("%u", -1);
	test_printf("%u", UINT_MAX);
	test_printf("%x", 0);
	test_printf("%x", -1);
	test_printf("%xx", UINT_MAX);
	test_printf("%X", 0);
	test_printf("%X", -1);
	test_printf("%XX", UINT_MAX);
	test_printf("%p", (void *)NULL);
	test_printf("%p", (void *)-1);
	test_printf("%p", (void *)ULONG_MAX);
	test_printf("%p", (void *)LONG_MIN);
	test_printf("%p", (void *)LONG_MAX);
	test_printf("%%", "yeet");
}
