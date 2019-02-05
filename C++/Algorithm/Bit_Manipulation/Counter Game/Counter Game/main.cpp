//
//  main.cpp
//  Counter Game
//
//  Created by Hoàng Trung Huy on 7/1/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int T = 0;
        bitset<64> N(0);
        unsigned long long int input = 0;
        int mostBit = 0;
        int count = 0;
        cin >> T;

        for (int i = 0; i < T; i++) {
                cin >> input;
                N = input;
                for (mostBit = 63; ( !N.test(mostBit) ) && (mostBit >= 0) ; mostBit--);

                for (count = 0; N.to_ullong() != 1; count++) {
                        N.reset(mostBit);
                        if (N == 0 ) {
                                mostBit--;
                                N.set(mostBit);
                        }
                        else {
                                if (mostBit != 0) {
                                        for (; ( !N.test(mostBit) ) && (mostBit >= 0) ; mostBit--);
                                }
                        }
//                        cout << "Most bit: " << mostBit << endl;
//                        cout << N << endl;
                }
                if (count % 2 != 0) {
                        cout << "Louise" << endl;
                }
                else {
                        cout << "Richard" << endl;
                }
        }

        return 0;
}


