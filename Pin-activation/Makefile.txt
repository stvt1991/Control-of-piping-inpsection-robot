CC = gcc
EXEC = result
CFLAGS = -lpthread -lrt -DBB_BLACK   

all: clean $(EXEC)

$(EXEC):  activation.o main.o

	$(CC) -o $(EXEC) main.o activation.o  -lpthread

activaton.o:

	$(CC) -o activation.o -c activation.c $(CFLAGS)

main.o:
	$(CC) -o main.o -c main.c  $(CFLAGS)
		
clean:

	rm -rf *.o 
	rm -rf $(EXEC)