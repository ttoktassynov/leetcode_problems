class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeParMap = {{')','('}, {']','['}, {'}','{'}};
        stack<char> parStack;
        parStack.push(s[0]);
        
        for (int i = 1; i < (int)s.size(); i++) {
            if (!closeParMap.count(s[i]))
                parStack.push(s[i]);
            else {
                if (!parStack.empty() && parStack.top() == closeParMap[s[i]]) {
                    parStack.pop();
                }
                else {
                    return false;
                }
            } 
            
        }
        return parStack.empty();
    }
};