output: travelExpenseMain.o expenses.o travelFees.o
	gcc travelExpenseMain.o -o output

travelExpenseMain.o: travelExpenseMain.c
	gcc -c travelExpenseMain.c

expenses.o: expenses.h
	gcc -c expenses.h

travelFees.o: travelFees.h
	gcc -c travelFees.h
	
clean:
	rm *.o output
