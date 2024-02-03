#pragma once
#include <iostream>
#include <string>
#include <vector>

class Tamagochi {
protected:
   std::string sound;
public:
   std::string name;
   int age;
   std::string breed;

   enum color
   {
      red = 1,
      green = 2,
      blue = 3
   };

   struct Toy {
      color color;
      std::string shape;
   };

   std::vector <Toy> favoriteToys;

   void addToy(int color, std::string shape);

   virtual void voice() = 0;

   virtual void play() = 0;

   void setSound(std::string mysound);
  
   Tamagochi(std::string name, int age, std::string breed,std::string sound);
 
   virtual ~Tamagochi();
};
