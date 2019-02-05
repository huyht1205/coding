//
//  main.cpp
//  restaurant
//
//  Created by Hoàng Trung Huy on 7/29/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int calculate_gcd(int big, int small) {
        while (big % small != 0) {
                int temp = big % small;
                big = max(temp, small);
                small = min(temp, small);
        }
        return small;
}

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int T; cin >> T;
        while (T--) {
                int p, q;
                cin >> p >> q;
                unsigned int mulResult = p * q;
                int smaller = min(p, q);
                int bigger = max(p, q);
                int gcd = calculate_gcd(bigger, smaller);
                cout << ( mulResult / (gcd * gcd) ) << endl;
        }

        return 0;
}


