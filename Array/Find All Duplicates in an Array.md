[Link](https://leetcode.com/problems/find-all-duplicates-in-an-array/)
# Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
```
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]
```
## Using Set
O(N) && S(N)
```cpp
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;
        for(auto it:nums)
            if(st.find(it) != st.end())
                ans.push_back(it);
            else
                st.insert(it);
        return ans;
    }
```
## Cycle Sort
O(N) &&  S(1)
```cpp
    vector<int> findDuplicates(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n;i++)
            while(a[a[i]-1]!=a[i] ) 
                swap(a[a[i]-1], a[i]);
        
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(a[i]-1 != i)
                ans.push_back(a[i]);
        
        return ans;
    }
```