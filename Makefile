output: travelExpenseMain.o expenses.o travelFees.o milesDrivenLodgingParking.o
	gcc travelExpenseMain.o -o output

travelExpenseMain.o: travelExpenseMain.c
	gcc -c travelExpenseMain.c

expenses.o: expenses.h
	gcc -c expenses.h

travelFees.o: travelFees.h
	gcc -c travelFees.h

milesDrivenLodgingParking.o: milesDrivenLodgingParking.h
	gcc -c milesDrivenLodgingParking.h

clean:
	rm *.o output
