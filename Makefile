CC=g++
cli:main.cpp
	$(CC) -o $@ $^
.PHONY:clean
clean:
	rm -f cli