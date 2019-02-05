//
//  main.cpp
//  Deque STL
//
//  Created by Hoàng Trung Huy on 7/14/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

class extDeque : public deque<int> {
public:
        int max() {
                int maxValue = 0;

                for (int i = 0; i < this->size(); i++) {
                        maxValue = std::max(maxValue, this->at(i));
                }

                return maxValue;
        }
};

void printKMax(int arr[], int n, int k){
        //Write your code here.
        extDeque q;

        int maxValue = 0;

        for (int i = 0; i < k; i++) {
                q.push_back(arr[i]);
        }

        maxValue = q.max();
        cout << maxValue << " ";

        for (int i = k; i < n; i++) {
                int temp = q.at(0);
                q.pop_front();
                q.push_back(arr[i]);
                maxValue = std::max(maxValue, arr[i]);
                if (temp == maxValue) {
                        maxValue = q.max();
                }
                cout << maxValue << " ";
        }

        cout << endl;
}
int main(){

        int t;
        cin >> t;
        while(t>0) {
                int n,k;
                cin >> n >> k;
                int i;
                int arr[n];
                for(i=0;i<n;i++)
                        cin >> arr[i];
                printKMax(arr, n, k);
                t--;
        }
        return 0;
}