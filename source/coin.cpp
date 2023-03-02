#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "coin.h"
using namespace std;
// the vector of the coin for fees
// and the coin name as a string
Coin::Coin()
{
  // possibly copy the coin names from buy file
}
Coin::Coin(string _name)
{
  name = _name;
  // buyFeesData.push_back(line); // this should just get the BUY fees
}


void Coin::print()
{
  for (int i = 0; i < allData.size(); i++)
  {
    cout << allData[i] << endl;
  }
}
// this will take what is in the placeholder function and
// make it so that it adds all the numbers together
// this is more difficult than it seems cause the numbers are strings
// so it has to take the decimal point into acount and grab the number
// from both sides of the decimal point
void Coin::getsumOfBuy(string COIN)
{
  float left = 0;
  string right;
  float rightNum;
  int find = 0;
  vector<float> fee;
convertToDecimal(placeHolder,fee);
  float sum;
  for (int i = 0; i < fee.size(); i++)
  {
    sum = fee[i] + sum;
  }
  if(COIN == "ALL"){
     cout << " Sum of total Buy fees for " << COIN << " coins in USD: " << sum << "$" << endl; 
  } else{
    cout << " Sum of total Buy fees for " << COIN << " in USD: " << sum << "$" << endl; 
}
}
////
// need an instance of coin first having all data in a vector
// this function will take in the file and put all the data into a vector?
void Coin::fileFound(string fileName)
{
  Coin ADA;
  ifstream fin;       // New file input stream instance
  fin.open(fileName); // Opening file name inside file input stream
  while (fin.fail())
  { // File fails to open
    cout << "File open error!" << endl;
    // cout << "Enter another file name: ";
    // cin >> fileName; // User input
    // fin.open(fileName); // Opening file again
  }
  cout << "File found! Now reading... "
       << " " << fileName << " " << endl;
  fin.close();
  // the coin we want fees of
}

// this should get all the data
// note: one of the annoying things about the csv files is that the lines dont end with a comma
// meaning you cant do a get line and seperate them based off of commas
// so this function takes that into account
// because eventually the find varaible will equal -1 because it cant find a comma
// this is an indicator that we are on the last word of the file
// so we can end the while loop and grab the last word
void Coin::readFile_CSV_files_2(string fileName)
{
  //   Coin ADA;
  // Intializing vector structure for Coin objects
  ifstream fin;       // New file input stream instance
  fin.open(fileName); // Opening file name inside file input stream
  string line;
  allData.clear(); // this is important so that when the function is called again, the data from the
  // previous function call is not already in the all Data vector
  int find;
  bool comma = true;
  bool end = false;
  bool first = true; // indicating first word
                     // getline(fin,line);
  // fin.ignore();
  while (getline(fin, line))
  { // Loops through each line in the stream

    first = true; // this is so we know that we are on the first word whenever this is called
    while (!end)
    {
      find = line.find(","); // we initally want to find a comma
      if (find < 0) // if find cant find a comma
      {
        allData.push_back(line.substr(0, string::npos)); // this will push back the rest of a line
        end = true; // this means that there is no more line left
      }
      else if (find > 0)
      { // this means that there is a distance between the starting point and a comma
        allData.push_back(line.substr(0, find)); // gets us a single word
        line = line.substr(find + 1, string::npos); // this gets the rest of the data
      }
    }
    end = false;
  }
  fin.close(); // Close file
}

