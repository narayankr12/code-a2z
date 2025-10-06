class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> charSet;
        int left = 0, right = 0, maxLength = 0;

        while (right < s.length()) {
            if (charSet.find(s[right]) == charSet.end()) {
                // Character not in set, add it
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                // Character already in set, remove from left
                charSet.erase(s[left]);
                left++;
            }
        }

        return maxLength;
        
    }
};
