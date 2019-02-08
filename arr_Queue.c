#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	long int student_no;
	int score;
	struct node *next;
};
struct node *header, *new_node, *target, *last_node, *temp_node;

void Insert(){

	printf("Adding a node at the end of the Queue.\n");
	new_node = (struct node *) malloc(sizeof(struct node));
	long int id_number;
	int st_score;
	printf("Insert Student's ID Number: ");
	scanf("%ld", &id_number);
	printf("Insert score received: ");
	scanf("%d", &st_score);		
	new_node->student_no = id_number;
	new_node->score = st_score;
//	new_node->next = NULL;

	if(header==NULL){
		header=new_node;
		target = header->next;
	}
	else{
		last_node = header;
		target = header->next;
		while(target!=NULL){
			last_node = target;
			target=target->next;
		}	
		last_node->next = new_node;
		new_node->next = NULL;
	}
		
}

void Delete(){

	printf("Deleting Node at front of the Queue\n");
	if(header==NULL)
		printf("Queue Empty. No Nodes Present.\n");	
	else{
		temp_node = header;
		header = header->next;
		free(temp_node);
	}
}

void Show(){
	target = header;
	if(target==NULL)
		printf("Empty Queue\n");
	else{
		printf("Showing all Nodes from Queue:\n");
		printf("Student\tScore\n");
		while(target!=NULL){

			printf("%ld\t", target->student_no);
			printf("%d\t", target->score);
			target= target->next;
			printf("\n");
		}
	}
	
}

/* 
	Display menu used in order to prevent main function
	from displaying infinite iterations after taking in
	user input. 
*/
void showMenu(){
	int num;
	printf("Insert NUMBER option for one of the following:\n"
	"1 - Insert (Add node at end of Queue)\n"
	"2 - Delete (Delete first node of Queue)\n"
	"3 - Show (Show all nodes in Queue)\n"
	"4 - Exit from the menu\n\n"
	"Enter option here:\t");
	scanf("%d", &num);
	switch(num){
		case 1:
			printf("You have chosen to Add a Node.\n");
			Insert();
			break;
		case 2:
			printf("You have chosen to Delete a Node.\n");
			Delete();
			break;
		case 3:
			printf("You have chosen to display the Queue.\n");
			Show();
			break;
		case 4:
			printf("Exited from Menu.\n");
			exit(0);
		default:
			printf("Invalid input.\n");
			break;
	}	
}

int main(){
	bool check = true;
	do{
		showMenu();
	}
	while(check == true);
	return 0;
}




