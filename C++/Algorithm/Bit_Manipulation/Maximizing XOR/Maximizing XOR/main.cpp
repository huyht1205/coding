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
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
        bitset<10> max = l ^ r;

        int index = 9;
        for (; (max[index] == 0) && (index >= 0); --index);
        for (; index >= 0; --index) {
                max.set(index, true);
        }

        return (int) max.to_ulong();
}

int main() {
        int res;
        int _l;
        cin >> _l;

        int _r;
        cin >> _r;

        res = maxXor(_l, _r);
        cout << res;
        
        return 0;
}

