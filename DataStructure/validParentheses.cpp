/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, int> val = {
        	{'(', 1}, {')', -1},
        	{'[', 2}, {']', -2},
        	{'{', 3}, {'}', -3},
        };

        for (int i = 0; i < s.size(); i++) {
        	if (val[s[i]] > 0) st.push(s[i]);
        	else {
        		if (st.empty()) return false;
        		char opening = st.top();
        		st.pop();
        		if (val[opening] + val[s[i]] != 0) return false;
        	}
        }
        return st.empty();
    }
};
