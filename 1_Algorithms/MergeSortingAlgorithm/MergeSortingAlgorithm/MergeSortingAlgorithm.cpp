#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
int main()
{
printf("Merge Sorting Begin!\n ");

return 0;
}*/
//test_1-merging two sorted arays
#if 0
int main()
{
	int arr_0[10] = {0};
	int arr_1[5] = { 1, 2, 5, 6, 8 };
	int arr_2[5] = { 3, 4, 7, 9, 10};
	int l = 0, m = 0, i = 0;
	printf("Merge Sorting Begin!\n");
	for (i = 0;( (i<10)&& (l<5) && (m<5) ); i++)
	{
		
		if (arr_1[l] < arr_2[m])
		{
			arr_0[i] = arr_1[l];
				l++;

		}
		else
		{
		    arr_0[i] = arr_2[m];
			m++;
		}


	}
		/* Copy the remaining elements of L[], if there are any */
		while (l < 5)
		{
			arr_0[i] = arr_1[l];
			i++;
			l++;
		}
		while (m < 5)
		{
			arr_0[i] = arr_2[m];
			i++;
			m++;
		}

	for (i = 0; i < 10; i++)
	{
		printf("%d", arr_0[i]);
	}
	printf("\n");
	return 0;
}

#endif


//test_2-merging two sorted arays organized in a func
#if 0
#define arr_size 10
void merge_this(uint32_t dest_arr[], uint32_t src_arr_1[], uint32_t src_arr_2[], uint32_t arr_1_length, uint32_t arr_2_length);
int main()
{
	uint32_t arr_0[arr_size] = { 0 };
	uint32_t arr_1[5] = { 0, 2, 4, 6, 8 };
	uint32_t arr_2[5] = { 3, 5, 7, 9, 10 };
	merge_this(arr_0, arr_2, arr_1, 5, 5);
	for (int i = 0; i < 10; i++)
	{
		printf("%d", arr_0[i]);
	}
	printf("\n");
	return 0;
}

void merge_this(uint32_t dest_arr[], uint32_t src_arr_1[], uint32_t src_arr_2[], uint32_t arr_1_length, uint32_t arr_2_length)
{
	uint32_t main_counter = 0;
	uint32_t max_length = (arr_1_length + arr_2_length);
	uint32_t arr_1_counter = 0, arr_2_counter = 0;
	printf("\nlet the Merging Begin!");
	for (main_counter = 0; ((main_counter<max_length) && (arr_1_counter<arr_1_length) && (arr_2_counter<arr_1_length)); main_counter++)
	{

		if (src_arr_1[arr_1_counter] < src_arr_2[arr_2_counter])
		{
			dest_arr[main_counter] = src_arr_1[arr_1_counter];
			arr_1_counter++;

		}
		else
		{
			dest_arr[main_counter] = src_arr_2[arr_2_counter];
			arr_2_counter++;
		}
		printf(".");


	}
	/* Copy the remaining elements of L[], if there are any*/
	while (arr_1_counter < 5)
	{
		dest_arr[main_counter] = src_arr_1[arr_1_counter];
		main_counter++;
		arr_1_counter++;
	}
	while (arr_2_counter < 5)
	{
		dest_arr[main_counter] = src_arr_2[arr_2_counter];
		main_counter++;
		arr_2_counter++;
	}
	printf("Done!.\n");

}

#endif


//test_3-sorting arays
#if 1
#define arr_size 10
void merge_this(uint32_t dest_arr[], uint32_t src_arr_1[], uint32_t src_arr_2[], uint32_t arr_1_length, uint32_t arr_2_length);
void mergeSort(uint32_t arr[], uint32_t left, uint32_t right);
int main()
{
	
	uint32_t arr_0[arr_size] = { 0 };
	uint32_t arr_1[arr_size] = { 10, 6, 4, 8, 7, 3, 5, 2, 9, 1 };

	for (int i = 0; i < 10; i++)
	{
		printf("%d", arr_0[i]);
	}
	printf("\n");
	return 0;
}

void merge_this(uint32_t dest_arr[], uint32_t src_arr_1[], uint32_t src_arr_2[], uint32_t arr_1_length, uint32_t arr_2_length)
{
	uint32_t main_counter = 0;
	uint32_t max_length = (arr_1_length + arr_2_length);
	uint32_t arr_1_counter = 0, arr_2_counter = 0;
	printf("\nlet the Merging Begin!");
	for (main_counter = 0; ((main_counter<max_length) && (arr_1_counter<arr_1_length) && (arr_2_counter<arr_1_length)); main_counter++)
	{

		if (src_arr_1[arr_1_counter] < src_arr_2[arr_2_counter])
		{
			dest_arr[main_counter] = src_arr_1[arr_1_counter];
			arr_1_counter++;

		}
		else
		{
			dest_arr[main_counter] = src_arr_2[arr_2_counter];
			arr_2_counter++;
		}
		printf(".");


	}
	/* Copy the remaining elements of L[], if there are any*/
	while (arr_1_counter < 5)
	{
		dest_arr[main_counter] = src_arr_1[arr_1_counter];
		main_counter++;
		arr_1_counter++;
	}
	while (arr_2_counter < 5)
	{
		dest_arr[main_counter] = src_arr_2[arr_2_counter];
		main_counter++;
		arr_2_counter++;
	}
	printf("Done!.\n");

}


void mergeSort(uint32_t arr[], uint32_t left, uint32_t right)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}



void mergeSort(uint32_t arr[], uint32_t left, uint32_t right)
{
	if (left == right / 2)
	{
		return arr[left];
	}
	mergeSort(arr, left, (right / 2));
	mergeSort(arr, ((right / 2) + 1), right);
	merge_this(arr, arr, arr, ((right / 2) - left), (right-)
}
#endif