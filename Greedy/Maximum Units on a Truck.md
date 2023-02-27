[Link](https://leetcode.com/problems/maximum-units-on-a-truck/description/)

# Maximum Units on a Truck

Example 1:

```
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
```

Example 2:

```
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
```

## Sol : Greedy

Time O(NlogN + N) <br>
Space O(1)

```cpp
    int maximumUnits(vector<vector<int>>& a, int W) {
        //sorting on the basis of 2nd element
        sort(a.begin(), a.end(), [](auto&a,auto&b){
            return a[1]>b[1];
        });
        int ans=0;
        for(auto&it:a){
            //cant take completely so taking jitna ho ske
            if(it[0] > W) return ans+(W*it[1]);

            ans+=(it[1]*it[0]);
            W-=it[0];
        }
        return ans;
    }
```
