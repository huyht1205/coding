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

char *const DEFAULT_OUTPUT = "/dev/stdout";

typedef struct {
    int begin;
    int end;
    int k;
} query_t;

long array_manipulation(const int n, query_t *const queries, const int queriesSz);

int main()
{
    query_t *queries = NULL;
    FILE    *fptr    = NULL;
    char    *output  = NULL;

    int n = 0;
    int q = 0;
    long result = 0;

    size_t queriesSz = 0;

    output = getenv("OUTPUT_PATH");
    if (NULL == output) {
        output = DEFAULT_OUTPUT;
    }

    fscanf(stdin, "%d %d", &n, &q);
    queriesSz = q * sizeof(queries[0]);

    queries = malloc(queriesSz);

    memset(queries, 0, queriesSz);

    for (int i = 0; i < q; i++) {
        fscanf(stdin, "%d %d %d", &queries[i].begin, &queries[i].end, &queries[i].k);
    }

    fptr   = fopen(output, "w");
    result = array_manipulation(n, queries, q);

    fprintf(fptr, "%ld\n", result);
    fclose(fptr);

    free(queries);

    return 0;
}

long array_manipulation(const int n, query_t *const queries, const int queriesSz)
{
    long a[n];
    long max = 0;

    memset(a, 0, sizeof(a));

    for (int q = 0; q < queriesSz; q++) {
        for (int i = (queries[q].begin - 1); i < (queries[q].end - 1); i++) {
            a[i] += queries[q].k;
            if (max < a[i]) {
                max = a[i];
            }
        }
    }

    return max;
}