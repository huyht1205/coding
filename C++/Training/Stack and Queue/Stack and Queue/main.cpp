//
//  main.cpp
//  Stack and Queue
//
//  Created by Hoàng Trung Huy on 6/28/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct __node {
        char c;
        struct __node *next;
} node;

class Solution {
        //Write your code here
private:
        node *stkTopPtr = NULL;
        node *stkBotPtr = NULL;
        node *queBackPtr = NULL;
        node *queFrontPtr = NULL;

public:
        void pushCharacter(char c) {
                node *tempPtr = new node;
                tempPtr->c = c;
                if (stkBotPtr == NULL) {
                        tempPtr->next = NULL;
                        stkTopPtr = tempPtr;
                        stkBotPtr = tempPtr;
                }
                else {
                        tempPtr->next = stkTopPtr;
                        stkTopPtr = tempPtr;
                }
        }

        void enqueueCharacter(char c) {
                node *tempPtr = new node;
                tempPtr->c = c;
                if (queBackPtr == NULL) {
                        queBackPtr = tempPtr;
                        queFrontPtr = tempPtr;
                }
                else {
                        queFrontPtr->next = tempPtr;
                        queFrontPtr = tempPtr;
                }
                tempPtr->next = NULL;

        }

        char popCharacter(void) {
                node *tempPtr = stkTopPtr;
                char output = 0;
                if (stkTopPtr != NULL) {
                        output = stkTopPtr->c;
                        stkTopPtr=stkTopPtr->next;
                        delete tempPtr;
                        return output;
                }
                else {
                        return 0;
                }

        }

        char dequeueCharacter(void) {
                node *tempPtr = queBackPtr;
                char output = 0;
                if (stkBotPtr != NULL) {
                        output = queBackPtr->c;
                        queBackPtr=queBackPtr->next;
                        delete tempPtr;
                        return output;
                }
                else {
                        return 0;
                }
                return 0;
        }
};

int main() {
        // read the string s.
        string s;
        getline(cin, s);

        // create the Solution class object p.
        Solution obj;

        // push/enqueue all the characters of string s to stack.
        for (int i = 0; i < s.length(); i++) {
                obj.pushCharacter(s[i]);
                obj.enqueueCharacter(s[i]);
        }

        bool isPalindrome = true;

        // pop the top character from stack.
        // dequeue the first character from queue.
        // compare both the characters.
        for (int i = 0; i < s.length() / 2; i++) {
                if (obj.popCharacter() != obj.dequeueCharacter()) {
                        isPalindrome = false;

                        break;
                }
        }

        // finally print whether string s is palindrome or not.
        if (isPalindrome) {
                cout << "The word, " << s << ", is a palindrome.";
        } else {
                cout << "The word, " << s << ", is not a palindrome.";
        }
        
        return 0;
}
