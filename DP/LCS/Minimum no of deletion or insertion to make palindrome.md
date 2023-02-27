[geeek](https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1)
[leet](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)
# Minimum number of deletions / insertion.
Given a string s. In one step you can insert or delete any character at any index of the string.
Return the minimum number of steps to make s palindrome.
```
Example 1:

Input: n = 7, str = "aebcbda"
Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".
                or 
we can insert 'e' and 'd' and make string "aedbcbdea".
```
## Solution : Dp
```cpp
int n;
int LCS(string &a, string &b){
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(i==0 || j==0) dp[i][j]=0;
            else if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            
    return dp[n][n];
}
int LongestPalindromicSubseq(string &s){
    string rev=s;
    reverse(rev.begin(), rev.end());
    return LCS(s,rev);
}
int minDeletions(string str, int N) { 
    //complete the function here 
    n=N;
    return N-LongestPalindromicSubseq(str);
} 
```