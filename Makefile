MAIN = src/travelExpenseMain.c
TRAVELFEES = src/travelFees.c
EXPENSES = src/expenses.c
LODGING = src/milesDrivenLodgingParking.c

all: output

program: src
    gcc -o bin/output $(MAIN) $(EXPENSES) $(TRAVELFEES) $(LODGING)

run: bin
    bin/output.exe