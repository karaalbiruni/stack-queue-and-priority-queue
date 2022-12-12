#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mainMenu();

struct Node
{
    char name[255];
    struct Node *next;
} *head = NULL, *curr = NULL;

struct Node *createNode(char name[])
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void pushHead(char name[])
{
    curr = createNode(name);
    
    if (head == NULL)
    {
        head = curr;
    }
    else
    {
        curr->next = head;
        head = curr;
    }

    mainMenu();
}

void popHead()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            curr = head;
            head = head->next;
            free(curr);
            curr = NULL;
        }
    }

    mainMenu();
}

void printMap()
{
    curr = head;
    if (head == NULL)
    {
        printf("Data is empty\n");
        return;
    }

    int a = 1;

    while (curr)
    {
        printf("%d. %s\n", a, curr->name);
        a++;
        curr = curr->next;
    }
}

int main()
{
    mainMenu();
    

    return 0;
}

void mainMenu()
{
    system("cls");

    printMap();
    puts("");

    int choice;
    puts("1. Insert");
    puts("2. Remove");
    puts("3. Exit");

    do
    {
        printf(">> ");
        scanf("%d", &choice); getchar();
    } while (choice < 1 || choice > 4);

    char name[255];

    if (choice == 1)
    {
        printf("Enter name: ");
        scanf("%[^\n]", name); getchar();

        pushHead(name);
    }
    else if (choice == 2)
    {
        popHead();
    }
    else if (choice == 3)
    {
        exit(0);
    }
}