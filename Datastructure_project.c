#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#define maxsize 100

int main();
void enterarray();
void array();
void displayarray();
void showarray();
void insertend();
void insertpos();
void delete_end();
void delete_pos();
void max();
void min();
void search();
int binarysearch();
void sort();
void bubblesort();
void insertionsort();
void selectionsort();
void quickSort();
void mergeSort();

void linkedlist();
void singlell();
void addnewnode();
void displaySLL();
void SLLoperations();
void addatbegSLL();
void addatendSLL();
void addatposSLL();
void deleteatbegSLL();
void deleteatendSLL();
void deleteatposSLL();
void maxSLL();
void minSLL();
void reverseSLL();
void showSLL();

void doublell();
void addnewnodeDLL();
void DLLopertions();
void displayDLL();
void addatbegDLL();
void addatendDLL();
void addatposDLL();
void deleteatbegDLL();
void deleteatendDLL();
void deleteatposDLL();
void reverseDLL();
void minDLL();
void maxDLL();

void acceptCLL();
void circularLinkedList();
void displayCLL();
void insertElementEndCLL();
void insertElementStartCLL();
void insertElementAnyPosCLL();
void deleteElementEndCLL();
void deleteElementStartCLL();
void deleteElementAnyPosCLL();


void stack();
void stackusingarr();
void stackusingll();
void push();
int pop();
void displaystack();

#define maxque 10
int main();
void Queusingarr();
void Enque();
void Deque();
void Peek();
void Displayque();
void addnewnodeque();

void enquell();
void dequell();
void peakque();
void displayquell();

int arr[maxque];
int front = -1;
int rear = -1;
void Enque()
{
    if (rear == maxque - 1)
    {
        printf("Overflowed...\n");
        sleep(3);
        Queusingarr();
        return;
    }
    else
    {
        if (front == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        printf("Enter the element:");
        scanf("%d", &arr[rear]);
        printf("Enque done...\n");
        sleep(1);
        Queusingarr();
        return;
    }
}

void Deque()
{
    if (front == -1)
    {
        printf("Underflowed...\n");
        sleep(2);
        Queusingarr();
        return;
    }
    else
    {
        front++;
        printf("%d is deleted\n", arr[front - 1]);
        if (front == rear + 1)
        {
            front = -1;
            rear = -1;
        }

        sleep(1);
        Queusingarr();
        return;
    }
}

void Peak()
{
    printf("Peak element is %d\n", arr[front]);
    sleep(3);
    Queusingarr();
    return;
}

void Displayque()
{
    if (front == -1)
    {
        printf("Underflowed...\n");
        Queusingarr();
        return;
    }
    else
    {
        int i;
        printf("The elements of the que are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    sleep(2);
    Queusingarr();
    return;
}

void Queusingarr()
{
    system("cls");
    printf("Que uisng array\n");
    printf("1.Enque\n");
    printf("2.Deque\n");
    printf("3.Peak\n");
    printf("4.Display the Que\n");
    printf("5.exit\n");
    printf("Enter your choice\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        Enque();
        break;
    }
    case 2:
    {
        Deque();
        break;
    }
    case 3:
    {
        Peak();
        break;
    }
    case 4:
    {
        Displayque();
        break;
    }
    case 5:
    {
        printf("Thank you...\n");
        sleep(2);
        main();
        break;
    }
    default:
    {
        printf("Please enter a right choice\n");
        sleep(2);
        Queusingarr();
        break;
    }
    }

    return;
}

struct nodeque
{
    int data;
    struct nodeque *link;
};

struct nodeque *frontque = NULL;
struct nodeque *rearque = NULL;
void Queusingll()
{
    system("cls");
    printf("Que uisng linked list\n");
    printf("1.Enque\n");
    printf("2.Deque\n");
    printf("3.Peak\n");
    printf("4.Display the Que\n");
    printf("5.Exit\n");
    printf("Enter your choice:");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        enquell();
        break;
    }
    case 2:
    {
        dequell();
        break;
    }
    case 3:
    {
        peakque();
        break;
    }
    case 4:
    {
        displayquell();
        break;
    }
    case 5:
    {
        main();
        break;
    }
    default:
    {
        printf("Please enter right choice...\n");
        sleep(2);
        Queusingll();
        break;
    }
    }
    return;
}

void enquell()
{
    struct nodeque *temp = (struct nodeque *)malloc(sizeof(struct nodeque));
    printf("Enter the element:");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (frontque == NULL)
    {
        frontque = temp;
        rearque = temp;
    }
    else
    {
        rearque->link = temp;
        rearque = temp;
    }
    printf("Enque done...\n");
    sleep(1);
    Queusingll();
    return;
}

void dequell()
{
    if (frontque == NULL)
    {
        printf("Underflowed...\n");
        sleep(2);
        Queusingll();
        return;
    }
    else
    {
        struct nodeque *ptr = frontque;
        if (frontque == rearque)
        {
            free(ptr);
            frontque = NULL;
            rearque = NULL;
            printf("Deque done.\n");
            sleep(1);
            Queusingll();
            return;
        }
        else
        {
            frontque = frontque->link;
            free(ptr);
            printf("Deque done.\n");
            sleep(1);
            Queusingll();
            return;
        }
    }
}

void peakque()
{
    printf("The peak element is %d\n", frontque->data);
    sleep(2);
    Queusingll();
    return;
}

