#include "Tamagochi.h"

   void Tamagochi::setSound(std::string mysound)
   {
      sound = mysound;
   }

   Tamagochi::Tamagochi(std::string name = "Нет имени", int age = 0, std::string breed = "Нет породы",
      std::string sound = " "):name(name), age(age), breed(breed)
   {
      setSound(sound);
   }

   Tamagochi::~Tamagochi()
   {
      delete[] favoriteToys;
   }
