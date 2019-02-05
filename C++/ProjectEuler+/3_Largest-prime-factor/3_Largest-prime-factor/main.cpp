//
//  main.cpp
//  3_Largest-prime-factor
//
//  Created by Hoàng Trung Huy on 8/3/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int n);

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T; cin >> T;

	while (T--) {
		unsigned long long input; cin >> input;
		unsigned long long maxPrime = input;

		while (maxPrime > 1) {

			maxPrime--;
		}

		cout << maxPrime << endl;
	}

	return 0;
}

bool is_prime(int n) {
	

	return false;
}