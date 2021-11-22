#include "push_swap.h"
void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
void ft_sort_int_tab(int *tab, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                ft_swap(&tab[i], &tab[j]);
            }
            j++;
        }
        i++;
    }
}

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int neg;
    size_t num;

    num = 0;
    neg = 1;
    if (*str == '-')
    {
        neg *= -1;
        str++;
    }
    while (ft_isdigit(*str))
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return (num * neg);
}
int len_av(char **av)
{
    int i;
    i = 0;
    while (*av)
    {
        i++;
        av++;
    }
    return i;
}
int check_list_bit(t_list *list, int pos_bit)
{
    int bit;
    int ret = 0;
    t_list *temp = list;
    while (list)
    {
        bit = list->content;
        //printf("%d\n",bit);
        if (((bit >> pos_bit) & 1) == 0 && ((bit >> (pos_bit - 1)) & 1) == 0)
        {
            ret++;
        }
        else
            ret--;
        list = list->next;
    }
    //printf("%d",ret);
    list = temp;
    if (ret == ft_lstsize(list))
        return 0;
    if (ret == -ft_lstsize(list))
        return 1;
    return 6;
}
int main(int ac, char **av)
{
    int len;
    int i = 0;
    av++;
    len = len_av(av);
    i = 0;
    t_list *list_a;
    parse_input(av, &list_a, len);
    //sort_least_sig_dig(&list_a,len);
    //sort_least_sig_dig_2bit(&list_a,len);
    sort_chunks(&list_a,len);
/*
    t_list *list_b = NULL;
    //print_list(list_a,list_b);
    int bits = 0;
    while ((len - 1) >> bits)
        bits++;
    int topnum;
    i = 0;
    int j = 0;
    while (i < bits)
    {
        if (i == 0)
        {
            j = 0;
            while (j < len)
            {
                topnum = list_a->content;
                if (((topnum >> i) & 1) == 0)
                {
                    printf("pb\n");
                    push_b(list_a->content, &list_a, &list_b);
                    //print_list(list_a,list_b);
                }
                else
                {
                    printf("ra\n");
                    rotate(&list_a);
                    //print_list(list_a,list_b);
                }
                j++;
            }
        }
        
        else if (i % 1 == 0)
        {
            //check next bit before pushing
            //push next 0s to b
            int size = ft_lstsize(list_a);
            j = 0;
            while (j < size)
            {
                topnum = list_a->content;
                if (((topnum >> i) & 1) == 0)
                {
                    printf("pb\n");
                    push_b(list_a->content, &list_a, &list_b);
                    //print_list(list_a,list_b);
                }
                else
                {
                    printf("ra\n");
                    rotate(&list_a);
                    //print_list(list_a,list_b);
                }
                j++;
            }
            size = ft_lstsize(list_b);
            j = 0;
            while (j < size)
            {
                topnum = list_b->content;
                if (((topnum >> i) & 1) == 1)
                {
                    printf("pa\n");
                    push_a(list_b->content, &list_a, &list_b);
                    //print_list(list_a,list_b);
                }
                else
                {
                    printf("rb\n");
                    rotate(&list_b);
                    //print_list(list_a,list_b);
                }
                j++;
            }
        }
        else
        {
            //check next bit before pushing
            //push next 0s to b
            int size = ft_lstsize(list_a);
            j = 0;
            while (check_list_bit(list_a, i))
            {
                topnum = list_a->content;
                if (((topnum >> i) & 1) == 0)
                {
                    printf("pb\n");
                    push_b(list_a->content, &list_a, &list_b);
                    //print_list(list_a,list_b);
                }
                else
                {
                    printf("ra\n");
                    rotate(&list_a);
                    //print_list(list_a,list_b);
                }
                j++;
            }
            size = ft_lstsize(list_b);
            j = 0;
            while (j < size)
            {
                topnum = list_b->content;
                if (((topnum >> i) & 1) == 1)
                {
                    printf("pa\n");
                    push_a(list_b->content, &list_a, &list_b);
                    //print_list(list_a,list_b);
                }
                else
                {
                    printf("rb\n");
                    rotate(&list_b);
                    //print_list(list_a,list_b);
                }
                j++;
            }
        }
        i++;
    }
    while (ft_lstsize(list_b) != 0)
    {
        printf("pa\n");
        push_a(list_b->content, &list_a, &list_b);
        //print_list(list_a,list_b);
    }
    //print_list(list_a,list_b);
    free(list_a);
    //printf("%d",0)*/
}