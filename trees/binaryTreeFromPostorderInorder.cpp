#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* construct(vector<int>& postorder, unordered_map<int, int>& hmap, int& rootIndex, int left, int right){
    if(left>right) return NULL;

    TreeNode* root = new TreeNode(postorder[rootIndex]);
    rootIndex--;
    int pivot = hmap[root->val];

    root->right = construct(postorder, hmap, rootIndex, pivot+1, right);
    root->left = construct(postorder, hmap, rootIndex, left, pivot-1);


    return root;
}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
    int rootIndex = postorder.size()-1;
    unordered_map<int, int> hmap;
    for(int i=0; i<inorder.size(); i++){
        hmap[inorder[i]] = i;
    }
    return construct(postorder, hmap, rootIndex, 0, inorder.size()-1);
}

void preorder(TreeNode* root){
    if(root){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    TreeNode* root = buildTree(postorder, inorder);
    cout<<"Preorder traversal of constructed tree: ";
    preorder(root);
    cout<<endl;

    return 0;
}