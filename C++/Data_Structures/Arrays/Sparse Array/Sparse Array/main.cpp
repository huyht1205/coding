#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct __dict {
        string value;
        int count;
} dict;

int main() {
        int N = 0;
        cin >> N;
        string temp;
        bool isAvail = false;

        vector<dict> dictVect;
        for (int i = 0; i < N; ++i) {
                cin >> temp;
                isAvail = false;
                for (int j = 0; j < dictVect.size(); ++j) {
                        if (dictVect[j].value == temp) {
                                dictVect[j].count++;
                                isAvail = true;
                        }
                }
                if (isAvail == false) {
                        dict tempDict;
                        tempDict.value = temp;
                        tempDict.count = 1;
                        dictVect.push_back(tempDict);
                }
        }

        int Q = 0;
        cin >> Q;
        int countResult = 0;

        for (int i = 0; i < Q; ++i) {
                countResult = 0;
                cin >> temp;
                isAvail = false;
                for (int j = 0; j < dictVect.size(); ++j) {
                        if (dictVect[j].value == temp) {
                                countResult = dictVect[j].count;
                                isAvail = true;
                                break;
                        }
                }
                if (isAvail) {
                        cout << countResult << endl;
                }
                else {
                        cout << 0 << endl;
                }
        }

        return 0;
}


