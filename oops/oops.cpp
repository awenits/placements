#include<bits/stdc++.h>

using namespace std;

class Hero {
    //properties
        int health;     //default private
    public:
        
        int level;

        Hero(){
            cout<<"Constructer Called!"<<endl;
        }
        
        Hero(int level, int health){
            this->level = level;
            this->health = health;
        }

        //replaces default copy constructor
        Hero(Hero& temp){
            cout<<"Copy constructor called!"<<endl;
            this->level = temp.level;
            this->health = temp.health;
        }

        void prnt(){
            cout<<"Level and Health: "<<this->level<<" "<<this->health<<endl;
        }

        //setters and getters
        int getHealth(){
            return health;
        }

        void setHealth(int n){
            health = n;
        }
};


int main(){
    //static allocation 
    Hero h1;                    //Also calls default constructor
    cout<<sizeof(h1)<<endl;
    //cout<<h1.health<<endl;    //private member can't access
    cout<<h1.level<<endl;       //garbage value 
    h1.level = 5;
    cout<<"Level "<<h1.level<<endl;
    h1.setHealth(90);
    cout<<"Health "<<h1.getHealth()<<endl;

    //dynamic allocation
    Hero* p = new Hero;             //calls default constructor
    p->level = 6;
    p->setHealth(100);
    cout<<"Level and Health: "<<p->level<<" "<<p->getHealth()<<endl;

    //calls parameterized constructor
    Hero* d = new Hero(7, 95);
    d->prnt(); 

    Hero shri(2, 50);
    shri.prnt();
    Hero vishnu(shri); //calls copy constructor
    vishnu.prnt();

    return 0;
}