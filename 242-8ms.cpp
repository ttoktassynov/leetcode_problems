class Solution {
public:
    bool isAnagram(string s, string t) {
        int used[26] = {};
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < (int) s.size(); i++) {
            used[s[i] - 'a']++;
            used[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (used[i]) return false;
        }
        return true;
    }
};