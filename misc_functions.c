#include "push_swap.h"
int find_first_bit(t_list *list,int bit)
{
    while(list)
    {
        int topnum=list->content;
        if(((topnum>>bit)&1) == 1)
        return(topnum);
        list=list->next;
    }
}
void print_list(t_list *lista,t_list *listb)
{
    printf("LIST A:");
    while(lista)
    {
        //print_binary(lista->content);
        printf("%d ",lista->content);
        lista=lista->next;
    }
    printf("\nLIST B:");
    while(listb)
    {
        //print_binary(listb->content);
        printf("%d ",listb->content);
        listb=listb->next;
    }
    printf("\n");
}
void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}
