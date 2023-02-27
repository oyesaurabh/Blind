[Link](https://leetcode.com/problems/maximum-subarray/)
# Maximum Sum Subarray
Given an integer array nums, find the subarray which has the largest sum and return its sum.
Example 1:
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```
Example 2:
```
Input: nums = [5,4,-1,7,8]
Output: 23
```
## Solution
O(N) && S(1)
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int sum=a[0],ans=a[0];
        for(int i=1;i<a.size();i++){
            if(sum<0)sum=a[i];
            else sum+=a[i];
            
            ans=max(ans,sum);
        }
        return ans;
    }
};
```
