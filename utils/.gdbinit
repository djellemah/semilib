# to see the value of a string ps string
define ps
print $arg0._M_dataplus._M_p
end

file .libs/testFileLogger
#set args "select * from sales where qty = 0"
break main
run
break __cxa_throw
break FileLogger::FileLogger(std::string const&, std::string const&)
cont
