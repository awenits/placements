#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    //unordered map implements hashing with separate chaining
    unordered_map<string, float> menu;      
    
    //IMP - to convert into map (sorted keys) just remove unordered_

    //inseting key-value pairs - O(1) time
    menu["maggi"] = 15;
    menu["colddrink"] = 20;
    menu["dosa"] = 99;
    menu["pizza"] = 499;

    //updating value of item
    menu["dosa"] = (1 + 0.10) * menu["dosa"];
    
    //search item
    string item;
    cout<<"Enter the item name: ";
    cin>>item;

    if(menu.count(item) == 0){
        cout<<item<<" is not available!"<<endl;
    }
    else{
        cout<<item<<" is available at price Rs. "<<menu[item]<<endl;
    }

    //deletion
    menu.erase("dosa");

    //iterate on all the items - random ordered
    for(auto item: menu){
        cout<<item.first<<" "<<item.second<<endl;
    }

    return 0;
}