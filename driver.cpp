// Programmer:  Devin Wood
// MST Username: dwwdtv
// Instructor:  HW
// Date:        11/08/2020
// File:        driver.cpp
// Description: The driver.cpp file tests the functionality of the Penguin and PenguinFarmer classes. 

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

// include both header files for both classes defined in Penguin.h and PenguinFarmer.h

#include "Penguin.h"
#include "PenguinFarmer.h"

using namespace std;


int main()
{
  const short NUM_PENGUINS = 5; // size of penguin array
  short oneYear = 365; // 365 days in a year (LCV for while loop)
  float totalPoop = 0; // start total poop at zero and increment within while loop

  srand(time(NULL)); // seed random with time NULL

  cout << "Testing non-default constructor..." << endl;

  Penguin nonDefaultPenguin("Jerry", 7, 23);
  cout << nonDefaultPenguin;

  cout << "\nTesting default constructor..." << endl;

  Penguin defaultPenguin;
  cout << defaultPenguin;

  cout << "\nCreating Homer the Farmer..." << endl;

//=====================================
//
// Use consts (4575)
//
// Deductions: -1
//=====================================
  PenguinFarmer homer("Homer", 4575, 0);
  cout << homer << endl;

  Penguin penguin[NUM_PENGUINS]; // initialize array of 5 penguins
  
  short bites = 0;

  while (oneYear > 0) // iterate 365 times
  {
    for (short i = 0; i < NUM_PENGUINS; i++)
    {
      bool fed;
      if (homer.feed(penguin[i]) == 0) // if no food is passed into eat()
      {
        homer.yell(fed);
        bites += 1; // increment bites PenguinFarmer object recieves
      }
      totalPoop += penguin[i].getLastPoop(); // increment total poop produced by calling getLastPoop() function for calling object Penguin
    }
    oneYear --;
  }


  for (short j = 0; j < NUM_PENGUINS; j++) // output penguin using overloaded operator in PenguinClass for each penguin in array
  {
    cout << penguin[j];
  }
  
  // output results of the driver.cpp test
  cout << "\nTotal amount of poop: " << totalPoop << " lbs." << endl;
  cout << homer;
  cout << "Homer got bit " << bites << " times." << endl;    

  return 0;
}
