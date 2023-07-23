#include <unordered_set>
#include <string> 
#include <vector>
#include <algorithm>
using namespace std;
bool canConnect(const string& first, const string& second) {
    return first[1] == second[0];
}

bool checkConnection(vector<string>& connect, const string& next_string) {
    if (connect.empty())
        return true;
    
    string prev_string = connect.back();
    return canConnect(prev_string, next_string);
}
string solution(vector<string> &A) {
    int n = A.size();
    string ans_string(n, '0');
    unordered_set<string> stringSet(A.begin(), A.end());
    
    vector<string> connect;
    
    for (int k = 0; k < n; k++) {
        if (checkConnection(connect, A[k])) {
            connect.push_back(A[k]);
            ans_string[k] = '1';
        }
    }
    
    return ans_string;
}
