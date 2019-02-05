//
//  main.cpp
//  Is this a binary search tree
//
//  Created by Hoàng Trung Huy on 7/13/16.
//  Copyright © 2016 Hoàng Trung Huy. All rights reserved.
//
#include <iostream>
#include <vector>

#define BST     true
#define NO_BST  false

using namespace std;

struct Node {
        int data;
        Node* left;
        Node* right;

        Node() {
                this->data = -1;
                this->left = NULL;
                this->right = NULL;
        }
};

class Tree {

public:
        // List of node data values:
        std::vector<int> values;
        // Total number of nodes in the tree:
        int count;

        Tree() {
                this->count = 0;
        }
        /* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

         The Node struct is defined as follows:
         struct Node {
         int data;
         Node* left;
         Node* right;
         }
         */
        int max_data (Node *root) {
                if (root->left == NULL) {
                        if (root->right == NULL) {
                                return root->data;
                        }
                        else {
                                return max(root->data, max_data(root->right));
                        }
                }
                else {
                        if (root->right == NULL) {
                                return max(root->data, max_data(root->left));
                        }
                        else {
                                return max(root->data, max(max_data(root->left), max_data(root->right)));
                        }
                }
        }

        int min_data (Node *root) {
                if (root->left == NULL) {
                        if (root->right == NULL) {
                                return root->data;
                        }
                        else {
                                return min(root->data, min_data(root->right));
                        }
                }
                else {
                        if (root->right == NULL) {
                                return min(root->data, min_data(root->left));
                        }
                        else {
                                return min(root->data, min(min_data(root->left), min_data(root->right)));
                        }
                }
        }

        bool checkBST(Node* root) {
                bool left = false;
                bool right = false;
                if (root->left != NULL) {
                        if (max_data(root->left) < root->data) {
                                left = checkBST(root->left);
                        }
                        else {
                                return false;
                        }
                }
                else {
                        left = true;
                }

                if (root->right != NULL) {
                        if (min_data(root->right) > root->data) {
                                right = checkBST(root->right);
                        }
                        else {
                                return false;
                        }

                }
                else {
                        right = true;
                }

                return left && right;
        }

        void inOrder (Node* root, int levels) {

                if(root != NULL) {
                        // If there are still unfilled levels, fill left subtree:
                        if (levels > 0) {
                                // Create a new left child node:
                                root->left = new Node();
                                inOrder(root->left, levels - 1);
                        }

                        // Set node data:
                        root->data = values.at(count);
                        count++;

                        // If there are still unfilled levels, fill right subtree:
                        if (levels > 0) {
                                // Create a new right child node:
                                root->right = new Node();
                                inOrder(root->right, levels - 1);
                        }
                }
        }

};

int main(int argc, char *argv[]) {
        int height;
        cin >> height;

        // Read data values for tree's nodes:
        Tree* tree = new Tree();
        int value;
        while (cin >> value){
                tree->values.push_back(value);
        }
        
        // Fill tree:
        Node* root = new Node(); 
        tree->inOrder(root, height);
        
        // Print result:
        if(tree->checkBST(root) == true) {
                cout << "Yes";
        }
        else {
                cout << "No";
        }
}