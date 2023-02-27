[Leet](https://leetcode.com/problems/palindrome-partitioning-ii/)<br>
[Geek](https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1)
# Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.
```
Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".

Example 3:
Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".
```
## Solution :: Recursive
```cpp
class Solution {
    bool is_pali(string &s,int i,int j){
        while(i<j)
            if(s[i++] != s[j--])return 0;
        return 1;
    }
    int solve(string &s,int i,int j){
        if(i>=j || is_pali(s,i,j))return 0;
        
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=1+solve(s,i,k)+solve(s,k+1,j);
            ans=min(ans,temp);
        }
        return ans;
    }
public:
    int minCut(string s) {
        return solve(s,0,s.size()-1);
    }
};
```
## Solution :: Memoization
```cpp
class Solution {
    int dp[2000+1][2000+1];
    bool is_pali(string &s,int i,int j){
        while(i<j)
            if(s[i++] != s[j--])return 0;
        return 1;
    }
    int solve(string &s,int i,int j){
        if(i>=j || is_pali(s,i,j))
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=1+solve(s,i,k)+solve(s,k+1,j);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
public:
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};
```
## Solution :: Optimized Memoization
```cpp
class Solution {
    int dp[2000+1][2000+1];
    bool is_pali(string &s,int i,int j){
        while(i<j)
            if(s[i++] != s[j--])return 0;
        return 1;
    }
    int solve(string &s,int i,int j){
        if(i>=j || is_pali(s,i,j))
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            
            int left,right;
            if(dp[i][k] != -1)
                left=dp[i][k];
            else
                left=solve(s,i,k), dp[i][k]=left;
            
            if(dp[k+1][j] != -1)
                right=dp[k+1][j];
            else
                right=solve(s,k+1,j), dp[k+1][j]=right;
            
                
            int temp=1+left+right;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
public:
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};
```
