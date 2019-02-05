//
//  main.cpp
//  And product
//
//  Created by Hoàng Trung Huy on 6/30/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        std::bitset<32> A(0);
        std::bitset<32> B(0);
        unsigned int temp = 0;
        unsigned int result_size = 0;

        unsigned int T = 0;
        std::cin >> T;

        for (int i = 0; i < T; ++i) {
                std::cin >> temp;
                A = temp;
                std::cin >> temp;
                B = temp;

                if ( (A == 0) || (B == 0)) {
                        std::cout << 0 << std::endl;
                }
                else if (A == B) {
                        std::cout << A.to_ulong() << std::endl;
                }
                else {
                        // A & B are checked to be always A <= B
                        if ( log2(A.to_ulong()) <= log2(B.to_ulong()) ) {
                                result_size = log2(A.to_ulong());
                        }
                        else {
                                result_size = log2(B.to_ulong());
                                temp = (unsigned int) A.to_ulong();
                                A = B;
                                B = temp;
                        }

                        // clear high bits of B
                        for (int j = 31; j >= (result_size + 1); --j) {
                                B.reset(j);
                        }

                        if (B == 0) {
                                std::cout << 0 << std::endl;
                        }
                        else {
                                unsigned int diff = (unsigned int) (B.to_ulong() - A.to_ulong());
                                unsigned int index = 0;
                                for (index = 1; diff > (unsigned int) pow(2, index); ++index) {
                                        A.reset(index);
                                }

                                A[0] = 0;
                                for (int j = index; j < result_size - 1; ++j) {
                                        A[j] = B[j] & A[j];
                                }
                                
                                std::cout << (A.to_ulong()) << std::endl;
                        }
                }
        }

        return 0;
}