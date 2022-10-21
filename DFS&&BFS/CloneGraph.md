[Link](https://leetcode.com/problems/clone-graph/)
# Clone Graph

![img](https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png)
```
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
```
## Solution DFS
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> mp;
    Node* dfs(Node *node){
        if(mp.find(node) != mp.end())return mp[node];
        Node *clone = new Node(node->val);
        mp[node]=clone;
        for(auto padosi:node->neighbors)
            clone->neighbors.push_back(dfs(padosi));
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        return dfs(node);
    }
};
```
## Solution BFS
```cpp

```