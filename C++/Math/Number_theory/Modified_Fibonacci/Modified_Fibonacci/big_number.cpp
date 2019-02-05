//
//  big_number.cpp
//  Modified_Fibonacci
//
//  Created by Hoàng Trung Huy on 7/21/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include "big_number.h"
#include <iostream>
#include <bitset>

using namespace big;

big_number::big_number(unsigned long long num) {
        do {
                value.push_back(num % 10);
                num /= 10;
        } while (num != 0);
}

void big_number::display(void) {
        int i = (int) value.size() - 1;
        for (; i >= 0; i--) {
                std::cout << (int) value.at(i);
        }
        std::cout << std::endl;
}

void big_number::add(big_number *adder) {

}

big_number big_number::operator+(const big_number *adder) {
        big_number result(0);
        const big_number *bigger;
        const big_number *smaller;

        if (this->value.size() >= adder->value.size()) {
                bigger = this;
                smaller = adder;
        }
        else {
                bigger = adder;
                smaller = this;
        }

        unsigned int carrier = 0;
        unsigned int temp = 0;
        int i = 0;
        for (; i < smaller->value.size(); i++) {
                temp = bigger->value.at(i) + smaller->value.at(i) + carrier;
                carrier = 0;
                if (temp >= 10) {
                        carrier = 1;
                        temp -= 10;
                }
                result.value.push_back(temp);
        }

        for (; carrier > 0; i++) {
                if (i < this->value.size()) {
                        temp = this->value.at(i) + carrier;
                        carrier = 0;
                        if (temp >= 10) {
                                carrier = 1;
                                temp -= 10;
                        }
                        this->value.at(i) = temp;
                }
                else {
                        this->value.push_back(carrier);
                        carrier = 0;
                }
        }
        return result;
}

void big_fibonacci(big_number *back2, big_number *back1, unsigned int n) {
        for (int i = 2; i <= n; i++) {
                back2->add(back1);
                std::swap(back2, back1);
        }
        back1->display();
}