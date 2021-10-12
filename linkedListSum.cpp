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

struct node* createListFromNum(int n){
    //for creating list of given integer
    struct node* newHead = NULL;
    struct node* temp;
    int remainder;
    while(n != 0){
        remainder = n % 10;
        n = n / 10;
        if(newHead == NULL){
            newHead = createNode(remainder);
            temp = newHead;
        }
        else{
            temp->next = createNode(remainder);
            temp = temp->next;
        }
    }

    return newHead;
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


int lenOfList(struct node* head){
    if(!head){
        return 0;
    }
    int len=0;

    struct node* pointer=head;
    while(pointer){
        len++;
        pointer = pointer->next;
    }
    return len;
}

struct node* addNumbersFromTwoLists(struct node* num1List, struct node* num2List){

    struct node* addListHead = NULL;
    struct node* temp = addListHead;
    struct node* p1 = num1List;
    struct node* p2 = num2List;
    int addition;
    int carry=0, n;
    while(p1 || p2){
        if(p1 && p2)
            addition = p1->data + p2->data + carry;
        else if(p1 && !p2)
            addition = p1->data + carry;
        else if(p2 && !p1)
            addition = p2->data + carry;

        if(addition >= 10){
            carry = addition / 10;
            addition = addition % 10;
        }

        if(!addListHead){
            addListHead = createNode(addition);
            temp = addListHead;
        }
        else{
            temp->next = createNode(addition);
            temp = temp->next;
        }
        if(p1)
            p1 = p1->next;
        if(p2)
            p2 = p2->next;
    }
    cout<<carry<<endl;

    return addListHead;
}


int main(){
    int num1, num2;
    cout<<"Enter the 1st Number: ";
    cin>>num1;
    struct node* num1List = createListFromNum(num1);
    cout<<"Enter the 2nd Number: ";
    cin>>num2;
    struct node* num2List = createListFromNum(num2);

    cout<<"Number 1: ";
    printList(num1List);
    cout<<"Number 2: ";
    printList(num2List);

    struct node* additionList = addNumbersFromTwoLists(num1List, num2List);
    cout<<"Addition List: ";
    printList(additionList);

    return 0;
}

