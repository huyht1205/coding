//
//  main.cpp
//  1_Multiples of 3 and 5
//
//  Created by Hoàng Trung Huy on 8/1/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long sum_type;

//#define MY_DEBUG

sum_type sum_arithmetic_seq(unsigned int first, unsigned int diff, unsigned int last);
unsigned int find_last(unsigned int a, unsigned int diff);

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int T; cin >> T;

        while (T--) {
                int N; cin >> N;
                sum_type sum = 0;
                unsigned int last_3 = find_last(N - 1, 3);
                unsigned int last_5 = find_last(N - 1, 5);
                unsigned int last_15 = find_last(N - 1, 15);

                sum_type sumSeq_3 = sum_arithmetic_seq(0, 3, last_3);
                sum_type sumSeq_5 = sum_arithmetic_seq(0, 5, last_5);
                sum_type sumSeq_15 = sum_arithmetic_seq(0, 15, last_15);

                sum = sumSeq_3 + sumSeq_5 - sumSeq_15;

                cout << sum << endl;
        }

        return 0;
}

sum_type sum_arithmetic_seq(unsigned int first, unsigned int diff, unsigned int last) {
        sum_type sum = 0;
        unsigned int n = ( (last - first) / diff) + 1;

        sum = ( (sum_type) n * (last - first) ) / 2 ;   

#ifdef MY_DEBUG
        cout << fixed << "n " << n << " | " << "Diff " << diff << " | " << "Last " << last << " : " << fixed << sum << endl;
#endif

        return sum;
}

unsigned int find_last(unsigned int a, unsigned int diff) {
        unsigned int last = a;
        while (last % diff != 0) {
                last--;
        }
        return last;
}