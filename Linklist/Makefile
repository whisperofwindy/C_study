EXE:=Linklist.exe
OBJS:=Linklist.o
CFLAGS:=-Wall -O2 -fPIC
LIBFUNCSO:=libfunc.so
LIBFUNCA:=libfunc.a

$(EXE):$(OBJS)
	gcc -o $@ $<
Linklist.o:Linklist.c
	gcc -c $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -rf $(EXE) $(OBJS)


