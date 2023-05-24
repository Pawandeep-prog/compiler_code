#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool isDigit(char c){
    return c>='0' && c<='9';
}

int toInt(char c){
    return c-48;
}

int main(){
    string inp;
    int ans=0;
    stack<int> s;

    std::cout<<"enter the postfix expression: ";
    std::cin>>inp;

    int len = inp.length(), t1, t2;

    for(int i=0; i<len; i++){
        if(isDigit(inp[i])){
            s.push(toInt(inp[i]));
        }
        else{
            t1 = s.top();
            s.pop();
            t2 = s.top();
            s.pop();
            if(inp[i]=='+') s.push(t1+t2);
            else if(inp[i]=='-') s.push(t2-t1);
            else if(inp[i]=='*') s.push(t1*t2);
            else s.push(t2/t1);
        }
    }

    ans = s.top();

    std::cout<<"evaluated postfix expression success ...";
    std::cout<<"\nanswer: "<<ans;

    return 0;
}