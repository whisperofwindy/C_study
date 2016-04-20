EXE:=LinkStack.exe
OBJS:=LinkStack.o
SOURCES:=LinkStack.c
CFLAGS:= -Wall -O2 -g

$(EXE):$(OBJS)
	gcc -o $@ $<
$(OBJS):$(SOURCES)
	gcc -o $@ -c $<

.PHONY:clean
clean:
	rm -rf $(EXE) $(OBJS)


