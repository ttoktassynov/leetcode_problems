class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> used;
        ostringstream oss;
        for (auto letter : s) { // O(n)
            used[letter]++;
        }
            
        for (int i = 0 ; i < (int) used.size(); i++) { // O(|alphabet|)
            int maxFreq = 0;
            int letterToErase = 0;
            for (auto [letter, frequency] : used) {// O(|alphabet|)
                if (frequency > maxFreq ) {
                    maxFreq = frequency;
                    letterToErase = letter;
                }
            }
            if (maxFreq) {
                for (int k = 0; k < maxFreq; k++) {//O(n)
                    oss << (char)letterToErase; 
                }
            }
            if (letterToErase) {
                used[letterToErase] = 0;
            }
        }
        return oss.str();
    }
};