void displayquell()
{
    printf("The elements of the que are:\n");
    struct nodeque *ptr = frontque;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    sleep(2);
    Queusingll();
    return;
}

void que()
{
    system("cls");
    printf("\t\t...Welcome to Que operations...\n\n");
    printf("1.Using Array\n");
    printf("2.Using Linked list\n");
    printf("3.Exit\n");
    printf("Enter your choice:");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        Queusingarr();
        break;
    }
    case 2:
    {
        Queusingll();
        break;
    }
    case 3:
    {
        printf("Thank You...\n");
        main();
        break;
    }
    default:
    {
        printf("Please enter a right choice:\n");
        sleep(2);
        que();
        break;
    }
    }
    return;
}

int i, j;
void enterarray()
{
    system("cls");
    int x;
    printf("Enter the size of the array:");
    scanf("%d", &x);
    int a[maxsize];
    printf("Enter the elements of the array\n");
    for (i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }
    array(a, x);
    return;
}

int topa=-1;
void stackArr();
void acceptStack();
void stackList();

struct nodeSTK {
    int info;
    struct nodeSTK *ptr;
};
struct nodeSTK* top;
int count = 0;
// Push() operation on a  stack
void pushStackList() {
    printf("Enter value to push:");
    int data;
    scanf("%d",&data);
    if (top == NULL)
    {
        top =(struct nodeSTK *)malloc(sizeof(struct nodeSTK));
        if(top==NULL)
        {
            printf("Stack Overflow");
            getch();
            return ;
        }
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        struct nodeSTK* temp =(struct nodeSTK *)malloc(sizeof(struct nodeSTK));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    printf("Node is Inserted\n\n");
    getch();
}
int popStackList() {
     struct nodeSTK* top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->ptr;
    int popped = top->info;
    free(top);
    top = top1;
    count--;
    return popped;
}
void showStackList() {
    // Display the elements of the stack
    struct nodeSTK* top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nNo element in stack\n");
        getch();
        return;
    }
    
    printf("The stack is:");
    while (top1 != NULL)
    {
        printf("%d  ", top1->info);
        top1 = top1->ptr;
    }
    getch();
}

void pushStackArr(int stack[],int n)
{
    if (topa == n )   
    {
        printf("\n Overflow");   
        return ;
    }
    else   
    {  
        int data;
        printf("Enter value to push:");
        scanf("%d",&data);
        printf("\n");
        topa = topa +1;   
        stack[topa] = data;   
    }
} 
int popStackArr (int stack[])  
{   
    if(topa == -1)   
    {  
        printf("Underflow");  
        return 0;  
    }  
    else   
    return stack[topa--];    
}   
void showStackArr(int stack[])  
{  
    printf("Elements in stack are:");
    int i;
    for (i=topa;i>=0;i--)  
    {  
        printf("%d  ",stack[i]);  
    }  
    printf("\n");
    if(topa == -1)   
    {  
        printf("Stack is empty\n");  
    }  
    getch();
}  

void acceptStack()
{
    sleep(1);
    system("cls");
    sleep(1);
    printf("Stack\n\n");
    printf("1.Array implementation\n");
    printf("2.Linked list implementation\n");
    printf("3.Go back to Data Structure selection screen\n");
    start:
    printf("Enter your choice:");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            stackArr();
            break;
        }
        case 2:
        {
            stackList();
            break;
        }
        case 3:
        {
            main();
            break;
        }
        default:
        {
            printf("invalid input\n");
            goto start;
        }
    }
    return ;
}
void stackArr()
{
    sleep(1);
    system("cls");
    sleep(1);
    printf("STACK IMPLEMENTATION USING ARRAY\n");
    printf("Enter size of stack:");
    int n;
    scanf("%d",&n);
    int stack[n];
    int choice;
    while(choice != 4)  
    {  
        system("cls");
        printf("Chose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\nEnter your choice: ");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                pushStackArr(stack,n);  
                break;  
            }  
            case 2:  
            {  
                printf("popped element =%d",popStackArr(stack));  
                getch();
                break;  
            }  
            case 3:  
            {  
                showStackArr(stack);  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                acceptStack();
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        };  
    }  
    return;
}
void stackList()
{
    sleep(1);
    system("cls");
    sleep(1);
    int choice;
    while(choice != 4)  
    {  
        system("cls");
        printf("STACK IMPLEMENTATION USING LINKED LIST\n");
        printf("Chose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\nEnter your choice: ");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                pushStackList();  
                break;  
            }  
            case 2:  
            {  
                printf("popped element =%d",popStackList());  
                getch();
                break;  
            }  
            case 3:  
            {  
                showStackList();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                acceptStack();
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        };  
    }  
    return;
}


