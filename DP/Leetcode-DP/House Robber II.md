[Link](https://leetcode.com/problems/house-robber-ii/?envType=study-plan&id=dynamic-programming-i)
# House Robber II
same as House Robber I, just here are in circular... so cant rob a[0] and a[n-1] at the same;
Example 1:
```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```
Example 2:
```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```
Example 3:
```
Input: nums = [1,2,3]
Output: 3
```
## Space Optimized DP
O(N) && S(1)
```cpp
class Solution {
    int houseRob1(vector<int>&a,int start,int end){
        //space optimized dp
        int pre1,pre2,curr;
        pre1=pre2=curr=0;
        for(int i=start;i<=end;i++){
            curr=max(a[i]+pre2, pre1);
            pre2=pre1;
            pre1=curr;
        }
        return curr;
    }
public:
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        if(n==2)return max(a[0], a[1]);
        return max(houseRob1(a,0,n-2), houseRob1(a,1,n-1));
    }
};
```