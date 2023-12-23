!do while mense while loop
!do loop is like for

program loops
implicit none

integer:: marks
character(len=2) :: c
print * , "Enter the marks of student"
read *, marks
touch 
if(marks>=85 .and. marks<=100) then
 c = 'A+'
 else if(marks<85 .and. marks>=75)then
 c = 'A'
 else if(marks<75 .and. marks>=65)then
 c = 'B+'
 else if(marks<65 .and. marks>=55)then
 c = 'B'
 else if(marks<55 .and. marks>=35)then
 c = 'C'
 else
 c = 'F'
end if

if(c=='F')then
print * , "You are  FAIL"
end if
print *, "Your Grade is = ", c 

end program loops 




