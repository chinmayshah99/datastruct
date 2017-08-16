# Task 1
Identify appropriate data structuring to solve below problem:
Suppose there are three diamond needles. Stacked on the first diamond needle were 64 gold disks of decreasing size. The one disk is moved to another needle each hour, subject to the following rules:
1.	Only one disk could be moved at a time. A larger disk must never be stacked above a smaller one.
2.	One and only one auxiliary needle could be used for the intermediate storage of disks.
Develop algorithm with appropriate data structuring identified in first step and write the code for the same.

## Solution

_Stack_ will be the appropriate data structure. 
Let N1, N2 and N3 be the needles. And D1, D2, D3, D4 be the discs with number corresponding to their radii. 
1.	D1 TO N3
2.	D2 TO N2
3.	D1 TO N2
4.	D3 TO N3
5.	D1 TO N1
6.	D2 TO N3
7.	D1 TO N3
8.	D4 TO N2
9.	D1 TO N2
10.	D2 TO N1
11.	D1 TO N1
12.	D3 TO N2
13.	D1 TO N3
14.	D2 TO N2
15.	D1 TO N2
This can be extended to set of any set of discs. 

Algorithm can be generalized something on similar line: 
1.	Find the highest accessible number
2.	If the needle is empty move it. 
3.	If not then access lowest disc radii and 2nd smallest element should not be the same needle and move it. 
4.	If 2nd smallest disc is on same needle then move it to highest possible disc that can be accessed. 
The algorithm is just generalized and haven’t been run on test cases so I’m not sure about it’s validity. 
