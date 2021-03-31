class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sorted(m + n);
        auto firstIt = nums1.begin(), 
            secondIt = nums2.begin(), 
            thirdIt = sorted.begin();
        
        while (firstIt < nums1.begin() + m && secondIt < nums2.begin() + n) {
            if (*firstIt < *secondIt) { 
                *thirdIt = *firstIt++;
            }
            else {
                *thirdIt = *secondIt++;
            }
            thirdIt++;
        }
        while (firstIt < nums1.begin() + m) {
            *thirdIt ++ = *firstIt++;
        }
        while (secondIt < nums2.begin() + n) {
            *thirdIt ++ = *secondIt++;
        }
        nums1 = move(sorted);
    }
};