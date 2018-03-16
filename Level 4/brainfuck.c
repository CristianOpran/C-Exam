#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *ptr;
	int i;
	int start[5000];

	ptr = (char*)malloc(sizeof(char) * 2048);
	i = 0;
	while(i < 2048)
	{
		ptr[i] = 0;
		i++;
	}
	i = 0;
	while(argv[1][i])
	{
		if(argv[1][i] == '>')
			ptr++;
		else if(argv[1][i] == '<')
			ptr--;
		else if(argv[1][i] == '+')
			*ptr = *ptr + 1;
		else if(argv[1][i] == '-')
			*ptr = *ptr - 1;
		else if(argv[1][i] == '.')
			write(1, ptr, 1);
		else if(argv[1][i] == '[')
		{
			if(*ptr == 0)
			{
				int nrs = 0, nrd = 0;
				do {
					if(argv[1][i] == '[')
						nrs++;
					if(argv[1][i] == ']')
						nrd++;
					i++;
				}while(nrs != nrd);
				i--;
			}
			else
			{
				start[++start[0]] = i;
			}
		}
		else if(argv[1][i] == ']')
		{
			if(*ptr != 0)
				i = start[start[0]];
			else
				start[0]--;
		}
		i++;
	}
}