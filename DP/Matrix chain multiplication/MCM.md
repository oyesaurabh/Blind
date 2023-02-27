[Link](https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)
# Matrix Chain Multiplication
Given a sequence of matrices, find the most efficient way to multiply these matrices together.<br>
```
For example:
suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,  
(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

Input: p[] = {10, 20, 30, 40, 30} 
Output: 30000 
There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Input: p[] = {10, 20, 30}  
Output: 6000  
There are only two matrices of dimensions 10x20 and 20x30. So there 
is only one way to multiply the matrices, cost of which is 10*20*30

```

## Solution : Recursive
```cpp
class Solution{
    int MCM_recursive(int arr[],int i,int j){
        if(i>=j)return 0;
        int cost=INT_MAX;
        for(int k=i;k<j;k++){
            int temp_cost;
            temp_cost=MCM_recursive(arr,i,k)
                      + MCM_recursive(arr,k+1,j)
                      + (arr[i-1]*arr[k]*arr[j]);
            cost=min(cost, temp_cost);
        }
        return cost;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return MCM_recursive(arr,1,N-1);
    }
};
```
## Solution : Memoization
```cpp
class Solution{
    int dp[100][100];
    int MCM_memoization(int arr[],int i,int j){
        if(i>=j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int cost=INT_MAX;
        for(int k=i;k<j;k++){
            int temp_cost;
            temp_cost=MCM_recursive(arr,i,k)
                      + MCM_recursive(arr,k+1,j)
                      + (arr[i-1]*arr[k]*arr[j]);
            cost=min(cost, temp_cost);
        }
        return dp[i][j]=cost;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return MCM_memoization(arr,1,N-1);
    }
};
```
