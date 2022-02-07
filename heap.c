/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "employee.h"
#include "heap.h"


/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void heapSort(struct Employee *A, int n)
{
	int i = n;
	while(i > 0){
		swap(&A[0],&A[i-1]);
		i--;
	}
	//TODO - BuildHeap on the list
	
	//TODO - while n > 0:
		//TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
		//TODO - A[n-1] now sorted in place!
		//TODO - So decrement n
		//TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
}


/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void buildHeap(struct Employee *A, int n)
{
	double i;
	for(i = floor(n/2); i >= 0; i--){
		heapify(A,i,n);
	}
	
	//TODO - heapify() every element from A[n/2] to A[0] until n-1
}


/**
 * We want to start with A[i] and trickle it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the list
 */

void heapify(struct Employee *A, int i, int n)
{
	int indexLeft = (2 * (i + 1)-1);
	int indexRight = (2 * (i+1));

	int smallest = i;
	if(indexLeft < n && A[indexLeft].salary <= A[smallest].salary){
		smallest = indexLeft;
	}

	if(indexRight < n && A[indexRight].salary <= A[smallest].salary){
		smallest = indexRight;
	}

	if(i != smallest){
		swap(&A[i],&A[smallest]);
		heapify(A,smallest,n);		
	}
}

/**
 * Gets the minimally paid employee. Assumes the given list is a min-heap.
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
struct Employee *getMinPaidEmployee(struct Employee *A, int n)
{
	struct Employee *minPayedEmp = &A[0];
	return minPayedEmp;
}


/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(struct Employee *e1, struct Employee *e2)
{
	struct Employee et = *e2;
	*e2 = *e1;
	*e1 = et;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(struct Employee *A, int n)
{
	int i;
	for(i = 0; i < n; i++){
		printf("[id=%s", A->name);
		printf(" sal=%d", A->salary);
		printf("]");
		A++;
	}
	printf("\n");
}
