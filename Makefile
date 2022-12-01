CC = gcc
MAIN = src/travelExpenseMain.c
EXPENSES = src/expenses.c
MILES = src/milesDrivenLodgingParking.c
TRAVELFEES = src/travelFees.c

all: program

program: src

	$(CC) -o bin/program $(MAIN) $(EXPENSES) $(MILES) $(TRAVELFEES)

run: bin
	bin/program.exe