#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    //for creating new nodes
    struct node* temp = new struct node;
    temp->data = data;
    temp->next = NULL;
    return temp;
};

struct node* createCircularList(int n){
    //for creating list of n elements

    struct node* newHead = NULL;
    struct node* temp;
    int ele;

    cout<<"Enter the elements: ";

    for(int i=0; i<n; i++){
        cin>>ele;
        if(i==0){
            newHead = createNode(ele);
            temp = newHead;
        }
        else{
            temp->next = createNode(ele);
            temp = temp->next;
        }
    }
    temp->next = newHead;
    return newHead;
}


void printCircularList(struct node* head){
    if(!head){
        cout<<"LinkedList is Empty!";
    }
    else{
        cout<<head->data<<" ";
        struct node* pointer=head->next;
        while(pointer != head){
            cout<<pointer->data<<" ";
            pointer = pointer->next;
        }
    }
    cout<<endl;
}

int lenOfCircularList(struct node* head){
    if(!head){
        return 0;
    }
    int len=1;

    struct node* pointer=head->next;
    while(pointer != head){
        len++;
        pointer = pointer->next;
    }
    return len;
}

vector<struct node*> splitCircularList(struct node* circularList){

    vector<struct node*> result(2, NULL);

    if(!circularList){
        cout<<"Given Circular List is empty!\n";
        return result;
    }

    int lenOfList = lenOfCircularList(circularList);

    struct node* endOfList1 = NULL;
    struct node* current = circularList;

    for(int i=0; i<lenOfList/2; i++){
        endOfList1 = current;
        current = current->next;
    }

    endOfList1->next = circularList;
    result[0] = circularList;
    result[1] = current;

    while(current->next != circularList){
        current = current->next;
    }
    current->next = result[1];

    return result;
}




int main(){

    //driver code
    int n;
    struct node* circularList = NULL;

    cout<<"Enter number of elements(Even) of circular LinkedList: ";
    cin>>n;

    if(n != 0)
        circularList = createCircularList(n);

    cout<<"Circular List: ";
    printCircularList(circularList);

    //two splitted lists stored in vector/array
    vector<struct node*> result = splitCircularList(circularList);

    cout<<"Splitted circular List1: ";
    printCircularList(result[0]);
    cout<<"Splitted circular List2: ";
    printCircularList(result[1]);

    return 0;
}
