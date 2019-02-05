#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int  *in;
    int **out;
}test_t;

#define ARR_LEN(a)  sizeof((a))/sizeof((a)[0])

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int **ret = NULL;
    int   i   = 0;

    ret = realloc(ret, sizeof(int *));
    ++(*returnSize);
    ret[i] = (int *)malloc(sizeof(int) * 3);

    return ret;
}

int main(void)
{
    int   **result   = NULL;
    int     resultSz = 0;
    int     input[]  = {-1, 0, 1, 2, -1, -4};

    result = threeSum(input, ARR_LEN(input), &resultSz);

    for (int i = 0; i < resultSz; ++i)
    {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }

    free(result);

    return 0;
}