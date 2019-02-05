//
//  main.cpp
//  Jesse-and-cookies
//
//  Created by Hoàng Trung Huy on 7/27/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */

        int N; cin >> N;
        int K; cin >> K;

        vector<int> input_vector;
        for (int i = 0; i < N; i++) {
                int input ; cin >> input;
                input_vector.push_back(input);
        }

        sort(input_vector.begin(), input_vector.end());

        cout << input_vector.size() << endl;
        input_vector.erase(input_vector.begin());
        cout << input_vector.size() << endl;

        return 0;
}