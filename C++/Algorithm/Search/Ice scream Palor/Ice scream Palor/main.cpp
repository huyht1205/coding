//
//  main.cpp
//  Ice scream Palor
//
//  Created by Hoàng Trung Huy on 7/13/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

typedef struct __node{
        int value;
        int indice;
        bool operator() (__node i, __node j) { return (i.value < j.value);}
}node;

bool comparator (node i, node j) {
        return (i.value < j.value);
}

bool findingConsition (int i, node j) {
        return (i == j.value);
}

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int T = 0;
        cin >> T;
        for (int testCase = 0; testCase < T; testCase++) {
                int M = 0;
                int N = 0;
                cin >> M >> N;

                vector<node> flavour;
                for (int i = 0; i < N; i++) {
                        node input;
                        cin >> input.value;
                        input.indice = i + 1;
                        flavour.push_back(input);
                }

                stable_sort(flavour.begin(), flavour.end(), comparator);

                bool found = false;
                int answer[2];

                int lowBound = 0;
                int highBound = N - 1;
                for (int i = 0; (i < N) && (flavour.at(i).value <= (M - 1)); i++) {
                        answer[0] = flavour.at(i).indice;
                        int target = M - flavour.at(i).value;
                        lowBound = i;
                        highBound = N - 1;
                        while (lowBound < highBound) {
                                int considering = (int) floor( (highBound - lowBound) / 2);
                                if (flavour.at(considering).value < target) {
                                        highBound = considering;
                                }
                                else if (flavour.at(considering).value > target) {
                                        lowBound = considering;
                                }
                                else {
                                        found = true;
                                        answer[1] = flavour.at(considering).indice;
                                        break;
                                }
                        }
                        if (found) {
                                cout << answer[0] << " " << answer[1] << endl;
                                break;
                        }
                }
        }

        return 0;
}