[linmk](https://leetcode.com/problems/longest-common-subsequence/)
# Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
For example, "ace" is a subsequence of "abcde".
```
Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```
## Recursive
```cpp
class Solution {
    int solve(string a,string b,int i,int j){
        if(i<0 || j<0)return 0;
        if(a[i]==b[j])
            return 1 + solve(a,b,i-1,j-1); 
        else
            return max(solve(a,b,i,j-1), solve(a,b,i-1,j));
    }
public:
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();
        return solve(a,b,n-1,m-1);
    }
};
```
## Memoization
```cpp
class Solution {
    int dp[1000 + 1][1000 +1];
    int solve(string a,string b,int i,int j){
        if(i<0 || j<0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        
        if(a[i]==b[j])
            return dp[i][j]=1 + solve(a,b,i-1,j-1);
        else
            return dp[i][j]=max(solve(a,b,i,j-1), solve(a,b,i-1,j));
    }
public:
    int longestCommonSubsequence(string a, string b) {
        if(a.empty() || b.empty())return 0;
        memset(dp,-1,sizeof(dp));
        int n=a.size(), m=b.size();
        return solve(a,b,n-1,m-1);
    }
};
```
## DP
```cpp
    int longestCommonSubsequence(string a, string b) {
        if(a.empty() || b.empty())return 0;
        int n=a.size(), m=b.size();   
        //initialization     
        int dp[n+1][m+1];
        // for(int i=0;i<=n;i++)dp[i][0]=0;
        // for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(i==0 || j==0)dp[i][j]=0;
                else dp[i][j]=-1;
        
        //choice diagram
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i-1]==b[j-1])
                    dp[i][j]= 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
        return dp[n][m];
    }
```