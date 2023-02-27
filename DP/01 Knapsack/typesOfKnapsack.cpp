//recursion: https://youtu.be/kvyShbFVaY8
//memoization: https://youtu.be/fJbIuhs24zQ
//topDowm: https://youtu.be/ntCGbPMeqgg
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class knapsack{
    int dp[101][101];
    public:
    knapsack(){
        memset(dp,-1,sizeof(dp));
    }
    //using recusion
    int recursive(vector<int> wt,vector<int > val,int W,int size){
        //base case
        if(size==0 || W==0)return 0;
        //incude
        if(wt[size-1] <= W)
            return max(val[size-1]+recursive(wt,val,W-wt[size-1],size-1),  recursive(wt,val,W,size-1));
        //won't incude
        else
            return recursive(wt,val,W,size-1);
    }
    //using memoization
    int memoization(vector<int> wt,vector<int > val,int W,int size){
        //base case
        if(size==0 || W==0)
            return 0;
        if(dp[W][size] != -1)
            return dp[W][size];

        if(wt[size-1]<=W)
            return (dp[W][size]=max(val[size-1]+memoization(wt,val,W-wt[size-1],size-1),  memoization(wt,val,W,size-1)) );
        else
            return (dp[W][size]=memoization(wt,val,W,size-1) );

    }
    //using top down approach
    int topdown(vector<int> wt,vector<int > val,int W,int size){
        //initialzation
        int dp[size+1][W+1];
        for(int i=0;i<=size;i++)
            for(int j=0;j<=W;j++)
                if(i==0 || j==0)
                    dp[i][j]=0;
                else
                    dp[i][j]=-1;

        //choice diagram code
        for(int i=1;i<=size;i++)
            for(int j=1;j<=W;j++)
                if(wt[i-1] <= j)
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
        
        //return final answer
        return dp[size][W];
    }

};
int main(){
    //here
    cout<<"enter number of elements\n";
    int size;
    cin>>size;
    cout<<"enter capacity\n";
    int W;
    cin>>W;

    vector<int> wt(size,0),val(size,0);
    cout<<"enter "<<size<<" weights\n";
    for(auto &it:wt)cin>>it;
    cout<<"enter "<<size<<" values\n";
    for(auto &it:val)cin>>it;

    knapsack ks;
    cout<<"\nRecursive\t"<<ks.recursive(wt,val,W,size);
    cout<<"\nMemoization\t"<<ks.memoization(wt,val,W,size);
    cout<<"\nTopdown\t\t"<<ks.topdown(wt,val,W,size);
    getch();
    return 0;
}