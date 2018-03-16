
#include "rpn_calc.h"

char *advance(char *str)
{
	while (*str && *str != ' ')
		++str;
	return (str);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *str = av[1];
		t_list *begin_list = NULL;

		while (*str)
		{
			if (ft_isnum(str))
			{
				ft_lstadd(&begin_list, atoi(str));
				str = advance(str);
			}
			else if (ft_isop(*str))
			{
				if (!ft_operate(&begin_list, *str))
					break ;
				str = advance(str);
			}
			else if (*str == ' ')
			{
				if (!*(str + 1))
					break;
				++str;
			}												
			else
				break ;
		}
		if (*str || begin_list->next)
				write(1, "Error\n", 6);
		else
			printf("%d\n", begin_list->val);
		while (begin_list)
			ft_lstdel(&begin_list);
		}
		else
			write(1, "Error\n", 6);
		return (0);
}
