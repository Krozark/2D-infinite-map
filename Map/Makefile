all: main.exe

.cpp.o:
	$(CC) $(FLAGS) -o "$@" -c "$<" 
	@cp $@ "$(OBJ_DIR)"

.c.o:
	$(CC) $(FLAGS) -o "$@" -c "$<"
	@cp $@ "$(OBJ_DIR)"


main.exe: main.cpp Tile.hpp Tile.o TileIsoHexa.o Area.hpp Map.hpp AreaManager.hpp AreaLoader.hpp ../Config.o
	$(CC) $^ $(FLAGS) -o $@


clean:
	@rm -f *.o
	@rm -f *.exe
	@rm -f ../*.o
