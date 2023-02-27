#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
bool subsetsum(vector<int> a,int t){
        bool dp[a.size()+1][t+1];
        //initialize
        for(int i=0;i<=a.size();i++)
            for(int j=0;j<=t;j++)
                if(j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=0;
        
        //code
        for(int i=1;i<=a.size();i++)
            for(int j=1;j<=t;j++)
                if(a[i-1] > j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=(dp[i-1][j] || dp[i-1][j-a[i-1]]);
        
        
        return dp[a.size()][t];
        
    }
bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)
            sum+=it;
        if(sum&1)return 0;
        
        return subsetsum(nums,sum/2);
    }
int main(){
        //here
        cout<<"size of array: ";
        int n;
        cin>>n;
        cout<<"\nenter elements\n";
        vector<int> arr(n);
        for(auto &it:arr)
            cin>>it;
        cout<< (canPartition(arr)?"Yes\n":"NO\n");
        getch();
        return 0;
}