#include "Tamagochi.h"
#include "MyException.h"

void Tamagochi::addToy(int color, std::string shape)
{
   if (shape == name)
   {
      throw MyException("Форма игрушки совпадает с именем животного!");
   }
   
   switch (color)
   {
   case 1:     favoriteToys.push_back(Toy{ red, shape});
               break;
   case 2:     favoriteToys.push_back(Toy{ green, shape });
               break;
   case 3:     favoriteToys.push_back(Toy{ blue, shape });
               break;
   default:    std::cout << "Такого цвета нету!" << std::endl;
   }
}

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
   }
