.DEFAULT_GOAL := bin/nightwing

make: 
	lbtcli -m .lbt
	
clean: 
	rm -f obj/*.o obj/lib/*.o bin/nightwing
	
bin/nightwing: build/__src_app.o build/__src_main.o 
	c++  -o $@ $^ `pkg-config --libs --cflags xcb` -ggdb 

build/__src_app.o: src/app.cc src/app.h src/config.h
	c++ `pkg-config --libs --cflags xcb` -ggdb -c -o build/__src_app.o ./src/app.cc

build/__src_main.o: src/main.cc
	c++ `pkg-config --libs --cflags xcb` -ggdb -c -o build/__src_main.o ./src/main.cc

