//
//  main.cpp
//  perfect-square-collection
//
//  Created by Hoàng Trung Huy on 7/29/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

#include "boost/timer/timer.hpp"

using namespace std;

typedef unsigned long long integer;

bool check_triple_square(integer x, integer y, integer z);
bool is_square(integer a);

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        boost::timer::auto_cpu_timer timer;
        const unsigned int repeat_time = 10000;

        int N; cin >> N;
        integer x, y, z;
        x = 2;
        y = 1;
        z = 0;
        if (pow(10, 12) < UINT64_MAX) {
                cout << "smaller" << endl;
        }
        for (; x <= UINT64_MAX && N > 0; x++) {
                if (is_square(x)) {
                        cout << x << endl;
                        N--;
                }
        }
        //cout << x << " " << y << " " << z << endl;

        return 0;
}

bool check_triple_square(integer x, integer y, integer z) {
        return ( is_square(x+y) & is_square(x-y) &
                 is_square(x+z) & is_square(x-z) &
                 is_square(y+z) & is_square(y-z)
                );
}

bool is_square(integer a) {
        if (a == 0) {
                return false;
        }
        else {
                bool square = false;

                integer closest = (integer) sqrt(a);
                if (closest * closest == a) {
                        square = true;
                }
                else {
                        square = false;
                }
                
                return square;
        }
}