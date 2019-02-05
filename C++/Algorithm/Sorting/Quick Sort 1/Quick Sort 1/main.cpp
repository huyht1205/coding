//
//  main.cpp
//  Quick Sort 1
//
//  Created by Hoàng Trung Huy on 7/5/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void partition(vector <int> *ar) {
        // Enter code for partitioning and printing here.
        int p = ar->front();
        vector<int> left, right;

        for (int i = 1; i < ar->size(); i++) {
                if (ar->at(i) < p) {
                        left.push_back(ar->at(i));
                }
                else if (ar->at(i) > p) {
                        right.push_back(ar->at(i));
                }
        }

        if (left.size() > 1) {
                partition(&left);
        }
        if (right.size() > 1) {
                partition(&right);
        }

        vector<int> new_ar;

        for (int i = 0; i < left.size(); i++) {
                cout << left.at(i) << " ";
                new_ar.push_back(left.at(i));
        }

        cout << p << " ";
        new_ar.push_back(p);

        for (int i = 0; i < right.size(); i++) {
                cout << right.at(i) << " ";
                new_ar.push_back(right.at(i));
        }
        cout << endl;

        *ar = new_ar;
}
int main(void) {
        vector <int>  _ar;
        int _ar_size;
        cin >> _ar_size;

        for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
                int _ar_tmp;
                cin >> _ar_tmp;
                _ar.push_back(_ar_tmp);
        }
        
        partition(&_ar);
        
        return 0;
}


