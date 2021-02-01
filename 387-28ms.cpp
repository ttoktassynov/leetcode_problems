class Solution {
public:
    int firstUniqChar(string s) {
        pair<int,int> letInfo[26] = {};
        int firstNonRepPos = (int) s.size();
        // update letter information table with frequencies and first appearance position
        for (int i = 0; i <(int)s.size(); i++) {
            const int letter = (int)s[i] - 'a';
            if (!letInfo[letter].first) {
                letInfo[letter].second = i;
            }
            letInfo[letter].first++;   
        }
        
        for (int i = 0; i < 26; i++){
            if (letInfo[i].first == 1) {
                firstNonRepPos = min(firstNonRepPos, letInfo[i].second);
            }
        }
        return (firstNonRepPos != (int) s.size()) ? firstNonRepPos : -1;
    }
};