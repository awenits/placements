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


void printTreeFromMaxLevel(struct treenode* head){
    /*
        Prints tree in Max to Min Level and left to right order.
        Idea is to push elements of tree in stack by level order
        first right child then left child and then pop/print the
        the elements of stack till elements are present in the stack.
    */

    stack<int> s;

    if(head){
        queue<struct treenode*> q;
        int n;
        q.push(head);
        while(!q.empty()){
            n = q.size();
            for(int i=0; i<n; i++){
                if(q.front()->right) q.push(q.front()->right);  //push right child to queue
                if(q.front()->left) q.push(q.front()->left);    //push left child to queue
                s.push(q.front()->data);                        //push the element to stack
                q.pop();
            }
        }
    }

    //pop/print elements of stack
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}


int main(){

    int n, ele;
    struct treenode* head = NULL;

    //to keep track of nodes while creating tree
    queue<struct treenode*> q;

    cout<< "Enter the number of elements (greater than 3) to be added in tree: ";
    cin >> n;
    cout<<"Enter the "<<n<<" elements: ";

    for(int i=1; i<=n; i++){
      cin>>ele;
      head = insertElement(head, ele, q);
    }

    cout<< "Required Output: ";
    printTreeFromMaxLevel(head);
    cout<<endl;

    return 0;
}
