//
//  main.cpp
//  Maximum subarray
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

        for (int i = 0; i < T; i++) {
                unsigned int N = 0;
                cin >> N;
                int arr[N];

                for (unsigned int j = 0; j < N; j++) {
                        cin >> arr[j];
                }

                int contSum = arr[0];        // continuous sum
                int sepaSum = arr[0];        // non-continuous sum
                int currentSum = arr[0];
                for (unsigned int j = 1; j < N; j++) {

                        // Calculate continuous sum
                        if ( (contSum + arr[j] ) > contSum ) {
                                contSum += arr[j];
                        }
                        else if (contSum <= arr[j]) {
                                contSum = arr[j];
                        }

                        // Calculate non-continuous sum
                        if ( (currentSum + arr[j]) > arr[j] ) {
                                currentSum+= arr[j];
                        }
                        else {
                                currentSum = arr[j];
                        }
                        if (currentSum > sepaSum) {
                                sepaSum = currentSum;
                        }
                }

                cout << sepaSum <<  " " << contSum << endl;
        }

        return 0;
}