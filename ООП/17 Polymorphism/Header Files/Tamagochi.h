#pragma once
#include<string>

class Tamagochi {
protected:
   std::string sound;
public:
   std::string name;
   int age;
   std::string breed;

   struct Toy {
      std::string color;
      std::string shape;
   };

   Toy* favoriteToys = new Toy[10];

   virtual void voice() = 0;

   virtual void play() = 0;

   void setSound(std::string mysound);
  
   Tamagochi(std::string name, int age, std::string breed,std::string sound);
 
   virtual ~Tamagochi();
};
