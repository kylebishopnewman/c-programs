#include <stdio.h>

void divide(int upper_array[], int upper_array_size);
void mergesort(int left_array[], int left_size, int right_array[], int right_size, int upper_array[], int upper_array_size);

int main()
{
	int numbers[] = {2, 7, 23, 3, 9, 1, 8, 33, 4, 3, 11};
	int array_size = 11;
	
	divide(numbers, array_size);

	/* print */
	int i;
	for (i = 0; i < array_size; i++)
		printf("%d,", numbers[i]);
}

/* divide: divides an array down to size 1 */
void divide(int upper_array[], int upper_array_size)
{
	/* check we haven't hit the bottom */
	if (upper_array_size == 1)
		return;
		
	/* divide the sides symbolically */
	int left_size, right_size;

	right_size = upper_array_size / 2;		/* right will always be 1 less than right */
	left_size = upper_array_size - right_size;

	/* create the logical arrays */
	int left_array[left_size], right_array[right_size];

	/* populate each side */
	int upper_array_offset, i;

	for (upper_array_offset = i = 0; i < left_size; i++)
		left_array[i] = upper_array[upper_array_offset++];
	for (i = 0; i < right_size; i++)
		right_array[i] = upper_array[upper_array_offset++];

	/* divide recursively each side */
		divide(left_array, left_size);
		divide(right_array, right_size);

	mergesort(left_array, left_size, right_array, right_size, upper_array, upper_array_size);
}

/* mergesort: sorts each side then merges into original array */
void mergesort(int left_array[], int left_size, int right_array[], int right_size, int upper_array[], int upper_array_size)
{
	/* sort */
	int is_sorted;
	int sorted_array[left_size + right_size];
	int left_offset, right_offset, sorted_array_offset, temp;

	left_offset = right_offset = sorted_array_offset = is_sorted = 0;

	while (is_sorted < 1) {
		if (left_array[left_offset] > right_array[right_offset]) {
			sorted_array[sorted_array_offset++] = right_array[right_offset++];
		}
		else if (left_array[left_offset] < right_array[right_offset]) {
			sorted_array[sorted_array_offset++] = left_array[left_offset++];
		}
		else
		{
			sorted_array[sorted_array_offset++] = left_array[left_offset++];
			sorted_array[sorted_array_offset++] = right_array[right_offset++];
		}

		if (left_offset >= left_size) {
			while (right_offset < right_size)
				sorted_array[sorted_array_offset++] = right_array[right_offset++];
			is_sorted = 1;
		}
		else if (right_offset >= right_size) {
			while (left_offset < left_size)
				sorted_array[sorted_array_offset++] = left_array[left_offset++];
			is_sorted = 1;
		}
	}

	/* merge */
	int upper_array_offset;
	
	upper_array_offset = sorted_array_offset = 0;

	while (upper_array_offset < upper_array_size)
		upper_array[upper_array_offset++] = sorted_array[sorted_array_offset++];
}
