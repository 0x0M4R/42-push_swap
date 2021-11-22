#include "push_swap.h"
// push from a to b , a rotates and b rev_rotates
// push from b to b rotates and a rev_rotates
// save moves based on this ^
//push 
void push_to_bottom(t_list **list_a, t_list **list_b, int i, int len)
{
    //check for 00
    int j = 0;
    while (j < len)
    {
        int topnum = (*list_a)->content;
        if (((topnum >> i) & 1) == 0 && ((topnum >> (i + 1)) & 1) == 0)
        // if least sig bit is 0 pb
        {

            //push to bottom!
            printf("pb\n");
            push_b((*list_a)->content, list_a, list_b);
            /*
            if (ft_lstsize(*list_a) < len)
            {
                printf("rb\n");
                rotate(list_b);
            }*/
        }
        else
        {
            printf("ra\n");
            rotate(list_a);
        }
        j++;
    }
}
void push_to_top(t_list **list_a, t_list **list_b, int i, int len)
{
    //check for 01
    int j = 0;
    while (j < len)
    {
        int topnum = (*list_a)->content;
        if (((topnum >> i) & 1) == 1 && ((topnum >> (i + 1)) & 1) == 0)
        // if least sig bit is 0 pb
        {

            //push to bottom!
            printf("pb\n");
            push_b((*list_a)->content, list_a, list_b);
        }
        else
        {
            printf("ra\n");
            rotate(list_a);
        }
        j++;
    }
}
void push10_to_top(t_list **list_a, t_list **list_b, int i, int len)
{
    //check for 01
    int j = 0;
    while (j < len)
    {
        int topnum = (*list_a)->content;
        if (((topnum >> i) & 1) == 0 && ((topnum >> (i + 1)) & 1) == 1)
        // if least sig bit is 0 pb
        {

            //push to bottom!
            printf("pb\n");
            push_b((*list_a)->content, list_a, list_b);
        }
        else
        {
            printf("ra\n");
            rotate(list_a);
        }
        j++;
    }
}
void connect(t_list **list_a, t_list **list_b)
{
    while (ft_lstsize(*list_b) != 0)
    {
        //check if next bit is 1. push it to before first 1s bit
        printf("pa\n");
        push_a((*list_b)->content, list_a, list_b);
    }
}
void sort_least_sig_dig_2bit(t_list **list_a, int len)
{
    t_list *list_b = NULL;
    //print_list(list_a,list_b);
    int bits = 0;
    while ((len - 1) >> bits)
        bits++;
    int topnum;
    int i = 0;
    int j = 0;
    while(i<bits-1)
    {
    push_to_bottom(list_a, &list_b, i, len);
    //push_0s_b(list_a, &list_b, 0, len);
    //print_list(*list_a, list_b);
    int size = ft_lstsize(*list_a);
    push_to_top(list_a, &list_b, i, size);
    //print_list(*list_a, list_b);
    size = ft_lstsize(*list_a);
    push10_to_top(list_a, &list_b, i, size);
    //print_list(*list_a, list_b);
    connect(list_a, &list_b);
    //print_list(*list_a, list_b);
    i++;
    }
    /*
    printf("\nNEXT 2BITS\n");
    push_to_bottom(list_a, &list_b, i, len);
    //push_0s_b(list_a, &list_b, 0, len);
    print_list(*list_a, list_b);
    size = ft_lstsize(*list_a);
    push_to_top(list_a, &list_b, i, size);
    print_list(*list_a, list_b);
    size = ft_lstsize(*list_a);
    push10_to_top(list_a, &list_b, i, size);
    print_list(*list_a, list_b);
    connect(list_a, &list_b);
    print_list(*list_a, list_b);
    i++;
    printf("\nNEXT 2BITS\n");
    push_to_bottom(list_a, &list_b, i, len);
    //push_0s_b(list_a, &list_b, 0, len);
    print_list(*list_a, list_b);
    size = ft_lstsize(*list_a);
    push_to_top(list_a, &list_b, i, size);
    print_list(*list_a, list_b);
    size = ft_lstsize(*list_a);
    push10_to_top(list_a, &list_b, i, size);
    print_list(*list_a, list_b);
    connect(list_a, &list_b);
    print_list(*list_a, list_b);
    i++;
    printf("\nNEXT 2BITS\n");
    push_to_bottom(list_a, &list_b, i, len);
    //push_0s_b(list_a, &list_b, 0, len);
    print_list(*list_a, list_b);
    size = ft_lstsize(*list_a);
    push_to_top(list_a, &list_b, i, size);
    print_list(*list_a, list_b);
    size = ft_lstsize(*list_a);
    push10_to_top(list_a, &list_b, i, size);
    print_list(*list_a, list_b);
    connect(list_a, &list_b);
    print_list(*list_a, list_b);*/
    //count how many bits needed
    //printf("%d",bits);
    //loop for every bit in every numb in a
    //if push 00 to bottom pb rb.
    //if 01 push to top pb
    //push 10s to top b pb
    //connect
    /*
    i = 0;
    int j = 0;
    while (i < bits)
    {
        j = 0;
        while (j < len)
        {
            topnum = list_a->content;
            if (((topnum >> i) & 1) == 0 && ((topnum >> (i + 1)) & 1) == 0)
            // if least sig bit is 0 pb
            {

                //push to bottom!
                printf("pb\n");
                push_b(list_a->content, &list_a, &list_b);
                if (ft_lstsize(list_a) < len)
                {
                    printf("rb\n");
                    rotate_a(&list_b);
                }
            }
            else if (((topnum >> i) & 1) == 1 && ((topnum >> (i + 1)) & 1) == 0)
            {
                printf("pb\n");
                push_b(list_a->content, &list_a, &list_b);
            }
            else
            {
                printf("ra\n");
                rotate_a(&list_a);
            }
            //rotate a until i+1 bit is 1
            j++;
        }
        j = 0;
        int size = ft_lstsize(list_a);
        //push to 1.0s top of b
        while (j < size)
        {
            topnum = list_a->content;
            if (((topnum >> i) & 1) == 0 && ((topnum >> (i + 1)) & 1) == 1)
            {
                printf("pb\n");
                push_b(list_a->content, &list_a, &list_b);
            }
            else
            {
                printf("ra\n");
                rotate_a(&list_a);
            }
            j++;
        }
        //check next bit before pushing
        //push to right pos
        //push back into a
        while (ft_lstsize(list_b) != 0)
        {
            //check if next bit is 1. push it to before first 1s bit
            printf("pa\n");
            push_a(list_b->content, &list_a, &list_b);

        }
        i++;
        i++;
    } */
}