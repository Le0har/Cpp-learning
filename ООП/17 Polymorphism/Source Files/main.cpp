#include <iostream>
#include <string>
#include "Tamagochi.h"
#include "Cat.h"
#include "Dog.h"

int Cat::countCat = 0;
int Dog::countDog = 0;

int main() {
   setlocale(LC_ALL, "Rus");

   Cat murka("Мурка", 4, "Британская короткошёрстная");

   std::cout << "Имя: " << murka.name << std::endl;
   std::cout << "Возраст: " << murka.age << std::endl;
   std::cout << "Порода: " << murka.breed << std::endl;
   murka.voice();

   Cat barsik;

   std::cout << "Имя: " << barsik.name << std::endl;
   std::cout << "Возраст: " << barsik.age << std::endl;
   std::cout << "Порода: " << barsik.breed << std::endl;
   barsik.voice();

   std::cout << "Количество кошек = " << Cat::countCat << std::endl;

   murka.play();
   barsik.play();

   Dog reks("Рэкс", 7, "Немецкая овчарка");
   reks.play();
   reks.chewBone();

   return 0;
}
