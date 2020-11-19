// Programmer:  Devin Wood
// MST Username: dwwdtv
// Instructor:  HW
// Date:        11/08/2020
// File:        Penguin.cpp
// Description: This file contains the function definitions for the Penguin class.


#include "Penguin.h" // include classes header file to define functions in any order

// Description: The setRandName() function will choose a name from penguin_names.dat
// at random and assign that name to the penguin.
// Pre: Assignment operator must be defined for member variable name.
// Post: Assigns random name to penguin member variable name.

void Penguin::setRandName()
{
  short randNum = rand() % 10;
  std::string randName;
 
  std::ifstream fin;

  fin.open("penguin_names.dat");
  while (randNum >= 0)
    {
      fin >> randName;
      randNum --;
    }

  m_name = randName;
   
  return;
}

// Description: The setName() function will assign the passed in value of name and
// and assign it to the penguin.
// Pre: Assignment operator must be defined for member variable name.
// Post: Assigns name to penguin member variable name.

void Penguin::setName(const std::string name)
{
  m_name = name;
  return;
}

// Description: The setWeight() function will assign the passed in value of weight and
// and assign it to the penguin.
// Pre: Assignment operator must be defined for member variable weight.
// Post: Assigns weight to penguin member variable weight.

//=====================================
//
// Good usage of private setter functions with validations
//
// Deductions: +2
//=====================================
void Penguin::setWeight(const float weight)
{
  if (weight <= 0)
    {
      std::cout << "Error! Weight must be a positive value.";
      exit(0);
    }

  m_weight = weight;

  return;  
}

// Description: The setAge() function will assign the passed in value of age and
// and assign it to the penguin.
// Pre: Assignment operator must be defined for member variable age.
// Post: Assigns age to penguin member variable name.

void Penguin::setAge(const short age)
{
  if ((age <=  0) || (age >= 1000))
    {
      std::cout << "Error! Age must be a positive value and less than 1000.";
      exit(0);
    }

  m_age = age;

  return;
}
 
// Description: The eat() function will calculate and apply the change in the penguins
// weight and calls the poop() function. 
// Pre: None
// Post: Returns the boolean value to isFood depending on whether or not the farmer
// had the food to feed the penguin.

bool Penguin::eat(const float amntFood)
{
  bool isFood;
  const float MIN_EPSILON = -0.05;
  const float MAX_EPSILON = 0.10;
  const short MAX_AGE = 1460;
  float epsilon;
  float food;
  
  float amntPoop;

  m_age ++;

  food = amntFood;

//=====================================
//
// Use consts (70000, .02, 165, 5)
//
// Deductions: -4
//=====================================
  epsilon = ((float(rand()) / float(RAND_MAX)) * (MAX_EPSILON - MIN_EPSILON)) + MIN_EPSILON;
  m_weight += (70000 * log(1 + (0.02 * food) * (epsilon / (165 + m_age / 5))));

  if (amntFood == 0)
  {
    isFood = 0;
    return isFood;
  }

  isFood = 1;
 
  if (m_age > MAX_AGE)
  {
    std::cout << "Error! Age must be a less than 1460.";
    exit(0);
  }
   
  
  m_lastPoop = poop(amntFood);

  return isFood;
  
}

// Description: The eat() function will calculate and apply the change in the penguins
// weight and calls the poop() function.
// Pre: -= and = operators must be defined for member variable weight.
// Post: Returns the float value of the amount of poop produced.

float Penguin::poop(const float amntFood)
{
  float amntPoop;
//=====================================
//
// Use consts (.005, .98)
//
// Deductions: -2
//=====================================
  float lostWeight = (0.005 * m_weight);
  
  amntPoop = lostWeight + .98 * amntFood;
  m_weight -= lostWeight;
  m_weight = static_cast<float>(static_cast<int>(m_weight * 10.)) / 10.;

  return amntPoop;
}

// Description: an overloaded insertion operator to output the object in a single line:  
// e.g.  Jerry weighs xx lbs and is yy days old
// Pre: Insertion operator must be defined for member variables name, weight, and age.
// Post: Outputs the penguin in the described form above.

std::ostream & operator << (std::ostream & out, const Penguin & p)
{
    out << p.m_name << " weighs " << p.m_weight << " lbs and is " << p.m_age << " days old" << std::endl;
    return out;
} 

