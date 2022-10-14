[Link](https://leetcode.com/problems/top-k-frequent-elements/)
# Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
```
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
```
## Solution :: HashMapph
**Time: O(n log k)** -> logn to delete n elemets from PQ and we are traversing through array 2 times.<br>
**Space: O(n + k)** -> N for hashMap and k for PQ.<br>

```cpp
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //max_heap
        for(auto it:mp){
            pq.push({it.second, it.first});
            if(pq.size() > k)pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);  
            pq.pop();
        }
        return ans;
    }
```
## Solution :: BucketSort
O(N) && S(N)

