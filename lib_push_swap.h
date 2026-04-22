#include <stddef.h>

typedef struct int_list
{
	int	id;
	struct int_list	*prev;
	int			content;
	struct int_list	*next;
}	lst_ab;

void	fixId(lst_ab *A);
void swap_a (lst_ab **A);
void swap_b (lst_ab **A);
void swap_ab (lst_ab **A, lst_ab **B);
void push_a (lst_ab **A,	lst_ab **B);
void push_b (lst_ab **A,	lst_ab **B);
void rotate_a (lst_ab **A);
void rotate_b (lst_ab **A);
void rotate_ab (lst_ab **A, lst_ab **B);
void reverse_rotate_a (lst_ab **A);
void reverse_rotate_b (lst_ab **A);
void reverse_rotate_ab (lst_ab **A, lst_ab **B);

void ft_lstprint(lst_ab *A, lst_ab* B);
