/*
 * Script for merge-sort of two bubble-sorted VLA arrays 
 */



#include <stdio.h>

void arr_initializer(int initz_size, int initz_arr[]);

void print_array(int prnt_size, int prnt_arr[]);

void bubble_sort(int bbl_size, int bbl_arr[]);

void merge(int mrg_size1, int mrg_size2, int merged_size, int mrg_arr1[], int mrg_arr2[], int merged_arr[]);

int main()
{
	int size1, size2 = 0;

	printf("Size of first array: \n");
	scanf("%d", &size1);

	printf("Size of second array: \n");
	scanf("%d", &size2);

	int arr1[size1];
	int arr2[size2];
	
	int size_merged = size1 + size2;
	int arr_merged[size_merged]; 
	for(int i_merged = 0; i_merged < size_merged; i_merged++){
		arr_merged[i_merged] = 0;
	}


	arr_initializer(size1, arr1);
	arr_initializer(size2, arr2);
	
	printf("\narr1:\n");
	print_array(size1, arr1);
	printf("\narr2:\n");
	print_array(size2, arr2);

	printf("\narr1:\n");
	bubble_sort(size1, arr1);
	printf("\narr2:\n");
	bubble_sort(size2, arr2);
	
	printf("\nMerged array:\n");
	merge(size1, size2, size_merged, arr1, arr2, arr_merged);

	return 0;
}

void arr_initializer(int initz_size, int initz_arr[])
{
	// Array initializer
	
	printf("Pass %d elements of an array: \n", initz_size);
	for(int i = 0; i < initz_size; i++){
		scanf("%d", &initz_arr[i]);
	}
}

void print_array(int prnt_size, int prnt_arr[])
{	
	// Prints an arrray
	
	for(int i = 0; i < prnt_size; i++){
		printf("[%d] ", prnt_arr[i]);
	}
	printf("\n");
}

void bubble_sort(int bbl_size, int bbl_arr[])
{
	// Sorting algorithm in ascending order

	int temp = 0;
	for(int i = 0; i < bbl_size; i++){
		for(int j = i + 1; j < bbl_size; j++){
			if(bbl_arr[i] > bbl_arr[j]){
				temp = bbl_arr[j];   
	
				bbl_arr[j] = bbl_arr[i];
				bbl_arr[i] = temp;
			}
		}
	}
	print_array(bbl_size, bbl_arr);
	printf("^sorted^\n");
}

void merge(int mrg_size1, int mrg_size2, int merged_size, int mrg_arr1[], int mrg_arr2[], int merged_arr[])
{		
	// Merging two sorted static arrays into merged array
	 
	// index_fixed are used to check how many elements 
	// were left out after merging,
	// in a case where one of the arrays' sizes is bigger 
	int index1_fixed = 0;
	int index2_fixed = 0; 

	for(int i = 0; i < mrg_size1; i++){
		for(int j = index2_fixed; j < mrg_size2; j++){ // index2_fixed is also used to memorize on which element of second arr we stopped
			if(mrg_arr1[i] <= mrg_arr2[j]){
				merged_arr[i+j] = mrg_arr1[i]; // i+j to account for index of total array
				index1_fixed += 1;	

				// break is used because after we've assigned new element to merged_arr, 
				// we need to iterate in first arr, since both are sorted and
				// further comparison of arrays' elements is pointless
				break;  
			}else{
				merged_arr[i+j] = mrg_arr2[j];
				index2_fixed += 1;
			}	
		}
	}
	
	// index_fixed is applied without +1, that would usually be used to account for arr starting from 0
	// because during merge index calculates before autoincrement of i (when i is still 0, fixed is 1),
	// hence difference is already accounted for
	if((index1_fixed) != mrg_size1){ 
		for(index1_fixed; index1_fixed < mrg_size1; index1_fixed++){ // index_fixed < mrg_size, and not <= because in the loop we will use it as index of arr (from 0 to <size> -1)
			merged_arr[index1_fixed + index2_fixed] = mrg_arr1[index1_fixed];
		}
	}else if((index2_fixed) != mrg_size2){
		for(index2_fixed; index2_fixed < mrg_size2; index2_fixed++){
			merged_arr[index1_fixed + index2_fixed] = mrg_arr2[index2_fixed];
		}
	}


	print_array(merged_size, merged_arr);
}

