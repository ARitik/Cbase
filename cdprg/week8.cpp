#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*' || c=='/')
    return 2;
    else if(c=='+'||c=='-')
    return 1;
    else 
    return -1;
}
void solve(string s)
{
    stack<char> st;
    string res;
    for(auto c:s)
    {
        if(( c>='a' and c<='z' )||( c>='A' and c<='Z' )||( c>='0' and c<='9' ))
            res+=c;
        else if (c=='(')
            st.push('(');
        else if (c==')')
        {
            while(!st.empty() and st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() and (prec(c)<=prec(st.top())))
            {
                res+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    cout<<res<<"\n";
}
int main()
{
    string exp;
    cout<<"The  inflix  expression : ";
    cin>>exp;  
    cout<<"The postflix expression : ";
    solve(exp);
    return 0;
}
