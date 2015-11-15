project: std.o 
	 cc std.o -o project
std.o:  std.c miniproject.h 
	cc -Wall -c std.c 

