
output: travelExpenseMain.o expenses.o
	gcc travelExpenseMain.o -o output

travelExpenseMain.o: travelExpenseMain.c
	gcc -c travelExpenseMain.c

expenses.o: expenses.h
	gcc -c expenses.h

clean:
	rm *.o output