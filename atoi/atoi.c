#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char *str;
    int   expect;
} test_t;

#define ARR_LEN(a)  (sizeof((a)) / sizeof((a)[0]))
const int MAXINT = INT32_MAX;
const int MININT = INT32_MIN;

int is_number(char c)
{
    return ( (c >= '0') && (c <= '9') ) ? 1 : 0;
}

int myAtoi(char *str)
{
    int numLen = 0;
    int sign   = 1;
    int begin  = 0;
    int multiplier = 1;
    int ret = 0;
    int i   = 0;

    for (i = 0; str[i] == ' '; ++i);
    if (str[i] == '-')
    {
        sign = -1;
        ++i;
    }
    else if (str[i] == '+')
    {
        ++i;
    }
    for (; str[i] == '0'; ++i);

    begin = i;
    for (; is_number(str[i]) ; ++i)
    {
        ++numLen;
    }


    if ( (numLen > 10) || ((numLen == 10) && (str[begin] > '2')) )
    {
        return (sign > 0) ? MAXINT : MININT;
    }

    for (int i = 0; i < numLen; ++i, multiplier *= 10)
    {
        int num = (str[begin + numLen - 1 - i] - '0') * multiplier * sign;
        if ( (sign > 0) && (num > (MAXINT - ret)) )
        {
            return MAXINT;
        }
        if ( (sign < 0) && (num < (MININT - ret)) )
        {
            return MININT;
        }
        else
        {
            ret = ret + num;
        }
    }

    return ret;
}

int main(void)
{
    test_t testCases[] = {
        {(char *)"0",      0},
        {(char *)"-1",    -1},
        {(char *)"+1",     1},
        {(char *)"+-2",    0},
        {(char *)" -42", -42},
        {(char *)"   +0 123",      0},
        {(char *)"1234 23434",  1234},
        {(char *)"1234 -23434", 1234},
        {(char *)"abc 123",   0},
        {(char *)"123 abc", 123},
        {(char *)"-9999999999",  MININT},
        {(char *)" 9999999999",  MAXINT},
        {(char *)"-91283472332", MININT},
        {(char *)" 2147483648",  MAXINT},
        {(char *)"-2147483649",  MININT},
        {(char *)"  0000000000012345678", 12345678},
        {(char *)"000000000000000000",           0},
        {(char *)"-000000000000001",            -1},
    };

    for (size_t i = 0; i < ARR_LEN(testCases); ++i)
    {
        int ret = (int)myAtoi(testCases[i].str);
        printf("%25s ---> %15d", 
            testCases[i].str,
            ret
            );
        if (ret != testCases[i].expect)
        {
            printf(": FAILED (expected %d)", testCases[i].expect);
        }
        printf("\n");
    }

    return 0;
}