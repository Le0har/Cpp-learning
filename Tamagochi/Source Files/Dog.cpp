#include "Dog.h"
#include "Tamagochi.h"

   void Dog::voice() 
   {
      std::cout << "Собака " << name << " издает звук " << sound << std::endl;
   }

   void Dog::play() 
   {
      if (favoriteToys.empty() == true)
      {
         std::cout << "У собаки " << name << " пока нету игрушек!" << std::endl;
         return;
      }
      Toy randomToy = favoriteToys[rand() % favoriteToys.size()];
      std::cout << "Собака " << name << " бежит за " << randomToy.shape << " цвета "
         << randomToy.color << std::endl;
   }

   void Dog::chewBone()
   {
      std::cout << "Собака " << name << " грызёт кость" << std::endl;
   }

   Dog::Dog(): Tamagochi("Нет имени", 0, "Нет породы", "Гав!")
   {
      countDog++;
   }

   Dog::Dog(std::string name, int age, std::string breed): Tamagochi(name, age, breed, "Гав!")
   {
      countDog++;
   }

   Dog::Dog(const Dog& d): Tamagochi(d.name, d.age, d.breed, "Гав!")
   {
      for(int i=0; i<favoriteToys.size(); i++)
      {
         favoriteToys[i] = d.favoriteToys[i];
      }
      countDog++;
   }

   Dog& Dog::operator=(const Dog& d)
   {
      if(this == &d)
      {
         return *this;
      }
      name = d.name;
      age = d.age;
      breed = d.breed;

      for(int i=0; favoriteToys.size(); i++)
      {
         favoriteToys[i] = d.favoriteToys[i];
      }
      return *this;
   }

   Dog::~Dog()
   {
      countDog--;
   }
