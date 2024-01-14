#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(string s){
        int n=s.size();
        stack<char>st;
        st.push(s[0]);
        //int i=1;
        for(int i=1;i<n;i++){
            char c=s[i];
            if(c=='('){
                st.push(c);
            }
            else if(!st.empty() && c==')' && st.top() == '(')
            {
                st.pop();
            }
            else{
                st.push(c);
            }

        }
        return st.empty();
    }
    bool f(int i,string s,int size){
        if(i==size){
            return check(s);
        }

        if(s[i] == '*')
        {
            s[i] = '(';
            bool op1 = f(i+1, s, size);
            s[i] = '*';

            s[i] = ')';
            bool op2 = f(i+1, s, size);
            s[i] = '*';

            string tmp1 = s.substr(0, i);
            string tmp2 = s.substr(i+1);
            string n = tmp1 + tmp2;
            bool op3 = f(i+1, n, size);

            return op1 || op2 || op3;
        }
        
        return f(i+1, s, size);
        
    }
    vector<pair<int,string>>dp;
    bool checkValidString(string s) {
        return f(0, s, s.size());
    }
};