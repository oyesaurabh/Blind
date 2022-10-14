[Link](https://leetcode.com/problems/product-of-array-except-self/)
# Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
```
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```
## Solution :: with /
O(N) && S(1)
```cpp
    vector<int> productExceptSelf(vector<int>& a) {
        int n=a.size();
        int zeros=count(a.begin(), a.end(), 0);
        if(zeros>1)return vector<int>(n, 0);
        
        long p=1;
        for(auto &it:a)if(it)p*=it; //taking product of all elements excepts for 0s
        
        for(auto &it:a)
            if(zeros)//if one zeros in array
                it=(it==0)?p:0;
            else//if no zeros in array
                it=p/it;
        
        return a;
    }
```
## Solution :: without /
O(N) && S(N), using additional array.
```cpp
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=size(nums);
        vector<int> left(n), right(n);
        left[0]=nums[0], right[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            left[i]=nums[i]*left[i-1];
        for(int i=n-2;i>=0;i--)
            right[i]=nums[i]*right[i+1];

        for(int i=0;i<n;i++)
            nums[i]=(i-1<0?1:left[i-1])*(i+1>=n?1:right[i+1]);
        
        return nums;   
    }
```