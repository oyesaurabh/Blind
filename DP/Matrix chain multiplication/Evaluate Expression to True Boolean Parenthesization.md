[Link](https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1)
# Evaluate Expression to True Boolean Parenthesization 
Given a boolean expression S of length N with following symbols.<br>
**Symbols**<br>
    'T' ---> true<br>
    'F' ---> false<br>
and following operators filled between symbols<br>
**Operators**<br>
    &   ---> boolean AND<br>
    |   ---> boolean OR<br>
    ^   ---> boolean XOR<br>
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.<br>
```
Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.
```
## Recursive
```cpp
class Solution{
int solve(string str, int i, int j, int istrue)
    {
        if(i>j)return 0;
        if(i==j){  //if only one element 
            if(istrue)return str[i]=='T';   
            else return str[i]=='F';
        }     
        int ans=0;
        
        for(int k=i+1;k<=j-1;k=k+2) //jumping form operator to operator
        {
            int leftT=  solve(str,i,k-1,1);
            int leftF=  solve(str,i,k-1,0);
            int rightT= solve(str,k+1,j,1);
            int rightF= solve(str,k+1,j,0);
         
            if(str[k]=='^')
            {
                if(istrue)
                ans+=(leftT*rightF) + (leftF*rightT);
                else ans+=(leftT*rightT) + (leftF*rightF) ;
            }
            else if(str[k]=='&')
            {
                if(istrue)
                ans+=(leftT*rightT);
                else ans+=(leftT*rightF) + (leftF*rightT) + (leftF*rightF);
            }
            else if(str[k]=='|')
            {
                if(istrue)
                ans+=(leftT*rightF) + (leftF*rightT) + (leftT*rightT);
                else ans+=(leftF*rightF) ;
            }
        }
        return ans;
    }
public:
    int countWays(int N, string S){
        return solve(S,0,N-1,1);
    }
};
```

## Dynamic Programming
```cpp
class Solution{
    int dp[201][201][2];
    int mod=1003;
int solve(string str, int i, int j, int istrue)
    {
        if(i>j)return 0;
        /*Just this line is extra*/
        if(dp[i][j][istrue] != -1)return dp[i][j][istrue];

        if(i==j){
            if(istrue)return str[i]=='T';   
            else return str[i]=='F';
        }     
        int ans=0;
        
        for(int k=i+1;k<=j-1;k=k+2)
        {
            int leftT=  solve(str,i,k-1,1);
            int leftF=  solve(str,i,k-1,0);
            int rightT= solve(str,k+1,j,1);
            int rightF= solve(str,k+1,j,0);
         
            if(str[k]=='^')
            {
                if(istrue)
                ans+=(leftT*rightF) + (leftF*rightT);
                else ans+=(leftT*rightT) + (leftF*rightF) ;
            }
            else if(str[k]=='&')
            {
                if(istrue)
                ans+=(leftT*rightT);
                else ans+=(leftT*rightF) + (leftF*rightT) + (leftF*rightF);
            }
            else if(str[k]=='|')
            {
                if(istrue)
                ans+=(leftT*rightF) + (leftF*rightT) + (leftT*rightT);
                else ans+=(leftF*rightF) ;
            }
        }
        /*And this line is extra*/
        return dp[i][j][istrue]=ans%mod;
    }
public:
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(S,0,N-1,1);
    }
};
```