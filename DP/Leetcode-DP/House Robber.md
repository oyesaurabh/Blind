[Link](https://leetcode.com/problems/house-robber/)
# House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:
```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```
Example 2:
```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```
## Recursive
O(2^N) && S(N)
```cpp
class Solution {
    int n;
    int recursive(vector<int>&a, int i){
        if(i==n-1)return a[n-1];
        if(i==n-2)return max(a[n-1], a[n-2]);
        return max(a[i]+recursive(a,i+2), recursive(a,i+1) );
    }
public:
    int rob(vector<int>& a) {
        n=a.size();
        return recursive(a,0);
    }
};
```
## Memoization
O(N) && S(N)
```cpp
class Solution {
    int n;
    int memo[101];
    int Memoization(vector<int>&a, int i){
        if(i==n-1)return a[n-1];
        if(i==n-2)return max(a[n-1], a[n-2]);
        
        if(memo[i]!=-1)return memo[i];
        
        return memo[i]=max(a[i]+Memoization(a,i+2), Memoization(a,i+1) );
    }
public:
    int rob(vector<int>& a) {
        n=a.size();
        memset(memo, -1, sizeof(memo));
        return Memoization(a,0);
    }
};
```
## DP
O(N) && S(N)
```cpp
class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        if(n==2)return max(a[0], a[1]);
        
        vector<int> dp(a);
        dp[1]=max(dp[1], dp[0]); // POINT TO BE NOTED so [2,1,3,100,1]
        for(int i=2;i<n;i++)
            dp[i]=max(a[i]+dp[i-2], dp[i-1]);
        return dp[n-1];
    }
};
```
## Spaced-Optimized DP
O(N) && S(1)
```cpp
class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        if(n==2)return max(a[0], a[1]);
        
        int pre2=0,pre1=0,curr=0;
        for(auto &it:a){
            curr=max(it+pre2, pre1);
            pre2=pre1;
            pre1=curr;
        }
        return curr;
    }
};
```