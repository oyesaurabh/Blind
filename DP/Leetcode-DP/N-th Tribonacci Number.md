[Link](https://leetcode.com/problems/n-th-tribonacci-number/)
# N-th Tribonacci Number
The Tribonacci sequence Tn is defined as follows: 
```
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
```
Given n, return the value of Tn.

**Example 1:**
```
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```
## Solution :: Recursion TLE
O(3^N) && S(N)
```cpp
class Solution {
    int recursive(int n){
        if(n==0)return 0;
        if(n==1 || n==2)return 1;
        return recursive(n-1)+recursive(n-2)+recursive(n-3);
    }
public:
    int tribonacci(int n) {
        return recursive(n);
    }
};
```
## Solution Memo
O(N) && S(N)
```cpp
class Solution {
    int memo[38];
    int memoization(int n){
        if(n==0)return 0;
        if(n==1 || n==2)return 1;
        if(memo[n]!=-1)return memo[n];
        return memo[n]=memoization(n-1)+memoization(n-2)+memoization(n-3);
    }
public:
    int tribonacci(int n) {
        memset(memo,-1,sizeof(memo));
        return memoization(n);
    }
```
## Solution DP
O(N) && S(N)
```cpp
class Solution {
public:
    int tribonacci(int n) {
        if(n<3)
            return n==0?0:1;
        int dp[n+1];
        dp[0]=0, dp[1]=dp[2]=1;
        for(int i=3;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        return dp[n];
    }
```
## Solution 2 Pointers
O(N) && S(1)
```cpp
class Solution {
public:
    int tribonacci(int n) {
        if(n<3)return n?1:0;
        
        int a=0,b=1,c=1,ans;
        for(int i=3;i<=n;i++){
            ans=a+b+c;
            a=b;
            b=c;
            c=ans;
        }
        return ans;
    }
```