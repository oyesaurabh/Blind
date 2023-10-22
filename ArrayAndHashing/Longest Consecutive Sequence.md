[Link](https://leetcode.com/problems/longest-consecutive-sequence/)

# Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

```
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

## Solution :: Sorting

O(NlogN) && S(1)

```cpp
    int longestConsecutive(vector<int>& a) {
        if(a.empty())return 0;

        sort(a.begin(), a.end());
        int ans=1,count=1,pre=a[0];
        for(int i=1;i<a.size();i++){
            if(pre+1 == a[i])
                count++;
            else if(pre != a[i])// 0 1 1 2 => 3(0,1,2)
                count=1;
            ans=max(ans, count);
            pre=a[i];
        }
        return ans;
    }
```

## Solution :: Set

O(N) && S(N)

```cpp
    int longestConsecutive(vector<int>& a) {
        if(a.empty())return 0;

        unordered_set<int> st(a.begin(), a.end());
        int ans=1;
        for(auto it:a)
            if(st.find(it-1) == st.end()){
                int count=1;
                while(st.find(++it)!=st.end()) count++;
                ans=max(ans, count);
            }
        return ans;
    }
```
