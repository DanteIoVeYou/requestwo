CC=g++
cli:main.cpp requestwo.cpp utils.cpp socket.cpp
	$(CC) -o $@ $^
.PHONY:clean
clean:
	rm -f cli