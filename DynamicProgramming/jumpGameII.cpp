/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

 

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 1000

*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int minJumps = 0;
        int n = nums.size();
        int can_reach = 0;
        pair<int, int> interval = {0, 0};
        
        if (n == 1) {
            return 0;
        }
        
        while (true) {
            for (int i = interval.first; i <= interval.second; i++) {
                can_reach = max(can_reach, i + nums[i]);
            }
            minJumps++;
            if (can_reach >= n - 1) {
                break;
            }
            interval = {interval.second + 1, can_reach};
        }
        return minJumps;
    }
};
