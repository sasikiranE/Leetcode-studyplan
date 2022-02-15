/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

 

Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomSize = ransomNote.size();
        int magazineSize = magazine.size();
        if (ransomSize > magazineSize) return false;
        unordered_map<char, int> ransomMap, magazineMap;
        for (auto &c : ransomNote) ransomMap[c]++;
        for (auto &c : magazine) magazineMap[c]++;
        for (auto &p : ransomMap) {
            if (magazineMap[p.first] < p.second) return false;
        }
        return true;
    }
};

