/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

 

Constraints:

    1 <= numRows <= 30


*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < numRows; i++) {
            int n = i + 1;
            vector<int> v(n);
            v[0] = v[n - 1] = 1;
            for (int k = 1; k < n - 1; k++) {
                v[k] = ans[i - 1][k - 1] + ans[i - 1][k];
            }
            ans.push_back(v);
        }
        return ans;
    }
};
