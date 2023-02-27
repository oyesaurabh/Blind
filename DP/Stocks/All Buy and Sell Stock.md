#  1. Buy and Sell Stock 1
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

1 transaction possible

Example 1:
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```
### Solution :: Greedy
Time Complexity: O(N)<br>
Space Complexity: O(1)<br>
```cpp
class Solution {
public:
    int maxProfit(vector<int>& Arr) {
        
        int maxProfit = 0;
        int buy = Arr[0];

        for(int i=1;i<Arr.size();i++){
            int curProfit = Arr[i] - buy;
            maxProfit = max(maxProfit,curProfit);
            buy = min(buy,Arr[i]);
        }
        return maxProfit;
    }
};
```
# 2. Best Time to Buy and Sell Stock II
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

infinite transaction possible

Example 1:
```
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```
### Solution :: greedy
Time Complexity: O(N)<br>
Space Complexity: O(1)<br>
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // We need prices for 2 days at least to find the profit.
        if (prices.empty() || prices.size() <= 1) {
            return 0;
        }

        int totalProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            // Checking if we can profit with previous day's price.
            // If yes, then we buy on previous day and sell on current day.
            // Add all such profits to get the total profit.
            if (prices[i - 1] < prices[i]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }

        return totalProfit;
    }
};
```
### Solution :: memoization
Time Complexity: O(N\*2)<br>
Space Complexity: O(N\*2) + O(N)<br>
```cpp
    int fun(vector<int>&a, int i, bool canBuy, vector<vector<int>>& dp){
        if(i==a.size())return 0;
        
        if(dp[i][canBuy] != -1)return dp[i][canBuy];
        
        if(canBuy)//                    buying so -a[i]
            return dp[i][canBuy]=max( fun(a,i+1,0,dp)-a[i], fun(a,i+1,1,dp)-0 );
        else //                         selling so +a[i]
            return dp[i][canBuy]=max( fun(a,i+1,1,dp)+a[i], fun(a,i+1,0,dp)+0 );
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fun(prices,0,1,dp);
    }
```
### Solution :: Tabulation
Time Complexity: O(N\*2)<br>
Space Complexity: O(N\*2)<br>
```cpp
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
            for(int buy=0;buy<=1;buy++){
                if(buy)//       buy so -a[i]
                    dp[i][buy]=max( dp[i+1][0]-a[i], dp[i+1][1] );
                else //            selling so +a[i]
                    dp[i][buy]=max( dp[i+1][1]+a[i], dp[i+1][0]);
            }
        return dp[0][1];
    }
```
### Solution :: Tabulation( Space Optimization )
Time Complexity: O(N\*2)<br>
Space Complexity: O(1)<br>
```cpp
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<int> next(2,0), curr(2,0);
        next[0]=next[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy)//       buy so -a[i]
                    curr[buy]=max( next[0]-a[i], next[1] );
                else //            selling so +a[i]
                    curr[buy]=max( next[1]+a[i], next[0]);
            }
            next=curr;
        }
        return curr[1];
    }
```
# 3. Best Time to Buy and Sell Stock III
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

can do at most 2 transactions.

