#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_new_position(const size_t oldPos, const size_t sz, const size_t d);
void swap_int(int *const a, int *const b);
void print_int_array(const int *const a, const size_t sz);
void rotate_left(int *const a, int *const ret, const int sz, const int d);
int is_number(char *str);

int main()
{
    int  n = 0;
    int  d = 0;
    int *in  = NULL;
    int *out = NULL;
    char input[6+1];
    char line[5+1+5+1];  //"10^5 10^5\0"
    memset(line, '\0', sizeof(line));

    fscanf(stdin, "%d %d\n", &n, &d);

    in  = (int *)malloc(sizeof(int) * n);
    out = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        for (size_t c = 0; c < sizeof(input); c++)
        {
            input[c] = getc(stdin);
            if (' ' == input[c])
            {
                break;
            }
        }
        if (is_number(input))
        {
            in[i] = atoi(input);
        }
    }

    rotate_left(in, out, n, d);
    print_int_array(out, n);

    free(in);
    free(out);

    return 0;
}

void print_int_array(const int *const a, const size_t sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void rotate_left(int *const a, int *const ret, const int sz, const int d)
{
    int rotation = (d >= sz) ? (d % sz) : d;
    int newPos = 0;

    for (int i = 0; i < sz; i++)
    {
        newPos = get_new_position(i, sz, rotation);
        ret[newPos] = a[i];
    }
}

void swap_int(int *const a, int *const b)
{
    static int tmp = 0;
    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

size_t get_new_position(const size_t oldPos, const size_t sz, const size_t d)
{
    return (oldPos < d) ? (oldPos - d + sz) : (oldPos - d);
}

int is_number(char *str)
{
    return ((48 <= str[0]) && (57 >= str[0])) ? 1 : 0;
}