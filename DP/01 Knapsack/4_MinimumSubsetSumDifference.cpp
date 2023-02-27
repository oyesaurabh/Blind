// https://youtu.be/-GtpxG6l_Mc
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int minimumSubsetDiff(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
            if(a[i-1] > j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
    
    int ans=INT_MIN;
    int half=sum/2;
    for(int i=0;i<=half;i++)
        if(dp[n][i])
            ans=sum-2*i;
    

    return ans;
    
}
int main(){
    //here
    int n;
    cout<<"N: ";
    cin>>n;
    int a[n];
    cout<<"elements:\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Minimum subset sum difference = "<<minimumSubsetDiff(a,n);
    getch();
    return 0;
}