[Link](https://leetcode.com/problems/climbing-stairs/)
# Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**Example 1:**
```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```
## Solution Recursion TLE
O(2^N) && S(N)
```cpp
class Solution {
    int recursion(int n){
        if(n==0 || n==1)return 1;
        return recursion(n-1)+recursion(n-2);
    }
public:
    int climbStairs(int n) {
        return recursion(n);
    }
};
```
## Solution Memo
O(N) && S(N)
```cpp
class Solution {
    int dp[46];
    int memo(int n){
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=memo(n-1)+memo(n-2);
    }
public:
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return memo(n);
    }
};
```
## Solution Greedy
O(N) && S(1)
```cpp
class Solution {

public:
    int climbStairs(int n) {

        if(n<=2)return n;
        int a=1,b=2,c;
        for(int i=2;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
```
