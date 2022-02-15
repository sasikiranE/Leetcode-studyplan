/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

 

Constraints:

    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.

 
*/

class Solution {
    bool equal(unordered_map<char, int>& a, unordered_map<char, int>& b) {
        for (auto &p : a) {
            if (b[p.first] != p.second) return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false;
        unordered_map<char, int> count1, count2;
        for (auto &c : s1) count1[c]++;
        // using sliding window of length n1.
        int l = 0, r = n1 - 1;
        for (int i = 0; i < n1; i++) {
            count2[s2[i]]++;
        }

        while (r + 1 < n2) {
            if (equal(count1, count2)) return true;
            count2[s2[l]]--;
            l++;
            count2[s2[r + 1]]++;
            r++;
        }
        return equal(count1, count2);
    }
};
