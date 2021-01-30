class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        array<int, 128> uniqLettersPos;
        fill(begin(uniqLettersPos), end(uniqLettersPos), -1);
        //cout << uniqLettersPos[0] << endl;
        int startPos = 0, endPos = 0;
        while (endPos < (int) s.size()) {
            char curChar = s[endPos];
            if (uniqLettersPos[curChar] != - 1) {
                startPos = max(startPos, uniqLettersPos[curChar] + 1);
                uniqLettersPos[curChar] = endPos;
            }
            uniqLettersPos[curChar] = endPos++;  
            maxLen = max(maxLen, endPos - startPos);
        }
        return maxLen;
    }
};