CC=gcc

all: travelFeesDemo 
travelFees.o: travelFees.c 
	$(CC) -c travelFees.c -o travelFees.o 
travelFeesTest.o: travelFeesTest.c 
	$(CC) -c travelFeesTest.c -o travelFeesTest.o 
travelFeesDemo: travelFeesTest.c travelFees.c
	gcc -o travelFeesDemo travelFeesTest.c travelFees.c
clean:  
	del travelFeesDemo.exe travelFees.o travelFeesTest.o