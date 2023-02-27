[Link](https://leetcode.com/problems/trapping-rain-water/)
# Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
<br><br>
***Example***<br>
![img](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
```

## Solution 1 : Brute force TLE
***Approach:*** For each index, we have to find the amount of water that can be stored and we have to sum it up.If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.
<br>
Time : O(N \* N)<br>
Space : O(1)
```cpp
    int trap(vector<int> a) {
        int ans;
        int n=a.size();
        for(int i=0;i<n;i++){
            int j=i;
            int leftMax=0,rightMax=0;
            while(j>=0)
                leftMax=max(a[j--],leftMax);
            j=i;
            while(j<n)
                rightMax=max(a[j++],rightMax);
            
            ans+=min(leftMax, rightMax)-a[i];
        }
        return ans;
    }
```
## Solution 2 :  Pre and Post Sum 
Time : O(2\*N)<br>
Space : O(2\*N)

```cpp
    int trap(vector<int> a) {
        int ans=0;
        int n=a.size();
        vector<int> left(n),right(n);
        left[0]=a[0];
        right[n-1]=a[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(a[i],left[i-1]);
            right[n-1-i]=max(right[n-i],a[n-1-i]);
        }
        for(int i=0;i<n;i++)
            ans+=min(left[i], right[i])-a[i];
        return ans;
    }
```

## Solution 3 : Two pointer approach
Time Complexity: O(N)<br>
Space Complexity: O(1)
```cpp
    int trap(vector<int>& a) {
        int i=0,j=a.size()-1;
        int maxL=0, maxR=0;
        int ans=0;
        while(i<j){
            maxL=max(maxL, a[i]);
            maxR=max(maxR, a[j]);
            
            if(maxL < maxR)
                ans+=maxL-a[i++];
            else
                ans+=maxR-a[j--];
        }
        
        return ans;
    }
```