1.	Imagine that the contents of queue Q1 and queue Q2 are as shown. What would be the contents of Q3 after the following code is executed? The queue contents are shown front(left) and rear(right).
Q1: 42 30 41 31 19 20 25 14 10 11 12 15
Q2: 4 5 4 10 13

	1.	Q3 = createQueue
	2.	count=0
	3.	loop (not empty Q1 and not empty Q2)
		a.	count:=count+1
		b.	dequeue (Q1, x)   // remove element from Q1 and store it in x
		c.	dequeue(Q2, y)  // remove element from Q2 and store it in y
		d.	if (y equal count)
			i.	enqueue (Q3, x) 
		e.	end if
	4.	end loop

empty


2.	What would be the contents of queue Q1 after the following code is executed and the following data are entered?

	1.	Q1 = createQueue
	2.	S1 = createStack
	3.	Loop(not end of file)
		a.	Read number
		b.	If(number not 0)
		i.	Pushstack(S1, number)
		c.	Else
			i.	Popstack(S1,x)
			ii.	Popstack(S1,x)
			iii.	Loop (not empty S1)
				1.	Popstack(S1, x)
				2.	Enqueue(Q1, x)
			iv.	End loop
		d.	End if
	4.	End loop

The data are 5, 7, 12, 4, 0, 4, 6, 8, 67, 34, 23, 5, 0, 44, 33, 22, 6, 0