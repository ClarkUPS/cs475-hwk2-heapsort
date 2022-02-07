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
	

	while (playerinput != 'n' || numElements > 128)
	{
		char name[MAX_NAME_LEN];
		int salary;
		
		printf("Name: ");
		scanf("%s",name);
		printf("Salary: ");
		scanf("%d",&salary);
		printf("\n");

		struct Employee temp;
		strcpy(temp.name, name);
		temp.salary = salary;
		
		A[numElements] = temp;
		numElements++;

		printf("Enter another user (y/n)? ");
		scanf(" %c" , &playerinput);


		int flag = 0;
		while(flag == 0){
			if(playerinput == 'n' || playerinput == 'y'){
				break;
			}
			printf("\nYour prevous input was: %c", playerinput);
			printf("\nSorry, could not parse your responce. Please enter either y or n: ");
		 	scanf(" %c" , &playerinput);
		 	printf("\n");

		}
		
	}
	
	
	
	
	
	
	// struct Employee a0 = {"a0", 55};
	// struct Employee a1 = {"a1", 42};
	// struct Employee a2 = {"a2", 99};
	// struct Employee a3 = {"a3", 90};
	// struct Employee a4 = {"a4", 73};
	// struct Employee a5 = {"a5", 81};
	// struct Employee a6 = {"a6", 84};
	// struct Employee a7 = {"a7", 93};
	// struct Employee a8 = {"a8", 79};
	// struct Employee a9 = {"a9", 97};
	// struct Employee a10 = {"a10", 83};
	// struct Employee a11 = {"a11", 21};

	// A[0] = a0;
	// A[1] = a1;
	// A[2] = a2;
	// A[3] = a3;
	// A[4] = a4;
	// A[5] = a5;
	// A[6] = a6;
	// A[7] = a7;
	// A[8] = a8;
	// A[9] = a9;
	// A[10] = a10;
	// A[11] = a11;

	

	printList(A,numElements);

	//heapify(A,2,numElements);
	buildHeap(A,numElements);
	printf("\n");

	printList(A,numElements);

	// printList(A,4);
	// swap(&A[0], &A[2]);
	// printList(A,4);


	//heapify()



	


	
	return 0;
}
