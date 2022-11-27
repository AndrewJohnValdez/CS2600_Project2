
output: travelExpenseMain.o expenses.o
	gcc travelExpenseMain.o -o output
travelExpenseMain.o: travelExpenseMain.c
	gcc -c travelExpenseMain.c
expenses.o: expenses.h
	gcc -c expenses.h

travelFeesDemo: travelFeesDemo
travelFeesUnitTest: travelFeesUnitTest
travelFees.o: travelFees.c 
	gcc -c travelFees.c -o travelFees.o 
travelFeesTest.o: travelFeesTest.c 
	gcc -c travelFeesTest.c -o travelFeesTest.o 
travelFeesDemo: travelFeesTest.c travelFees.c
	gcc -o travelFeesDemo travelFeesTest.c travelFees.c

travelFeesUnitTest: travelFeesUnitTest.c travelFees.c
	gcc -o travelFeesUnitTest travelFeesUnitTest.c travelFees.c
travelFeesUnitTest.o: travelFeesUnitTest.c
	gcc -c travelFeesUnitTest.c -o travelFeesUnitTest.o

clean:
	rm *.o output

cleantf:
	del travelFeesDemo.exe travelFees.o travelFeesTest.o travelFeesUnitTest.exe travelFeesUnitTest.o