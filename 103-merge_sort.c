#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sorted sub-arrays into a single sorted array
 * @array: The array to be sorted
 * @left: Pointer to the left sub-array
 * @left_size: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_size: Size of the right sub-array
 * Return: Nothing
 */

void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	int *tmp;
	size_t i, j, k;

	tmp = malloc(sizeof(int) * (left_size + right_size));
	if (!tmp)
		return;

	i = 0;
	j = 0;
	k = 0;
	while (i < left_size && j < right_size)
	{
	if (left[i] <= right[j])
		tmp[k++] = left[i++];
	else
		tmp[k++] = right[j++];
	}

	while (i < left_size)
		tmp[k++] = left[i++];

	while (j < right_size)
		tmp[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = tmp[i];

	free(tmp);
}

/**
 * merge_sort - Sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (!array || size < 2)
		return;

	mid = size / 2;

	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < mid; i++)
	{
		printf("%d", left[i]);
		if (i != size - 1)
		{
			printf(", ");
			printf("\n");
		}
	}
	printf("[right]: ");
	for (i = 0; i < size - mid; i++)
	{
		printf("%d", right[i]);
		if (i != size - 1)
		{
			printf(", ");
			printf("\n");
		}
	}
	merge(array, left, mid, right, size - mid);

	printf("[Done]: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
		{
			printf(", ");
			printf("\n");
		}
	}
}
