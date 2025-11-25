#include <stdarg.h>
#include <unistd.h>

void	test(char *s, ...)
{
	va_list	test;
	int i = -1;
	char *temp;

	va_start(test, s);
	while (++i <= 4)
	{
		temp = va_arg(test, char *);
		write(1, temp, strlen(temp));
	}
}

int main()
{
	test("abcde", "hello ", "world ");
}