/*
#define stacksize 10
int arr[stacksize];
int top = -1;
void stack()
{
    system("cls");
    int choice1;
    printf("Stack operations...\n");
    printf("1.Using Array\n2.Using Linked list\n3.Exit\nEnter your choice\n");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
    {
        stackusingarr();
        break;
    }
    case 2:
    {
        // stackusingll();
        break;
    }
    case 3:
    {
        main();
        break;
    }
    default:
    {
        printf("Error! Please Enter right choice\n");
        stack();
        break;
    }
    }
}
void stackusingarr()
{
    int choice;
    printf("1.Push\n2.Pop\n3.Display elements\n");
    printf("4.IsEmpty\n5.Isfull\n6.Top\n7.Exit\nEnter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        int data;
        printf("Enter data to insert ");
        scanf("%d", &data);
        push(data);
        break;
    }
    case 2:
    {
        pop();
        int value = pop();
        printf("%d is deleted from top of the stack\n", value);
        sleep(2);
        stackusingarr();
        break;
    }
    case 3:
    {
        displaystack();
        break;
    }
    case 4:
    {
        if (top == -1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        sleep(2);
        stackusingarr();
        break;
    }
    case 5:
    {
        if (top == stacksize - 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        sleep(2);
        stackusingarr();
        break;
    }
    case 6:
    {
        printf("'%d'is at the top\n", arr[top]);
        sleep(2);
        stackusingarr();
        break;
    }
    default:
    {
        stack();
        break;
    }
    }
}
void push(int data)
{
    if (top == stacksize - 1)
    {
        printf("Stack overflowed\n");
        stack();
        return;
    }
    else
    {
        top++;
        arr[top] = data;
        stack();
        return;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("Stack underflowed");
        exit(1);
    }
    else
    {
        top--;
        return arr[top + 1];
    }
}

void displaystack()
{
    printf("Elements are:\n");
    for (i = 0; i < top + 1; i++)
    {
        printf("%d ", arr[i]);
    }
    sleep(3);
    stack();
    return;
}
*/

struct node
{
    int data;
    struct node *link;
};

void linkedlist()
{
    system("cls");
    printf("Linked list operations...\n");
    printf("1.Singly linked list\n");
    printf("2.Doubly linked list\n");
    printf("3.Circular linked list\n");
    printf("4.Exit\n");
    printf("Enter your choice");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        singlell();
        break;
    }
    case 2:
    {
        doublell();
        break;
    }
    case 3:
    	{
    		acceptCLL();
    		break;
		}
    case 4:
    {
        printf("Thank you...\n");
        main();
        break;
    }
    default:
    {
        system("cls");
        printf("Please enter right choice \n");
        linkedlist();
        break;
    }
    }
}
void singlell()
{
    printf("Singly Linked List\n\n");
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("Enter 1st number:");
    scanf("%d", &(head->data));
    printf("Enter 1 to add new number else 0\n");
    int choice;
    scanf("%d", &choice);
    addnewnode(head, choice);
    SLLoperations(head);
    return;
}

void addnewnode(struct node *ptr, int choice)
{
    if (choice == 0)
    {
        ptr->link = NULL;
        return;
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter number:");
        scanf("%d", &(temp->data));
        ptr->link = temp;
        ptr = ptr->link;

        printf("Enter 1 to add new number else 0\n");
        int choice;
        scanf("%d", &choice);
        addnewnode(ptr, choice);
        return;
    }
}

void SLLoperations(struct node *head)
{
    system("cls");
    printf("1.Display the List\n");
    printf("2.Add a node at beginning\n");
    printf("3.Add a node at end\n");
    printf("4.Add a node at any position\n");
    printf("5.Delete a node from beginning\n");
    printf("6.Delete a node from end\n");
    printf("7.Delete a node from any position\n");
    printf("8.Reverse the node\n");
    printf("9.Maximum element in the list\n");
    printf("10.Minimum element in the list\n");
    printf("11.Exit\n");
    printf("Enter your choice:\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        displaySLL(head);
        break;
    }
    case 2:
    {
        addatbegSLL(head);
        break;
    }
    case 3:
    {
        addatendSLL(head);
        break;
    }
    case 4:
    {
        addatposSLL(head);
        break;
    }
    case 5:
    {
        deleteatbegSLL(head);
        break;
    }
    case 6:
    {
        deleteatendSLL(head);
        break;
    }
    case 7:
    {
        deleteatposSLL(head);
        break;
    }
    case 8:
    {
        reverseSLL(head);
        break;
    }
    case 9:
    {
        maxSLL(head);
        break;
    }
    case 10:
    {
        minSLL(head);
        break;
    }
    case 11:
    {
        linkedlist();
        break;
    }
    default:
    {
        printf("Please enter a right choice...\n");
        SLLoperations(head);
        break;
    }
    }
}

void displaySLL(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        SLLoperations(head);
    }
    else
    {
        struct node *ptr = head;
        printf("The linked list contains:");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        sleep(3);
        SLLoperations(head);
    }
    return;
}

void showSLL(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        SLLoperations(head);
    }
    else
    {
        struct node *ptr = head;
        printf("The linked list contains:");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
    return;
}

