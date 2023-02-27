[link](https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#)
## Recursive
```cpp
class Recursive{
    int solve(int price[],vector<int>& length,int size,int N){
        if(size==0 || N==0)
            return 0;                                //   only difference instead of size-1, 
                                                    //    |
        if(length[size-1]<=N)                      //     V
            return max( price[size-1]+solve(price,length,size,N-length[size-1]),
                    solve(price,length,size-1,N) );
        else
            return solve(price,length,size-1,N);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> length;
        for(int i=1;i<=n;i++)
            length.push_back(i);
        return solve(price,length,n,n);
    }
};
```
## Memoization
```cpp
class Recursive{
    int dp[1001][1001];
    int solve(int price[],vector<int>& length,int size,int N){
        if(size==0 || N==0)
            return 0;
        if(dp[size][N]!=-1)return dp[size][N];
        if(length[size-1]<=N)
            return dp[size][N]=max( price[size-1]+solve(price,length,size,N-length[size-1]),
                    solve(price,length,size-1,N) );
        else
            return dp[size][N]=solve(price,length,size-1,N);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> length;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
            length.push_back(i);
        return solve(price,length,n,n);
    }
};
```
## Dynamic Programming
```cpp
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n+1][n+1];
        vector<int> length;
        for(int i=1;i<=n;i++)
            length.push_back(i);
        //initialization
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(i==0 || j==0 )dp[i][j]=0;
                else dp[i][j]=-1;
        //choice diagram
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(length[i-1] <= j)
                    dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]], 
                                 dp[i-1][j] );
                else
                    dp[i][j]=dp[i-1][j];
            }
        return dp[n][n];
    }
};
```