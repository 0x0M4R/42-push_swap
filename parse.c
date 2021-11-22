#include "push_swap.h"
int *make_sorted_list(t_list *list_a, int len)
{
    int i=0;
    int sortlist[len];
    t_list *list_cpy=list_a;
    while(list_a)
    {
        sortlist[i]=list_a->content;
        list_a=list_a->next;
        i++;
    }
    i=0;
    /*
    while(i<len)
        printf("%d ",sortlist[i++]);
    printf("\n");*/
    list_a=list_cpy;
    ft_sort_int_tab(sortlist,len);
    i=0;
    return sortlist;
}
//convert numbers to range from 0-N
void convert_2_range(t_list *list_a, int len)
{
    int *sorted = make_sorted_list(list_a,len);
    int i=0;
    while(list_a)
    {
        i=0;
        while (i<len)
        {
            if((int)(list_a->content)==sorted[i])
            {
            list_a->content=i;
            //printf("%d %d\n", list_a->content,sortlist[i]);
            break;
            }
            i++;
        }
        list_a=list_a->next;
    }
}

void parse_input(char **av, t_list **list_a,int len)
{
    while(*av)
    {
        if (!list_a)
        list_a=ft_lstnew(ft_atoi(*av));
        else
        {
        t_list *value= ft_lstnew(ft_atoi(*av));
        ft_lstadd_back(list_a,value);
        }
        av++;
    }
    convert_2_range(*list_a,len);
}