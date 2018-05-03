
/*
DESCRIPTION :   Linked List Queue - Using a linked list dynamic data structure implement a queue structure IT services ticketing system.
                            The system will enable the user add tickets when IT fix requests are received via phone.

DATE: 20/04/17

COMPLIER:  CodeBlocks

OS : Windows 10

AUTHOR : Kevin Fitzpatrick and Buchita Gitchamnan

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declare structure
typedef struct node
{
    char name[16];  //Name
    int contact;        //Contact number
    char desc[41];  //Description
    float time;     //Time
    struct node *next;

}Anode;

Anode *head = NULL;
Anode *tail = NULL;
Anode *current = NULL;  //current position pointer
Anode *first = NULL;

//declare prototypes
int intro();
void addQ();
void deQ();
void display();

int main()
{
    int choice =0;

    intro();


    do
    {
        //display the menu
        printf("\n\n***MENU***\n\n");
        printf("1. Enter ticket\n");
        printf("2. Delete a ticket\n");
        printf("3. Display all tickets\n");
        printf("4. Exit\n\n");

        scanf("%d", &choice);
        getchar();//prevents infinite loop if char entered

        switch(choice)
        {
            case 1:
            {
                current= tail;

                if(current->contact != NULL)
                {
                    printf("\n!!!List is full!!!\n2");
                }
                else
                {
                    //pass on to enqueue function for adding in a ticket
                    addQ();
                }

                break;
            }//end case 1
            case 2:
            {
                current = head;

                if(current->contact == NULL)
                {
                    printf("\n!!!List is empty!!!\n");
                }
                else
                {
                    //passing to dequeue function
                    deQ();
                }

                break;
            }//end case 2
            case 3:
            {
                int i;
                current = head;

                for(i=0; i<5; i++)
                {
                    if(current->contact == NULL)
                    {
                        printf("\n!!!List is empty!!!\n");
                    }
                    else
                    {
                        printf("\n\tTicket %d\n", i+1);
                        //display the ticket
                        display();

                        current = current->next;
                    }
                }//end for
                break;
            }//end case 3
            case  4:
            {
                //terminate the program
                return 0;

            }//end case 4
            default:
            {
                printf("\nInvalid Input\n");
                break;
            }//end default

        }//end switch

    }
    while(choice!= 4);  //only exit when opt = 4


    getchar();
    return(0);
}

int intro()
{
    int i;
    //create the first node
    first = (struct node*)malloc(sizeof(Anode));

    if(first == NULL)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    head = first;//sets head and tail to the start
    tail = first;

    for(i=0; i<4; i++)
    {
        tail->next = (struct node*)malloc(sizeof(Anode));//creates next 4 nodes

        if(tail->next == NULL)
        {
            printf("\n Node creation failed \n");
            return NULL;
        }

        tail->contact = NULL;//each contact variable set to NULL using it as identifier

        tail->next->next = NULL;//last node = NULL
        if(i != 4)
        {
            tail = tail -> next;//tail moved forward
        }
    }//end for

    tail->next = first;//points last node to first creating a loop

    tail = first;//set to top of the queue

    //examples
    strcpy(tail->name, "Jane");
    tail->contact = 4558;
    strcpy(tail->desc, "Monitor broken");
    tail->time = 12.05;

    tail = tail->next;

    strcpy(tail->name, "Sean");
    tail->contact = 5656;
    strcpy(tail->desc, "Desktop won't flickering");
    tail->time = 12.06;

    tail = tail->next;

    strcpy(tail->name, "Mark");
    tail->contact = 1212;
    strcpy(tail->desc, "Router lights amber");
    tail->time = 12.10;

    tail = tail->next;


}//end intro

void addQ()
{
    printf("\nEnter Name: ");
    scanf("%10s", tail->name);
    getchar();

    printf("\nEnter Contact Number: ");
    scanf("%d",&tail->contact);
    getchar();

    printf("\nEnter Description: ");
    gets(tail->desc);

    printf("\nEnter time: ");
    scanf("%f",&tail->time);

    while(tail->time > 24 || tail->time < 1)//limits time entered
    {
        printf("\nEnter a valid time (eg. 13.45)\n");
        scanf("%f",&tail->time);
    }
    printf("\n\tNEW TICKET\n");

    current = tail;
    display();//display node created

    tail = tail->next;
}//end addQ

void deQ()
{
    current = head;//reset back to start of queue

    display();//display node being deleted

    printf("\tWAS DE-QUEUED\n");
    head->contact = NULL;//contact being used as an identifier = NULL
    head = head->next;
}//end deQ

void display()//displays current node
{
    printf("Name:           ");
    printf("%s\n",current->name);

    printf("Contact Number: ");
    printf("%d\n",current->contact);

    printf("Description:    ");
    printf("%s\n",current->desc);

    printf("Time:           ");
    printf("%.2f\n",current->time);
}//end display


