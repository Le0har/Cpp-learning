#pragma once
#include <iostream>
#include <string>
#include "Tamagochi.h"

class Cat: public Tamagochi {

public:
   static int countCat;

   void voice() override;
  
   void play() override;
  
   Cat();

   Cat(std::string name, int age, std::string breed);

   Cat(const Cat& c);

   Cat& operator=(const Cat& c);
  
   ~Cat();
};
