#include "rpn_calc.h"

void	ft_lstdel(t_list **begin_list)
{
	t_list	*tmp;

	tmp = *begin_list;
	*begin_list = tmp->next;
	free(tmp);
}
