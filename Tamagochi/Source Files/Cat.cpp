#include "Cat.h"
#include "Tamagochi.h"

   void Cat::voice() 
   {
      std::cout << "Кошка " << name << " издает звук " << sound << std::endl;
   }

   void Cat::play() 
   {
      if (favoriteToys.empty() == true)
      {
         std::cout << "У кошки " << name << " пока нету игрушек!" << std::endl;
         return;
      }
      Toy randomToy = favoriteToys[rand() % favoriteToys.size()];
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
      for(int i=0; i<favoriteToys.size(); i++)
      {
         favoriteToys[i] = c.favoriteToys[i];
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

      for(int i=0; i<favoriteToys.size(); i++)
      {
         favoriteToys[i] = c.favoriteToys[i];
      }
      return *this;
   }

   Cat::~Cat()
   {
      countCat--;
   }
