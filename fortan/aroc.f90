program aroc

implicit none

real:: radii , area
real,parameter :: pi=3.14

print * , "Enter the radius of a circle"
read *, radii

area = pi*radii*radii;

print * , "Area of a circle =  " , area 

end program aroc
