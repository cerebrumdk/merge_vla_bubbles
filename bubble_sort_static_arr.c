/*
 * Bubble-sort algorithm on static array
 */

#include <stdio.h>

void print_array(int prnt_size, int prnt_arr[]);

void bubble_sort(int bbl_size, int bbl_arr[]);

int main()
{	
	int size = 9;
	int arr[9] = {22, 2, -1, 5, 9, 6, 34, 3, -23};
	bubble_sort(size, arr);

	return 0;
}

void print_array(int prnt_size, int prnt_arr[])
{
	printf("\nYour array: \n");
	for(int i = 0; i < prnt_size; i++){
		printf("[%d] ", prnt_arr[i]);
	}
	printf("\n");
}

void bubble_sort(int bbl_size, int bbl_arr[])
{
	int temp = 0;
	for(int i = 0; i < bbl_size; i++){
		for(int j = i + 1; j < bbl_size; j++){
			if(bbl_arr[i] > bbl_arr[j]){
				temp = bbl_arr[j];

				bbl_arr[j] = bbl_arr[i];
				bbl_arr[i] = temp; 
				
				printf("i = %d; j = %d\n", i, j);
				print_array(bbl_size, bbl_arr);
			}
		}
	}
	print_array(bbl_size, bbl_arr);
	printf("^sorted^\n");
}

