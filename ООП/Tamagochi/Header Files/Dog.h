#pragma once
#include <iostream>
#include <string>
#include "Tamagochi.h"

class Dog: public Tamagochi {

public:
   static int countDog;

   void voice() override;
   
   void play() override;
  
   void chewBone();
   
   Dog();

   Dog(std::string name, int age, std::string breed);
  
   Dog(const Dog& d);
  
   Dog& operator=(const Dog& d);
  
   ~Dog();
};
