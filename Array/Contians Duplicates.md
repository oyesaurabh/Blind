[Link](https://leetcode.com/problems/contains-duplicate/)
## Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

```
Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false
```
## Solution
Time : O(N)<br>
Space : O(N)<br>
```cpp
    bool containsDuplicate(vector<int>& a) {
        unordered_set<int> m;
        for(int x:a)
            if(m.find(x) == m.end())
                m.insert(x);
                
            else
                return true;
                
        return false;
    }
```