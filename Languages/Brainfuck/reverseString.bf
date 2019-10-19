[
	VARIABLE LENGTH STRING REVERSER
	
	This program takes TWO digits of string length and then the string
	immediately after that to output the inputString in reversed order
		This is a good excercise in BrainFuck and also demonstrates how
		inefficient this language is, even for such a simple task.
	This block will be as good as a comment because the starting cell
	is always zero, thus acting like a while(false) loop.
	
	Author: makeway4pk
]
c#1 means cell number 1 (starting)

Obtaining 48 by its prime factors
+++[	c#1  3 
>++[	c#2 x2  
>++[	c#3 x2 
>++[	c#4 x2 
>++[	c#5 x2 
>+		c#6 x1 
<-]<-]<-]<-]<-]	closed all loops
c#1

Taking in string length digits in two cells before 48
>>>>,	c#5
<,		c#4
c#4

Subtracting stored 48(ASCII: '0') from both digits
>>[		c#6 counter=48
<-<-	c#5 & #4
>>-]	c#6 exit cond check & exit
c#6

Adding tens value(c#5) to the ones value(c#4)
<[			c#5 counter
<++++++++++	c#4 add 10
>-]			c#5 exit
c#5

Copy strLength to c#2
<[<<+>>-]
c#4

Using c#2 as counter
<<[
	>,				c#3 Input 
	<[>>+<<-]		copy counter to c#4
	>>-				decrement and repeat
]
c#(next to last input)

Output reversed and alternating
<[.<<]