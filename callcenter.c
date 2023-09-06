#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"


/*
* Name: Tanish hupare
* Email: Huparet@oregonstate.edu
*/


struct data {
	int ID;
	char name[50];
	char reason[100];
};

struct call{
	int ID;
	int size_q;
	int size_s;
	struct queue* queue;
	struct stack* stack;
};

/******************************************************
** function void print_prompt();
** description: this function prints out all the options for user to choose from.
** Parameters: none
** Pre-conditions: the function needs to be called in the int main.
** Post-conditions: this function prints out all the prompts.
******************************************************/

void print_prompt(){

	printf("1. Receive a new call \n");
	printf("2. Answer a call \n");
	printf("3. Current state of the stack - answered calls \n");
	printf("4. Current state of the queue - calls to be answered \n");
	printf("5. Quit \n \n");

	printf("Choose an option: ");

}

/******************************************************
** function void receive_call(struct call* c_center);
** description: this function takes in the data for name and reason and stores it into the queue, it also increments the ID and size for the queue.
** Parameters: Struct call* c_center.
** Pre-conditions: the function needs to be called in the int main and also store the queue.
** Post-conditions: this function stores the call and reason values into the data.
******************************************************/

void receive_call(struct call* c_center){

	struct data* a_call = (struct data*)malloc(sizeof(struct data));	
	char remove[100];

	printf("Enter caller's name: ");
	scanf("%c", &remove);
	scanf("%[^\n]", a_call->name);

	printf("Call reason: ");
	scanf("%c", &remove);
	scanf("%[^\n]", a_call->reason);

	printf("\n");

	c_center->ID = c_center->ID+1;
	a_call->ID = c_center->ID;

	c_center->size_q = c_center->size_q+1;

	queue_enqueue(c_center->queue, a_call);
		printf("The call has been successfully added to the queue! \n\n");

}

/******************************************************
** function: void answer_call(struct call* c_c);
** description: this function moves data infromation from the queue into the stack, it also adds/subtract from the queue and stack.
** Parameters: Struct call* c_c
** Pre-conditions: the function needs to be called in the int main and also store the call struct.
** Post-conditions: this function moves the information off the data fromm the queue into the stack.
******************************************************/

void answer_call(struct call* c_c){	

	if(queue_isempty(c_c->queue) != 0){

		printf("No more calls need to be answered in the stack at the moment! \n");

	}else{

		c_c->size_q = c_c->size_q-1;
		c_c->size_s = c_c->size_s+1;

		void* que_val = queue_front(c_c->queue);

		printf("The following call has been answered and added to the stack! \n\n");

		queue_dequeue(c_c->queue);
		stack_push(c_c->stack, que_val);

		struct data* stack_call = (struct data*)stack_top(c_c->stack);

		printf("ID: %d\n", stack_call->ID);
		printf("Caller's name: %s\n", stack_call->name);
		printf("Call reason: %s\n", stack_call->reason);

	}
}

/******************************************************
** function void display_stack(struct call* call_s);
** description: this function displays the number of calls in the stack and also the last call answered.
** Parameters: Struct call* call_s
** Pre-conditions: the function needs to be called in the int main and also store the call struct.
** Post-conditions: this function displays the data thats still stored into the stack.
******************************************************/

void display_stack(struct call* call_s){

	if(stack_isempty(call_s->stack) != 0){

		printf("No calls in the stack \n");

	}else{
		
		struct data* display_s = (struct data*)stack_top(call_s->stack);

		printf("Number of calls answered: %d\n",call_s->size_s);
		printf("Details of the last call answered: \n\n");

		printf("Caller's name: %s\n", display_s->name);
		printf("Call reason: %s\n",display_s->reason);
	}
}

/******************************************************
** function void display_queue(struct call* call_s);
** description: this function displays the number of calls in the queue and also the first call answered.
** Parameters: Struct call* call_q
** Pre-conditions: the function needs to be called in the int main and also store the call struct.
** Post-conditions: this function displays the data thats still stored into the queue.
******************************************************/

void display_queue(struct call* call_q){

	if(queue_isempty(call_q->queue) != 0){
		printf("No calls in the queue \n");

	}else{
		
		struct data* display_q = (struct data*)queue_front(call_q->queue);

		printf("Number of calls answered: %d\n",call_q->size_q);
		printf("Details of the first call answered: \n\n");

		printf("Caller's name: %s\n", display_q->name);
		printf("Call reason: %s\n",display_q->reason);
	}
}

/******************************************************
** function void free_calls(struct call* free_call);
** description: this function frees all the information in the queue and stack by using the for loop and the it frees the stack and queue struct.
** Parameters: Struct call* free_call
** Pre-conditions: the function needs to be called in the int main and also store the call struct.
** Post-conditions: this function free's the stack and queue and eveything in the stack and queue.
******************************************************/

void free_calls(struct call* free_call){

	for(int i = 0; i < free_call->size_q; i++){

	struct data* q = (struct data*)queue_dequeue(free_call->queue);
	free(q);
	}

	for(int i = 0; i < free_call->size_s; i++){

	struct data* s = (struct data*)stack_pop(free_call->stack);
	free(s);
	}

	queue_free(free_call->queue);
	stack_free(free_call->stack);
	free(free_call);

}

int main(int argc, char const *argv[]) {


	int user_option; // user input from 1-5.
	

	struct call* call_c = malloc(sizeof(struct call)); // allocating memoery for the struct.

	call_c->queue = queue_create();	// creating queue. 
	call_c->stack = stack_create(); // creating stack.

	do{
		printf("\n");
		print_prompt();
		scanf("%d", &user_option);

		// uses switch cases by taking in the user_options.

		switch(user_option)
		{
			case 1:
				receive_call(call_c);
				break;

			case 2:
				answer_call(call_c);
				break;
			case 3:
				display_stack(call_c);
				break;
			case 4:
				display_queue(call_c);
				break;
						
		}	

	}while(user_option != 5);

	// calls the free_call function below

	free_calls(call_c);

	printf("you have quit the program \n \n");
  
	return 0;
}
