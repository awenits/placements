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


struct node* createList(int n){
    //for creating list of n elements

    struct node* newHead = NULL;
    struct node* temp;
    int ele;
    if(n!=0)        //for handling empty list scenario if n==0
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
    return newHead;
}


struct node* mergeTwoLists(struct node* list1, struct node* list2){
    if(list1 == NULL) return list2; //if list1 is empty merged list will contain elements from list2 only
    if(list2 == NULL) return list1; //if list2 is empty merged list will contain elements from list1 only

    struct node* head;
    struct node* p1;
    struct node* p2;

    p1 = list1;
    p2 = list2;

    //for selecting head of new node
    if(p1->data > p2->data){
        head = p2;
        p2 = p2->next;
    } else {
        head = p1;
        p1= p1->next;
    }

    struct node* temp = head;

    while(p1 && p2){
        if(p1->data > p2->data){
            temp->next = p2;
            p2 = p2->next;
        } else {
            temp->next = p1;
            p1= p1->next;
        }
        temp = temp->next;
    }
    while(p1){              //if elements exist in p1
        temp->next = p1;
        p1= p1->next;
        temp = temp->next;
    }
    while(p2){              //if elements exist in p2
        temp->next = p2;
        p2= p2->next;
        temp = temp->next;
    }

    return head;
}


void printList(struct node* head){
    //for printing the given linkedlist
    if(!head)
        cout<<"LinkedList is empty!";
    struct node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){

    int n;
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    struct node* temp;

    cout<<"Enter number of elements of 1st sorted LinkedList: ";
    cin>>n;
    //for creating list of n elements
    list1 = createList(n);

    cout<<"Enter number of elements of 2nd sorted LinkedList: ";
    cin>>n;
    //for creating list of n elements
    list2 = createList(n);

    cout<<"List1 : ";
    printList(list1);
    cout<<"List2 : ";
    printList(list2);

    temp = mergeTwoLists(list1, list2);

    cout<<"MergedList : ";
    printList(temp);

    return 0;
}
