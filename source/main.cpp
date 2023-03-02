#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "coin.h"
using namespace std;
// questions for scott:
// can you have a varaible that is constant with the file name
// so if we were to open file but change the name of the file
// can we make it so that it still opens the correct file?

//    newGame = line.substr(game+1,string::npos);
// the above line doesnt work unless I put + 1 to game, why?
/*
purpose:
what we want the data to do is to take the fees of the coinbase file and add them to the withdrawl fees
the coinbase file fees are in USD and the withdrawl fees are specific to the tokens.
what the code will do is ask the user which coin they would like to know the total fees of
it will then take that input find the fees in the coinbase file then find the fees in the
withdrawl file, convert those fees to USD and then add them together. that will give you the total fees

we have one class that is USD - its simbolizes that we are converting to us dollars 
the idea is to have one class where we do all our transactions
the behaviors would be to get withdrawl fees and total fees
from files 

time chunk or day has a utc time stamp it will cointain behaviors for averging 
it will hold data and pricing
vector of time chunks
look at label of coin find the coin object and then from their figure out the day

x-axis time
y - axis is value
tt - when you made transaction
porportions
// making a function that gets buy value

*/
//vector<Coin*> readFile(string fileName);

// void fileFound(string fileName);
// void readFile(string fileName,vector<string>& allData);
//  void getBuyFees(string COIN,vector<string> allData);
void ALL_buy(Coin test);
void ONE_buy(Coin test);
void ALL_withdrawal(Coin test, string COIN_ALL[]);
void ONE_withdrawal(Coin test);
string COIN_ALL[11] = {"ADA", "ALGO","BTC","DOT","ETH","FET","MATIC","RNDR","SKL","SOL","USDT"};
int main(){

Coin test; 
string answer;
cout << "ALL or ONE coin buy fees? " << endl;  
cin >> answer;   
if (answer == "ALL"){
  ALL_buy(test);
} else if (answer == "ONE"){
  ONE_buy(test);
} 
//string csvFile ="tests/" + COIN +".csv";

cout << "ALL or ONE coin withdrawal fees? " << endl; 
cin >> answer; 
if (answer == "ALL"){
  ALL_withdrawal(test,COIN_ALL);

} else if (answer == "ONE"){
  ONE_withdrawal(test);
} 






/////////// BELOW IS FOR WITHDRAWALS //////////////////////
// Coin with;
//  string file_Withdrawal = "tests/Withdrawal fees CB.txt";
//  test.fileFound(file_Withdrawal);
//   test.readFile_withdrawal(file_Withdrawal);
//    test.getWithMasterInfo(COIN); // gets withdrawal fees from mater file
//     test.convertDate();
//      test.fileFound(csvFile);
//        test.readFile_CSV_files_2(csvFile);
//          test.setDates_OpenCloseFile(COIN);
//           test.average_OC();
//            test.compareDates(COIN);
//             test.withFeesinUSD_sum(COIN);
// ///////

/*
STEPS:
1. find file
2. read file == put in all data vector
3. get specific info in file. meaning seperate info out of all data vector
4. convert the dates from master file to look like token csv files and make that the new dates
5. open the csv files
6. put csv file into all data 
7. take all data vector and seperate it into dates, open, and close vectors
8. take the open and close and make an average
9. comare master withdrawal file and token csv file to find equal dates
10. once you have equal dates set the wit_fees == the average * wit_fees
*/
cout << "end of main " << endl;




}
void ALL_buy(Coin test){

//string csvFile ="tests/" + COIN +".csv";
string file_Buy= "tests/fileReportCyrptoCoinBsMay5th.csv";
test.fileFound(file_Buy);// this just makes sure that the file can be opened
test.readFile_CSV_files_2(file_Buy); 
 test.setBuyFees_ALL();
 //test.print();
 test.getsumOfBuy("ALL");
}
void ONE_buy(Coin test){
string COIN;  
cout << "what coin do you want the fees of? " << endl;
cout << "enter name: "; 
cin >> COIN;
bool equals = false;
for (int i = 0; i < 11; i++){
if (COIN == COIN_ALL[i]){
equals = true;
}
}
if(equals){
 string csvFile ="tests/" + COIN +".csv";
string file_Buy= "tests/fileReportCyrptoCoinBsMay5th.csv"; // this is the master coinbase file with info
test.fileFound(file_Buy);// this just makes sure that the file can be opened
test.readFile_CSV_files_2(file_Buy); 
test.setBuyFees(COIN);
 //test.print();
test.getsumOfBuy(COIN); 
}else if (!equals){
  cout << "coin not found \n";
  ONE_buy(test);
}
//cout << "what coin do you want?" << endl;
// cin >> COIN;



}
void ALL_withdrawal(Coin test,string COIN_ALL[]){
for (int i = 0; i < 11; i++){
  string csvFile ="tests/" + COIN_ALL[i] +".csv";
  string file_Withdrawal = "tests/Withdrawal fees CB.txt";
 test.fileFound(file_Withdrawal);
  test.readFile_withdrawal(file_Withdrawal);
   test.getWithMasterInfo(COIN_ALL[i]); // gets withdrawal fees from mater file
    test.convertDate();
     test.fileFound(csvFile);
       test.readFile_CSV_files_2(csvFile);
         test.setDates_OpenCloseFile(COIN_ALL[i]);
          test.average_OC();
           test.compareDates(COIN_ALL[i]);
            test.withFeesinUSD_sum(COIN_ALL[i]);
            test.addWith();
}
test.addWith_after();
}



void ONE_withdrawal(Coin test){
  string COIN;
cout << "what coin do you want the fees of? " << endl;
cout << "enter name: "; 
cin >> COIN;
bool equals = false;
for (int i = 0; i < 11; i++){
if (COIN == COIN_ALL[i]){
equals = true;
}
}
if(equals){
  string csvFile ="tests/" + COIN +".csv";
    string file_Withdrawal = "tests/Withdrawal fees CB.txt";
 test.fileFound(file_Withdrawal);
  test.readFile_withdrawal(file_Withdrawal);
   test.getWithMasterInfo(COIN); // gets withdrawal fees from mater file
    test.convertDate();
     test.fileFound(csvFile);
       test.readFile_CSV_files_2(csvFile);
         test.setDates_OpenCloseFile(COIN);
          test.average_OC();
           test.compareDates(COIN);
            test.withFeesinUSD_sum(COIN);
}else if (!equals){
  cout << "coin not found" << endl;
  ONE_withdrawal(test);
}


}