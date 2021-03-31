class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        int n = end - start + 1;
        for (int k = start; k <= start + (end - start) / 2; k++ ){
            if (s[k] != s[end - k + start]) {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = (int) s.size();
        for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
            if (s[i] != s[j]) {
                return (isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1));
            }
        }
        return true;
    }
};