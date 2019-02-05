//
//  main.cpp
//  Sherlock_and_Divisors
//
//  Created by Hoàng Trung Huy on 7/18/16.
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

        int T;
        cin >> T;

        for (int i = 0; i < T; i++) {
                int n;
                cin >> n;

                int count = 0;
                int limit = (int) floor(sqrt(n));
                if ( (n != 0) && (n % 2 == 0) ) {
                        for (int i = 1; i <= limit; i++) {
                                if (n % i == 0) {
                                        if (i % 2 ==0) {
                                                count++;
                                        }
                                        if ( (n / i) % 2 == 0 ) {
                                                count++;
                                        }
                                        if ( (n / i) == i ) {
                                                count--;
                                        }
                                }
                        }
                }
                cout << count << endl;
        }

        return 0;
}


