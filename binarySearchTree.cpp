#include<bits/stdc++.h>
using namespace std;

struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
};

struct treenode* newNode(int value)
{
    treenode* temp = new struct treenode;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorderTraversal(struct treenode* node, vector<struct treenode*> &q) {
    if(node){
        inorderTraversal(node->left, q);
        q.push_back(node);
        inorderTraversal(node->right, q);
    }
}


struct treenode* insertElement(struct treenode* root, int value)
{
    if (root == NULL)
        return newNode(value);

    else if (root->data > value){
        root->left = insertElement(root->left, value);
    }
    else {
        root->right = insertElement(root->right, value);
    }

    return root;
}

struct treenode* searchElement(struct treenode* root, int value)
{
    if (root->data == value)
        return root;

    else if (root->data > value){
        return searchElement(root->left, value);
    }
    else {
        return searchElement(root->right, value);
    }
}

struct treenode* inorderSuccessor(struct treenode* r, struct treenode* p){
    vector<struct treenode*> q;
    inorderTraversal(r, q);
    for(int i=0; i<q.size(); i++){
        if(q[i]->data == p->data){
            if((i+1) != q.size()){
                return q[i+1];
            }
        }
    }
    return NULL;
}


int main(){
    int n, ele;
    struct treenode* r = NULL;
    struct treenode* p = NULL;
    cout<< "Enter the number of elements to be added in BST: ";
    cin >> n;
    for(int i=1; i<=n; i++){
      cout<<"Enter the element" <<i<<": ";
      cin>>ele;
      r = insertElement(r, ele);
    }

    cout<<"r points to: "<<r->data<<endl;

    cout<< "Enter the number to which pointer p points: ";
    cin >> ele;
    p = searchElement(r, ele);

    struct treenode* in = inorderSuccessor(r, p);
    if(!in)
        cout<<"No inorder successor Present for :"<<p->data<<endl;
    else{
        cout<<"Inorder successor of "<<p->data<<" is: ";
        cout<<in->data;
    }

    return 0;
}
