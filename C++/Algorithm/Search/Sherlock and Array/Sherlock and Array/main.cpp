//
//  main.cpp
//  Sherlock and Array
//
//  Created by Hoàng Trung Huy on 7/12/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define YES     1
#define NO      0

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int T = 0;
        cin >> T;

        for (int testcase = 0; testcase < T; testcase++) {
                int N = 0;
                cin >> N;
                vector<int> object;
                unsigned long long total = 0;
                for (int i = 0; i < N; i++) {
                        int element = 0;
                        cin >> element;
                        object.push_back(element);
                        total += element;
                }

                bool found = NO;
                unsigned long long leftSum = 0;
                for (int i = 0; i < N; i++) {
                        if ( total - object.at(i) - leftSum == leftSum ) {
                                found = YES;
                                break;
                        }
                        leftSum += object.at(i);
                }
                if (found) {
                        cout << "YES" << endl;
                }
                else
                        cout << "NO" << endl;

        }

        return 0;
}
