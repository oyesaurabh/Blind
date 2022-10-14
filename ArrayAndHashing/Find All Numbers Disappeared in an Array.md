[Link](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
# Find All Numbers Disappeared in an Array
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
```
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
```
## Solution :: Cycle sort
Time : O(N)
Space : O(1)
```cpp
    vector<int> findDisappearedNumbers(vector<int>& a) {
        vector<int> ans;
        int n=a.size();
        for(int i=0;i<n;i++)
            while(a[a[i]-1]!=a[i])
                    swap(a[i],a[a[i]-1]);

        
        for(int i=0;i<n;i++){
            if(a[i]-1!=i)
                ans.push_back(i+1);
        }
        return ans;
    }
```
