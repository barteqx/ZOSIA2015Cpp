CC = g++-mp-4.9

%:
		clear && \
	$(CC) $@.cpp -o $@.o --std=gnu++1y \
		&& echo '\n-------' \
		&& ./$@.o \
		&& echo '-------\n' \
		&& rm $@.o \

clean:
	rm *.o