void addatbegSLL(struct node *ptr)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter any number to add at beginning\n");
    scanf("%d", &temp->data);
    temp->link = ptr;
    ptr = temp;
    printf("Insertion at beginning is done...\n");
    sleep(2);
    SLLoperations(ptr);
    return;
}
void addatendSLL(struct node *head)
{
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter any number to add at end\n");
    scanf("%d", &temp->data);

    ptr->link = temp;
    temp->link = NULL;
    printf("Insertion at end of linkedlist is done...\n");
    sleep(2);
    SLLoperations(head);
    return;
}
void addatposSLL(struct node *head)
{
    showSLL(head);
    struct node *ptr = head;
    printf("\nEnter position which you want to insert a new node\n");
    int num;
    scanf("%d", &num);
    int i = 1;
    while (i < (num - 1))
    {
        ptr = ptr->link;
        i++;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number to insert at pos %d:", num);
    scanf("%d", &temp->data);
    temp->link = ptr->link;
    ptr->link = temp;

    printf("Insertion is done...\n");
    sleep(2);
    SLLoperations(head);
    return;
}

void deleteatbegSLL(struct node *head)
{
    struct node *ptr = head;
    head = ptr->link;
    free(ptr);
    printf("Deletion of node at beginning is done...\n");
    sleep(2);
    SLLoperations(head);
    return;
}

void deleteatendSLL(struct node *head)
{
    struct node *ptr = head;
    while (ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
    printf("Deletion of node at end is done...\n");
    sleep(2);
    SLLoperations(head);
    return;
}

void deleteatposSLL(struct node *head)
{
    struct node *ptr = head;
    showSLL(head);
    int num;
    printf("\nEnter node number which you want to delete(cannot be used to delete node at beginning and end):");
    scanf("%d", &num);
    int i = 1;
    while (i < (num - 1))
    {
        ptr = ptr->link;
    }
    struct node *temp = ptr->link;
    ptr->link = ptr->link->link;
    free(temp);

    printf("Node at %d position is deleted\n", num);
    sleep(2);
    SLLoperations(head);
    return;
}

void maxSLL(struct node *head)
{
    struct node *ptr = head;
    int max = ptr->data;
    while (ptr->link != NULL)
    {
        if ((ptr->data) > max)
        {
            max = ptr->data;
        }
        ptr = ptr->link;
    }
    printf("Max is %d\n", max);
    sleep(3);
    SLLoperations(head);
    return;
}

void minSLL(struct node *head)
{
    struct node *ptr = head;
    int min = ptr->data;
    while (ptr->link != NULL)
    {
        if ((ptr->data) < min)
        {
            min = ptr->data;
        }
        ptr = ptr->link;
    }
    printf("min is %d\n", min);
    sleep(3);
    SLLoperations(head);
    return;
}

void reverseSLL(struct node *head)
{
    struct node *temp1 = NULL;
    struct node *temp2 = NULL;

    while (head != NULL)
    {
        temp2 = head->link;
        head->link = temp1;
        temp1 = head;
        head = temp2;
    }
    head = temp1;
    printf("Linked list is reversed...\n");
    sleep(2);
    SLLoperations(head);
    return;
}

struct nodedll
{
    struct nodedll *prev;
    int data;
    struct nodedll *next;
};

void DLLoperations(struct nodedll *head)
{
    system("cls");
    printf("1.Display the List\n");
    printf("2.Add a node at beginning\n");
    printf("3.Add a node at end\n");
    printf("4.Add a node at any position\n");
    printf("5.Delete a node from beginning\n");
    printf("6.Delete a node from end\n");
    printf("7.Delete a node from any position\n");
    printf("8.Reverse the node\n");
    printf("9.Maximum element in the list\n");
    printf("10.Minimum element in the list\n");
    printf("11.Exit\n");
    printf("Enter your choice:\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        displayDLL(head);
        break;
    }
    case 2:
    {
        addatbegDLL(head);
        break;
    }
    case 3:
    {
        addatendDLL(head);
        break;
    }
    case 4:
    {
        addatposDLL(head);
        break;
    }
    case 5:
    {
        deleteatbegDLL(head);
        break;
    }
    case 6:
    {
        deleteatendDLL(head);
        break;
    }
    case 7:
    {
        deleteatposDLL(head);
        break;
    }
            case 8:
            {
                reverseDLL(head);
                break;
            }
            case 9:
            {
                maxDLL(head);
                break;
            }
            case 10:
            {
                minDLL(head);
                break;
            }
        
    case 11:
    {
        linkedlist();
        break;
    }
    default:
    {
        printf("Please enter a right choice...\n");
        DLLoperations(head);
        break;
    }
    }
}

void showDLL(struct nodedll *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {
        struct nodedll *ptr = head;
        printf("The linked list contains:");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return;
}

void displayDLL(struct nodedll *head)
{
	if (head==NULL){
		printf("Linked list is empty\n");
	}
	else{
    struct nodedll *ptr = head;
    printf("The elements of the double linked list are:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
    sleep(2);
    DLLoperations(head);
    return;
}

void doublell()
{
    system("cls");
    printf("Double Linked List\n");
    struct nodedll *head = (struct nodedll *)malloc(sizeof(struct nodedll));
    printf("Enter 1st number:");
    scanf("%d", &(head->data));
    head->prev = NULL;
    printf("Enter 1 to add new number else enter 0\n");
    int choice;
    scanf("%d", &choice);
    addnewnodeDLL(head, choice);
    DLLoperations(head);
    return;
}

void addnewnodeDLL(struct nodedll *ptr, int choice)
{
    if (choice == 0)
    {
        ptr->next = NULL;
        return;
    }
    else
    {
        struct nodedll *temp = (struct nodedll *)malloc(sizeof(struct nodedll));
        printf("Enter the number:");
        scanf("%d", &temp->data);
        temp->prev = ptr;
        ptr->next = temp;
        ptr = ptr->next;
        printf("Enter 1 to add new number else enter 0\n");
        int choice;
        scanf("%d", &choice);
        addnewnodeDLL(ptr, choice);
        return;
    }
}

void addatbegDLL(struct nodedll *ptr)
{
    struct nodedll *temp = (struct nodedll *)malloc(sizeof(struct nodedll));
    printf("Enter the element to insert at beginning:");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = ptr;
    ptr = temp;
    printf("Done...\n");
    sleep(1);
    DLLoperations(ptr);
    return;
}

void addatendDLL(struct nodedll *head)
{
    struct nodedll *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    struct nodedll *temp = (struct nodedll *)malloc(sizeof(struct nodedll));
    printf("Enter the elements to insert at end:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = ptr;
    ptr->next = temp;
    printf("Done...\n");
    sleep(2);
    DLLoperations(head);
    return;
}

void addatposDLL(struct nodedll *head)
{
	showDLL(head);
    struct nodedll *ptr = head;
    printf("Enter the position at which you want to add a new node: ");
    int pos;
    scanf("%d", &pos);
    int i = 1;
    while (i < pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct nodedll *temp = (struct nodedll *)malloc(sizeof(struct nodedll));
    printf("Enter the element: ");
    scanf("%d", &temp->data);
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next = temp;
    printf("done...\n");
    sleep(2);
    DLLoperations(head);
    return;
}

void deleteatbegDLL(struct nodedll *head)
{
    struct nodedll *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    printf("Done...\n");
    sleep(2);
    DLLoperations(head);
    return;
}

void deleteatendDLL(struct nodedll *head)
{
    struct nodedll *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    struct nodedll *temp = ptr->next;
    ptr->next = NULL;
    free(temp);
    printf("Done...\n");
    sleep(2);
    DLLoperations(head);
    return;
}

void deleteatposDLL(struct nodedll *head)
{
    struct nodedll *ptr = head;
    printf("Enter the position from which you want to delete the element:");
    int pos;
    scanf("%d", &pos);
    int i;
    while (i < pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct nodedll *temp = ptr->next;
    ptr->next = ptr->next->next;
    ptr->next->next->prev = ptr;
    free(temp);
    printf("Done...\n");
    sleep(2);
    DLLoperations(head);
    return;
}

void reverseDLL(struct nodedll*head){
	struct nodedll*ptr1=head;
	struct nodedll*ptr2=head->next;
	
	ptr1->next=NULL;
	ptr1->prev=ptr2;
	
	while(ptr2!=NULL){
		ptr2->prev=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr2->prev;
	}
	head=ptr1;
	printf("Done...\n");
	sleep(2);
	DLLoperations(head);
	return;
}

void maxDLL(struct nodedll*head){
	struct nodedll*ptr=head;
	int max=ptr->data;
	while(ptr!=NULL){
		if(ptr->data>max){
			max=ptr->data;
		 }
			ptr=ptr->next;
	}
	printf("max element is %d\n",max);
	sleep(2);
	DLLoperations(head);
	return;
}

void minDLL(struct nodedll*head){
	struct nodedll*ptr=head;
	int min=ptr->data;
	while(ptr!=NULL){
		if((ptr->data)<min){
			min=ptr->data;
		 }
			ptr=ptr->next;
	}
	printf("min element is %d\n",min);
	sleep(2);
	DLLoperations(head);
	return;
}


struct nodeCLL{
    int data;
    struct nodeCLL *link;
};
void circularLinkedList(struct nodeCLL *tail)
{
    sleep(1);
    system("cls");
    sleep(1);
    printf("\nOPERATIONS ON CLL:\n");
    printf("1.View Linked List elements \n");
    printf("2.Insert an element at end of list\n");
    printf("3.Insert an element at beginning of list \n");
    printf("4.Insert an element at any position in the list\n");
    printf("5.Delete first node in linked list\n");
    printf("6.Delete last node in linked list\n");
    printf("7.Delete nth node in linked list\n");
    printf("8.Go back to Data Structures selection screen\n");
    start:
    printf("Enter what operation(index) you want to perform?:");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            displayCLL(tail);
            break;
        }
        case 2:
        {
            insertElementEndCLL(tail);
            break;
        }
        case 3:
        {
            insertElementStartCLL(tail);
            break;
        }
        case 4:
        {
            insertElementAnyPosCLL(tail);
            break;
        }
        case 5:
        {
            deleteElementStartCLL(tail);
            break;
        }
        case 6:
        {
            deleteElementEndCLL(tail);
            break;
        }
        case 7:
        {
            deleteElementAnyPosCLL(tail);
            break;
        } 
        case 8:
        {
            main();
            break;
        }
        default:
        {
            printf("invalid input\n");
            goto start;
        }
    }
    return ;
}
struct nodeCLL* addNewNodeCLL(struct nodeCLL *ptr,struct nodeCLL *head,char ch)
{  
    if(ch=='n')
    {
        ptr->link=head;
        return ptr;
    }
    else
    {
        struct nodeCLL *temp=(struct nodeCLL*)malloc(sizeof(struct nodeCLL));
        printf("\nEnter number:");
        scanf("%d",&(temp->data));
        ptr->link=temp;
        ptr=ptr->link;

        printf("Enter \"y\" to enter one more number or \"n\" to stop:");
        char  ch;
        scanf(" %c",&ch);
        addNewNodeCLL(ptr,head,ch);
    }
}
void acceptCLL()
{
    sleep(1);
    system("cls");
    sleep(1);
    printf("CIRCULAR LINKED LIST\n\n");
    struct nodeCLL *head=(struct nodeCLL*)malloc(sizeof(struct nodeCLL));
    printf("Enter number in 1st node:");
    scanf("%d",&(head->data));
    printf("Enter \"y\" to enter one more number or \"n\" to stop:");
    char ch;
    scanf(" %c",&ch);
    struct nodeCLL* tail=addNewNodeCLL(head,head,ch);
    circularLinkedList(tail);
    return;
}
void displayCLL(struct nodeCLL*tail)
{
    sleep(1);
    system("cls");
    sleep(1);
    if(tail==NULL)
    printf("Linked List is empty");
    else
    {
        printf("Elements in list are:\n");
        struct nodeCLL *ptr=tail->link;
        do
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        while(ptr!=tail->link);
        getch();
        circularLinkedList(tail);
        return;
    }
}
void insertElementEndCLL(struct nodeCLL *tail)
{
    sleep(1);
    system("cls");
    sleep(1);
    struct nodeCLL *ptr=tail->link;
    while(ptr!=tail)
    ptr=ptr->link;
    struct nodeCLL *temp=(struct nodeCLL*)malloc(sizeof(struct nodeCLL));
    printf("Enter number to join at end:");
    scanf("%d",&(temp->data));
    temp->link=tail->link;
    ptr->link=temp;
    tail=tail->link;
    printf("Data inserted at end of list");
    getch();
    circularLinkedList(tail);
    return;
}
void insertElementStartCLL(struct nodeCLL *tail)
{
    sleep(1);
    system("cls");
    sleep(1);
    struct nodeCLL *temp=(struct nodeCLL*)malloc(sizeof(struct nodeCLL));
    printf("Enter number to join at start:");
    scanf("%d",&(temp->data));
    temp->link=tail->link;
    tail->link=temp;
    printf("Data inserted at first place in list");
    getch();
    circularLinkedList(tail);
    return;
}
void insertElementAnyPosCLL(struct nodeCLL *tail)
{
    sleep(1);
    system("cls");
    sleep(1);
    struct nodeCLL *ptr=tail->link;
    printf("Enter which node you want to keep data in(start counting from 1) \nyou cant insert in node 1 using this function:");
    int n;
    scanf("%d",&n);
    int i=1;
    while(i<n-1)
    {
    ptr=ptr->link;
    i++;
    }
    struct nodeCLL *temp=(struct nodeCLL*)malloc(sizeof(struct nodeCLL));
    printf("Enter number to insert at node number %d(starting from 1):",n);
    scanf("%d",&(temp->data));
    temp->link=ptr->link;
    ptr->link=temp; 
    printf("inserted");
    circularLinkedList(tail);
    return;
}  
void deleteElementEndCLL(struct nodeCLL* tail) {
    sleep(1);
    system("cls");
    sleep(1);
    
    if (tail == NULL) {
        printf("Linked List is empty\n");
        getch();
        circularLinkedList(tail);
        return;
    }
    
    if ((tail)->link == tail) {
        free(tail);
        tail = NULL;
    } else {
        struct nodeCLL* ptr = (tail)->link;
        struct nodeCLL* prev = tail;
        
        while (ptr!= tail) {
            prev = ptr;
            ptr = ptr->link;
        }
        
        prev->link = (tail)->link;
        free(ptr);
        tail=prev;
    }
    
    printf("Data deleted from the end of the list\n");
    getch();
    circularLinkedList(tail);
}
void deleteElementStartCLL(struct nodeCLL* tail) {
    sleep(1);
    system("cls");
    sleep(1);
    
    if (tail == NULL) {
        printf("Linked List is empty\n");
        getch();
        circularLinkedList(tail);
        return;
    }
    
    struct nodeCLL* ptr = tail->link;
    
    if (ptr == tail) {
        free(ptr);
        tail = NULL;
    } else {
        tail->link = ptr->link;
        free(ptr);
    }
    
    printf("Data deleted from the beginning of the list\n");
    getch();
    circularLinkedList(tail);
}
void deleteElementAnyPosCLL(struct nodeCLL* tail) {
    sleep(1);
    system("cls");
    sleep(1);
    
    if (tail == NULL) {
        printf("Linked List is empty\n");
        getch();
        circularLinkedList(tail);
        return;
    }
    
    printf("Enter the position of the node to delete (starting from 1): ");
    int pos;
    scanf("%d", &pos);
    
    if (pos < 1) {
        printf("Invalid position\n");
        getch();
        circularLinkedList(tail);
        return;
    }
    
    if (pos == 1) {
        deleteElementStartCLL(tail);
        circularLinkedList(tail);
        return;
    }
    
    struct nodeCLL* ptr = tail->link;
    struct nodeCLL* prev = tail;
    int count = 1;
    
    while (count < pos && ptr != tail) {
        prev = ptr;
        ptr = ptr->link;
        count++;
    }
    
    if (count != pos) {
        printf("Invalid position\n");
        getch();
        circularLinkedList(tail);
        return;
    }
    
    prev->link = ptr->link;
    
    if (ptr == tail) {
        tail = prev;
    }
    
    free(ptr);
    
    printf("Data deleted from position %d in the list\n", pos);
    getch();
    circularLinkedList(tail);
}

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newTreeNode->data = value;
    newTreeNode->left = newTreeNode->right = NULL;
    return newTreeNode;
}

struct TreeNode* insertTreeNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createTreeNode(value);
    }

    if (value < root->data) {
        root->left = insertTreeNode(root->left, value);
    } else if (value >= root->data) {
        root->right = insertTreeNode(root->right, value);
    }

    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct TreeNode* searchTreeNode(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return searchTreeNode(root->left, value);
    }

    return searchTreeNode(root->right, value);
}

struct TreeNode* findMinimum(struct TreeNode* TreeNode) {
    struct TreeNode* current = TreeNode;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct TreeNode* deleteTreeNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteTreeNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteTreeNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteTreeNode(root->right, temp->data);
    }

    return root;
}


    struct TreeNode* root = NULL;
    int choice, value;
    struct TreeNode* result;


void tree(){
	 while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a Node\n");
        printf("2. Delete a Node\n");
        printf("3. Search for a Node\n");
        printf("4. View inorder traversal\n");
        printf("5. View preorder traversal\n");
        printf("6. View postorder traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insertTreeNode(root, value);
                printf("Node inserted successfully.\n");
                getch();
                system("cls");
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                root = deleteTreeNode(root, value);
                printf("Node deleted successfully.\n");
                getch();
                system("cls");
                break;
            case 3:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                result = searchTreeNode(root, value);
                if (result != NULL) {
                    printf("Node found in the tree.\n");
                } else {
                    printf("Node not found in the tree.\n");
                }
                getch();
                system("cls");
                break;
            case 4:
                printf("Inorder Traversal of the Binary Search Tree: ");
                inorderTraversal(root);
                printf("\n");
                getch();
                system("cls");
                break;
            case 5:
                printf("Preorder Traversal of the Binary Search Tree: ");
                preorderTraversal(root);
                printf("\n");
                getch();
                system("cls");
                break;
            case 6:
                printf("Postorder Traversal of the Binary Search Tree: ");
                postorderTraversal(root);
                printf("\n");
                getch();
                system("cls");
                break;
            case 7:
                printf("Exiting the program...\n");
                getch();
                system("cls");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                getch();
                system("cls");
        }
    }
    return;
}

