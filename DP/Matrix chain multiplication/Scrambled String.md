[Link](https://leetcode.com/problems/scramble-string/)
# Check if a string is a scrambled form of another string
Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.<br><br>
**Scrambled string**<br>
Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.<br>
```
Below is one possible representation of str = “coder”:
    coder
   /    \
  co    der
 / \    /  \
c   o  d   er
           / \
          e   r

To scramble the string, we may choose any non-leaf node and swap its two children. 
Suppose, we choose the node “co” and swap its two children, it produces a scrambled string “ocder”.
    ocder
   /    \
  oc    der
 / \    /  \
o   c  d   er
           / \
          e   r
```
**Thus, “ocder” is a scrambled string of “coder”.**
## Recursive
