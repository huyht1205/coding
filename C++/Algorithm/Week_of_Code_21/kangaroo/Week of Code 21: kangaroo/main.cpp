//
//  main.cpp
//  Week of Code 21: kangaroo
//
//  Created by Hoàng Trung Huy on 7/3/16.
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


int main(){
        int x1;
        int v1;
        int x2;
        int v2;
        cin >> x1 >> v1 >> x2 >> v2;


        if ( (x1 < 0) || (x1 > 10000) ||
             (x2 < 0) || (x2 > 10000) ||
             (x1 >= x2) ||
             (v1 < 1) || (v2 < 1) ||
             (v1 > 10000) || (v2 > 10000)
            ) {
                cout << "NO" << endl;
        }
        else {
                if ( v2 >= v1 ) {       // is parallel
                        cout << "NO" << endl;
                }
                else {       // intercept each other at point where number of jump < 0
                        cout << "YES" << endl;
                }

        }
        return 0;
}

