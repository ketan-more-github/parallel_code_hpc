

program switch
implicit none

character(len=10) :: inp
print * , "Enter the color of signal"
read *, inp

select case(inp)
case ("red")
    print * , "You Have to Stop "
    
 case ("yellow")
    print * , "You Have to wait "
    
    case ("green")
        print * , "You CAn Gooooo " 
          case ("orange")
              print * , "JAy shree ram"
            case default
            	print * , "Enter Valid COLOUR"
 end select

end program switch 




