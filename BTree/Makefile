btree.exe:btree.o
	gcc -o $@  $<
btree.o:btree.c
	gcc -o $@ -c $<

.PHONY:clean
clean:
	rm -rf *.o *.exe
