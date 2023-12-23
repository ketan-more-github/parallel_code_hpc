
program doloop
implicit none

Integer(Kind =8) :: i,fact , num
print * , "Enter the num to get table"
read *, num



! do v = 1, 10
!print * , num*v
!end do



fact = num

do i = num-1,1,-1
	fact = fact*i
end do

write(* , '(i4,a,i15)') num , "!=" , fact

end program doloop 




