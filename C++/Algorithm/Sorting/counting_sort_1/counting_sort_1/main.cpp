//
//  main.cpp
//  counting_sort_1
//
//  Created by Hoàng Trung Huy on 7/7/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct __countingElement {
        int value;
        int count;
}countingElement;

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */

        int n = 0;
        cin >> n;

        countingElement *a[n];

        bool found;
        for (int i = 0; i < n; i++) {
                int input = 0;
                cin >> input;
                found = false;
                for (int j = 0; j < i; j++) {
                        if (input == a[j]->value) {
                                a[i] = a[j];
                                a[i]->count++;
                                found = true;
                                break;
                        }
                }
                if (found == false) {
                        a[i]->value = input;
                        a[i]->count = 0;
                }

        }
        return 0;
}
