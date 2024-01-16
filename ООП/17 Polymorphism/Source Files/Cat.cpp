#include "Cat.h"
#include "Tamagochi.h"

   void Cat::voice() 
   {
      std::cout << "Кошка " << name << " издает звук " << sound << std::endl;
   }

   void Cat::play() 
   {
      Toy randomToy = favoriteToys[rand() % 10];
      std::cout << "Кошка " << name << " играет с " << randomToy.shape << " цвета "
         << randomToy.color << std::endl;
   }

   Cat::Cat(): Tamagochi("Нет имени", 0, "Нет породы", "Мяу!")
   {
      countCat++;
   }

   Cat::Cat(std::string name, int age, std::string breed): Tamagochi(name, age, breed, "Мяу!")
   {
      countCat++;
   }

   Cat::Cat(const Cat& c): Tamagochi(c.name, c.age, c.breed, "Мяу!")
   {
      favoriteToys = new Toy[10];
      for(int i=0; i<10; i++)
      {
         favoriteToys[i].color = c.favoriteToys[i].color;
         favoriteToys[i].shape = c.favoriteToys[i].shape;
      }
      countCat++;
   }

   Cat& Cat::operator=(const Cat& c)
   {
      if(this == &c)
      {
         return *this;
      }
      name = c.name;
      age = c.age;
      breed = c.breed;
      delete[] favoriteToys;
      favoriteToys = new Toy[10];
      for(int i=0; i<10; i++)
      {
         favoriteToys[i].color = c.favoriteToys[i].color;
         favoriteToys[i].shape = c.favoriteToys[i].shape;
      }
      return *this;
   }

   Cat::~Cat()
   {
      countCat--;
   }
