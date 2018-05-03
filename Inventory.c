/*
    DESCRIPTION :   Inventory implementation
                                Create a simple IT assets inventory that performs the following functions:
                                1. Add new item
                                2. Delete old item
                                3. Edit item
                                4. Find item
                                5. Record inventory
    DATE :   20/04/2017

    COMPLIER : CodeBlocks

    OS : Windows10

    AUTHOR : Kevin Fitzpatrick and Buchita Gitchamnan


*/

#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

//declare prototype
void add_new_item(void);
void delete_old_item(void);
void edit_item(void);
void find_item(void);
void display(void);

//declare a structure
struct node
{
    char quality[11];
    char name[21];
    char price[26];
    struct node *next;

};
typedef struct node item;
item *start, *temp;

int main ()
{
	int choice;

    //find a memory to allocate the memory
	start=(item *)malloc(sizeof(item));
	start=NULL;

	do
    {
        //display the menu
        printf("\n\n\n ***INVENTORY*** \n\n");
        printf("1. Add new item. \n");
        printf("2. Delete old item. \n");
        printf("3. Edit an item. \n");
        printf("4. Find an item. \n");
        printf("5. Exit\n\n\n");

        //read in the choice
        scanf("%d", &choice);

		switch(choice)
        {
            case 1:
            {
                //add in new item
                add_new_item();
                break;
            }
            case 2:
            {
                //delete old item
                delete_old_item();
                break;
            }
            case 3:
            {
                //edit an item
                edit_item();
                break;
            }
            case 4:
            {
                //find an item
                find_item();
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                printf("\n Please Enter option 1 to 5\n");
                break;
            }
        }//end switch

    }//end do
    while(choice !=5);
}//end main



void add_new_item()
{
	item *ptr,*prev;

    //find a memory to create temp
	temp=(item *)malloc(sizeof(item));

    //get details
	printf("\n\n\nQuality: ");
	scanf("%10s", temp->quality);

	printf("\nModel:");
	scanf("%20s", temp->name);

	printf("\nCost: ");
	scanf("%25s", temp->price);

	temp->next=NULL;

	if(start==NULL)
    {
        start = temp;
    }
	else
    {
        prev=ptr=start;


        while(strcmp(temp->name, ptr->name)>0)
        {
            prev=ptr;
            ptr= ptr->next;

            if (ptr == NULL)
            {
                break;
            }
        }
		if(ptr==prev)
        {
			temp->next=start;
			start=temp;
        }
		else if(ptr==NULL)
        {
            prev->next=temp;
        }
		else
        {
			temp->next=ptr;
			prev->next=temp;
		}//end inner else

	}//end else

	display();
}//end add_new_item


void delete_old_item()
 {
	item *ptr,*prev,*temp;
	char str[20];
	char yes_or_no='n';

	if(start==NULL)
    {
		printf("\n\nInventory is Empty....\n\n");
        getch();
		return;
	}

	printf("Enter Model to Delete : ");
	scanf("%s",str);

    prev=ptr=start;

    while(strcmp(ptr->name,str)!=0)
    {
        prev=ptr;
        ptr= ptr->next;
        if (ptr == NULL)
        {
            break;
        }
    }
	if( ptr !=NULL)
    {
		printf("\nDeleting item.....Confirm [y/n]: ");
		yes_or_no=getch();

		printf("\nQuality: %s\n",ptr->quality);
		printf("\nModel: %s\n",ptr->name);
		printf("\nPrice: %s\n",ptr->price);

		if((yes_or_no =='y')||(yes_or_no =='Y'))
        {
			if (ptr==start)
            {
				temp=start->next;
				free(start);
				start=temp;
			}
			else
            {
				temp=ptr->next;
				free(ptr);
				prev->next=temp;
			}
			printf("\n\n1 Item deleted....");
		}
		else
        {
            printf("\n\nItem not Deleted....");
        }
	}
	else
    {
		printf("\nitem not Found .......");
	}


    display();
}//edn delete



void edit_item()
{
	item *ptr;
	char str[20];

	if(start==NULL)
    {
		printf("\nInventory is Empty\n");
        getch();
		return;
	}

	printf("Enter Item to Edit : ");
	scanf("%s",str);

    ptr=start;

    while(strcmp(ptr->name,str)!=0)
    {
        ptr= ptr->next;

        if (ptr == NULL)
        {
            break;
        }
        else if(ptr!=NULL)
        {

            printf("Quality: %s", ptr->quality);
            scanf("%s", ptr->quality);

            printf("Model: %s", ptr->name);
            scanf("%s", ptr->name);

            printf("Price: %s", ptr->price);
            scanf("%s", ptr->price);

            printf("Done");
        }
        else
        {
            printf("Item not Found\n");
        }
        getch();
    }

    display();

}//end edit


void find_item()
 {
	item *ptr;
	char str[21];

	if(start==NULL)
    {
		printf("\nInventory is Empty\n");
        getch();
		return;
	}
	printf("Find item, Enter the model: ");
	scanf("%s",str);
    ptr=start;
    while(strcmp(ptr->name,str)!=0)
    {
        ptr= ptr->next;
        if (ptr == NULL)
        {
            break;
        }
    }
	if( ptr!=NULL)
    {
		printf("Quality: %s\n",ptr->quality);
		printf("Model : %s\n",ptr->name);
		printf("Price : %s\n",ptr->price);
	}
	else
    {
		printf("Item not Found \n");
	}

    //display the list
    display();


}//end find_item





void display()
{
	item *ptr;

	//check if the list is empty
	if(start==NULL)
    {
		printf("\n\nInventory is Empty....\n\n");
        getch();
		return;
	}
	printf("\n\n\nINVENTORY\n");

    //display the inventory list
	for(ptr=start; ptr !=NULL; ptr=ptr->next)
    {
		printf("\nQuality: %s", ptr->quality);
		printf("\nModel:%s", ptr->name);
		printf("\nPrice: %s", ptr->price);

    }//end for

}//end display



