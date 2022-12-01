CC = gcc
MAIN = src/travelExpenseMain.c
INPUT = src/expenses.c
OUTPUT = src/milesDrivenLodgingParking.c
METHODS = src/travelFees.c

all: program

program: src

	$(CC) -o bin/program $(MAIN) $(INPUT) $(OUTPUT) $(METHODS)

run: bin
	bin/program.exe