/*
  Code to print right and left side views of Binary Tree.
*/

#include<bits/stdc++.h>
using namespace std;

struct treenode{
    //structure of a node of tree
    int data;
    struct treenode* left;
    struct treenode* right;
};


struct treenode* newNode(int value)
{
    //function to create a new treenode dynamically
    treenode* temp = new struct treenode;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


struct treenode* insertElement(struct treenode* head, int value, queue<treenode *>& q)
{
    /*function for inserting elements in a tree in level order*/

    //create a new node for the given value
    struct treenode* node = newNode(value);

    if (head == NULL){
        //if tree is empty assigning it as root of the tree
        head = node;
    }
    else if (q.front()->left == NULL){
        //if trees last node's left child is not present assign new node to left of it
        q.front()->left = node;
    }
    else {
        //if trees last node's right child is not present assign new node to right of it
        q.front()->right = node;

        q.pop(); //remove when both the child are assigned
    }

    //insert new node to queue
    q.push(node);


    return head;
}

void rightSideView(treenode* root) {
    vector<int> ans;
    if(!root)
        return;
    queue<treenode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        cout<<q.front()->data<<" ";
        while(size--){
            treenode* front = q.front();
            q.pop();
            if(front->right && front->right->data != INT_MIN)
                q.push(front->right);
            if(front->left && front->left->data != INT_MIN)
                q.push(front->left);
        }
    }
}

void leftSideView(treenode* root) {
    vector<int> ans;
    if(!root)
        return;
    queue<treenode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        cout<<q.front()->data<<" ";
        while(size--){
            treenode* front = q.front();
            q.pop();
            if(front->left && front->left->data != INT_MIN)
                q.push(front->left);
            if(front->right && front->right->data != INT_MIN)
                q.push(front->right);
        }
    }
}

int main(){
    struct treenode* head = NULL;

    //to keep track of nodes while creating tree
    queue<struct treenode*> q;

    /*
                   1
                2     3
              N   5 N   4
        For this tree corresponding vector representation is as follows
        where INT_MIN represents NULL value.
    */
    vector<int> tree = {1,2,3,INT_MIN,5, INT_MIN,4};

    for(auto ele: tree){
      head = insertElement(head, ele, q);
    }

    cout<< "Right Side View: ";
    rightSideView(head);
    cout<<endl;
    cout<< "Left Side View: ";
    leftSideView(head);
    cout<<endl;

    return 0;
}