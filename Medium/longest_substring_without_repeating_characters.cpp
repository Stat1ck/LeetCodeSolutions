//Given a string s, find the length of the longest substring without duplicate characters.
//
//Example 1:
//
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//
//Example 2:
//
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//
//Example 3:
//
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//Constraints:
//
//0 <= s.length <= 5 * 104
//s consists of English letters, digits, symbols and spaces.
//
// ************************************************************
//
// Accepted 988 / 988 testcases passed
//
// Runtime 8ms
// Beats 60.35%
//
// Memory 11.82MB
// Beats 58.52%
//
// ************************************************************

#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 0 || s.size() == 1) {
            return s.size();
        }

        std::unordered_map<char, int> elems;
        int max = 0;
        int current = 0;
        int prev = -1;

        for (int i = 0; i < s.size(); i++) {
            if (elems.find(s[i]) != elems.end() && elems[s[i]] > prev) {
                prev = elems[s[i]];
                current = i - prev - 1;
            }

            elems[s[i]] = i;
            current++;
            if (current > max) {
                max = current;
            }
        }

        return max;
	}
};

int main_longest_substring_without_repeating_characters() {
    Solution solution;
    //std::string s = "dvdf"; // Expected 3
    std::string s = "abcabcbb"; // Expected 3
    //std::string s = "abba"; // expected 2

    int res = solution.lengthOfLongestSubstring(s);

    std::cout << res << std::endl;

    return 0;
}