//////////////////
void Coin::readFile_withdrawal(string fileName)
{
  //   Coin ADA;
  // Intializing vector structure for Coin objects
  ifstream fin;                         // New file input stream instance
  fin.open(fileName, ifstream::binary); // Opening file name inside file input stream
  string line;
  allData.clear(); // this is important so that when the function is called again, the data from the
  // previous function call is not already in the all Data vector

  int num = 0;
  int newNum = 1;
  while (getline(fin, line))
  {                  // Loops through each line in the stream
    line.pop_back(); // in theory, should remove the CR from the end

    allData.push_back(line); // this line should just get the fees of the coin
    num++;
  }
  for (int i = 0; i < allData.size(); i++)
  {
    if (i == newNum)
    {

      // cout << allData[i] << " size: " << allData[i].size()<< endl;

      newNum = newNum + 6;
    }
  }
  fin.close(); // Close file
}
void Coin::convertToDecimal(vector<string> convert, vector<float> &newVector)
{
  newVector.clear();

  int find;
  float left; // left side of float
  string Str_right; // just to get size
  float right; // right side of float
  for (int i = 0; i < convert.size(); i++)
  {
    find = convert[i].find("."); // sets find to number of spces till decimal point
    if (find > 0) // if find exists
    {
      left = stoi(convert[i].substr(0, find)); // gets left side of decimal point
      Str_right = convert[i].substr(find + 1, 3); // gets size of right into a string
      right = stoi(convert[i].substr(find + 1, 3)); // gets right side of decimal as a float

      float divide = pow(10, Str_right.size()); // get number to divide right by
      newVector.push_back(left + right / divide); // our new vector that will hold floats
      // converts right side to decimal by dividng by the size of itself 
      
    }
    else if (find < 0) // no decimal exists
    { // in this case it is -1
      newVector.push_back(0);
    }
  }
  for(int i = 0; i < newVector.size(); i++){
 // cout << "newVector: " << newVector[i] << " newVector.size(): " << newVector.size() << endl;    
  }

}

// this gets with fees for the specific coin from all Data
void Coin::getWithMasterInfo(string COIN)
{
  wit_fees_string.clear();
  int num = 0;
  int j = 0;
  for (int i = 0; i < allData.size(); i++)
  {

    if (allData[i] == COIN)
    {
      // cout << "went in if statment" << endl;
      allData[i - 1] = allData[i - 1].substr(0, 12); // to get full date

      wit_date.push_back(allData[i - 1]); // pushes back withdrawal dates

      wit_fees_string.push_back(allData[i + 1]);
      num++;
    }
  }
//cout << " wit string: " << wit_fees_string.size() << endl;
//cout << " wit_fees size: " << wit_fees.size() << endl;
  convertToDecimal(wit_fees_string, wit_fees);
  cout << "wit_fees: " << wit_fees[j] << " wit_fees size: " << wit_fees.size() << endl;
  j++;
}

/////////////
void Coin::setBuyFees(string COIN)
{

  for (int i = 0; i < allData.size(); i++)
  {
    if (allData[i] == COIN)
    {
      // cout << "allData size: " << allData[i].size() << endl;
      // line = line.substr(0, 5);
      allData[i + 2] = allData[i + 2].substr(0, 5); // this just gets 3 decimal places
      placeHolder.push_back(allData[i + 2]);
      // cout << allData[i + 2] << endl; // equal to fees
    }
  }
}

void Coin::setBuyFees_ALL()
{
  int count = -1;
  cout << allData.size() << endl;
  for (int i = 0; i < allData.size(); i++)
  {
    if (allData[i] == "fee US dollar"){ // works
      cout << "yes: " << i << endl; // i == 8
      count = i; // sets count to 8
    }
    if (i == count + 11) 
    {
      //cout << "in: " << i << endl; 
      // cout << "allData size: " << allData[i].size() << endl;
      // line = line.substr(0, 5);
      allData[i] = allData[i].substr(0, 5); // this just gets 3 decimal places
      placeHolder.push_back(allData[i]);
       cout << allData[i] << endl; // equal to fees
      count = 11 + count;
    }
  }
}

