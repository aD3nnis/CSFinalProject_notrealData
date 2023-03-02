#ifndef COIN_H
#define COIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Coin{

private:
//vector coin objects in int main;
//vector <string> coinNames;
vector<string> placeHolder;// this placeholder is ment to keep the buy fees

vector<string> wit_date; // master dates
vector<string> wit_fees_string;
vector<float> wit_fees;// master withdrawal fees


string name; // has no real purpose yet
vector<string> buyFeesData;
vector<string> allData; // grabs all data from the buy fees file
//vector<string> month;
vector<string> date;
vector<string> _open;
vector <float> open;
//vector<float> floatOpen;

vector<string> _close;
vector<float> close;
vector<vector <string> > masterWithdrawal_info; // this will hold three different vectors
// a vector of vectors is something that I talked to scott about and should be helpful
// one for fees for the coin, one for dates, 
// we need coin to hold all the above
vector<float> average;
vector<float> all_with;
float sum;
float all_sum;

public:
Coin();
Coin(string line);
void getsumOfBuy(string COIN);
void comvertToInt(vector<string> Ph);

void print();
// this makes sure that the file can be opened
void fileFound(string fileName);
// this reads the file for CSV files
// why it is just CSV files is because in the getline function call 
// we have a comma 
// void readFile_CSV_files(string fileName);
void readFile_CSV_files_2(string fileName);
//void setDates_masterFile();
void setDates_OpenCloseFile(string COIN);
void readFile_withdrawal(string fileName);
void setBuyFees(string COIN);
void setBuyFees_ALL();
void getWithMasterInfo(string COIN);
void convertDate();
void compareDates(string COIN);
void average_OC();
void convertToDecimal(vector<string> convert, vector<float> &newVector);
void withFeesinUSD_sum(string COIN);
void addWith();
void addWith_after();

};



#endif