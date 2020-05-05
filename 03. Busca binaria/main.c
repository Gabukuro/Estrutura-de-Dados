#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int binarySearch (int vet[], int num, int left, int right)
{
	int mid = (right + left) / 2;
	
	if(vet[mid] == num) {
		printf("\n\tPosition => vet[%d]\n", mid);
		return mid;
	}else if(num < vet[left] || num > vet[right]) {
		return printf("\n\tNumber not found!\n");
	}else {
		if(vet[mid] < num) {
			return binarySearch(vet, num,  mid+1, right);
		} else {
			return binarySearch(vet, num, left, mid-1);
		};
	};
}

int main() {
	
	int size = 1000, option = 0;
	int *vetor;
	vetor = (int *)malloc(size *sizeof(int));
	
	printf("\tWhich number do you want to search 'binarily'?\n\n\tYour choice: ");
	scanf("%d", &option);
	
	createRandomVetor(vetor, size);		
	mergeSort(vetor, 0, size - 1);
	binarySearch(vetor, option, 0, size - 1);
	printVetor(vetor, size);
}
