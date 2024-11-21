/*
 * Merge algorithm of two sorted static arrays
 */

#include <stdio.h>

void print_array(int prnt_size, int prnt_arr[]);

void merge(int mrg_size1, int mrg_size2, int merged_size, int mrg_arr1[], int mrg_arr2[], int merged_arr[]);

int main()
{
	int size1 = 4;
	int size2 = 4;
	int size_merged = size1 + size2;

	int arr1[4] = {1, 2, 4, 5};
	int arr2[4] = {3, 6, 7, 8};
	int arr_merged[8] = {0};

	merge(size1, size2, size_merged, arr1, arr2, arr_merged);
	
	return 0; 
}

void print_array(int prnt_size, int prnt_arr[])
{
	// Prints out an array

	printf("\nYour array: \n");
		for(int i = 0; i < prnt_size; i++){
			printf("[%d] ", prnt_arr[i]);
		}
	printf("\n");
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
				merged_arr[i+j] = mrg_arr1[i];
				
				index1_fixed += 1;
				printf("\nfixed1, fixed2: %d, %d\n", index1_fixed, index2_fixed);

				printf("i = %d; j = %d", i, j);
				print_array(merged_size, merged_arr);
				
				// break is used because after we've assigned new element to merged_arr, 
				// we need to iterate in first arr, since both are sorted and
				// further comparison of arrays' elements is pointless
				break;
			}else{
				merged_arr[i+j] = mrg_arr2[j];
				index2_fixed += 1;
					
				printf("i = %d; j = %d", i, j);
				print_array(merged_size, merged_arr);
				
				printf("\nfixed1, fixed2: %d, %d\n", index1_fixed, index2_fixed);
			}
		}
	}
		
	// index_fixed is applied without +1, that would usually be used to account for arr starting from 0
	// because during merge index calculates before autoincrement of i (when i is still 0, fixed is 1),
	// hence difference is already accounted for
	if((index1_fixed) != mrg_size1){
		for(index1_fixed; index1_fixed < mrg_size1; index1_fixed++){
			merged_arr[index1_fixed + index2_fixed] = mrg_arr1[index1_fixed];
		}
	}else if((index2_fixed) != mrg_size2){
		for(index2_fixed; index2_fixed < mrg_size2; index2_fixed++){
			merged_arr[index1_fixed + index2_fixed] = mrg_arr2[index2_fixed];
		}
	}

	print_array(merged_size, merged_arr);
	printf("^merged^\n");
}









































































