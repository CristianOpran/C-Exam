
#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	t_list *list;
	int count;

	list = begin_list;
	count = 0;
	if (list)
	{
		count = 1;
		while(list->next)
		{
			list = list->next;
			count++;
		}
	}
	return (count);
}
