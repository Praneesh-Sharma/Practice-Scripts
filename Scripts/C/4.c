/*WAP program to input n number of elements in an dynamic array . Write a menu to do the following operations in the array.

    a)    Insert an element.
    b)    Delete and element.
    c)    Reverse the elements.
    d)    Search an element.
    e)    Sort all elements.
    f)    Display all the elements.
    g)    Display all composite elements.
    h)    Quit
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int roll;
    struct node *next;
} * NODE;

NODE start = NULL;

NODE create(NODE start)
{
    NODE new_node;
    int x;
    printf("Enter -1 to End\n");
    printf("Enter the roll: ");
    scanf("%d", &x);
    while (x != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->roll = x;
        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = start;
            start = new_node;
        }
        printf("Enter the roll: ");
        scanf("%d", &x);
    }
    return start;
}

void display(NODE start)
{
    NODE ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->roll);
        ptr = ptr->next;
    }
}

void search_SL(NODE start, int val)
{
    NODE ptr;
    ptr = start;
    int flag = 1;
    while (ptr != NULL)
    {
        if (ptr->roll == val)
            flag = 0;
        ptr = ptr->next;
    }
    if (flag == 0)
        printf("Element found\n");
    else
        printf("Element not found\n");
}

NODE insert_end_SL(NODE start, int val)
{
    NODE ptr = start;
    NODE new_node = (struct node *)malloc(sizeof(struct node));
    new_node->roll = val;
    new_node->next = NULL;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}

NODE insert_start_SL(NODE start, int val)
{
    NODE new_node = (struct node *)malloc(sizeof(struct node));
    new_node->roll = val;
    new_node->next = start;
    start = new_node;
    return start;
}

NODE insert_after_SL(NODE start, int val, int item)
{
    NODE new_node = (struct node *)malloc(sizeof(struct node));
    NODE ptr = start;
    NODE preptr = start;
    new_node->roll = val;
    while (preptr->roll != item)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

NODE insert_before_SL(NODE start, int val, int item)
{
    NODE new_node = (struct node *)malloc(sizeof(struct node));
    NODE ptr = start;
    NODE preptr = start;
    new_node->roll = val;
    while (ptr->roll != item)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

NODE delete_end_SL(NODE start)
{
    NODE ptr = start;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    ptr->next=NULL;
    return start;
}

NODE delete_start_SL(NODE start)
{
    NODE ptr=start->next;
    start=ptr;
    return start;
}

NODE delete_after_SL(NODE start, int item)
{
    NODE ptr = start;
    NODE preptr = start;
    while (preptr->roll != item)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next=ptr->next;
    return start;
}

NODE delete_before_SL(NODE start, int item)
{
    NODE ptr = start;
    NODE preptr = start;
    while (ptr->next->roll != item)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next=ptr->next;
    return start;
}

NODE delete_SL(NODE start, int item)
{
    NODE ptr = start;
    NODE preptr = start;
    while (ptr->roll != item)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next=ptr->next;
    return start;
}


int main()
{
    int user_choice;
    printf("Enter your choice for performing the following operations on a linked list: \n");
    printf("1 to Create: \n");
    printf("2 to Display: \n");
    printf("3 to Insert: \n");
    printf("4 to Delete: \n");
    printf("5 to Search: \n");
    printf("6 to Exit: \n");
    scanf("%d", &user_choice);

    NODE LL;
    while (user_choice != 6)
    {
        if (user_choice == 1)
        {
            LL = create(start);
        }
        if (user_choice == 2)
        {
            display(LL);
            printf("\n");
        }
        if (user_choice == 3)
        {
            int pos;
            printf("Where do you want to insert? \n");
            printf("1: At the beginnning\n");
            printf("2: At the end\n");
            printf("3: After a particular node\n");
            printf("4: Before a particular node\n");
            scanf("%d", &pos);

            if (pos == 1)
            {
                int val;
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                LL = insert_start_SL(LL, val);
            }
            if (pos == 2)
            {
                int val;
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                LL = insert_end_SL(LL, val);
            }
            if (pos == 3)
            {
                int val;
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                int item;
                printf("Enter the item after which the value will be inserted: ");
                scanf("%d", &item);
                LL = insert_after_SL(LL, val, item);
            }
            if (pos == 4)
            {
                int val;
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                int item;
                printf("Enter the item before which the value will be inserted: ");
                scanf("%d", &item);
                LL = insert_before_SL(LL, val, item);
            }
        }
        if (user_choice == 4)
        {
            int pos;
            printf("Which value do you want to delete? \n");
            printf("1: At the beginnning\n");
            printf("2: At the end\n");
            printf("3: After a particular node\n");
            printf("4: Before a particular node\n");
            printf("5: At the particular node\n");
            scanf("%d", &pos);

            if (pos == 1)
            {
                LL = delete_start_SL(LL);
            }
            if (pos == 2)
            {
                LL = delete_end_SL(LL);
            }
            if (pos == 3)
            {
                int item;
                printf("Enter the item after which the value is present which will be deleted: ");
                scanf("%d", &item);
                LL = delete_after_SL(LL, item);
            }
            if (pos == 4)
            {
                int item;
                printf("Enter the item before which the value is present which will be deleted: ");
                scanf("%d", &item);
                LL = delete_before_SL(LL, item);
            }
            if (pos == 5)
            {
                int item;
                printf("Enter the item which will be deleted: ");
                scanf("%d", &item);
                LL = delete_SL(LL, item);
            }
        }
        if (user_choice == 5)
        {
            int val;
            printf("Enter the value to be searched: ");
            scanf("%d", &val);
            search_SL(LL, val);
        }

        printf("Enter your choice again: ");
        scanf("%d", &user_choice);
    }
}