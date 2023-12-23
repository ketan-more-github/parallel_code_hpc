program fun
implicit none

integer:: a, b, calc_area , perimeter
print * , "Enter Length"
read *, a
print * , "Enter  len= " , a

print * , "Enter breadth"
read *, b
print * , "Enter  bred= " , b

print *,"area of rect = " , calc_area(a,b)


call calc_peri(a,b,perimeter)

print *,"Perimeter of rect = " , perimeter

end program fun



function calc_area(a,b)

implicit none
integer :: a,b,calc_area
calc_area = a*b

end function calc_area



subroutine calc_peri(a ,b,perimeter)

implicit none
integer :: a,b,perimeter
perimeter = 2*(a+b)

end subroutine calc_peri
