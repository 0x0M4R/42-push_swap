#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void push_b(int num,t_list **list_a, t_list **list_b);
void push_a(int num,t_list **list_a, t_list **list_b);
void rotate(t_list **list_a);
void rev_rotate(t_list **list_a);
void print_list(t_list *lista,t_list *listb);
void print_binary(unsigned int number);
int *make_sorted_list(t_list *list_a, int len);
void convert_2_range(t_list *list_a, int len);
void parse_input(char **av, t_list **list_a,int len);
void	ft_swap(int *a, int *b);
void	ft_sort_int_tab(int *tab, int size);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void sort_least_sig_dig(t_list **list_a,int len);
int check_list_bit(t_list *list, int pos_bit);
void sort_least_sig_dig_2bit(t_list **list_a, int len);
void sort_chunks(t_list **list_a, int len);