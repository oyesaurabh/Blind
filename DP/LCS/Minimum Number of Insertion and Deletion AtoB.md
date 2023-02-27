[Link](https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1)
# Minimum Number of Insertion and Deletion
**Input**: str1 = "heap", str2 = "pea"<br>
**Output**: 3<br>
**Explanation**: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.
 
```cpp
class Solution{
    int n,m;
	int LCS(string &a,string &b){
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
 	    for(int i=0;i<=n;i++)
 	        for(int j=0;j<=m;j++)
 	            if(i==0 || j==0)
 	                dp[i][j]=0;
 	            else if(a[i-1] == b[j-1])
 	                dp[i][j]=1+dp[i-1][j-1];
 	            else
 	                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
 	    return dp[n][m];
	}

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    n=str1.size();
	    m=str2.size();
	    int lcs=LCS(str1,str2);
	    return n-lcs+m-lcs;
	} 
};
```