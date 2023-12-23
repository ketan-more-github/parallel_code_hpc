program fun2
implicit none


integer:: radius, areaof_circle
print * , "Enter the radius"
read *, radius
print * , "Enter radius = " , radius

print *,"area of circle  = " , areaof_circle(radius)

end program fun2



function areaof_circle(a)

implicit none
integer :: a , areaof_circle
areaof_circle = 3.14*a*a

end function areaof_circle




