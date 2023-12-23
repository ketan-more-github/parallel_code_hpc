

program vector

  implicit none  
  integer :: marks(1:5)
  integer :: i, sum = 0
  real :: store
  
  call read_value(marks)
  
  do i = 1,5 
  	 print * , marks(i)             
  enddo
  
 

end program vector

subroutine read_value(Array)

	integer, intent(out), dimension(5):: Array
	
	print *, "Input 5 value insert into array  "
  
  	do i = 1, 5
  		read *, Array(i)
  	enddo
  	  
  	do i = 1, 5
  		Array(i) = Array(i)*Array(i)  
  	enddo
  	
  	
  	

end subroutine read_value
