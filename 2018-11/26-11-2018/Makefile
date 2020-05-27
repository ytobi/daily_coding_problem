solution: solution.o handy_list.o handy_hashtbl.o
	gcc -o solution solution.o handy_list.o handy_hashtbl.o

solution.o: solution.c
	gcc -c solution.c

handy_list.o: ../../handy/include/handy_list.c
	gcc -c ../../handy/include/handy_list.c
handy_hashtbl.o: ../../handy/include/handy_hashtbl.c
	gcc -c ../../handy/include/handy_hashtbl.c
	
clean:
	rm *.o
