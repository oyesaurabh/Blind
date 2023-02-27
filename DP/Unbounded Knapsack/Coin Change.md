[Link](https://leetcode.com/problems/coin-change/)
# Coin Change I
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

### ***In short : Minimum # of coins needed***
```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```
## Recursive
Time: O(2^n)<br>
Space: O(n)
```cpp
class Solution {
public:
    int n;
    int solve(vector<int>&a,int target,int ind){
        if(ind>=n || target<=0)
            return target==0?0:INT_MAX-1;
                                  //  |                       |
        if(a[ind] <= target)      //  V take                  V not take
            return min(1+solve(a,target-a[ind],ind), 0+solve(a,target,ind+1));
        else
            return solve(a,target,ind+1);
    }
    int coinChange(vector<int>& a, int target) {
        n=a.size();
        int ans=solve(a,target,0);
        return ans==INT_MAX-1?-1:ans;
    }
};
```
## Memoization
Time: O(n.m)<br>
Space: O(n.m)
```cpp
class Solution {
public:
    int n;
    int dp[13][10001];
    int solve(vector<int>&a,int target,int ind){
        if(ind>=n || target<=0)
            return target==0?0:INT_MAX-1;
        
        if(dp[ind][target]!=-1)return dp[ind][target];
                                  //  |                       |
        if(a[ind] <= target)      //  V take                  V not take
            return dp[ind][target]=min(1+solve(a,target-a[ind],ind), 0+solve(a,target,ind+1));
        else
            return dp[ind][target]=0+solve(a,target,ind+1);
    }
    int coinChange(vector<int>& a, int target) {
        n=a.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(a,target,0);
        return ans==INT_MAX-1?-1:ans;
    }
};
```
## DP
Time: O(n.m)<br>
Space: O(n.m)
```cpp
class Solution {
public:
    int n;
    int dp[12+1][10000+1];
    int solve(vector<int>&a,int target){
        //initialize
        for(int i=0;i<=n;i++)
            for(int j=0;j<=target;j++)
                if(i==0 || j==0)
                    dp[i][j]=(j==0?0:INT_MAX-1);
        
       for(int i=1;i<=n;i++)
           for(int j=1;j<=target;j++)
               if(a[i-1]<=j)
                   dp[i][j]=min(0+dp[i-1][j], 1+dp[i][j-a[i-1]] );
                else
                    dp[i][j]=0+dp[i-1][j];
        
       return dp[n][target];
    }
    int coinChange(vector<int>& a, int target) {
        n=a.size();
        int ans=solve(a,target);
        return ans==INT_MAX-1?-1:ans;
    }
};
```