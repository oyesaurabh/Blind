[Link](https://leetcode.com/problems/jump-game/)
# Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
<br>

Return true if you can reach the last index, or false otherwise.

Example 1:
```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```
Example 2:
```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```
## Recursive
O(M^N), where M is the max value in Array && S(N)
```cpp
class Solution {
    int n;
    bool recursion(vector<int>&a,int i){
        if(i>=n-1)return 1;
        
        for(int jumps=1;jumps<=a[i];jumps++)
            if(recursion(a,i+jumps))
                return 1;
        
        return 0;
    }
public:
    bool canJump(vector<int>& a) {
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
    int memo[10001];
    bool recursion(vector<int>&a,int i){
        if(i>=n-1)return 1;
        if(memo[i]!=-1)return memo[i];
        
        bool ans=0;
        for(int jumps=1;jumps<=a[i];jumps++)
            if(recursion(a,i+jumps)){
                ans=1;
                break;
            }
        
        return memo[i]=ans;
    }
public:
    bool canJump(vector<int>& a) {
        n=a.size();
        memset(memo, -1, sizeof(memo));
        return recursion(a,0);
    }
};
```
## Greedy
O(N) && S(1)
```cpp
class Solution {
    int n;
public:
    bool canJump(vector<int>& a) {
        n=a.size();
        int max_jump=0;
        for(int i=0;i<n;i++){
            if(i>max_jump)return 0;
            max_jump=max(max_jump,a[i]+i);
        }
        return 1;
    }
};
```

