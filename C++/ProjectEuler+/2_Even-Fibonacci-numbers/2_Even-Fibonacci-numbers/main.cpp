//
//  main.cpp
//  2_Even-Fibonacci-numbers
//
//  Created by Hoàng Trung Huy on 8/3/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long num_type;

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */

        int T; cin >> T;

        while (T--) {
                num_type input; cin >> input;
                num_type sum = 2;

                num_type back_1 = 2;
                num_type back_2 = 0;
                num_type num = (4 * back_1) + back_2;

                while (num <= input) {
                        back_2 = back_1;
                        back_1 = num;

                        sum += num;

                        num = (4 * back_1) + back_2;
                }

                cout << sum << endl;
        }

        return 0;
}