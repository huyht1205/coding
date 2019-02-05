//
//  main.cpp
//  Equal Stacks
//
//  Created by Hoàng Trung Huy on 7/4/16.
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
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int get_height(vector<int> stack);
bool is_equal(int a, int b, int c);

int main(){
        int n[3];

        for (int i = 0; i < 3; i++) {
                cin >> n[i];
        }

        vector<int> h[3];
        for (int i = 0; i < 3; i++) {
                h[i] = vector<int> (n[i]);
                for(int j = (n[i] - 1); j >= 0; j--){
                        cin >> h[i][j];
                }
        }

        int height[3];
        for (int i = 0; i < 3; i++) {
                height[i] = get_height(h[i]);
        }

        //int highest = max( height[0], max(height[1], height[2] ) );
        int target = min( height[0], min (height[1], height[2]) );
        while ( !is_equal( height[0], height[1], height[2] ) ) {
                for (int i = 0; i < 3; i++) {
                        while (height[i] > target) {
                        //if ( height[i] == highest) {
                                height[i] -= h[i].back();
                                h[i].pop_back();
                        }
                }
                //if (highest == 0) {
                if (target == 0)
                        break;
                //highest = max( height[0], max(height[1], height[2] ) );
                target = min( height[0], min (height[1], height[2]) );
        }

        //cout << highest << endl;
        cout << target << endl;

        return 0;
}

int get_height(vector<int> stack) {
        int sum = 0;
        for (int i = 0; i < stack.size(); i++) {
                sum += stack[i];
        }

        return sum;
}

bool is_equal(int a, int b, int c) {
        return ( (a == b) && (b == c) );
}