//To be used in expenses.c
extern double totalHours();        
extern void convertDayAndHour();     

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
extern void getMealFees();


//Variables 
extern int numberOfDays; 
extern int departure, arrival;
extern double hourTotal;
extern double testAirfare;
extern double testCarRental;
extern double testTaxi;
extern double travelFeesTotal;
//If these variables are global, we would not need setFareTravels
//just need to add #include "../include/main.h" to other files to work