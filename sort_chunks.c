#include "push_swap.h"
// push from a to b , a rotates and b rev_rotates
// push from b to b rotates and a rev_rotates
// save moves based on this ^
int find_first_num(t_list *list, int min, int max)
{
    int i = 0;
    while (list)
    {
        if (list->content >= min && list->content <= max)
            return (i);
        i++;
        list = list->next;
    }
}
int find_last_num(t_list *list, int min, int max)
{
    int i = 0;
    int j = 0;
    t_list *temp = list;
    while (list)
    {
        if (list->content >= min && list->content <= max)
            i++;
        list = list->next;
    }
    list = temp;
    int k = 0;
    while (list)
    {
        if (list->content >= min && list->content <= max)
        {
            k++;
            if (k == i)
                return (j);
        }
        j++;
        list = list->next;
    }
}
int check_if_biggest(t_list *list, int num)
{
    int i = 0;
    t_list *temp = list;
    while (list)
    {
        if (num > list->content)
            i++;
        list = list->next;
    }
    //printf("I:%d",i);
    list = temp;
    if (i == ft_lstsize(list))
        return 1;
}
int find_smallest(t_list *list)
{
    int small = 2147483647;
    while (list)
    {
        if (small > list->content)
            small = list->content;
        list = list->next;
    }
    return small;
    printf("small:%d", small);
}
int find_next(t_list *list, int num)
{
    //int small=2147483647;
    //printf("[[%d]]", num);
    t_list *temp = list;
    while (num)
    {
        list = temp;
        while (list)
        {
            if (list->content == num)
                return (list->content);
            list = list->next;
        }
        num++;
    }
    //return small;
    //printf("small:%d",small);
}
void sort_chunks(t_list **list_a, int len)
{
    t_list *list_b = NULL;
    //print_list(list_a,list_b);
    int bits = 0;
    while ((len - 1) >> bits)
        bits++;
    int topnum;
    int i = 1;
    int j = 0;
    int min = 0;
    int max = len/5;
    while (ft_lstsize(*list_a) != 0)
    {
        printf("next\n");
        while (ft_lstsize(list_b) < max && ft_lstsize(*list_a) != 0)
        {
            if (find_first_num(*list_a, min, max-1) < (ft_lstsize(*list_a) - find_last_num(*list_a, min, max-1)))
            {
                printf("%d",(ft_lstsize(*list_a) - find_last_num(*list_a, min, max-1)));
                i = 0;
                while (i < find_first_num(*list_a, min, max-1))
                {
                    printf("ra\n");
                    rotate(list_a);
                    //print_list(*list_a, list_b);
                    i++;
                }
            }
            else
            {
                i = 0;
                while (i< ft_lstsize(*list_a) - find_last_num(*list_a, min, max))
                {
                    //printf("%d ", find_first_num(list_a, min, max));
                    //printf("%d ", find_last_num(list_a, min, max));
                    //printf("\n%d ", ft_lstsize(list_a));
                    printf("rra\n");
                    rev_rotate(list_a);
                    //print_list(*list_a, list_b);

                    i++;
                }
            }
            if (check_if_biggest(list_b, (*list_a)->content) && ft_lstsize(list_b))
            {
                //get smallest number on top.
                while (list_b->content != find_smallest(list_b))
                {
                    printf("rb\n");
                    rotate(&list_b);
                    //print_list(*list_a, list_b);
                }
            }
            else if ((*list_a)->content < find_smallest(list_b) && ft_lstsize(list_b))
            {
                //get largest number on top.
                while (!check_if_biggest(list_b, list_b->content))
                {
                    printf("rb\n");
                    rotate(&list_b);
                    //print_list(*list_a, list_b);
                }
            }
            else if(ft_lstsize(list_b)>1)
            {
                //printf(find_next)
                while (list_b->content != find_next(list_b,(*list_a)->content))
                {
                    printf("rb\n");
                    rotate(&list_b);
                    //print_list(*list_a, list_b);
                }
            }
            //printf("\n%d",);
            printf("pb\n");
            push_b((*list_a)->content, list_a, &list_b);
            print_list(*list_a, list_b);
            //printf("\nb%d",(list_b)->content);
            //find zero to 19
            //find closet from top or bottom of stack
            //ra or rb to the number
            //if biggest number than push ontop of samllest in b
            // if smallest push on largest in b
        }
        min=max;
        max+=max;
    }
}
