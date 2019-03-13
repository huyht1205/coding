#ifndef MACROS_H
#define MACROS_H

#include <stdio.h>

#define RETURN_WEMSG_IF(exp, r, fmt, ...) do {\
    if ((exp)) {\
        fprintf(stderr, "ERROR: " fmt, ##__VA_ARGS__);\
        return r;\
    }\
} while (0)

#define LOG(fmt, ...)   printf(fmt, ##__VA_ARGS__)
#define ARR_LEN(arr)    sizeof(arr)/sizeof(arr[0])

#endif // MACROS_H