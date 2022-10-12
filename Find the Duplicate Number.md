[Link](https://leetcode.com/problems/find-the-duplicate-number/)
# Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
```
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
```
## Approach 1 (Sorting)

Time complexity : O(N\*log(N))  
Space complexity : O(1) (Ignoring space taken by sorting algo)

```cpp
int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++) {
        if(nums[i]==nums[i-1]) return nums[i];
    }
    return -1;
}
```

## Approach 2 (Calculate frequency)

Time complexity : O(N)  
Space complexity : O(N)

```cpp
int findDuplicate(vector<int>& a) {
        int size=n.size();
        vector<int> a(size,0);
        for(int i=0;i<size;i++)
            if(a[n[i]-1]==0)
                a[n[i]-1]++;
            else return n[i];
        return -1;
}
```

## Approach 3 (Floyd's Tortoise and Hare)

Time complexity : O(N)  
Space complexity : O(1)

```cpp
    int findDuplicate(vector<int>& n) {
        //linked list cycle method
        int slow = n[0];
        int fast=n[0];
        do{
            slow=n[slow];
            fast=n[n[fast]];
        }while(slow!=fast);
        fast=n[0];
        while(fast != slow){
            fast=n[fast];
            slow=n[slow];
        }
        return slow;
    }
```

## Approach 4 ( negative marking )
Time complexity : O(N)  
Space complexity : O(1)

```cpp
int findDuplicate(vector<int>& nums) {
        //negative marking
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[abs(nums[i])] >= 0 )
                nums[abs(nums[i]) ]*=-1;
            else
                return abs(nums[i]);
        return -1;
}
```

## Approach 4 ( cycle sort )
Time complexity : O(N)  
Space complexity : O(1)

```cpp
int findDuplicate(vector<int>& a) {
        //cycle sort
        for(int i=0;i<a.size();i++)
            while( a[a[i]-1] != a[i] )
                swap(a[a[i]-1],a[i]);
         
        //searching element which are not in correct index
        for(int i=0;i<a.size();i++)
            if(a[i]-1 != i)
                return a[i];
        return 69;  //can return any thing... non-reachable code
}
```
