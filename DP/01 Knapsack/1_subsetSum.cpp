// https://youtu.be/_gPcYovP7wc
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
bool recursive(vector<int> a,int n,int t){
    if(t==0)
        return 1;
    if(n<0 || t<0)
        return 0;
    bool include=recursive(a,n-1,t-a[n-1]);
    bool exclude=recursive(a,n-1,t);
    return (include || exclude);
}
bool dp(vector<int> a,int sum){
    int size=a.size();
    // vector<vector<int>> dp(size+1,vector<int>(sum+1));
    bool dp[size+1][sum+1];

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
        for(int j=1;j<=sum;j++)
            if(a[i-1] > j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];

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
    cout<<"recursively "<<(recursive(arr,n,t)?"true":"false");
    cout<<"\nDP "<<(dp(arr,t)?"true":"false");
    getch();
    return 0;
}