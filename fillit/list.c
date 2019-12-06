////
//// Created by Laquanda Voyance on 03/12/2019.
////
//
//#include "fillit.h"
//
//void print_tetri(t_list *head)
//{
//	int i;
//	printf("YA TYT");
//	i = 1;
//	while (head->next != NULL)
//	{
//		printf("\nNode %d = %s", i, head->content);
//		i++;
//		head = head->next;
//	}
//	printf("\nNode %d = %s", i, head->content);
//}
//t_list 	*make_list(const char *buff)
//{
//	char 	cur_char;
//	t_list	*head;
//	t_list	*tetri;
//	t_list	*tmp;
//
//	head = NULL;
//	cur_char = 'A';
//	head = ft_lstnew(get_coords(ft_strsplit(buff, '\n'), cur_char++), 9);
//	//head = tetri;
//	tmp = head;
//	while (tmp->next != NULL)
//		tmp = tmp->next;
//	tetri = ft_lstnew(get_coords(ft_strsplit(buff, '\n'), cur_char++), 9);
//	tmp->next = tetri;
//	return (head);
//}
