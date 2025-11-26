# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	test(char *s, ...)
{
	va_list	test;
	int i = -1;
	int temp;

	va_start(test, s);
	while (++i <= 4)
	{
		temp = va_arg(test, int);
		printf("%i", temp);
	}
}



int main()
{

	test("tututu", NULL, 2, 3, 4, 5, 6);
	// void *argument;
	// int j;

	// printf("c : ");
	// j = printf("%c", NULL);
	// printf(", result : %i \n", j);
	// printf("s : ");
	// j = printf("%s", NULL);
	// printf(", result : %i \n", j);
	// printf("p : ");
	// j = printf("%p", NULL);
	// printf(", result : %i \n", j);
	// printf("d : ");
	// j = printf("%d", NULL);
	// printf(", result : %i \n", j);
	// printf("i : ");
	// j = printf("%i", NULL);
	// printf(", result : %i \n", j);
	// printf("u : ");
	// j = printf("%u", NULL);
	// printf(", result : %i \n", j);
	// printf("x : ");
	// j = printf("%x", NULL);
	// printf(", result : %i \n", j);
	// printf("X : ");
	// j = printf("%X", NULL);
	// printf(", result : %i \n", j);
	// printf("%% : ");
	// j = printf("%%", NULL);
	// printf(", result : %i \n", j);
}
