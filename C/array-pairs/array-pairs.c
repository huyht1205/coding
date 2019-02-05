#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

const int RANGE = 1000000000;

char *const DEFAULT_OUTPUT = "/dev/stdout";

long solve(const int *const arr, const size_t arrLen, const long max);
void print_array(const int *const arr, const size_t arrLen);
size_t closest_max_index(const int *const arr, size_t arrLen, const int input);

int main(int argc, char *argv[])
{
    char inBuf[10 + 1];
    int  *arr  = NULL;
    FILE *fptr = NULL;
    char *outputFile = NULL;
    int  n      = 0;     
    long result = 0;
    long max    = 0;

    arr = (int *)malloc(sizeof(int) * n);

    outputFile = getenv("OUTPUT_PATH");
    if (NULL == outputFile) {
        outputFile = DEFAULT_OUTPUT;
    }

    n = atoi(fgets(inBuf, sizeof(inBuf), stdin));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; ; j++)
        {
            inBuf[j] = (char)fgetc(stdin);
            if ( (inBuf[j] < 48) || (inBuf[j] > 57) )
            {
                break;
            }
            if (j == sizeof(inBuf))
            {
                fprintf(stderr, "ERROR: overflow input buffer.\n");
                return -1;
            }
        }
        arr[i] = atoi(inBuf);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    result = solve(arr, n, max);

    fptr = fopen(outputFile, "w");
    fprintf(fptr, "%ld\n", result);
    fclose(fptr);

    free(arr);

    return 0;
}

long solve(const int *const arr, const size_t arrLen, const long max)
{
    long ret = 0;

    for (int i = arrLen - 2; i >= 0; --i)
    {
        if (arr[i] <= arr[i + 1])
        {
            ret *= 2;
        }
        if ( (arr[i] * arr[i + 1]) <= max )
        {
            ++ret;
        }
    }

    return ret;
}

void print_array(const int *const arr, const size_t arrLen)
{
    for (size_t i = 0; i < arrLen; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

size_t closest_max_index(const int *const arr, size_t arrLen, const int input)
{
    size_t index = 0; 
    size_t begin = 0;
    size_t end   = arrLen - 1;

    int closestMax = 0;

    while (end > begin)
    {
        index = (size_t)floor(begin + ((end - begin) / 2));
        if (input > arr[index])
        {

        }
    }

    return index;
}