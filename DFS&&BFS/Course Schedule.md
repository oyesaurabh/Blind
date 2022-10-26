[Link](https://leetcode.com/problems/course-schedule/)
# Course Schedule
Example 1:
```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```
Example 2:
```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```
## Solution :: DFS
```cpp
class Solution {
    bool iscycle(vector<vector<int>>&adj, vector<int>&vis,int node){
        if(vis[node]==2)
            return true;
        vis[node]=2;//currently processing
        
        for(auto it:adj[node])
            if(vis[it] != 1 && iscycle(adj,vis,it))
                return true;
        
        vis[node]=1;// processed completely
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        //create graph... if there is any cycle then return false else true
        //cycle detection algo - coloring O(V+N)
        
        //create adjacent matrix
        vector<vector<int>> adj(n);
        for(auto &it:a)
            adj[it[0]].push_back(it[1]);
        
        //if isCycle return false
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
            if(vis[i]==0 && iscycle(adj,vis,i))
                return 0;
        return 1;
    }
};
```