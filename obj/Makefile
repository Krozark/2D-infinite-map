OBJ = $(wildcard *.o)

all: $(EXEC)
	
$(EXEC): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o "$(TOP)/$(EXEC)"

clean:
	@rm -f *.o
