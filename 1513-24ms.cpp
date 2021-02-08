class Solution {
public:
    int numSub(string s) {
        long long onesubstrSum = 0, oneCount = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '1'){
                oneCount++;
            }
            if (s[i] == '0' || i == (int) s.size() - 1) {
                //printf("onecount is %d\n", oneCount);
                onesubstrSum += oneCount * (oneCount + 1) / 2;
                oneCount = 0;
            }
        }
        return onesubstrSum % 1'000'000'007;
    }
};