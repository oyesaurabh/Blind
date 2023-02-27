// https://youtu.be/F7wqWbqYn9g
// Similar question https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int dp(vector<int> a,int sum){
    int size=a.size();
    int dp[size+1][sum+1];

    //initialize
    for(int i=0;i<=size;i++)
        for(int j=0;j<=sum;j++)
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
            else 
                dp[i][j]=-1;

    //code
    for(int i=1;i<=size;i++)
        for(int j=0;j<=sum;j++)
            if(a[i-1] > j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];

    //return last element               
    return dp[size][sum];
}
int main(){
    //here
    cout<<"size of array: ";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &it:arr)
        cin>>it;
    cout<<"TARGET:\t";
    int t;
    cin>>t;
    cout<<dp(arr,t);
    getch();
    return 0;
}