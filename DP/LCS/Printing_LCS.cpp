#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void LCS(string a,string b){
    //solving using DP becoz why not
    int dp[a.size()+1][b.size()+1];

    //filling table
    for(int i=0;i<=a.size();i++)
        for(int j=0;j<=b.size();j++){
            if(i==0 || j==0) 
                dp[i][j]=0; // i==0 || j==0, no string so length of LCS = 0
            else if(a[i-1] == b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }

    //printing
    int i=a.size(),j=b.size();
    string ans="";
    while(i>0 && j>0)
        if(a[i-1] == b[j-1])
            ans+=a[i-1], i--,j--;
        else
            dp[i][j] == dp[i-1][j]?i--:j--;

    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
}
int main(){
    //here
    string a,b;
    cout<<"string A & B input dedo\n";
    cin>>a>>b;
    LCS(a,b);
    getch();
    return 0;
}