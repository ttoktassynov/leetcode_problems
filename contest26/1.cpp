#include <iostream>
using namespace std;
int maxPower(string s){
    int res = 0;
    int cur = 1;
    for (size_t i = 1; i < s.size(); ++i){
        if (s[i] != s[i - 1]){
            res = max(res, cur);
            cur = 1;
        }
        else{
            ++cur;
        }
    }
    return max(res, cur);
}
int main(){
    string s;
    cin >> s;
    cout << maxPower(s) << endl;
}