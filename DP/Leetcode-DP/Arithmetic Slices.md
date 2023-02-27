# Arithmetic Slices
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.<br>

Given an integer array nums, return the number of arithmetic subarrays of nums.
Example 1:
```
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
```
Example 2:
```
Input: nums = [1]
Output: 0
```
## DP 
O(2N) && S(N) 
```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
//      at least three elements
        if(n < 3)return 0;  
        
        vector<int> dp(n,0);
        for(int i=1;i<n-1;i++)
            if(a[i]-a[i-1] == a[i+1]-a[i])
                dp[i]=dp[i-1]+1;
        int sum=0;
        for(auto&it:dp)
            sum+=it;
        return sum;
    }
};
```
## Two Pointers
O(N) && S(1) 
```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
//      at least three elements
        if(n < 3)return 0;  
        
        int diff=a[1]-a[0], ans=0, cnt=0;
        for(int i=1;i<a.size()-1;i++){      
            int curr_diff=a[i+1]-a[i];
            if(curr_diff == diff)
                cnt++;
            else
                cnt=0, diff=curr_diff;
            ans+=cnt;
        }
        return ans;
        
    }
};
```