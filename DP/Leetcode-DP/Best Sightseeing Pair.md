# Best Sightseeing Pair
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
<br>

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
<br>

Return the maximum score of a pair of sightseeing spots.
Example 1:
```
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
```
Example 2:
```
Input: values = [1,2]
Output: 2
```
## Brute
O(N*N) && S(1)
```cpp
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        //Brute
        int ans=INT_MIN;
        for(int i=0;i<a.size();i++){
            int temp=0;
            for(int j=i+1;j<a.size();j++){
                temp=a[i]+a[j]+i-j;
                ans=max(ans, temp);
            }
        }
            
        return ans;
    }
};
```
## DP
O(N) && S(1)
```cpp
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int i=0,ans=a[0];
        for(int j=1;j<a.size();j++){
            ans=max(ans, a[i]+a[j]+i-j);
            if(a[i]+i < a[j]+j)
                i=j;
        }
        return ans;
    }
};
```