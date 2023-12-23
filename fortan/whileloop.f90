
program doloop
implicit none

integer :: i
i=5
 do while(i<=100)
 i = i+1
   if(i<10) then
   print *,i
   end if
 end do

end program doloop 