//////////////////
// this converts the date in withdrawal fees file into looking like the individual coin open and close files
void Coin::convertDate()
{
  // May 02, 2022

  string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  // this information is based off of the coin
  // so we have to make  sure when we are calling the function that we are getting the month based off
  // of what coin we want.
  string _month;
  string day; // example place holder for
  string year;
  int start;
  int end;
  for (int j = 0; j < wit_date.size(); j++)
  {
    //  cout <<"withdrawalPH[" << j <<"]: " << withdrawalPH[j] << endl;
    _month = wit_date[j].substr(0, 3); // each month is only 3 letters
    start = wit_date[j].find(" ");
    day = wit_date[j].substr(start + 1, 2);

    // cout << "day:" << day << endl;
    int pH = 0; // place holder
    for (int i = 0; i < 12; i++)
    { // we are using 12 because that is how many moths are in a year
      if (_month == month[i])
      {
        pH = i + 1;
        if (pH < 10)
        {
          _month = "0" + to_string(pH);
        }
        else if (pH > 10)
        {
          _month = to_string(pH);
        }
      }
    }
    // cout <<"withdrawalPH[" << j <<"]: " << withdrawalPH[j] << endl;
    wit_date[j] = wit_date[j].substr(start + 1, string::npos);

    start = wit_date[j].find(" ");
    // cout <<"start: " << start << endl;
    year = wit_date[j].substr(start + 1, 4);
    // cout << _month << endl;
    wit_date[j] = year + "-" + _month + "-" + day;
    // cout << wit_date[j] << endl;
  }
  // format: YYYY-MM-DD
}

//////////////////
void Coin::setDates_OpenCloseFile(string COIN)
{
  ifstream file;
  file.open("tests/" + COIN + ".csv");

  string line;
  int find;

  int i = 0;
  bool first = true;
  // bool passedThrough2 = false;
  while (getline(file, line))
  {

    //
    find = line.find(",");
    date.push_back(line.substr(0, find));
    line = line.substr(find + 1, string::npos);
    find = line.find(",");
    _open.push_back(line.substr(0, 7));
    _close.push_back(line.substr(find + 1, 7));

    i++;
    // close = line.substr(0,5);
  }
  //   for (int i = 0; i < date.size(); i ++){
  //     cout << "date: " << date[i] << endl;
  // }
  file.close();
}
void Coin::average_OC()
{

  average.clear();
  convertToDecimal(_open, open); // this puts all infor in open file to average as a decicaml
  // cout <<"open: " << open[0] << endl;
  //  cout << "pass through open" << endl;
  convertToDecimal(_close, close);
  for (int i = 0; i < open.size(); i++)
  { // THIS IS ONE BECAUSE THEY FIRST LINE IS A WORD "PRICE"

    average.push_back((open[i] + close[i]) / 2);
  }
  for (int i = 0; i < average.size(); i++)
  { // THIS IS ONE BECAUSE THEY FIRST LINE IS A WORD "PRICE"
    // cout << "average: " << average[i] << endl;
  }
}
void Coin::compareDates(string COIN)
{
  for (int i = 0; i < wit_date.size(); i++)
  { // take size of how many dates are in master file for specific coin
    for (int j = 0; j < date.size(); j++)
    { // take in all the dates from csv file so that they can be compared
      if (wit_date[i] == date[j])
      { // comparing dates from the two different files
   // cout << "wit_fees: " << wit_fees[i] << " wit_fees size: " << wit_fees.size() << endl;
        wit_fees[i] *= average[i + 1]; // this is i+1 for average because on every file the first line is words not statistics
                                       // this changes the wit fees from master file to equal the averages calculated in average_OC
      }
    }
  }
}

void Coin::withFeesinUSD_sum(string COIN)
{
  sum = 0;
  for (int i = 0; i < wit_fees.size(); i++)
  {
    //cout << "wit_fees: " << wit_fees[i] << " wit_fees size: " << wit_fees.size() << endl;
    sum += wit_fees[i];
  }
  cout << "  Sum of withdrawal fees for " << COIN << " in USD: $" << sum << endl;
}

void Coin::addWith(){
  all_with.push_back(sum);

}

void Coin::addWith_after(){

  for (int i = 0; i < all_with.size(); i++){

    all_sum = all_sum + all_with[i];
  }
    for (int i = 0; i < all_with.size(); i++){

    cout <<  all_with[i] << " + ";
  }
  
  cout << " = " << all_sum << endl;
}