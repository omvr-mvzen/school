# Variables
CC=gcc
CFLAGS= -c -Wall

all: student

student: main.o student.o student_data_handler.o
	$(CC) main.o student.o student_data_handler.o -o student

# .o files
main.o: main.c
	$(CC) $(CFLAGS) main.c

student.o : student.c
	$(CC) $(CFLAGS) student.c

student_data_handler.o: student_data_handler.c
	$(CC) $(CFLAGS) student_data_handler.c

clean:
	rm -rf *.o