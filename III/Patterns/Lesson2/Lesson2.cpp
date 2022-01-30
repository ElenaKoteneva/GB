#include <iostream>
#include <map>
#include <vector>

/* 1. Абстрактная фабрика
 * Как видите, на каждый тип пиццы создается свой собственный класс. И в целом это неплохо.
 * Но выбор конкретного класса для создания экземпляра усложняет функцию orderPizza() и не позволяет
 * закрыть её для изменений. Реализуйте паттерн “абстрактная фабрика” который позволит создавать пиццу
 * не привязываясь к её типу, чтобы внутри функции orderPizza()  не создавались конкретные экземпляры
 * классов с пиццами
 * */

// Абстрактный базовый класс для всех возможных видов пиццы
class Pizza
{
public:
   virtual void prepare(std::string);
   virtual void bake() {};
   virtual void cut() {};
   virtual void box() {};
};

// Виды пиццы
class CheesePizza:public Pizza {};
class GreekPizza:public Pizza {};
class PepperoniPizza:public Pizza {};

// Абстрактная фабрика для производства пиццы
class PizzaFactory
{
public:
    virtual Pizza* createPizza() = 0;

    virtual ~PizzaFactory() {};
};

// Фабрика для создания Сырной пиццы
class CheesePizzaFactory : PizzaFactory
{
public:
    CheesePizza* createCheesePizza()
    {
        return new CheesePizza;
    }
};

// Фабрика для создания Греческой пиццы
class GreekPizzaFactory : PizzaFactory
{
public:
    GreekPizza* createGreekPizza()
    {
        return new GreekPizza;
    }
};

// Фабрика для создания Пепперони пиццы
class PepperoniPizzaFactory : PizzaFactory
{
public:
    PepperoniPizza* createPepperoniPizza()
    {
        return new PepperoniPizza;
    }
};

// Создает пиццу, не привязываясь к ее типу.
Pizza* orderPizza(PizzaFactory* pizza)
{
   return pizza->createPizza();
}

/* 2. Команда. Вы решили запрограммировать умную лампочку, которую можно включать и выключать и задавать
 * цвет свечения. В вашем распоряжении есть следующий класс.
 * Реализуйте паттерн команда, чтобы можно было сохранять состояние лампочки и проигрывать её мерцание
 * как в прямом так и в обратном направлении.
 */

enum class Colors
{
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   CYAN,
   BLUE,
   VIOLET,
   WHITE
};

class Light
{
private:
   bool state;
   Colors color;
public:

   Light():state(false), color(Colors::WHITE){};

   void On()
   {
       if(!state)
       {
           state = true;
       }
   };

   void Off()
   {
       if(state)
       {
           state = false;
       }
   };

   void changeColor(Colors newColor)
   {
       color = newColor;
   }

   bool getState() const
   {
       return state;
   }

   Colors getColor() const
   {
       return color;
   }

};

// Базовый класс
class Command
{
protected:
    Light* m_light;
    //Command(Light* l) : m_light(l) {}

public:
    virtual ~Command() {};
    virtual void Execute() = 0;
    virtual void Back() = 0;

    void setLight(Light* _light)
    {
        m_light = _light;
    }

    void getColor()
    {
        m_light->getColor();
    }

};

// Классы для каждого метода класса Light
class OnCommand : public Command
{
public:
     OnCommand(){}

     void Execute() override
     {
       m_light->On();
     }

     void Back() override
     {
       m_light->Off();
     }
};

class OffCommand : public Command
{
public:
     OffCommand(){}

     void Execute() override
     {
       m_light->Off();
     }

     void Back() override
     {
       m_light->On();
     }
};

class ChangeColorCommand : public Command
{
private:
    Colors lastColor, m_color;
public:
    ChangeColorCommand(Colors _color)
    {
        lastColor = m_color;
        m_color = _color;
    }

     void Execute() override
     {
         m_light->changeColor(m_color);
     }

     void Back() override
     {
       m_light->changeColor(lastColor);
     }
};

class GetStateCommand : public Command
{
public:
     GetStateCommand() {}

     void Execute() override
     {
         m_light->getState();
     }

};

/*3. Decorator. Вы решили открыть кофейню и вам понадобилось наладить учет производства напитков.
 * Вы создали абстрактный класс, в котором определили метод для расчета стоимости всех напитков.
 *
 * Но к кофе можно заказать еще различные  добавки (шоколад, корица, взбитые сливки) или наоборот
 *  взять без сахара. Дополнения не бесплатны, поэтому они должны быть встроены в систему оформления заказов.
 *  А отсутствие сахара должно наоборот снижать стоимость. Понятное дело, что создавать отдельные классы для
 *  каждого варианта “сборки” кофе - не вариант. И тут нам на помощь придет декоратор!
 *  Реализуйте паттерн декоратор, с помощью которого можно будет сварить кофе с любым составом добавок.
 *  */

