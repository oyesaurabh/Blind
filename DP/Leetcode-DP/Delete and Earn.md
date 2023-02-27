# Delete and Earn
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
<br>

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

Example 1:
```
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
```
Example 2:
```
Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
```
## Recursion TLE
O(2^N) && S(N)
```cpp
class Solution {
    int n;
    int solve(vector<int>&a,int i){
        if(i>=n)return 0;
        
        //taking element that we want to include
        int value = a[i];
        int sum=0;
        while(i<n && a[i]==value)
            sum+=a[i++];
        
        //finding element which is > a[i]+1
        int index=i;
        while(index<n && a[index]==value+1)
            index++;
        
        return max(sum+solve(a,index), solve(a,i));
        
    }
public:
    int deleteAndEarn(vector<int>& a) {
        n=a.size();
        if(n==1)return a[0];
        sort(a.begin(), a.end());
        return solve(a,0);
    }
};
```
## same as House rob I
O(N) && S(1)
```cpp
class Solution {
    int houseRob(vector<int>&a){
        int curr,pre1,pre2;
        pre2=pre1=curr=0;
        for(int i=1;i<=10000;i++){
            curr=max((i*a[i])+pre2, pre1);
            pre2=pre1;
            pre1=curr;
        }
        return curr;
   }
public:
    int deleteAndEarn(vector<int>& a) {
        
        vector<int> dp(10001);
        for(auto&it:a)
            dp[it]++;
        return houseRob(dp);
            
    }
};
```