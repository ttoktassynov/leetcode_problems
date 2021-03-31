class Solution {
public:
    bool isPalindrome(const string& s, int remove) {
        int n = (int) s.size();
        int start = 0, end = n - 1;
        while (start < end) {
           if (start != remove && end != remove && s[start] != s[end]) {
               return false;
           }
            else if( start == remove) {
                start++;
            }
            else if (end == remove) {
                end--;
            }
            else {
                start++;
                end--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = (int) s.size();
        for (int i = 0; i < s.size(); i++) {
            if (isPalindrome(s, i)) {
                return true;
            }
        }
        return false;
    }
};