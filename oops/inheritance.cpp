#include<bits/stdc++.h>

using namespace std;

//base class 
class Human{
    private:
        int age;
    public:
        int height;
    protected:
        int weight;
    public:
        int getAge(){
            return this->age;
        }

        void setWeight(int w){
            this->weight = w;
        }
};

//derived class
class Male: public Human{
    public:
        string color;

        void sleep(){
            cout<<"Male Sleeping!"<<endl;
        }

        int getWeight(){
            return this->weight;
        }
};


int main(){
    Male obj1;
    //cout<<obj1.age<<endl;       //Male can't inherit form Human private age
    //cout<<obj1.weight<<endl;    //Male inherited protected weight so can be accesed only within derived class
    cout<<obj1.height<<endl;      //Male inherited public height
    cout<<obj1.color<<endl;       //exist in Male class
    obj1.sleep();
    cout<<obj1.getWeight()<<endl;   //weight can be accessed with the help of getters of class
    return 0;
}