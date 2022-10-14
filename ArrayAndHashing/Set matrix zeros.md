[Question link](https://leetcode.com/problems/set-matrix-zeroes/)
# Set matrix zeros

Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
![img](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)
```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```
![img](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)
```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```
## Approach 1 (Using 2d matrix)

Time complexity : O(M\*N\*(M+N))  
Space complexity : O(M\*N)

```cpp
void setZeroes(vector<vector<int>>& matrix) {
    int i, j, p, q, m=matrix.size(), n=matrix[0].size();
    vector<vector<int>> z(m, vector<int>(n, 1));
    for(i=0; i<m; i++) 
        for(j=0; j<n; j++) 
            if(matrix[i][j]==0) {
                for(p=0; p<m; p++) z[p][j]=0;
                for(q=0; q<n; q++) z[i][q]=0;
            }
        
    for(i=0; i<m; i++) 
        for(j=0; j<n; j++) 
            matrix[i][j] *= z[i][j];
    
}
```
## Approach 2 (constant space)
Time complexity : O(M\*N\*(M+N))  
Space complexity : O(1)

wont be accepted on leetcode becoz input can also contain -1

```cpp
void setZeroes(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    //set entire R and C -1 except for zero
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(matrix[i][j]==0){
                for(int p=0;p<n;p++)
                    if(matrix[p][j])
                        matrix[p][j]=-1;
                for(int q=0;q<m;q++)
                    if(matrix[i][q])
                        matrix[i][q]=-1;
            }
    for(auto &it:matrix)
        for(auto &i:it)
            if(i==-1)i=0;

    return matrix;
}
```
## Approach 3 (Using two 1d matrix)

Time complexity : O(M\*N)  
Space complexity : O(M+N)

```cpp
void setZeroes(vector<vector<int>>& a) {
    int n=a.size(), m=a[0].size();
    vector<int> row(n,1),col(m,1);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]==0)
                row[i]=col[j]=0;

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        if(row[i]==0 || col[j]==0)
            a[i][j]=0;
}
```

## Approach 4 (Constant space)

Time complexity : O(M\*N)  
Space complexity : O(1)

```cpp
void setZeroes(vector<vector<int>>& matrix) {
    bool r=0,c=0;
    int n=a.size(), m=a[0].size();
    for(int i=0;i<n;i++)if(a[i][0]==0){r=1;break;}
    for(int j=0;j<m;j++)if(a[0][j]==0){c=1;break;}
    
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(a[i][j]==0)
                a[i][0]=a[0][j]=0;
    //traversing 0th column
    for(int i=1;i<n;i++)
        if(a[i][0]==0)
            for(int j=1;j<m;j++)
                a[i][j]=0;
    //traversing 0th row
    for(int j=1;j<m;j++)
        if(a[0][j]==0)
            for(int i=1;i<n;i++)
                a[i][j]=0;
    
    if(r) for(int i=0;i<n;i++) a[i][0]=0;
    if(c) for(int j=0;j<m;j++) a[0][j]=0;
}
```

## Approach 5 (Most optimized, complexity same as above)

Time complexity : O(M\*N)  
Space complexity : O(1)

```cpp
void setZeroes(vector<vector<int>>& matrix) {
    int i, j, n=matrix.size(), m=matrix[0].size();
    bool col0=0;
    for(i=0; i<n; i++) {
        if(matrix[i][0]==0) 
            col0 = 1;
        for(j=1; j<m; j++)
            if(matrix[i][j]==0)
                matrix[i][0] = matrix[0][j] = 0;
    }
    for(i=n-1; i>=0; i--) {
        for(j=m-1; j>0; j--)
            if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;
        if(col0) 
            matrix[i][0]=0;
    }
}
```