//
//  main.cpp
//  Quick Sort - In place
//
//  Created by Hoàng Trung Huy on 7/5/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(vector<int> *ar, int lo, int hi);
void quick_sort(vector<int> *ar, int lo, int hi);
void print_vector(vector<int> *ar);

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int n = 0;
        cin >> n;

        vector<int> *ar = new vector<int>;
        int input = 0;

        for (int i = 0; i < n; i++) {
                cin >> input;
                ar->push_back(input);
        }

        quick_sort(ar, 0, (int) ar->size() - 1);

        print_vector(ar);

        return 0;
}

void quick_sort(vector<int> *ar, int lo, int hi) {
        if (lo < hi) {
                int p = partition(ar, lo, hi);
                quick_sort(ar, lo, p - 1);
                quick_sort(ar, p + 1, hi);
        }
}

int partition(vector<int> *ar, int lo, int hi) {
        int p = ar->at(hi);
        int i = lo;
        for (int j = lo; j < hi - 1; j++) {
                if (ar->at(j) <= p) {
                        swap(ar->at(j), ar->at(i));
                        i++;
                }
        }
        swap(ar->at(i), ar->at(hi));

        return i;
}

void print_vector(vector<int> *ar) {
        for (int i = 0; i < ar->size(); i++) {
                cout << ar->at(i) <<  " ";
        }
        cout << endl;
}