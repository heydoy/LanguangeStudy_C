/*
 * Student No. 1815364
 * Name. Kim Doy
 * exer10/t2.c
 * merge sorted 
 */

#include <stdio.h>
#include <stdlib.h>

int* merge(int *a, int *b, int size);
int* pmerged = NULL;
int main(void){
	int i;
	int size;
	
	printf("How many numbers? ");
	scanf("%d", &size);
	
	int *pa = (int *)malloc(sizeof(int)*size);
	int *pb = (int *)malloc(sizeof(int)*size);

	printf("Enter %d  numbers : ", size);
	for(i = 0; i < size; i++)
		scanf("%d", pa+i);
	printf("Again... : ");
	for(i = 0; i < size; i++)
		scanf("%d", pb+i);

	pmerged =  merge(pa, pb, size);

	printf("Merged array: ");
	for(i = 0 ; i < size*2 ; i++)
		printf("%d ",*(pmerged+i));

	printf("\n");
	free(pa);
	free(pb);
	free(pmerged);
	return 0;
}

int* merge(int *a, int *b, int size){
	
	int i, temp;
	int *merged = (int *)malloc(sizeof(int)*size*2);
	
	for(i = 0; i < size * 2 ; i++){
			merged[2*i] = a[i];
			merged[2*i+1] = b[i];
	}

	for(i = 0; i < size *2 ; i++){
		for(int j = 0; j < size*2-1; j++){
			if(merged[j] > merged[j+1]){
				temp = merged[j];
				merged[j] = merged[j+1];
				merged[j+1] = temp;
			}
		}
	}
	

	return merged;
}
