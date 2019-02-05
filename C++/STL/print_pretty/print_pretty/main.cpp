//
//  main.cpp
//  print_pretty
//
//  Created by Hoàng Trung Huy on 7/25/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
        int T; cin >> T;
        //cout << setiosflags(ios::uppercase);
        //cout << setw(0xf) << internal;
        while(T--) {
                double A; cin >> A;
                double B; cin >> B;
                double C; cin >> C;
                cout.unsetf(ios_base::uppercase);
                cout << left << hex << showbase << (int) A << endl;
                cout << right << setfill('_') << showpos << setprecision(2) << fixed << setw(15) << B << endl;
                cout.unsetf(ios_base::showpos);
                cout << left << setprecision(9) << scientific << C;
        }
        return 0;
        
}