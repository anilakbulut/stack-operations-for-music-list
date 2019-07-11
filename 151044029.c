/*ANIL AKBULUT 151044029 HW9	<<---->>	Music Stack List*/

/*Used libraries and definitions*/
#include <stdio.h>
#include <stdlib.h> /*For malloc function*/
#include <string.h> /*For string operations*/
#define LENGHT_STR 30 /*Max number of strings*/

/*Stack created as linked list.*/
struct person{
	char name[LENGHT_STR]; /*name string keeps the names of musicians*/
	char surname[LENGHT_STR];/*surname string keeps the surnames of musicians*/
	char musical_Work[LENGHT_STR];/*work string keeps the names of musicians' works*/
	int age;/*surname string keeps the ages of musicians*/
	struct person *next; /* link list pointer*/
}*top;

/*Prototypes of used functions*/
void addNode(char name[], char surname [], char creation [], int age);
void deleteNode();
void Sort_Alphabetically();
void swap(struct person *node1,struct person *node2);
void print_stack();

/*The add node function allows us to create a new node and add it to the stack.*/
/*Gets the struct elements as a parameter.*/
void addNode(char name[], char surname [], char creation [], int age){
	struct person *head;
	head = (struct person*) malloc(sizeof(struct person));
	strcpy(head->name,name);
	strcpy(head->surname,surname);
	strcpy(head->musical_Work,creation);
	printf("-%d-\n",age );
	head->age = age;
	head->next = top;
	top = head;
}
/*The delete node function to delete nodes from stack.*/
void deleteNode(){
	if(top == NULL)
		return;
	struct person *head = top;
	top = top->next;
	free(head);
}
/*Sort function sorts the stack in name order.*/
void Sort_Alphabetically(){
	struct person *node1;
	struct person *node2;

	for (node1 = top; node1 != NULL; node1 = node1->next)
		for (node2 = top; node2 != NULL; node2 = node2->next)
			if(strcmp(node1->name,node2->name) < 0)
				swap(node1,node2);
	
}
/*The swap function allows two nodes to be moved by copying the elements together.*/
void swap(struct person *node1,struct person *node2){
	struct person temp;
	temp = 	*node1;
	strcpy(node1->name,node2->name);
	strcpy(node2->name,temp.name);		

	strcpy(node1->surname,node2->surname);
	strcpy(node2->surname,temp.surname);

	strcpy(node1->musical_Work,node2->musical_Work);
	strcpy(node2->musical_Work,temp.musical_Work);

	node1->age = node2->age;
	node2->age = temp.age;

}
/*Sort function sorts the stack in age order.*/
void Sort_Increasingly(){
	struct person *node1;
	struct person *node2;
	for (node1 = top; node1 != NULL; node1 = node1->next)
		for (node2 = top; node2 != NULL; node2 = node2->next)
			if(node1->age < node2->age)
				swap(node1,node2);
}

/*The print stack function allows you to press the stack nodes on the screen.*/
void print_stack(){
	int i;
	struct person *head = top;
	printf("----------------\n");
	for (i = 1; head!= NULL; ++i){
		printf("%d) %s\n%s \n%s \n%d \n",i,head->name,head->surname,head->musical_Work,head->age);
		head = head->next;	
	}
}
int main()
{
	top = NULL;
	
	char name[LENGHT_STR];
	char surname[LENGHT_STR];
	char musical_Work[LENGHT_STR];
	int age;
	/*Menu created*/
	int exit = 0;
	int command;
	while(exit == 0){
		printf("****MENU**** \n");
		printf("1- Add a Person to the Stack \n");	
		printf("2- Pop a Person from the Stack \n");
		printf("3- Sort Alphabetical Order \n");
		printf("4- Sort Age in Increasing Order\n");
		printf("5- Exit menu\n");
		printf("*************\n");
		printf("Select your Choise: ");
		scanf("%d",&command);
		
		switch(command){
			case 1:
				printf("Name:");
				scanf(" %[^\n]s",name); 
				printf("Surname:");
				scanf(" %[^\n]s",surname);
				printf("Creation:");
				scanf(" %[^\n]s",musical_Work);
				printf("Age:");
				scanf("%d",&age);
				addNode(name,surname,musical_Work,age);
				break;
			case 2:
				deleteNode();
				break;
			case 3:
				Sort_Alphabetically();
				break;
			case 4:
				Sort_Increasingly();
				break;
			case 5:
				exit = 1;
				break;
			default:
				printf("unnown command : %d\n",command);
		}
		print_stack();
	}
	return 0;
}