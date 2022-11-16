# O INICIO DE TUDO "HELLO WORLD"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
    void            *content;
    struct s_list    *next;
}                    t_list;

t_list    *ft_lstnew(void *content)
{
    t_list    *lstnew;

    lstnew = malloc(sizeof(t_list));
    if (!lstnew)
        return (NULL);
    lstnew->content = content;
    lstnew->next = NULL;
    return (lstnew);
}

void    *ft_map(void *elem)
{
    int        len;
    char        *content;

    len = 0;
    content = (char *)elem;
    while (content[len])
    {
      if (content[len] >= 65 && content[len] <= 90)
        content[len] = content[len] + 32;
      else
        content[len] = content[len] - 32;
      len++;
    }
}

void    ft_del(void *content)
{
    free(content);
    printf("\n:::>free<:::\n");
}

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst || !del)
        return ;
    del(lst->content);
    free (lst);
}

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list    *ptr_aux;

    if (!lst || !del)
        return ;
    while (*lst)
    {
        ptr_aux = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = ptr_aux;
    }
}

int    ft_lstsize(t_list *lst)
{
    int    len;

    len = 0;
    while (lst != 0)
    {
        lst = lst->next;
        len ++;
    }
    return (len);
}

t_list    *ft_lstlast(t_list *lst)
{
    int    len;

    len = ft_lstsize(lst);
    while (len -1 > 0)
    {
    lst = lst->next;
    len--;
    }
    return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list    *ptr_aux;

    if (!*lst)
    {
        *lst = new;
        return ;
    }
    ptr_aux = ft_lstlast(*lst);
    ptr_aux->next = new;
}

t_list    *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list    *lstnew;
    t_list    *ptr_aux;

    lstnew = NULL;
    while (lst)
    {
        ptr_aux = ft_lstnew((f)(lst->content));
        if (!lst)
            ft_lstclear(&ptr_aux, del);
        ft_lstadd_back(&lstnew, ptr_aux);
        lst = lst->next;
    }
    return (lstnew);
}

int main(void)
{
    t_list        *elem;
    t_list        *elem2;
    t_list        *list;
    char        *str = strdup("lorem");
    char        *str2 = strdup("ipsum");

    elem = ft_lstnew(str);
    elem2 = ft_lstnew(str2);
    
    elem->next = elem2;

    list = ft_lstmap(elem, &ft_map, &ft_del);
    return (0);
}
