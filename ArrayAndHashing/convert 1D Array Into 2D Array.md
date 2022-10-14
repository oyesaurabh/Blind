[Link](https://leetcode.com/problems/convert-1d-array-into-2d-array/)
# Convert 1D Array Into 2D Array
![img](https://assets.leetcode.com/uploads/2021/08/26/image-20210826114243-1.png)
```
Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]
Explanation: The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.

```
## Solution 
O(N) && S(M*N)
```cpp
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        if(m*n!=a.size())return {};
        vector<vector<int>> ans(m,vector<int>(n));
        int i=0,j=0;
        for(auto it:a){
            ans[i][j++]=it;
            if(j==n) j=0,i++;
        }
        return ans;
    }
```