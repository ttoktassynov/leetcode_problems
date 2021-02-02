class Solution {
public:
    string frequencySort(string s) {//O(N) + O(|abc|*log|abc|)
        priority_queue<pair<int, int>> lettersHeap;
        unordered_map<int, int> usedMap; 
        ostringstream output;
        for (auto letter : s) { // O(N)
            usedMap[letter]++;
        }
        
        //O(|abc|*log|abc|)
        for (auto [letter, frequency] : usedMap) {//O(|abc|)
            lettersHeap.push({frequency, letter});//O(log|abc|)
        }
        
        //O(|abc|*log|abc|)
        while (!lettersHeap.empty()) {//O(|abc|)
            auto letterInfo = lettersHeap.top();
            output << string(letterInfo.first, letterInfo.second);
            lettersHeap.pop();//O(log|abc|)
        }
        return output.str();
    }
};