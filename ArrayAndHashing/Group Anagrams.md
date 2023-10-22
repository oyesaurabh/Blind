[Link](https://leetcode.com/problems/group-anagrams/description/)

# Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

```
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

```
Example 2:

Input: strs = [""]
Output: [[""]]
```

```
Example 3:

Input: strs = ["a"]
Output: [["a"]]
```

## Solution :: HashMap

Time: O(n\*k log k) where n=size of array, k=length of each string <br>
Space: O(N ) //not sure

```cpp
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(auto it:strs){
            string temp=it;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto&it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
```
