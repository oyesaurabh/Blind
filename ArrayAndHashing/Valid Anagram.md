[Link](https://leetcode.com/problems/valid-anagram/)
# Valid Anagram
```
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
```
## Solution
Count chars, strings should have same # of chars if anagram<br>
Time: O(n)<br>
Space: O(26)<br>
```cpp
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())return 0;
        vector<int> a(26,0);
        for(char c:s)
            a[c-'a']++;
        for(char c:t){
            a[c-'a']--;
            if(a[c-'a']<0)return 0;
        }
        return 1;
    }
```