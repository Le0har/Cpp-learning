#include "Dog.h"
#include "Tamagochi.h"

   void Dog::voice() 
   {
      std::cout << "Собака " << name << " издает звук " << sound << std::endl;
   }

   void Dog::play() 
   {
      Toy randomToy = favoriteToys[rand() % 10];
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
      favoriteToys = new Toy[10];
      for(int i=0; i<10; i++)
      {
         favoriteToys[i].color = d.favoriteToys[i].color;
         favoriteToys[i].shape = d.favoriteToys[i].shape;
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
      delete[] favoriteToys;
      favoriteToys = new Toy[10];
      for(int i=0; i<10; i++)
      {
         favoriteToys[i].color = d.favoriteToys[i].color;
         favoriteToys[i].shape = d.favoriteToys[i].shape;
      }
      return *this;
   }

   Dog::~Dog()
   {
      countDog--;
   }
