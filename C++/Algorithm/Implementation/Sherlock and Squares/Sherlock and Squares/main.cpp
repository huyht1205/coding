//
//  main.cpp
//  Sherlock and Squares
//
//  Created by Hoàng Trung Huy on 7/3/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */

        int T = 0;
        cin >> T;
        unsigned int A = 0;
        unsigned int B = 0;
        unsigned int begin = 0;
        unsigned int end = 0;

        for (int i = 0; i < T; i++) {
                cin >> A;
                cin >> B;
                begin = 0;
                end = 0;
                begin = (unsigned int) ceil( sqrt(A) );
                end = (unsigned int) floor( sqrt(B) );

                cout << (end - begin + 1) << endl;
        }

        return 0;
}


