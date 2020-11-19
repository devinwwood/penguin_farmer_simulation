// Programmer:  Devin Wood
// MST Username: dwwdtv
// Instructor:  HW
// Date:        11/08/2020
// File:        PenguinFarmer.cpp
// Description: This file contains the function definitions for the PenguinFarmer class.


#include "PenguinFarmer.h"  // include classes header file to define functions in any order

// Description: The setName() function will assign the passed in value of name and
// and assign it to the PenguinFarmer.
// Pre: Assignment operator must be defined for member variable name.
// Post: Assigns name to PenguinFarmer member variable name.

void PenguinFarmer::setName(const std::string name)
{
  m_name = name;
  return;
}

// Description: The setFood() function will assign the passed in value of food and
// and assign it to the PenguinFarmer.
// Pre: Assignment operator must be defined for member variable food.
// Post: Assigns food to penguin member variable food.

void PenguinFarmer::setFood(const float food)
{
  if (food < 0)
    {
      std::cout << "Error! Amount of food must be a positive value.";
      exit(0);
    }

  m_food = food;

  return;
}

// Description: The setMoney() function will assign the passed in value of money and
// and assign it to the PenguinFarmer.
// Pre: Assignment operator must be defined for member variable money.
// Post: Assigns name to penguin member variable money.

void PenguinFarmer::setMoney(const float money)
{
  if (money < 0)
    {
      std::cout << "Error! Amount of money must be a positive value.";
      exit(0);
    }

  m_money = money;

  return;
}

// Description: an overloaded insertion operator to output the object in a single line:  
// e.g.   Frank has xxx lbs of food and $yyy.yy.
// Pre: Insertion operator must be defined for member variables name, food, and money.
// Post: Outputs the PenguinFarmer in the described form above.

std::ostream & operator << (std::ostream & out, const PenguinFarmer & p)
{
    out << p.m_name << " has " << p.m_food << " lbs of food and $" << p.m_money  << std::endl;
    return out;
}

// Description: The feed() function passes in penguin by reference and that penguin
// calls the eat() function. Then the money for the PenguinFarmer is updated by how much poop
// is produced.
// Pre: += and = must be defined for PenguinFarmer member variable money and food.
// Post: Returns the boolean value of isFed that is determined by the eat() function call by penguin object.

bool PenguinFarmer::feed(Penguin & p)
{
  bool isFed;
  const float MIN_FOOD = 2.0;
  const float MAX_FOOD = 3.0;
  float randFood;
  randFood = ((float(rand()) / float(RAND_MAX)) * (MAX_FOOD - MIN_FOOD)) + MIN_FOOD;
  
  if (m_food == 0)
    {
      isFed = p.eat(m_food);
      m_money += (0.05 * p.getLastPoop());
      m_money = static_cast<float>(static_cast<int>(m_money * 100.)) / 100.;
      return isFed;
    }
        
  else if (randFood > m_food)
    {
      isFed = p.eat(m_food);
      m_food = 0;
      m_money += (0.05 * p.getLastPoop());
      m_money = static_cast<float>(static_cast<int>(m_money * 100.)) / 100.;
      return isFed;
    }
  
  else
    {
      isFed = p.eat(randFood);
      m_food -= randFood;
      m_money += (0.05 * p.getLastPoop());
      m_money = static_cast<float>(static_cast<int>(m_money * 100.)) / 100.;
      return isFed;
    }

}

// Description: If boolean value of ouch is false, then the yell() function outputs message to the screen.
// Pre: None.
// Post: Returns nothing.

void PenguinFarmer::yell(const bool ouch) const
{
  if (ouch == 0)
    {
      std::cout << "D'oh!" << std::endl;
      return;
    }
  return;
}
      

