[Link](https://leetcode.com/problems/shortest-common-supersequence/)
# Shortest Common Supersequence
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
```
Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
```
## DP
```cpp
class Solution {
    int n,m;
    string LCS(string a, string b){
        int dp[n+1][m+1]; 
        //DP to fill 2D matrix
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(i==0 || j==0) 
                    dp[i][j]=0;
                else if(a[i-1] == b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        
        //now the actual fun begins 
        string ans="";
        int i=n, j=m;
        while(i>0 && j>0)
            if(dp[i][j]==dp[i-1][j-1])
                ans+=(a[i-1]), i--, j--;
            else if(dp[i][j]==dp[i-1][j])
                ans+=(a[i-1]), i--;
            else
                ans+=(b[j-1]), j--;
        while(i>0)
            ans+=(a[i-1]),i--;
        while(j>0)
            ans+=(b[j-1]),j--;
        
        //finally reverse our string and return it
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string shortestCommonSupersequence(string a, string b) {
        n=a.size();
        m=b.size();     
        return LCS(a,b);
    }
};
```