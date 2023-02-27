[link](https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1)
# Longest Common Substring
Given two strings. The task is to find the length of the longest common substring.
```
Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
```
## Recursive
```cpp

```
## DP
```cpp
    int longestCommonSubstr (string a, string b, int n, int m)
    {
        // your code here
        int ans=0;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(a[i-1]==b[j-1])
                    ans=max(ans, dp[i][j]=1+dp[i-1][j-1]);
                else
                    dp[i][j]=0;
                    
        return  ans;
    }
```