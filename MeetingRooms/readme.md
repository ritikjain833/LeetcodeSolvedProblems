
Meeting Rooms 252: </br>

Given an array of meeting time intervals consisting of start and end times[[s1,e1],[s2,e2],...](si< ei), determine if a person could attend all meetings.</br>


Approach:</br>
sort by starting times and if i.end>(i+1).start then return false 

return true </br>


Meeting Rooms II 253. </br>

Problem https://www.interviewbit.com/problems/meeting-rooms/  </br>

Approach:</br>

Sort by starting times </br>
use a minheap to store the ending times. </br>

if start_time<=pq.peek() reduce the number of rooms and top too. </br>
add the endtime to the pq;





