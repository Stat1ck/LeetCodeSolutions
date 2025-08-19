//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.
//
//Example 1:
//
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
//Example 2:
//
//Input: nums = [3,2,4], target = 6
//Output: [1,2]
//Example 3:
//
//Input: nums = [3,3], target = 6
//Output: [0,1]
//
// ************************************************************
//
// Accepted 63 / 63 testcases passed
//
// Runtime 0ms
// Beats 100.00%
//
// Memory 14.92MB
// Beats 20.33%
//
// ************************************************************

#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> we_need;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];

            if (we_need.find(val) != we_need.end()) {
                return std::vector<int> { we_need[val], i };
            }

            we_need[target - val] = i;
        }

        return std::vector<int> { -1, -1 };
    }
};

int main_two_sum() {
    Solution solution;

    std::vector<int> nums = {
        -3, 4, 3, 90
    };
    int target = 0;

    std::vector<int> res = solution.twoSum(nums, target);

    if (res[0] == -1 || res[1] == -1) {
        std::cout << "Can't find indices" << std::endl;
    }

    std::cout << "[" << res[0] << "," << res[1] << "]" << std::endl;

	return 0;
}