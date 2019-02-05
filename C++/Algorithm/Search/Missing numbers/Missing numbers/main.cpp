//
//  main.cpp
//  Missing numbers
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

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */

        int input;
        int n[2] = {0, 0};
        vector<int> arr[2];
        int minNum = 0;

        for (int i = 0; i < 2; i++) {
                cin >> n[i];
                for (int j = 0; j < n[i]; j++) {
                        cin >> input;
                        if (j == 2) {
                                minNum = min(minNum, input);
                                cout << minNum << endl;
                        }
                        arr[i].push_back(input);
                }
        }

        int missing = n[1] - n[0];

        bitset<100> set[2];
        for (int i = 0; i < 2; i++) {
                for (int j = 0; j < n[i]; j++) {
                        set[i].set(arr[i][j] - minNum);
                }
        }

        vector<int> result;
        set[0] ^= set[1];

        int count = (int) set[0].count();
        for (int i = 0; (i < 100) || (count > 0); i++) {
                if (set[0].test(i)) {
                        result.push_back(minNum + i);
                        count--;
                }
        }
        for (int i = 0; i < result.size(); i++) {
                cout << result.at(i) << " ";
        }
        cout << endl;

        missing -= set[0].count();

        return 0;
}