Example 1:
```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```
### Solution :: Greedy
Time Complexity: O(N)<br>
Space Complexity: O(1)<br>
```cpp
coming soon
```
### Solution :: Recursion TLE
Time Complexity: O(2^N)<br>
Space Complexity: O(N)<br>
```cpp
    int fun(vector<int>&a,int i,bool canBuy,int transaction){
        if(i==a.size() || transaction==0)return 0;
        
        if(canBuy)//buying
            return max(fun(a,i+1,0,transaction)-a[i], fun(a,i+1,1,transaction)-0);
        else //selling
            return max(fun(a,i+1,1,transaction-1)+a[i], fun(a,i+1,0,transaction)+0);
    }
public:
    int maxProfit(vector<int>& a) {
       return fun(a,0,1,2); 
    }
```
### Solution :: Memo
Time Complexity: O(N\*2\*3)<br>
Space Complexity: O(N\*2\*3) + O(N)<br>
```cpp
class Solution {
    int fun(vector<int>&a,int i,bool canBuy,int trans,int dp[][2][3]){
        if(i==a.size() || trans==0)return 0;
        
        if(dp[i][canBuy][trans] != -1)return dp[i][canBuy][trans];
        
        if(canBuy)//buying
        return dp[i][canBuy][trans]=max(fun(a,i+1,0,trans,dp)-a[i], fun(a,i+1,1,trans,dp));
        else //selling
        return dp[i][canBuy][trans]=max(fun(a,i+1,1,trans-1,dp)+a[i], fun(a,i+1,0,trans,dp));
    }
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int dp[n+1][2][3];
        memset(dp,-1,sizeof(dp));
        return fun(a,0,1,2,dp); 
    }
};
```
### Solution :: Tabulation
Time Complexity: O(N\*2\*3)<br>
Space Complexity: O(N\*2\*3)<br>
```cpp
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<=1;j++)
                for(int k=0;k<=2;k++){
                    if(k==0)//BaseCase
                        dp[i][j][k]=0;
                    else if(j)
                        dp[i][j][k]=max(dp[i+1][0][k]-a[i], dp[i+1][1][k] );
                    else
                        dp[i][j][k]=max(dp[i+1][1][k-1]+a[i], dp[i+1][0][k] );
                }
        return dp[0][1][2];
    }
};
```
### Solution :: Tabulation( space Optimized )
Time Complexity: O(N\*2\*3)<br>
Space Complexity: O(1)<br>
```cpp
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> next(2,vector<int>(3,0)), curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++)
                for(int k=0;k<=2;k++){
                    if(k==0)
                        curr[j][k]=0;//BaseCase
                    else if(j)
                        curr[j][k]=max(next[0][k]-a[i], next[1][k] );
                    else
                        curr[j][k]=max(next[1][k-1]+a[i], next[0][k] );
                }
            next=curr;
        }
        return curr[1][2];
    }
```
# 4. Best Time to Buy and Sell Stock IV
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)

complete at most k transactions.

***NOTE*** <br>
same as 3rd one(at most 2 transaction), here we have at most k transaction...
Example 1:
```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```
### Solution :: Tabulation
Time Complexity: O(N\*2\*k)<br>
Space Complexity: O(N\*2\*k)<br>
```cpp
    int dp[1001][2][101];
    int solve(vector<int>&a,int i,int canbuy,int trans){
        if(trans==0 || i==a.size())return 0;
        
        if(dp[i][canbuy][trans] != -1)return dp[i][canbuy][trans];
        
        int profit;
        if(canbuy)//buying
            profit= max(solve(a,i+1,0,trans)-a[i] , solve(a,i+1,1,trans)-0);
        else//selling
            profit= max(solve(a,i+1,1,trans-1)+a[i] , solve(a,i+1,0,trans)+0);
        
        return dp[i][canbuy][trans]=profit;
    }
public:
    int maxProfit(int k, vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return solve(a,0,1,k);
    }
```
# 5. Best Time to Buy and Sell Stock IV
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

***NOTE*** : after selling, we can't take the next price... so we call i+2 instead of i+1. Rest will be same.

Example 1:
```
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

### Solution :: Memo
Time Complexity: O(N\*2)<br>
Reason: There are N*2 states therefore at max ‘N*2’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum

Space Complexity: O(N\*2) + O(N)<br>
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N\*2) ).
```cpp
    int dp[5001][2];
    int solve(vector<int>&a,int i,int canbuy){
        if(i >= a.size())return 0;
        
        if(dp[i][canbuy] != -1)return dp[i][canbuy];
        
        if(canbuy)
            return dp[i][canbuy]=max(solve(a,i+1,0)-a[i], solve(a,i+1,1));//                     |
        else //selling                        V 
            return dp[i][canbuy]=max(solve(a,i+2,1)+a[i], solve(a,i+1,0));
    }
public:
    int maxProfit(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return solve(a,0,1);
    }
```
# 6. Best Time to Buy and Sell Stock with Transaction Fee
[Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Example 1:
```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```
### Solution :: Memo
Time Complexity: O(N\*2)<br>
Reason: There are N*2 states therefore at max ‘N*2’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum

Space Complexity: O(N\*2) + O(N)<br>
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N\*2) ).
```cpp
class Solution {
    int fee;
    vector<vector<int>>dp;
    int solve(vector<int>&a, int i,int canbuy){
        if(i>=a.size())return 0;
        
        if(dp[i][canbuy] != -1)return dp[i][canbuy];
        
        int profit;
        if(canbuy)
            profit=max(solve(a,i+1,0)-a[i], solve(a,i+1,1));
        else 
            profit=max(solve(a,i+1,1)+a[i]-fee, solve(a,i+1,0));
        return dp[i][canbuy]=profit;
    }
public:
    int maxProfit(vector<int>& a, int fee) {
        this->fee=fee;
        int n=a.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(a,0,1);
    }
};
```
