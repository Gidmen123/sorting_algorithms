#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    unsigned int i, j, k = 0, *count = NULL, *output = NULL;

    if (!array || size < 2)
        return;

    /* Find the largest element in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > (int) k)
            k = array[i];
    }

    /* Allocate memory for the count and output arrays */
    count = malloc(sizeof(unsigned int) * (k + 1));
    output = malloc(sizeof(int) * size);

    if (!count || !output)
    {
        free(count);
        free(output);
        return;
    }

    /* Initialize count array with 0s */
    for (i = 0; i <= k; i++)
        count[i] = 0;

    /* Store the count of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Modify the count array to contain the actual position of each element
     * in the output array */
    for (i = 1; i <= k; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size - 1; (int) i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted output array back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Print the count array */
    for (j = 0; j <= k; j++)
        printf(" %u", count[j]);
    printf("\n");

    /* Free memory */
    free(count);
    free(output);
}
