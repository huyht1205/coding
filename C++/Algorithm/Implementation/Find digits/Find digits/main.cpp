//
//  main.cpp
//  Find digits
//
//  Created by Hoàng Trung Huy on 7/4/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
        int t;
        cin >> t;
        for(int a0 = 0; a0 < t; a0++){
                int n;
                cin >> n;

                int arraySize = int( ceil( log10(n) ) );
                int array[arraySize];

                int temp = n;
                for (int i = 0; i < arraySize; i++) {
                        int div = int ( pow(10, (arraySize-1) - i) );
                        array[i] = int (temp / div);
                        temp %= div;
                }

                int count = 0;
                for (int i = 0; i < arraySize; i++) {
                        if (array[i] != 0) {
                                if (n % array[i] == 0) {
                                        count++;
                                }
                        }
                }

                cout << count << endl;
        }
        return 0;
}


