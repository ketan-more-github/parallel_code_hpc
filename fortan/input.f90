program add

implicit none

logical:: a , b , and_val , or_val


print * , "Enter Input value (Logical)"
read *, a
print * , "Enter  value= " , a

print * , "Enter Input value (Logical)"
read *, b
print * , "Enter  value = " , b

and_val = a .and. b
or_val =  a .or. b
print * , "and_value = " , and_val , "or_value = " , or_val

end program add
