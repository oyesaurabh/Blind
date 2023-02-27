[Link](https://leetcode.com/problems/jump-game-ii/)
# Jump Game II
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1:
```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```
Example 2:
```
Input: nums = [2,3,0,1,4]
Output: 2
```
## Recursion
```cpp
class Solution {
    int n;
    int recursion(vector<int>&a,int i){
        if(i>=n-1)return 0; //if at last index, then 0 jumps needed.
        int ans=INT_MAX-1;
        for(int jumps=1;jumps<=a[i];jumps++)
            ans=min(ans,1+recursion(a,i+jumps));
            
        return ans;
    }
public:
    int jump(vector<int>& a) {
        n=a.size();
        return recursion(a,0);
    }
};
```
## Memoization
O(N^2) && S(N)
```cpp
class Solution {
    int n;
    int dp[10001];
    int Memoization(vector<int>&a,int i){
        if(i>=n-1)return 0; //if at last index, then 0 jumps needed.
        int ans=INT_MAX-1;
        if(dp[i]!=-1)return dp[i];
        for(int jumps=1;jumps<=a[i];jumps++)
            ans=min(ans,1+Memoization(a,i+jumps));
            
        return dp[i]=ans;
    }
public:
    int jump(vector<int>& a) {
        n=a.size();
        memset(dp,-1,sizeof(dp));
        return Memoization(a,0);
    }
};
```