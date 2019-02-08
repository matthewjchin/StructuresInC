#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    long int student_no;
	int score;
    struct node *next_node;
};
// the node HEADER is the main node in question
struct node *header, *new_node, *target, *last, *temp_node;

// Insert a node at top of stack
void Push(){
	printf("Adding a Node to top of Stack.\n");
	new_node = (struct node *) malloc(sizeof(struct node));
	long int id;
	int st_score;
	printf("Insert Student ID Number: ");
	scanf("%ld", &id);
	printf("Enter the student's score: ");
	scanf("%d", &st_score);
	new_node->student_no = id;
	new_node->score = st_score;
	new_node->next_node=NULL;
	if(header==NULL)
		header=new_node;
	else{
		new_node->next_node = header;
		header=new_node;
	}
}

// Deleing the node from the top of the Stack
void Pop(){
	printf("Removing the top Node from the Stack.\n");
	if(header==NULL)
		printf("No Nodes in the Stack.\n");
	else{
		temp_node=header;
		header = header->next_node;
		free(temp_node);
	}
}

// Display all nodes in stack
void Show(){
	target=header;
	if(target==NULL)
		printf("Empty Stack\n");
	else{
		printf("Showing all Nodes from Stack:\n\n");
		printf("Student\tScore\n");
		while(target!=NULL){
			printf("%ld\t", target->student_no);
			printf("%d\t", target->score);
			target=target->next_node;
			printf("\n");
		}
	}
}

void menu(){
	int num;
	printf("Menu of Items:\n");
	printf("Insert NUMBER option for one of the following:\n"
	"1 - Push (Add Node at top of Stack)\n"
	"2 - Pop (Delete Node from top of Stack\n"
	"3 - Show (Display all nodes in Stack):\n"
	"4 - Exit from Menu\n"
	"------------------------------------------------------\n"
	"Enter option Here:\t");
	scanf("%d", &num);
	switch(num){
		case 1:
			printf("Chosen: Push\n");
			Push();
			break;
		case 2:
			printf("Chosen: Pop\n");
			Pop();
			break;
		case 3:
			printf("Chosen: Show\n");
			Show(); 
			break;
		case 4:
			printf("Exited from Menu\n");
			exit(0);
		default:
			printf("Incorrect Input.\n");
			break;
	}	
}


int main(){
	bool repeated = true;
	do{
		menu();
	}  while(repeated == true);
	return 0;
}









