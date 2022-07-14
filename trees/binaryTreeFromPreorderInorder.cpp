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


TreeNode* construct(vector<int>& preorder, unordered_map<int, int>& hmap, int& rootIndex, int left, int right){
    if(left>right) return NULL;

    TreeNode* root = new TreeNode(preorder[rootIndex]);
    rootIndex += 1;
    int pivot = hmap[root->val];

    root->left = construct(preorder, hmap, rootIndex, left, pivot-1);
    root->right = construct(preorder, hmap, rootIndex, pivot+1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> hmap;
    for(int i=0; i<inorder.size(); i++){
        hmap[inorder[i]] = i;
    }
    int rootIndex = 0;
    return construct(preorder, hmap, rootIndex, 0, inorder.size()-1);
}

void postorder(TreeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};

    TreeNode* root = buildTree(preorder, inorder);
    cout<<"Postorder traversal of constructed tree: ";
    postorder(root);
    cout<<endl;
    
    return 0;
}