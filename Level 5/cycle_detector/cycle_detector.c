
#include "list.h"
#include <stdlib.h>

int cycle_detector(const t_list *list)
{
	if (list == NULL)
		return (1);
	
	const t_list *slow, *fast;

	slow = list;
	fast = list;

	while (1)
	{
		slow = slow->next;
		if (fast->next != NULL)
			fast = fast->next->next;
		else
			return 0;

		if (slow == NULL || fast == NULL)
			return 0;
		if (slow == fast)
			return 1;
	}

}

