#include "rpn_calc.h"

void	ft_lstadd(t_list **begin_list, int val)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))))
	{
		new->val = val;
		new->next = *begin_list;
		*begin_list = new;
	}
}
