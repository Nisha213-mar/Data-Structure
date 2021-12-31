<h1>Singly Linked List</h1>
<h2>Singly Linked List: It is the simplest type of linked list in which every node contains some data and a pointer to the next node of the same data type. The node contains a pointer to the next node means that the node stores the address of the next node in the sequence.
<h3>1. Tutorial Link</h3>
<h3><a href="https://www.youtube.com/watch?v=nxtDe6Gq4t4
          https://www.youtube.com/watch?v=jgqg6Qw68_Q&t=214s">[TUTORIAL]</a></h3>


<h3>2.See My Codes here in cpp in both method classes and object and structure :-</h3>
<h3><a href="https://github.com/Nisha213-mar/README1.md/blob/main/Linked%20List/Singly%20Linked%20List/singly_linked_list.cpp">CLASSES</a></h3>
<h4><a href="https://github.com/Nisha213-mar/README1.md/blob/main/Linked%20List/Singly%20Linked%20List/practice3.cpp">STRUCTURES</a></h5>
<h3>3. Linked List Implementation in C Language :</h3>
<<<<<<< HEAD
=======

```cpp
          #include <stdio.h>
#include <malloc.h>

struct Node
{
    int val;
    struct Node *next;
};

typedef struct Node N;
N *start = NULL, *tmp, *ptr;

void createList();
void displayList();
void insertBeg();
void insertEnd();
void countNodes();
void insertAt();
void insertBefore();
void searchNode();
void deleteFirst();
void deleteLast();
void deleteAny();
void updateNode();
void reverseList();

void main()
{
    int ch;
    do
    {
        printf("\n...M.E.N.U...\n");
        printf("1...Create List.\n");
        printf("2...Display List.\n");
        printf("3...Insert at beginning.\n");
        printf("4...Insert at the end.\n");
        printf("5...Count nodes.\n");
        printf("6...Insert at specific position.\n");
        printf("7...Insert before a given node.\n");
        printf("8...Search an element.\n");
        printf("9...Delete first element.\n");
        printf("10...Delete last element.\n");
        printf("11...Delete any element.\n");
        printf("12...Update a node.\n");
        printf("13...Reverse the List.\n");
        printf("0...EXIT.\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            printf("\nEnd of Program\n");
            break;
        case 1:
            createList();
            break;
        case 2:
            displayList();
            break;
        case 3:
            insertBeg();
            break;
        case 4:
            insertEnd();
            break;
        case 5:
            countNodes();
            break;
        case 6:
            insertAt();
            break;
        case 7:
            insertBefore();
            break;
        case 8:
            searchNode();
            break;
        case 9:
            deleteFirst();
            break;
        case 10:
            deleteLast();
            break;
        case 11:
            deleteAny();
            break;
        case 12:
            updateNode();
            break;
        case 13:
            reverseList();
            break;
        default:
            printf("\nInvalid Input!!\n");
            break;
        }
    } while (ch != 0);
}

void createList()
{
    ptr = (N *)malloc(sizeof(N));
    printf("\nEnter value:");
    scanf("%d", &ptr->val);
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
        tmp = ptr;
    }
    else
    {
        tmp->next = ptr;
        tmp = ptr;
    }
}

void displayList()
{
    tmp = start;
    while (tmp != NULL)
    {
        printf("%d->", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void insertBeg()
{
    ptr = (N *)malloc(sizeof(N));
    printf("\nEnter value:");
    scanf("%d", &ptr->val);
    ptr->next = start;
    start = ptr;
}

void insertEnd()
{
    ptr = (N *)malloc(sizeof(N));
    printf("\nEnter value:");
    scanf("%d", &ptr->val);
    ptr->next = NULL;
    tmp = start;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = ptr;
}

void countNodes()
{
    int c = 0;
    tmp = start;
    while (tmp != NULL)
    {
        c++;
        tmp = tmp->next;
    }
    printf("\nNumber of Nodes are: %d\n", c);
}

void insertAt()
{
    int n, c = 1;
    tmp = start;
    printf("\nAfter which one to insert:");
    scanf("%d", &n);
    while (c != n)
    {
        tmp = tmp->next;
        c++;
    }
    ptr = (N *)malloc(sizeof(N));
    printf("\nEnter value:");
    scanf("%d", &ptr->val);
    ptr->next = tmp->next;
    tmp->next = ptr;
}

void insertBefore()
{
    int n;
    printf("\nEnter value before which you want to insert:");
    scanf("%d", &n);
    ptr = (N *)malloc(sizeof(N));
    tmp = start;
    while (tmp->next->val != n)
    {
        tmp = tmp->next;
    }
    printf("\nEnter value to insert:");
    scanf("%d", &ptr->val);
    ptr->next = tmp->next;
    tmp->next = ptr;
}

void searchNode()
{
    int n, flag = 0, count = 0;
    printf("\nEnter node for searching:");
    scanf("%d", &n);
    tmp = start;
    while (tmp->next != NULL)
    {
        count++;
        if (tmp->val == n)
        {
            flag = 1;
            break;
        }
        tmp = tmp->next;
    }
    if (flag == 1)
        printf("\nFound at position %d\n", count);
    else
        printf("\nValue doesn't exist\n");
}

void deleteFirst()
{
    tmp = start;
    start = tmp->next;
    free(tmp);
}

void deleteLast()
{
    tmp = start;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
}

void deleteAny()
{
    int n;
    printf("\nEnter value which you want to delete:");
    scanf("%d", &n);
    tmp = start;
    if (tmp->val == n)
        deleteFirst();
    else
    {
        int flag = 0;
        while (tmp->next != NULL)
        {
            if (tmp->next->val == n)
            {
                flag = 1;
                break;
            }
            tmp = tmp->next;
        }
        if (flag == 1)
            tmp->next = tmp->next->next;
        else
            printf("\nValue doesn't exist in the List\n");

}
}

void deleteAnypos()
    {
        int n;
        printf("\nEnter position which you want to delete:");
        scanf("%d", &n);
        tmp = start;
        if (n == 1)
        {
            start = tmp->next;
            free(tmp);
        }
        else
        {
            int c = 1;
            while (c != n-1)
            {
                tmp = tmp->next;
                c++;
            }
            ptr = tmp->next;
            tmp->next = tmp->next->next;
            free (ptr);
        }
    }


void updateNode()
{
    int n, flag = 0;
    printf("\nEnter value which you want to update:");
    scanf("%d", &n);
    tmp = start;
    while (tmp != NULL)
    {
        if (tmp->val == n)
        {
            flag = 1;
            break;
        }
        tmp = tmp->next;
    }
    if (flag == 1)
    {
        int n1;
        printf("\nEnter value to update with:");
        scanf("%d", &n1);
        tmp->val = n1;
    }
    else
        printf("\nInvalid Input\n");
}

void reverseList()
{
    N *new;
    ptr = NULL;
    tmp = start;
    while (tmp != NULL)
    {
        new = tmp->next;
        tmp->next = ptr;
        ptr = tmp;
        tmp = new;
    }
    start = ptr;
}

```
>>>>>>> a0db6dd529c994592bac027cac41888c7a74e006

