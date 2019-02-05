//
//  main.cpp
//  String_Stream
//
//  Created by Hoàng Trung Huy on 7/28/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
        // Complete this function
        stringstream target;
        target << str;

        vector<int> result;
        int temp;
        while (target >> temp) {
                char skip_comma;
                result.push_back(temp);
                target >> skip_comma;
        }

        return result;
}

int main() {
        string str;
        cin >> str;
        vector<int> integers = parseInts(str);
        for(int i = 0; i < integers.size(); i++) {
                cout << integers[i] << "\n";
        }
        
        return 0;
}

