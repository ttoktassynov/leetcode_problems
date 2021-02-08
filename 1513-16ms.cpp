class Solution {
public:
    int numSub(string s) {
        int onesubstrSum = 0, oneCount = 0, mod = (int) 1e9 + 7;
        for (int i = 0; i < (int) s.size(); i++) {
            oneCount = s[i] == '1' ? (oneCount + 1) : 0;
            onesubstrSum = (onesubstrSum + oneCount) % mod;
        }
        return onesubstrSum;
    }
};