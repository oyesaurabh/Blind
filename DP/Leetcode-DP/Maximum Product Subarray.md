[Link](https://leetcode.com/problems/maximum-product-subarray/)
# Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.
Example 1:
```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```
Example 2:
```
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```
## Brute TLE
O(N*N) && S(1)
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pro=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int curr_pro=1;
            for(int j=i;j<nums.size();j++){
                curr_pro*=nums[j];
                max_pro=max(max_pro, curr_pro);
            }
        }
        return max_pro;
    }
};
```
## DP
Product will always contains subarray either from starting or end.<br>
O(2N) && S(1)
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,p=1;
        int n=nums.size();
        //aage se
        for(int i=0;i<n;i++){
            p*=nums[i];
            ans=max(ans,p);
            if(p==0)p=1;
        }
        p=1;
        //peeche se
        for(int i=n-1;i>=0;i--){
            p*=nums[i];
            ans=max(ans,p);
            if(p==0)p=1;
        }
        return ans;
    }
};
```