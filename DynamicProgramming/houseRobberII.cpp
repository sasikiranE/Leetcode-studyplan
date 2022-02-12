/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:

Input: nums = [1,2,3]
Output: 3

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000


*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> firstAllowed(n, -1);
        vector<int> lastAllowed(n, -1);
        
        firstAllowed[0] = nums[0];
        lastAllowed[0] = 0;
        
        
        if (n == 1) {
            return nums[0];
        }
        
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        
        firstAllowed[1] = max(nums[0], nums[1]);
        lastAllowed[1] = nums[1];
        
        // case for firsthouse allowed and last one not allowed.
        for (int i = 2; i < n - 1; i++) {
            firstAllowed[i] = max(firstAllowed[i - 1], nums[i] + firstAllowed[i - 2]);
        }
        
        // case for firsthouse not allowed and last one allowed to rob.
        
        for (int i = 2; i < n; i++) {
            lastAllowed[i] = max(lastAllowed[i - 1], nums[i] + lastAllowed[i - 2]);
        }
        
        return max(firstAllowed[n - 2], lastAllowed[n - 1]);
    }
};