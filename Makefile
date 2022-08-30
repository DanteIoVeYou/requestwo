CC=g++
cli:main.cpp requestwo.cpp utils.cpp socket.cpp unittest.cpp 
	$(CC) -o $@ $^ 
.PHONY:clean
clean:
	rm -f cli