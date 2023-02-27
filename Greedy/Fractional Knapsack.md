[Link](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

# Fractional Knapsack

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.

Example 1:

```
Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack.
```

Example 2:

```
Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
```

## Solution 1 :

Time : O(2\*N)<br >
Space : O(N)

```cpp
    double fractionalKnapsack(int W, Item a[], int n)
    {
        // Your code here
        double ans=0;
        priority_queue<pair<double,int> >  pq;
        for(int i=0;i<n;i++)
            pq.push({(double)a[i].value/a[i].weight,i});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int index=top.second;

            if(a[index].weight > W)return ans+(top.first*W);//cant take completely
            else W-=a[index].weight;
            ans+=a[index].value;
        }
        return ans;
    }
```

## Solution 2 :

Time : O(N + NlogN)<br >
Space : O(1)

```cpp
static bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
    // Sorting Item on basis of ratio
    sort(arr, arr + N, cmp);

    double finalvalue = 0.0;

    // Looping through all items
    for (int i = 0; i < N; i++) {

        // If adding Item won't overflow,
        // add it completely
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }

        // If we can't add current Item,
        // add fractional part of it
        else {
            finalvalue
                += arr[i].value
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    // Returning final value
    return finalvalue;
}
```
