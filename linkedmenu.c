#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node *next_node;
};
struct node *head_node, *newest, *target, *prev, *temp;

// Insertion of node at begninning of structure
void insertBeg(){  // Option 1
    int number;
    newest = (struct node*)malloc(sizeof(struct node));
    printf("Enter a number: ");
    scanf("%d", &number);
    
    newest->data=number;
    newest->next_node=NULL;
    if(head_node==NULL)
        head_node=newest;
    else{
        newest->next_node=head_node;
        head_node=newest;
    }
}

// Insertion of node at end of structure
void insertEnd(){  // Option 2
	int number;
    newest = (struct node*)malloc(sizeof(struct node));

    printf("Enter a number to the END of the list: ");
    scanf("%d", &number);
    newest->data=number;
    if(head_node==NULL){
        head_node=newest;
        newest->next_node = NULL;
    } 
    else{
        prev = head_node;
        target=head_node->next_node;
        while(target!=NULL){
            prev=target;
            target=target->next_node;
        }
        prev->next_node=newest;
        newest->next_node=NULL;
    }
    
}

// Deleting the first node at beginning of structure
void deleteFirst(){  // Option 3
    if(head_node==NULL)
        printf("Structure Empty. No Nodes in list.\n");
    else{
        temp=head_node;
        head_node = head_node->next_node;
        free(temp);
    }
}

// Deleting the last node - end of structure
void deleteLast(){  // Option 4
    if(head_node==NULL)
        printf("Structure Empty. No Nodes in list.\n");
    else{
        temp=head_node;
        while(temp->next_node != NULL){
            prev=temp;
            temp=temp->next_node;
        }
        free(prev->next_node);
        prev->next_node=NULL;
    }
}

/*
    Search for node - if found delete it
    Else - return message that node could not be found for deletion
*/
void searchDelete(){  // Option 5
    int number;
    printf("Insert the number of node to be deleted: ");
    scanf("%d", &number);

    if(head_node==NULL)
        printf("Node Could Not be Deleted.\n");
    else{
        temp=head_node;
        while(temp->data != number){
            prev = temp;
            temp=temp->next_node;
            if(temp == NULL){
                printf("Node Could Not be Deleted\n");
                free(temp);
                return;
            }
        }
        prev->next_node = temp->next_node;
        free(temp);
    }

}

// Return the entire node structure to the user
void display(){  // Option 6
    target=head_node;
    printf("The linked list is:\n");
    while(target!=NULL){
        printf("%d\t",target->data);
        target=target->next_node;
        // free(target);
    }
    printf("\n");
}

void menu(){
    int choice;
    printf("Enter a number for one of the following:\n"
    "1 - Insert node at beginning of list\n"
    "2 - Insert node at end of list\n"
    "3 - Delete first node\n"
    "4 - Delete last node\n"
    "5 - Search for node and delete it\n"
    "6 - Display list\n"
    "7 - Exit\nEnter response here: ");
    scanf("%d", &choice);
    switch(choice){
            case 1:
                insertBeg();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                searchDelete();
                break;
            case 6:
                display();
                break;
            case 7:  // Exit from the menu
                printf("Program Menu Ended.\n");
                exit(0);
            default: 
                printf("Invalid Input\n");
    }
}

int main(){  // Main Function
    
    bool rep=true;
    do{
        menu();
    } while(rep == true);
    return 0;
}
