#include<iostream>
#include<vector>

using namespace std;

int main(){
    //declaration
    vector<int> v;
    cout<<"Size of the declared v: "<<v.size()<<endl;
    cout<<"Capacity of the declared v: "<<v.capacity()<<endl;

    //declation and initialization
    vector<int> arr = {1,2,3,4,5};
    cout<<"Size of the initialized arr: "<<arr.size()<<endl;
    cout<<"Capacity of the initialized arr: "<<arr.capacity()<<endl;

    //inserting element at the end of the vector
    arr.push_back(6);
    cout<<"Size of the arr after inserting an element: "<<arr.size()<<endl;
    cout<<"Capacity of the arr after inserting element: "<<arr.capacity()<<endl;    //2x the previous capacity

    //removes last element
    arr.pop_back();

    //printing all the elements
    for (int i = 0; i < arr.size();i++)
    {   
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //fill constructor - Initialize vector of size 10 with value 7
    vector<int> a(10, 7);

    for (int i = 0; i < a.size();i++)
    {   
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    //2D Vectors - each row can have different number of elements
    vector<vector<int>> arr2d = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9, 10},
        {11, 12}
    };

    //access and update value - 1 changes to 11
    arr2d[0][0] += 10;

    //printing 2d vector
    for (int i = 0; i < arr2d.size(); i++)
    {
        //for each loop
        for (int n: arr2d[i])
        {
            cout<<n<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}