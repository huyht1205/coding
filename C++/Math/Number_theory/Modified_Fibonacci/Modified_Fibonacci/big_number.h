//
//  big_number.h
//  Modified_Fibonacci
//
//  Created by Hoàng Trung Huy on 7/21/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#ifndef big_number_h
#define big_number_h

#include <iostream>
#include <vector>

namespace big {
        class big_number;
        big_number *add_big_num(big_number *bigA, big_number *bigB);
        void big_fibonacci(big_number *back2, big_number *back1, unsigned int n);
}

class big::big_number {
public:
        std::vector<char> value;
        big_number(unsigned long long num);
        void add(big_number *adder);
        big_number operator+(const big_number *adder);
        void display(void);
};

#endif /* big_number_h */
