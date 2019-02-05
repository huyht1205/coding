#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */

        int T = 0;
        cin >> T;
        string A;
        string B;
        bitset<26> charSet_A(0);
        bitset<26> charSet_B(0);

        for (int i = 0; i < T; i++) {
                cin >> A;
                cin >> B;
                charSet_A.reset();
                charSet_B.reset();

                for (int j = 0; (j < A.length() ) && ( !charSet_A.all() ); j++) {
                        charSet_A.set(A[j] - 97);
                }

                for (int j = 0; (j < B.length() ) && ( !charSet_B.all() ); j++) {
                        charSet_B.set(B[j] - 97);
                }

                charSet_A &= charSet_B;
                if (charSet_A.any()) {
                        cout << "YES" << endl;
                }
                else {
                        cout << "NO" << endl;
                }
        }

        return 0;
}