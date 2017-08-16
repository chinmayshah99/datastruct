# Task 2

Identify suitable data structure for given scenarios. Specify reason for it.


1.	To implement a system for reversing a word.
•	Stack – Because you want to reverse the word, it should be last in first out. 
•	Array – The access time in array will be really fast ( just output in reverse order) 
Both Stack and Array has it’s own benefits with array providing faster access and storage solution. 
2.	To implement printer spooler so that jobs can be printed in the order of the arrival.
•	Queue – The concept of first in first out is needed here. 
Array can be a possible solution but as it is printer spooler, the size of each request may vary and thus queue is appropriate. 
3.	To represent an image in a form of bitmap.
•	Bitmap is 2-D array. So a 2-D array of a struct is an appropriate solution
4.	For representing a city region telephone network.
•	It will be combination of Tree and Undirected graph. 
The landlines connected at home are connected to telephone exchange like a Tree. The telephone exchanges are connected to each other which is basically a undirected graph.
5.	To store information about the directories and files in a system.
•	Tree – File system is basically root followed by sub-roots which are folders. The files are leaves which are at end. 
6.	To implement a system for parsing syntax.
•	Queue – This is because you start reading the file from left to right top to bottom. Which is basically a first in first out. 
Array could have been a solution, but when you change the code(in the middle) , it would have been in-efficient both memory and time consuming. 
7.	To implement back functionality in web browser.
•	Double- connected linked list – This is because when you click the back button, you can visit any page that you have visited in the random order and also can also be back to the current tab with forward button. 
8.	To record sequence of all the pages browsed in one session.
•	Stack- This is because all of them will be with time-stamp which will be in particular order. Also as you browse, you keep adding them on top of the existing history. 
9.	To process network packets coming to the router.
•	Queue – This will keep transmitting packets as soon as they arrive -first in first out
•	Directed Graph- This will be used for finding the destination, like packets from one router will be sent to another on basis of destination location on packet by finding the appropriate router using the directed graph. 
•	Linked List – This is because as packets keep on arriving, the destination will combine the packets. 
10.	To represent machines on internet and to find optimal path between source machine and destination machine to send data.
•	Undirected graph- This will be used to find the shortest distance on basis of minimum nodes to the destination. 
•	Tree- Once it reaches a node on LAN, let’s say main SVKM router, it’s tree as router acts as root and all devices connected to it are it’s leaves. 
11.	To represent connections\relations in social networking sites.
•	Undirected graph- Because each user is connected to other user somehow. Friends connected are mutual. 
•	But if user follows someone, and they aren’t mutually following back, it’s a directed graph. Ex fan following of celebrity on twitter. 
12.	Google maps to travel from your home to office in minimum time.
•	Undirected graph-  This is basically a shortest path problem, which is undirected graph. 