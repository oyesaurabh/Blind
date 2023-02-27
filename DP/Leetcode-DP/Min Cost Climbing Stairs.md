[Link](https://leetcode.com/problems/min-cost-climbing-stairs/)
# Min Cost Climbing Stairs
Example 1:
```
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
```
Example 2:
```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```
## Solution Recursion
O(2^N) && S(N)
```cpp
class Solution {
    int recursion(vector<int>&a,int i){
        if(i>=a.size()-2)
            return a[i];
        return a[i]+min(recursion(a,i+1), recursion(a,i+2));
    }
public:
    int minCostClimbingStairs(vector<int>& a) {
        return min(recursion(a,0), recursion(a,1));   
    }
};
```
## Solution Memo
O(N) && S(N)
```cpp
class Solution {
    int dp[1000+1];
    int memo(vector<int>&a,int i){
        if(i>=a.size()-2)
            return a[i];
        if(dp[i]!=-1)return dp[i];
        return dp[i]=a[i]+min(memo(a,i+1), memo(a,i+2));
    }
public:
    int minCostClimbingStairs(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return min(memo(a,0),memo(a,1));     
    }
};
```
## Solution Greedy
O(N) && S(1)
```cpp
class Solution {
    
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n=a.size();
        for(int i=2;i<n;i++)
            a[i]+=min(a[i-1], a[i-2]);
        return min(a[n-1], a[n-2]);
    }
};
```
