CC=gcc

all: travelFeesDemo 
unitTest: travelFeesUnitTest
travelFees.o: travelFees.c 
	$(CC) -c travelFees.c -o travelFees.o 
travelFeesTest.o: travelFeesTest.c 
	$(CC) -c travelFeesTest.c -o travelFeesTest.o 
travelFeesDemo: travelFeesTest.c travelFees.c
	gcc -o travelFeesDemo travelFeesTest.c travelFees.c

travelFeesUnitTest: travelFeesUnitTest.c travelFees.c
	gcc -o travelFeesUnitTest travelFeesUnitTest.c travelFees.c
travelFeesUnitTest.o: travelFeesUnitTest.c
	$(CC) -c travelFeesUnitTest.c -o travelFeesUnitTest.o 

clean:  
	del travelFeesDemo.exe travelFees.o travelFeesTest.o travelFeesUnitTest.exe travelFeesUnitTest.o