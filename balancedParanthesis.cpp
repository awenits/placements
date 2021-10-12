#include<bits/stdc++.h>
using namespace std;

bool checkBalanced(string paranthesisString){
    stack<char> st;

    for(char c: paranthesisString){
        if(c == '{' || c == '[' || c == '('){
            st.push(c);
        }
        else{
            if(st.empty()){
                return false;
            }
            else{
                char x = st.top();
                if(!((x == '{' && c == '}') || (x == '[' && c == ']') || (x == '(' && c == ')'))){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
    }

    if(!st.empty()){
        return false;
    }

    return true;
}

int main(){
    string paranString;
    cout<<"Enter the paranthesis string: ";
    cin>>paranString;
    if(checkBalanced(paranString)){
        cout<<paranString<<" "<<"is balanced."<<endl;
    }
    else
    {
        cout<<paranString<<" "<<"is not balanced."<<endl;
    }
    return 0;
}
