# to see the value of a string ps string
define ps
print $arg0._M_dataplus._M_p
end

file .libs/testLogger
break main
run
break __cxa_throw
cont
