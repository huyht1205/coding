//
//  main.cpp
//  Modified_Fibonacci
//
//  Created by Hoàng Trung Huy on 7/19/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/timer/timer.hpp>
#include "big_number.h"
#include <deque>
#include <vector>

using namespace std;

inline int *add(int &a, int &b) {
        int *result;

        *result = a + b;

        return result;
}

int main(int argc, const char * argv[]) {
        boost::timer::auto_cpu_timer timer;
        const int repeat = 1000000;

        int a = 0;
        int b = 1;
        int result = 0;

        timer.start();
        cout << "Operator +" << endl;
        for (int i = 0; i < repeat; i++) {
                result = a + b;
        }
        timer.stop();
        timer.report();

        int *resultPtr = 0;

        timer.start();
        cout << "Function with pointer" << endl;
        for (int i = 0; i < repeat; i++) {
                resultPtr = add(a, b);
        }
        timer.stop();
        timer.report();
}