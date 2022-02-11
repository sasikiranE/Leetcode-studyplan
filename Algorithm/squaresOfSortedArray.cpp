/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idx = -1;
        int mini = INT_MAX;
        int n = nums.size();
        for (int i  = 0; i < n; i++) {
            if (abs(nums[i]) < mini) {
                idx = i;
                mini = abs(nums[i]);
            }
        }
        
        vector<int> ans;
        ans.push_back(mini * mini);
        
        int i = idx - 1;
        int j = idx + 1;
        
        while (i >= 0 and j < n) {
            if (abs(nums[i]) <= abs(nums[j])) {
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
            else {
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        
        while (i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            i--;
        }
        
        while (j < n) {
            ans.push_back(nums[j] * nums[j]);
            j++;
        }
        return ans;
        
    }
};