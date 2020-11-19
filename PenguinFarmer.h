// Programmer:  Devin Wood
// MST Username: dwwdtv
// Instructor:  HW
// Date:        11/08/2020
// File:        PenguinFarmer.h
// Description: This file contains the class definition for PenguinFarmer.


#ifndef PENGUIN_FARMER_H
#define PENGUIN_FARMER_H

#include "Penguin.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
//=====================================
//
// Forgot cstdlib, read the README
//
// Deductions: -1
//=====================================
#include <cstdlib>

class PenguinFarmer
{
  private:
    std::string m_name;
    float m_food;
    float m_money;

    void setName(const std::string name);
    void setFood(const float food);
    void setMoney(const float money);
    

  public:
    PenguinFarmer(const std::string name, const float food, const float money) {setName(name); setFood(food); setMoney(money);}
    friend std::ostream & operator << (std::ostream & out, const PenguinFarmer & p);
    bool feed(Penguin & p);
    void yell(const bool ouch) const;

};

#endif

