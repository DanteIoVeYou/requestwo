CC=g++
cli:main.cpp requestwo.cpp utils.cpp socket.cpp unittest.cpp
	$(CC) -o $@ $^ -std=c++17
.PHONY:clean
clean:
	rm -f cli