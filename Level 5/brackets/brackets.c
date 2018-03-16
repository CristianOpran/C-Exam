
#include <unistd.h>
#define BUFF_SIZE (4096)

static int match(char a, char b)
{
	return ((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')'));
}

static int check(char *str)
{
	int i;
	int top;
	int stack[BUFF_SIZE];

	i = 0;
	top = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') 
			stack[++top] = str[i];
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if(!match(stack[top--], str[i]))
				return 0;
		i +=1;
	}
	return (!top);
}

int main (int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc == 1)
		write(1, "\n",1);
	while (--argc)
	{
		if (check(argv[++i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}

