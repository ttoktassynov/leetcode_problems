class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        
        for (int i = 0; i < (int) s.size() - maxLen; ++i) {
            int j = i;
            //cout << "i = " << i << endl;
            unordered_set<char> seenSet;
            while (j < (int) s.size() && !seenSet.count(s[j])) {
                //cout << "no repeating character = " << s[j] << " at j = " << j << endl;
                seenSet.insert(s[j++]);
            }
            maxLen = max(maxLen, (int) seenSet.size());
        }
        return maxLen;
    }
};