void displayarray(int *a, int x)
{
    system("cls");
    printf("Your array is :\n");
    for (i = 0; i < x; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    array(a, x);
    return;
}

void showarray(int *a, int x)
{
    system("cls");
    printf("Your array is :\n");
    for (i = 0; i < x; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}
void insertend(int *a, int x)
{
    system("cls");
    x = x + 1;
    printf("Enter the element to insert at end:");
    scanf("%d", &a[x - 1]);
    printf("Element inserted at end...\n");
    showarray(a, x);
    array(a, x);
    return;
}
void insertpos(int *a, int x)
{
    showarray(a, x);
    int p;
    x = x + 1;
    printf("Enter the position at which you have to insert:");
    scanf("%d", &p);
    for (i = 0; i < x - p + 1; i++)
    {
        a[x - 1 - i] = a[x - 2 - i];
    }
    printf("Enter the element to insert:");
    scanf("%d", &a[p - 1]);
    printf("Element enserted at position...\n");
    showarray(a, x);
    array(a, x);
    return;
}
void delete_end(int *a, int x)
{
    system("cls");
    x = x - 1;
    showarray(a, x);
    array(a, x);
    return;
}
void delete_pos(int *a, int x)
{
    int p;
    showarray(a, x);
    printf("Enter the position at which you want to delete the element:");
    scanf("%d", &p);
    for (i = 0; i < x - p + 1; i++)
    {
        a[p - 1 + i] = a[p + i];
    }
    x = x - 1;
    showarray(a, x);
    array(a, x);
    return;
}
void max(int *a, int x)
{
    system("cls");
    int max = a[0];
    for (i = 0; i < x; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    printf("Max is %d\n", max);
    array(a, x);
    return;
}
void min(int *a, int x)
{
    void displayarray();
    int min = a[0];
    for (i = 0; i < x; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    printf("Min is %d\n", min);
    array(a, x);
    return;
}
void search(int *a, int x)
{
    system("cls");
    int choice, val;
    printf("Searching operations\n");
    printf("1.Binary search\n2.Linear search\n3.exit\nEnter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("Welcome to binary search operations\n");
        printf("Enter the element to search:\n");
        scanf("%d", &val);
        int b[100];
        for (i = 0; i < x; i++)
        {
            b[i] = a[i];
        }
        bubblesort(b, x);
        int result = binarysearch(b, 0, x - 1, val);
        if (result == -1)
        {
            printf("Element is not found\n");
            array(a, x);
        }
        else
        {
            printf("Element is at the %d position\n", result + 1);
        }
        sleep(2);
        system("cls");
        array(a, x);
        break;
    }
    case 2:
    {
        int c[100];
        printf("Welcome to linear search operations\n");
        printf("Enter the element to search:\n");
        scanf("%d", &val);
        for (i = 0, j = 0; i < x; i++)
        {
            if (a[i] == val)
            {
                c[j] = i;
                j++;
            }
        }
        printf("The searched element is at the position:");
        for (i = 0; i < j; i++)
        {
            printf("%d ", c[i] + 1);
        }
        printf("\n");
        sleep(2);
        system("cls");
        array(a, x);
        break;
    }
    case 3:
    {
        system("cls");
        array(a, x);
        break;
    }
    default:
    {
        printf("Invalid choice...!");
        system("cls");
        search(a, x);
        break;
    }
    }
}
int binarysearch(int *a, int beg, int end, int val)
{
    if (end >= beg)
    {
        int mid = (beg + end) / 2;
        if (a[mid] == val)
            return mid;
        else if (a[mid] > val)
            return binarysearch(a, beg, mid - 1, val);
        else
            return binarysearch(a, mid + 1, end, val);
    }
    else
        return -1;
}
void sort(int *a, int x)
{
    system("cls");
    int choice;
    printf("\nWelcome to sorting operartions\n");
    printf("1.Bubblesort\n2.Insertion sort\n3.Selection sort\n4.Quick sort\n5.Merge sort\n6.exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        bubblesort(a, x);
        printf("Your array is sorted with bubblesort and the sorted array is:\n");
        for (i = 0; i < x; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        array(a, x);
        break;
    }
    case 2:
    {
        insertionsort(a, x);
        printf("Your array is sorted with insertionsort and the sorted array is:\n");
        for (i = 0; i < x; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        array(a, x);
        break;
    }
    case 3:
    {
        selectionsort(a, x);
        printf("Your array is sorted with selectionsort and the sorted array is:\n");
        for (i = 0; i < x; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        array(a, x);
        break;
    }
    case 4:
    {
        quickSort(a, 0, x - 1);
        printf("Your array is sorted with selectionsort and the sorted array is:\n");
        for (i = 0; i < x; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        array(a, x);
        break;
    }
    case 5:
    {
        mergeSort(a, 0, x - 1);
        printf("Your array is sorted with quicksort and the sorted array is:\n");
        for (i = 0; i < x; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        array(a, x);
        break;
    }
    case 6:
    {
        array(a, x);
        break;
    }
    default:
    {
        printf("Ivalid choice..!");
        sort(a, x);
        break;
    }
    }
}
void bubblesort(int *a, int x)
{
    for (i = 0; i < x - 1; i++)
    {
        for (j = 0; j < x - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int flag = a[j];
                a[j] = a[j + 1];
                a[j + 1] = flag;
            }
        }
    }
}
void insertionsort(int *a, int x)
{
    int i, j, key;
    for (i = 1; i < x; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void selectionsort(int *a, int x)
{
    for (i = 0; i < x - 1; i++)
    {
        int small = i;
        for (j = i + 1; j < x; j++)
        {
            if (a[j] < a[small])
            {
                small = j;
            }
        }
        int temp = a[small];
        a[small] = a[i];
        a[i] = temp;
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temporary arrays */
    int L[n1], R[n2];

    /* copy data to temporary arrays */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* merge the temporary arrays back into arr[l..r] */
    i = 0; /* initial index of first subarray */
    j = 0; /* initial index of second subarray */
    k = l; /* initial index of merged subarray */
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* copy the remaining elements of L[] if any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* copy the remaining elements of R[] if any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;  /* find the middle point */
        mergeSort(arr, l, m);     /* sort first half */
        mergeSort(arr, m + 1, r); /* sort second half */
        merge(arr, l, m, r);      /* merge the sorted halves */
    }
}

/* helper function to swap two elements */
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* partition function to rearrange the elements of arr[] */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; /* pivot element */
    int i = (low - 1);     /* index of smaller element */
    int j;
    for (j = low; j <= high - 1; j++)
    {
        /* if current element is smaller than or equal to pivot */
        if (arr[j] <= pivot)
        {
            i++; /* increment index of smaller element */
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* main quick sort function */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* partition index */
        int pi = partition(arr, low, high);
        /* recursively sort elements before and after partition index */
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void reversearray(int *a, int x)
{
    system("cls");
    int b[maxsize];
    for (i = 0, j = x - 1; i < x; i++, j--)
    {
        b[i] = a[j];
    }
    a = b;
    printf("Your array is reversed and the new array is:\n");
    for (i = 0; i < x; i++)
    {
        printf("%d ", a[i]);
    }
    array(a, x);
    return;
}
void array(int *a, int x)
{
    int choice1;
    printf("\n1.Display the array\n");
    printf("2.Insert at end\n");
    printf("3.Insert at pos\n");
    printf("4.Delete at end\n");
    printf("5.Delete at pos\n");
    printf("6.Find maximum\n");
    printf("7.Find minimum\n");
    printf("8.Search an element\n");
    printf("9.Sort the array\n");
    printf("10.Reverse the array\n");
    printf("11.Exit...\n");
    printf("Enter your choice:");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
    {
        displayarray(a, x);
        break;
    }
    case 2:
    {
        insertend(a, x);
        break;
    }
    case 3:
    {
        insertpos(a, x);
        break;
    }
    case 4:
    {
        delete_end(a, x);
        break;
    }
    case 5:
    {
        delete_pos(a, x);
        break;
    }
    case 6:
    {
        max(a, x);
        break;
    }
    case 7:
    {
        min(a, x);
        break;
    }
    case 8:
    {
        search(a, x);
        break;
    }
    case 9:
    {
        sort(a, x);
        break;
    }
    case 10:
    {
        reversearray(a, x);
        break;
    }
    case 11:
    {
        main();
        break;
    }
    default:
    {
        printf("Please enter a valid choice...\n");
        array(a, x);
        break;
    }
    }
}
int main()
{
    system("cls");
    int choice;
    printf("\n\n\t\t.......WELCOME TO DATA STRUCTURES PROGRAMMING.....\n\n\n");
    printf("1.Array\n2.Linked list\n3.Stack\n4.Queue\n5.Tree\n6.Exit\nEnter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        enterarray();
        break;
    }
    case 2:
    {
        linkedlist();
        break;
    }
    case 3:
    {
        acceptStack();
        break;
    }
    case 4:
    {
        que();
        break;
    }
    case 5:
    	{
    		tree();
    		break;
		}
	case 6:
		{
			printf("Thank You...\n");
			break;
		}
    default:
    {
    	    printf("Please enter a right choice\n");
			sleep(2);
			main();
            break;
    }
    }
    return 0;
}


