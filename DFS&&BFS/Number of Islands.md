[Link](https://leetcode.com/problems/number-of-islands/)
# Number of Islands

Example 1:
```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```
Example 2:
```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```
## Solution DFS
```cpp
class Solution {
    int n,m;
    void dfs(vector<vector<char>>& a,int i,int j){
        if(i>=n||i<0 || j>=m||j<0 || a[i][j]!='1')return; //outofbound
        a[i][j]='0';
        dfs(a,i+1,j);
        dfs(a,i,j+1);
        dfs(a,i-1,j);
        dfs(a,i,j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands=0;
        n=grid.size();
        m=grid[0].size();
        
        //actual logic
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]=='1')
                    dfs(grid,i,j), numOfIslands++;
        
        return numOfIslands;
    }
};
```