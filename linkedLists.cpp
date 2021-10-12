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

struct treenode* insertElement(struct treenode* root, int value, queue<treenode *>& q)
{
    struct treenode* node = newNode(value);
    if (root == NULL)
        root = node;

    else if (q.front()->left == NULL){
          q.front()->left = node;
    }
    else {
        if(q.front()->left->data == -1) {
            delete q.front()->left;
            q.front()->left = NULL;
        }
        if(value != -1)
            q.front()->right = node;
        q.pop();
    }
    if(value != -1)
      q.push(node);
    return root;
}

void levelOrderTraversal(struct treenode* node) {
    if(node){
        queue<struct treenode*> q;
        struct treenode* temp;
        int n;
        q.push(node);
        while(!q.empty()){
            n = q.size();
            for(int i=0; i<n; i++){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                cout<<q.front()->data<<" ";
                q.pop();
            }
        }

    }
}

void inorderTraversal(struct treenode* node) {
    if(node){
        inorderTraversal(node->left);
        cout<<node->data <<" ";
        inorderTraversal(node->right);
    }
}


void postorderTraversal(struct treenode* node) {
    if(node){
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout<<node->data <<" ";
    }
}


int main(){

    vector<int> elements;
    int n, ele;
    struct treenode* root = NULL;
    queue<struct treenode*> q;
    cout<< "Enter the number of elements to be added: ";
    cin >> n;
    for(int i=1; i<=n; i++){
      cout<<"Enter the element" <<i<<": ";
      cin>>ele;
      root = insertElement(root, ele, q);
    }

    cout<< "Level order Traversal of the tree formed: ";
    levelOrderTraversal(root);
    cout<<endl;
    cout<< "Inorder Traversal of the tree formed: ";
    inorderTraversal(root);
    cout<<endl;
    cout<< "Postorder Traversal of the tree formed: ";
    postorderTraversal(root);
    cout<<endl;

    return 0;
}
