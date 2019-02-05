//
//  main.cpp
//  Mark and Toys
//
//  Created by Hoàng Trung Huy on 7/12/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
        long long n, k; cin >> n >> k;

        vector<int> prices;

        for(int i = 0; i < n; i++)
        {
                int p; cin >> p;
                prices.push_back(p);
        }

        int answer = 0;

        sort(prices.begin(), prices.end());

        long total = 0;
        for (int i = 0; i < n; i++) {
                if (total + prices.at(i) <= k) {
                        total += prices.at(i);
                        answer++;
                }
                else
                        break;
        }

        cout << answer << endl;
        
        return 0;
}

