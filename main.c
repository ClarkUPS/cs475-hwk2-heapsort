#include <stdio.h>
#include "employee.h"
#include "heap.h"
#include <string.h>

#define MAX_EMPLOYEES 128
int main()
{
	struct  Employee A[MAX_EMPLOYEES];
	int numElements = 0;
	char playerinput; //checks if the player wants to contenue
	

	while (playerinput != 'n' || numElements > 128) //the main loop for adding names
	{
		char name[MAX_NAME_LEN];
		int salary;
		
		//get name and salary
		printf("Name: ");
		scanf("%s",name);
		printf("Salary: ");
		scanf("%d",&salary);
		printf("\n");

		//add infor to a temp employee
		struct Employee temp;
		strcpy(temp.name, name);
		temp.salary = salary;
		
		//adds elements to array
		A[numElements] = temp;
		numElements++;

		//get next input
		printf("Enter another user (y/n)? ");
		scanf(" %c" , &playerinput);


		//make sure the input for if you want to enter another is good.
		int flag = 0;
		while(flag == 0){
			//check if input is y or n
			if(playerinput == 'n' || playerinput == 'y'){
				break;
			}
				//repeat the input if you enter something incorrect
			printf("\nYour prevous input was: %c", playerinput);
			printf("\nSorry, could not parse your responce. Please enter either y or n: ");
		 	scanf(" %c" , &playerinput);
		 	printf("\n");

		}
		
	}
	

	buildHeap(A,numElements); //builds and sorts the heap


	printList(A,numElements); //prints the results

	
	return 0;
}
