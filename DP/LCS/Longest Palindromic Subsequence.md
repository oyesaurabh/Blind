[leet](https://leetcode.com/problems/longest-palindromic-subsequence/)<br>
[geek](https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1)
# Longest Palindromic Subsequence
Example 1:
```
Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.
```
Example 2:
```
Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.
```
## DP
```cpp
class Solution {
    int n;
//     int dp[1000 +1][1000 + 1];
//     int lCS_memoization(string &a,string &b,int i,int j){
//         if(i==0 || j==0)return 0;
//         if(dp[i][j] != -1)return dp[i][j];     
//         if(a[i-1] == b[j-1])
//             return dp[i][j]=1+lCS_memoization(a,b,i-1,j-1);
//         else
//             return dp[i][j]=max(lCS_memoization(a,b,i-1,j), lCS_memoization(a,b,i,j-1));
//     }
    int LCS(string &a,string &b){
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(i==0 || j==0)
                    dp[i][j]=0; //initialization
                else if(a[i-1] == b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        
        return dp[n][n];
    }
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())return 0;
        // memset(dp,-1,sizeof(dp));
        n=s.size();
        string rev=s;
        reverse(rev.begin(), rev.end());
        
        // return lCS_memoization(s,rev,n,n);
        return LCS(s,rev);
    }
};
```