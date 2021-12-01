#include <iostream>
#include <cstdint>
#include <cstring>

/*  Создать класс Person (человек) с полями: имя, возраст, пол и вес.
 *  Определить методы переназначения имени, изменения возраста и веса.
 *  Создать производный класс Student (студент), имеющий поле года обучения. 
 *  Определить методы переназначения и увеличения этого значения. 
 *  Создать счетчик количества созданных студентов. В функции main() создать несколько студентов.
 *  По запросу вывести определенного человека.
 */

class Person
{
    // Нужно явно private
    std::string m_name;
    std::uint8_t m_age, m_weigth;
    bool m_gender;

public:
    Person(std::string _name, uint8_t _age = 0, bool _gender = 1, uint8_t _weigth = 0) // Гендер 0 или 1 только :D
        : m_name(_name), m_age(_age), m_gender(_gender), m_weigth(_weigth)
    {
    }

    std::string setName(std::string _name)
    {
        m_name = _name;
        return m_name;
    }

    uint8_t setAge(uint8_t _age)
    {
        m_age = _age;
        return m_age;
    }

    uint8_t setWeigth(uint8_t _weigth)
    {
        m_weigth = _weigth;
        return m_weigth;
    }

    std::string getName() const
    {
        return m_name;
    }

    int getAge() const
    {
        return m_age;
    }

    int getWeigth() const
    {
        return m_weigth;
    }

    char getGender() const
    {
        if (m_gender)
        {
            return 'M';
        }
        else 
        {
            return 'W';
        }
    }

};

class Student : public Person
{
    uint8_t m_year;
    static uint16_t count; // m_count

public:
    
    Student(std::string _name, uint8_t _age = 0, bool _gender = 1, uint8_t _weigth = 0,
            uint8_t _year = 0)
        : Person(_name, _age, _gender, _weigth), m_year(_year)
    {
        // Счетчик только увеличивается. Даже если объекты мы удалили.
        // Класс не должен знать о том, что количество объектов подсчитывают.
        ++count;
        std::cout << count << std::endl;
    }

    uint8_t setYear(uint8_t _year)
    {
        m_year = _year;
        return m_year;

    }

    uint8_t increaseYear()
    {
        m_year++;
        return m_year;
    }

    int getYear() const
    {
        return m_year;
    }

};

uint16_t Student::count = 0;

/* Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
 * У Fruit есть две переменные-члена: name (имя) и color (цвет). 
 * Добавить новый класс GrannySmith, который наследует класс Apple.
 */

class Fruit
{
    std::string m_name;
    std::string m_color;

public:
   
    Fruit(std::string _name, std::string _color)
        : m_name(_name), m_color(_color)
    {
    }

    std::string getName() const
    {
        return m_name;
    }

    std::string getColor() const
    {
        return m_color;
    }
};

class Apple : public Fruit
{
public:
    // А тут у меня будет возможность создать класс Apple с именем "pineapple". Нужно такое пресекать.
    Apple(std::string _color = "red", std::string _name = "apple")
        : Fruit(_name, _color)
    {
    }

};

class Banana : public Fruit
{
public:
    // Ну и тут Banana с именем "raccoon"
    Banana(std::string _name = "banana", std::string _color = "yellow")
        : Fruit(_name, _color)
    {   
    }
};

class GrannySmith : public Apple
{
public:

    GrannySmith(std::string _name = "Granny Smith apple", std::string _color = "green")
        : Apple(_color, _name)
    {
    }
};

/* Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, 
 используя объектно-ориентированное программирование. Сколько будет классов в программе?
 Какие классы будут базовыми, а какие производными?
 Продумать реализацию игры с помощью классов и записать результаты.
*/

// Ну, желательно было хотябы пустые методы (названия методов только) прикинуть :)
class Game
{

};

class Card
{

};

class Hand
{

};

class Deck : public Hand
{

};

class GenericPlayer : public Hand
{

};

class Player : public GenericPlayer
{

};

class House : public GenericPlayer
{

};


int main()
{
    //-----1-----
    
    Student student[4] = {
        Student("Sergey", 25, 1, 75, 5),
        Student("Elena", 21, 0, 59, 2),
        Student("Ivan", 19, 1, 82, 1),
        Student("Mary", 23, 0, 62, 3)
    };
    
    uint8_t id = 4;

    for (uint8_t i = 1; i <= 4; i++)
    {
        if (i == id)
        {
            std::cout << student[i-1].getName() << " ";
            std::cout << student[i-1].getAge() << " ";
            std::cout << student[i-1].getGender() << " ";
            std::cout << student[i-1].getWeigth() << " ";
            std::cout << student[i-1].getYear() << "\n";

        }
    }
     
    //-----2-----

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    /* My apple is red.
     * My banana is yellow.
     * My Granny Smith apple is green*/

    return 0;
}

