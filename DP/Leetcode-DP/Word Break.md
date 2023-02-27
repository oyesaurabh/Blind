# Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
<br>

Note that the same word in the dictionary may be reused multiple times in the segmentation.
<br>

Example 1:
```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```
Example 2:
```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```
Example 3:
```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```
## Recursive TLE
```cpp
class Solution {
    unordered_set<string> uset;
    int n;
    bool solve(string&s, int k){
        if(k>=n)return 1;
        
        for(int i=k;i<n;i++)
            if( uset.find(s.substr(k,i-k+1))!=uset.end() && solve(s,i+1) )
                return 1;
        return 0;
    }
public:
    bool wordBreak(string s, vector<string>& dic) {
        for(auto&it:dic)
            uset.insert(it);
        n=s.size();
        return solve(s,0);
    }
};
```
## Memo
```cpp
class Solution {
    unordered_set<string> uset;
    int n;
    int dp[301];
    bool solve(string&s, int k){
        if(k>=n)return 1;
        
        if(dp[k]!=-1)return dp[k];
        for(int i=k;i<n;i++)
            if( uset.find(s.substr(k,i-k+1))!=uset.end() && solve(s,i+1) )
                return dp[k]=1;
        return dp[k]=0;
    }
public:
    bool wordBreak(string s, vector<string>& dic) {
        for(auto&it:dic)
            uset.insert(it);
        
        memset(dp,-1,sizeof(dp));
        n=s.size();
        return solve(s,0);
    }
};
```