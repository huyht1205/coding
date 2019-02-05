//
//  main.cpp
//  Vector Sort
//
//  Created by Hoàng Trung Huy on 7/15/16.
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
        int N = 0;
        cin >> N;

        vector<int> answer;
        for (int i = 0; i < N; i++) {
                int input;
                cin >> input;
                answer.push_back(input);
        }

        sort(answer.begin(), answer.end());

        for (int i = 0; i < answer.size(); i++) {
                cout << answer.at(i) << " ";
        }
        cout << endl;

        return 0;
}


