// Programmer:  Devin Wood
// MST Username: dwwdtv
// Instructor:  HW
// Date:        11/08/2020
// File:        Penguin.h
// Description: This file contains the class definition for Penguin.




#ifndef PENGUIN_H
#define PENGUIN_H

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>

class Penguin
{
  private:
    std::string m_name;
    float m_weight;
    short m_age;
    float m_lastPoop;
    
    void setRandName();
    void setName(const std::string name);
    void setWeight(const float weight);
    void setAge(const short age);

    float poop(const float amntFood);

    

  public:
    Penguin() : m_weight(5.0), m_age(0) {setRandName();}
    Penguin(const std::string name, const float weight, const short age) {setName(name); setWeight(weight); setAge(age);}
    bool eat(const float amntFood);
    float getLastPoop() const {return m_lastPoop;}
    friend std::ostream & operator << (std::ostream & out, const Penguin & p);
     
};

#endif
