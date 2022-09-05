[question link](https://leetcode.com/problems/two-sum/)

# Two SUM

# problem statement
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

>>Example 1:
>>Input: nums = [2,7,11,15], target = 9
>>Output: [0,1]
>>Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

# Solution 
time complexity : O(N)
space complexity : O(N)

```cpp
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            if(m.find(t-nums[i]) != m.end())
                return {i ,m[t-nums[i]]};
            else
                m[nums[i]]=i;
        
        return {};
    }
```