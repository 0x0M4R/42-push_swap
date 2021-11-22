#include "push_swap.h"
void push_b(int num,t_list **list_a, t_list **list_b)
{
    t_list *value= ft_lstnew(num);
    ft_lstadd_front(list_b,value);
    t_list *nodetodel=*list_a;
    *list_a=nodetodel->next;
    free(nodetodel);
}
void push_a(int num,t_list **list_a, t_list **list_b)
{
    t_list *value= ft_lstnew(num);
    ft_lstadd_front(list_a,value);
    t_list *nodetodel=*list_b;
    *list_b=nodetodel->next;
    free(nodetodel);
}
void rotate(t_list **list_a)
{
    t_list *first=ft_lstnew((*list_a)->content);
    t_list *temp=(*list_a)->next;
    *list_a=temp;
    ft_lstadd_back(list_a,first);
}
void rev_rotate(t_list **list_a)
{
    t_list *last=ft_lstnew(ft_lstlast(*list_a)->content);
    ft_lstadd_front(list_a,last);
    t_list *temp=*list_a;
    t_list *prev;
    while ((*list_a)->next)
    {
        prev=*list_a;
        *list_a=(*list_a)->next;
    }
    *list_a=temp;
    prev->next = NULL;
}