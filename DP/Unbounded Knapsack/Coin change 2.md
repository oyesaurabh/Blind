[Link](https://leetcode.com/problems/coin-change-2/)
# Coin Change 2
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
### ***In short : Total number of ways***

```
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```
## Recursive
```cpp
class Solution {
    int n;
    int solve(vector<int>& a,int t,int size){
        if(t==0) // target = 0...means we got the answer
            return 1;
        if(size<0)return 0; //we tried all the combinations butt couldnt find any answer so return 0
        
        if(a[size] <= t)
            return solve(a,t-a[size],size)+solve(a,t,size-1); //take both
        else
            return solve(a,t,size-1); // ignore
    }
public:
    int change(int t, vector<int>& a) {
        n=a.size();
        return solve(a,t,n-1);
    }
};
```
## Memoization
```cpp
class Solution {
    int n;
    int dp[301][5001];
    int solve(vector<int>& a,int t,int size){
        if(t==0)return 1;
        if(size<0)return 0;
        
        if(dp[size][t] != -1)return dp[size][t];
        if(a[size] <= t)
            return dp[size][t]=solve(a,t-a[size],size)+solve(a,t,size-1); //take both
        else
            return dp[size][t]=solve(a,t,size-1); // ignore
    }
public:
    int change(int t, vector<int>& a) {
        n=a.size();
        memset(dp,-1,sizeof(dp));
        return solve(a,t,n-1);
    }
};
```
## DP
```cpp
class Solution {
public:
    int change(int t, vector<int>& a) {
        int n=a.size();

        int dp[n+1][t+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=t;j++)
                if(i==0)      // i==0 means, no element to select... so dp[i][j]=0
                    dp[i][j]=0;  
                else if(j==0) // j==0 means target=0 therefore always true {}....so dp[][]=1
                    dp[i][j]=1;
                else
                    dp[i][j]=-1;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=t;j++){
                if(a[i-1] <= j)
                    dp[i][j]=( dp[i-1][j] + dp[i][j-a[i-1]] );
                else
                    dp[i][j]=dp[i-1][j];
            }
        return dp[n][t];
    }
};
```