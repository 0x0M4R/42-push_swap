#include "push_swap.h"
// push from a to b , a rotates and b rev_rotates
// push from b to b rotates and a rev_rotates
// save moves based on this ^
void push_0s_b(t_list **list_a, t_list **list_b, int i, int len)
{
    int j = 0;
    while (j<len)
    {
        int topnum = (*list_a)->content;
        if (((topnum >> i) & 1) == 0)
        {
            printf("pb\n");
            push_b((*list_a)->content, list_a, list_b);
            //print_list(*list_a,list_b);
        }
        else
        {
            printf("ra\n");
            rotate(list_a);
            //rotate(list_b);
            //print_list(*list_a,list_b);
        }
        j++;
    }
}
void push_1s_a(t_list **list_a, t_list **list_b, int i, int len)
{
    int j = 0;
    while (j<len)
    {
        int topnum = (*list_b)->content;
        if (((topnum >> i) & 1) == 1)
        {
            printf("pa\n");
            push_a((*list_b)->content, list_a, list_b);
            //print_list(list_a,list_b);
        }
        else
        {
            printf("rb\n");
            rotate(list_b);
            //rotate(list_a);
            //print_list(list_a,list_b);
        }
        j++;
    }
}
void sort_least_sig_dig(t_list **list_a, int len)
{
    t_list *list_b = NULL;
    //print_list(list_a,list_b);
    int bits = 0;
    while ((len - 1) >> bits)
        bits++;
    int topnum;
    int i = 1;
    int j = 0;
    push_0s_b(list_a, &list_b, 0, len);
    //print_list(*list_a,list_b);
    while (i < bits)
    {
        //printf("\nnewbit\n");
        int size = ft_lstsize(*list_a);
        
        push_0s_b(list_a, &list_b, i, size);
        //print_list(*list_a,list_b);
        size = ft_lstsize(list_b);
        push_1s_a(list_a, &list_b, i, size);
        print_list(*list_a,list_b);
        i++;
    }
    while (ft_lstsize(list_b) != 0)
    {
        printf("pa\n");
        push_a(list_b->content, list_a, &list_b);
        //print_list(*list_a,list_b);
    }
    //print_list(*list_a,*list_a);
    //printf("%d",0)
}