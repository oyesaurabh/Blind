[link](https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1)
# Longest Repeating Subsequence
Given a string, find the length of the longest repeating subsequence, such that the two subsequences don’t have same string character at the same position, i.e. any ith character in the two subsequences shouldn’t have the same index in the original string.<br>
![img](https://media.geeksforgeeks.org/wp-content/cdn-uploads/longest-repeating-subsequence.jpg)

## DP
```cpp
class Solution {
    int n;
    int lcs(string a,string b){
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(a[i-1]==b[j-1] && i!=j)// this is the only extra condition
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                    
        return dp[n][n];
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    n=str.size();
		    return lcs(str,str);
		}

};
```