//To be used in expenses.c
extern double totalHours(int, int, int);        
extern void convertDayAndHour(double);     

//To be used in travelFees.c
extern int getAmount();                          
extern double getTotal(); 
extern double airfareAmount();                  
extern double taxiAmount();                       
extern double carRental();    

//To be used in calculateExpenses.c
extern double calculateTotalExpenses();
extern double calculateAllowableExpenses();

//To be used in otherExp.c
extern double registrationFee();
extern double getMealFees();


//To be used in milesDrivenLodgingParking.c
extern double parkingFee(int);
extern double hotelExpense(int);
extern double milesDriven();

//To be used in travelExpenseMain.c
extern void setTravelValues();
extern void setFareValues();
extern void displayResults();

//Variables 
extern int numberOfDays; 
extern int departure, arrival;
extern double hourTotal;
extern double testAirfare;
extern double testCarRental;
extern double testTaxi;
extern double travelFeesTotal;
extern double totalMiles;
extern double totalHotelExpense;
extern double totalParkingFees;
extern double grandTotal;
extern double hotelAllowance;
extern double parkingAllowance;
extern double totalMileDrivenAllowance;
extern double totalAllowance;
extern double registrationFees;
extern double mealTotal;
extern double totalReimbursement;
extern double totalMilesDrivenAllowance;
extern double totalAmountSaved;

