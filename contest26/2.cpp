#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}
vector<string> simplifiedFractions(int n) {
    if (n == 1){
        return {};
    }
    vector<string> res;
    while (n > 1){
        for (int i = 1; i < n; ++i){
            if (gcd(i, n) == 1)
                res.push_back(to_string(i) + "/" + to_string(n));
        }
        n--;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    for (const auto& fraction : simplifiedFractions(n)){
        cout << fraction << " ";
    }
}