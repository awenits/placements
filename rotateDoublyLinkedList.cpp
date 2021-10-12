#include<bits/stdc++.h>
using namespace std;

struct dllnode{
    int data;
    struct dllnode* prev;
    struct dllnode* next;
};


struct dllnode* newNode(int value)
{
    dllnode* temp = new struct dllnode;
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}


struct dllnode* createDLL(int num){
    cout<<"Enter "<<num<<" elements: ";
    int ele;
    struct dllnode* head = NULL;
    struct dllnode* temp;
    struct dllnode* prev;
    for(int i=0; i<num; i++){
        cin>>ele;
        if(!head){
            head = newNode(ele);
            temp = head;
        }
        else{
            temp->next = newNode(ele);
            prev = temp;
            temp = temp->next;
            temp->prev = prev;
        }
    }
    return head;
};


void printDll(struct dllnode* head){
    struct dllnode* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void printReverseDll(struct dllnode* head){
    struct dllnode* endOfDll = head;
    while(endOfDll->next){
        endOfDll = endOfDll->next;
    }
    struct dllnode* temp = endOfDll;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

struct dllnode* rotateDLL(struct dllnode* head, int N){
    struct dllnode* endOfDll = head;
    while(endOfDll->next){
        endOfDll = endOfDll->next;
    }

    struct dllnode* temp = head;
    struct dllnode* newHead;
    for(int i=0; i<N; i++){
        endOfDll->next = temp;
        temp->prev = endOfDll;
        endOfDll = endOfDll->next;
        newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
    }

    return newHead;
}


int main(){
    struct dllnode e = {5, NULL, NULL};
    struct dllnode d = {4, NULL, &e};
    struct dllnode c = {3, NULL, &d};
    struct dllnode b = {2, NULL, &c};
    struct dllnode a = {1, NULL, &b};
    e.prev = &d;
    d.prev = &c;
    c.prev = &b;
    b.prev = &a;

    int num, N;
    cout<<"Enter number of elements of to be stored in Doubly LinkedList: ";
    cin>>num;
    struct dllnode* dList = createDLL(num);

    cout<<"Enter value of N to rotate anticlockwise: ";
    cin>>N;

    cout<<"Given DLL: ";
    printDll(dList);

    //printReverseDll(dList);
    cout<<"Rotated DLL: ";
    struct dllnode* head = rotateDLL(dList, N);
    printDll(head);

    return 0;
}
