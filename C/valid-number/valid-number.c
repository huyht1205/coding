#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_LEN(a) (size_t)(sizeof((a)) / sizeof((a)[0]))

typedef struct {
    char *str;
    bool  expect;
} test_t;

bool isNumber(char *s)
{
    int    i   = 0;
    bool e   = 0;
    bool dot = 0;

    for (; (' ' == s[i]); ++i);
    if ( ('-' == s[i]) || ('+' == s[i]) )
    {
        ++i;
    }

    for (; '\0' != s[i]; ++i)
    {
        if ( ('e' == s[i]) && (! e) )
        {
            if ('-'== s[i+1])
            {
                ++i;
            }
            e = true;
        }
        else if ( ('.' == s[i]) && (! e) && (! dot) )
        {
            dot = true;
        }
        else if ( (' ' != s[i]) && (('0' > s[i]) || ('9' < s[i])) )
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    test_t tests[] = {
        {" 0.1 ", true},
        {"abc" ,  false},
        {"1 a" ,  false},
        {"2e10",  true},
        {" 1e",   false},
        {"e3",    false},
        {" 6e-1", true},
        {" --6 ", false},
        {"-+3",   false},
        {" -90e3   ", true},
        {" 99e2.5 ",  false},
        {"53.5e93",   true},
        {"95a54e53",  false},
    };

    for (size_t i = 0; i < ARR_LEN(tests); ++i)
    {
        bool ret = isNumber(tests[i].str);
        printf("%-15s--> %d", tests[i].str, ret);
        if (ret != tests[i].expect)
        {
            printf(" FAILED");
        }
        printf("\n");
    }

    return 0;
}