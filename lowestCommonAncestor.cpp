#include<bits/stdc++.h>
using namespace std;

struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
};



int main(){

}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //pp stores the max value while qq stores min of the values to be searched
    int pp = max(p->val,q->val);
    int qq = min(p->val,q->val);

    //As root can be descendent of itself
    //so if any(of pp or qq) equals root value root will be LCA
    if(root->val == pp || root->val == qq){return root;}

    //if both values lies on two different sides
    //then ofcourse root is the LCA
    if(root->val > qq && root->val < pp){return root;}

    //If both values lies in leftSubtree
    if(pp < root->val){
        return lowestCommonAncestor(root->left, p, q);
    }

    //If both values lie in rightSubtree
    if(qq > root->val){
        return lowestCommonAncestor(root->right, p, q);
    }

    //our answer willn't depend upon this return value
    //only returning to satisfy fn need
    //can be any TreeNode* value
    return root;

}