class Beverage{            // Абстрактный класс
public:
   virtual void getDescription() const = 0;
   virtual double cost() const = 0;
    virtual ~Beverage(){}
};

class HouseBlend: public Beverage{   // Молотый
public:
   double cost() const override {

       return 5.5;
   }

   void getDescription() const override
   {
       std::cout << "HouseBlend " ;
   };
};

class DarkRoast: public Beverage
{  // Темной обжарки
public:

    double cost() const override
    {
       return 6.0;
    }

    void getDescription() const override
    {
       std::cout << "DarkRoast " ;
    };
};

class Decaf: public Beverage
{    // Без кофеина
public:
   double cost() const override {
       return 7.3;
   }

   void getDescription() const override
   {
      std::cout << "Decaf " ;
   };


};

class Espresso: public Beverage
{  // Эспрессо
public:
   double cost() const override {
       return 3.5;
   }

   void getDescription() const override
   {
      std::cout << "Espresso " ;
   };
};

class Decorator : public Beverage // использует отношение "является"
{
private:
    Beverage* m_beverage; // отношение "имеет"
public:
    Decorator(Beverage* _beverage)
    {
        m_beverage = _beverage;
    }

    void getDescription() const override
    {
        m_beverage->getDescription(); // делегирование
    }

    double cost() const override
    {
        return m_beverage->cost(); // делегирование
    }
};

// Дополнительное декорирование
class WithChocolateDecorator : public Decorator
{
public:
    WithChocolateDecorator(Beverage* beverage) : Decorator(beverage) {}

    void getDescription() const override
    {
        // Делегирование базовому классу
        Decorator::getDescription();
        //и реализация дополнительной функциональности
        std::cout << "with chocolate ";
    }

    double cost() const override
    {
        // Делегирование базовому классу и реализация дополнительной функциональности
        return Decorator::cost() + 2.5;
    }
};

class WithMilkDecorator : public Decorator
{
public:
    WithMilkDecorator(Beverage* beverage) : Decorator(beverage) {}

    void getDescription() const override
    {
        // Делегирование базовому классу
        Decorator::getDescription();
        //и реализация дополнительной функциональности
        std::cout << "with milk ";
    }

    double cost() const override
    {
        // Делегирование базовому классу и реализация дополнительной функциональности
        return Decorator::cost() + 2.5;
    }
};

class WithCinnamonDecorator : public Decorator
{
public:
    WithCinnamonDecorator(Beverage* beverage) : Decorator(beverage) {}

    void getDescription() const override
    {
        // Делегирование базовому классу
        Decorator::getDescription();
        //и реализация дополнительной функциональности
        std::cout << "with cinnamon ";
    }

    double cost() const override
    {
        // Делегирование базовому классу и реализация дополнительной функциональности
        return Decorator::cost() + 2.5;
    }
};

class SugarFreeDecorator : public Decorator
{
public:
    SugarFreeDecorator(Beverage* beverage) : Decorator(beverage) {}

    void getDescription() const override
    {
        // Делегирование базовому классу
        Decorator::getDescription();
        //и реализация дополнительной функциональности
        std::cout << "Sugar free ";
    }

    double cost() const override
    {
        // Делегирование базовому классу и реализация дополнительной функциональности
        return Decorator::cost() - 1.0;
    }
};

int main()
{
    //--------- 2 Light--------
    /*
    std::vector<Command*> vectorCommand;
    vectorCommand.push_back( new ChangeColorCommand(Colors::BLUE));
    vectorCommand.push_back( new ChangeColorCommand(Colors::GREEN));
    vectorCommand.push_back( new ChangeColorCommand(Colors::ORANGE));
    vectorCommand.push_back( new ChangeColorCommand(Colors::YELLOW));
    vectorCommand.push_back( new ChangeColorCommand(Colors::VIOLET));

    for (size_t i=0; i<vectorCommand.size(); ++i)
      vectorCommand[i]->Execute();

    for (size_t i=0; i<vectorCommand.size(); ++i)
       vectorCommand[i]->Back();
*/

    //--------- 3 Beverage --------

    Beverage* beverage = new SugarFreeDecorator(new WithChocolateDecorator(new HouseBlend));
    beverage->getDescription();
    std::cout << beverage->cost() << "$";
    delete beverage;
    return 0;
}


