#include <iostream>
#include <cassert>
#include <vector>


/* 1 Fabric Method
 * Давайте вспомним наше домашнее задание по абстрактным фабрикам и пиццериям.
 * Не кажется ли вам, что его будет намного логичнее выполнить с помощью паттерна Абстрактный метод?)
 * Ведь когда фабрика по производству пиццерий одна, то нет смысла в их большом количестве. А вот метод
 * по изготовлению разных пицц - самое оно. Решите задачу с пиццериями с использованием паттерна “Фабричный метод”.
 * */

class Pizza
{
public:
   virtual void prepare() = 0;
   virtual void bake() {};
   virtual void cut() {};
   virtual void box() {};
   virtual ~Pizza() {}
};

class CheesePizza : public Pizza
{
public:
    void prepare() override
    {
      std::cout << "Preparing CheesePizza" << std::endl;
    }
};

class GreekPizza : public Pizza
{
public:
    void prepare() override
    {
      std::cout << "Preparing GreekPizza" << std::endl;
    }
};

class PepperoniPizza : public Pizza
{
public:
    void prepare() override
    {
      std::cout << "Preparing PepperoniPizza" << std::endl;
    }
};

// Фабрики объектов
class Factory
{
  public:
    virtual Pizza* createPizza() = 0;
    virtual ~Factory() {}
};

class CheesePizzaFactory: public Factory
{
  public:
    Pizza* createPizza() {
      return new CheesePizza;
    }
};

class GreekPizzaFactory: public Factory
{
  public:
    Pizza* createPizza() {
      return new GreekPizza;
    }
};

class PepperoniPizzaFactory: public Factory
{
  public:
    Pizza* createPizza() {
      return new PepperoniPizza;
    }
};

/* 2 Builder
 * Вам предложено создать систему планирований Экскурсий. Гости парка могут выбрать гостиницу,
 * заказать билеты на аттракционы, зарезервировать места в ресторане и даже заказать специальные мероприятия.
 * Отпуск случайного отдыхающего может выглядеть так (...).
 * Реализуйте паттерн строитель, позволяющий планировать любой день любым удобным способом.
 * */

class Events
{
public:
   virtual void getEvent() = 0;
   virtual ~Events() {};
};

class Hotel: public Events
{
public:
   void getEvent()
   {
       std::cout << "Booking Hotel" << std::endl;
   }
};

class Park: public Events
{
public:
   void getEvent()
   {
       std::cout << "Park visiting" << std::endl;
   }
};

class Food: public Events
{
public:
   virtual void getEvent() = 0;
   virtual ~Food() {};
};

class Dinner: public Food
{
public:
   Dinner() : _type("dinner") {}
   void getEvent()
   {
       std::cout << "Food " << _type << std::endl;
   } ;
private:
   std::string _type;
};

class Lunch: public Food
{
public:
   Lunch() : _type("lunch") {}
   void getEvent()
   {
       std::cout << "Food " << _type << std::endl;
   } ;
private:
   std::string _type;
};

class Breakfast: public Food
{
public:
   Breakfast() : _type("breakfast") {}
   void getEvent()
   {
       std::cout << "Food " << _type << std::endl;
   } ;
private:
   std::string _type;
};

class Special: public Events
{
public:
   virtual void getEvent() = 0;
   virtual ~Special() {};
};

class Skating: public Special
{
public:
   Skating() : _type("skating") {}
   void getEvent()
   {
       std::cout << "Special " << _type << std::endl;
   }
private:
   std::string _type;
};

class Circus: public Special
{
public:
   Circus() : _type("circus") {}
   void getEvent()
   {
       std::cout << "Special " << _type << std::endl;
   } ;
private:
   std::string _type;
};

// Класс EventsList содержит все типы событий.
class EventsList
{
  public:
    std::vector<Hotel*> hotel;
    std::vector<Park*> park;
    std::vector<Dinner*> dinner;
    std::vector<Lunch*> lunch;
    std::vector<Breakfast*> breakfast;
    std::vector<Skating*> skating;
    std::vector<Circus*> circus;
    void getEvent()
    {

        for(const auto& unit : hotel) unit->getEvent();
        for(const auto& unit : park) unit->getEvent();
        for(const auto& unit : dinner) unit->getEvent();
        for(const auto& unit : lunch) unit->getEvent();
        for(const auto& unit : breakfast) unit->getEvent();
        for(const auto& unit : skating) unit->getEvent();
        for(const auto& unit : circus) unit->getEvent();


    }
};

// Базовый класс EventsBuilder объявляет интерфейс для поэтапного построения дней и предусматривает
// его реализацию по умолчанию.
class EventsBuilder
{
  protected:
    EventsList* events;
  public:
    EventsBuilder(): events(0) {}
    virtual ~EventsBuilder() {}
    virtual void createEvents() {}

    virtual void buildHotel() {}
    virtual void buildPark() {}
    virtual void buildDinner() {}
    virtual void buildLunch() {}
    virtual void buildBreakfast() {}
    virtual void buildSkating() {}
    virtual void buildCircus() {}

    virtual EventsList* getEvents() const {return events;}
};

// Список событий на первый день:
class FirstDayBuilder: public EventsBuilder
{
public:
  void createEvents() override {events = new EventsList;}

  void buildHotel() override {events->hotel.push_back(new Hotel());}
  void buildPark() override {events->park.push_back(new Park());}
  void buildDinner() override {events->dinner.push_back(new Dinner());}
  void buildLunch() override {events->lunch.push_back(new Lunch());}
  void buildBreakfast() override {events->breakfast.push_back(new Breakfast());}
  void buildSkating() override {events->skating.push_back(new Skating());}
};

// Список событий на второй день:
class SecondDayBuilder: public EventsBuilder
{
public:

    void createEvents() override {events = new EventsList;}

    void buildHotel() override {events->hotel.push_back(new Hotel());}
    void buildPark() override {events->park.push_back(new Park());}
    void buildLunch() override {events->lunch.push_back(new Lunch());}
    void buildBreakfast() override {events->breakfast.push_back(new Breakfast());}
    void buildCircus() override {events->circus.push_back(new Circus());}

};

class Director
{
  public:
    EventsList* createEvents( EventsBuilder& builder)
    {
        builder.createEvents();

        builder.buildHotel();
        builder.buildPark();
        builder.buildDinner();
        builder.buildLunch();
        builder.buildBreakfast();
        builder.buildSkating();
        builder.buildCircus();

        return( builder.getEvents());
    }
};

/* 3 Bridge
 * Представьте графический редактор, благодаря которому пользователи могут рисовать на экране
 * графические элементы. Для упрощения возьмем один объект - прямоугольник. Пусть у вас будет
 * абстрактный класс (Implementer).
 * Создайте вашему Implementer 2 реализации - рисование кистью и рисование карандашом.
 * Создайте реализацию Абстракции class Square: public Shape которая будет реализовывать метод draw,
 * вызывая рисование квадрата у конкретного implementer.
 * */

// Implementor
class DrawingImplementor
{
public:
    virtual void drawSquare() = 0;
    virtual ~DrawingImplementor() {}
};

class DrawBrush: public DrawingImplementor
{
public:
    void drawSquare() override
    {
        std::cout << "Draw square by brush\n";
    }
};

class DrawPencil: public DrawingImplementor
{
public:
    void drawSquare() override
    {
        std::cout << "Draw square by pencil" << std::endl;
    }
};

// Abstraction
class Shape
{
public:
    virtual void draw() = 0; // low-level
    virtual void resize(double pct) = 0; // high-level
    virtual ~Shape() { }
};

class Square: public Shape
{
private:
    DrawingImplementor* _drawindImpl;
public:
    Square(DrawingImplementor* drawindImpl) : _drawindImpl(drawindImpl) {};

    void draw() override
    {
        _drawindImpl->drawSquare();
    }

    void resize(double pct) override
    {
        std::cout << "Resize " << pct << std::endl;
    }
};

int main()
{

    std::cout << "--------- 1 Fabric Method --------\n";

    CheesePizzaFactory* cheesePizza_factory = new CheesePizzaFactory;
    GreekPizzaFactory*  greekPizza_factory  = new GreekPizzaFactory ;
    PepperoniPizzaFactory*  pepperoniPizza_factory  = new PepperoniPizzaFactory ;

    std::vector<Pizza*> v;
    v.push_back( cheesePizza_factory->createPizza());
    v.push_back( greekPizza_factory->createPizza());
    v.push_back( pepperoniPizza_factory->createPizza());

    for(int i = 0; i < (int)v.size(); ++i)
        v[i]->prepare();

    delete cheesePizza_factory;
    delete greekPizza_factory;
    delete pepperoniPizza_factory;

    std::cout << "\n-------- 2 Builder ---------\n";

    Director dir;
    FirstDayBuilder firstDay_builder;
    SecondDayBuilder secondDay_builder;

    EventsList* firstDay = dir.createEvents(firstDay_builder);
    EventsList* secondDay = dir.createEvents(secondDay_builder);

    std::cout << "Events 1st day:" << std::endl;
    firstDay->getEvent();

    std::cout << "\nEvents 2nd day:" << std::endl;
    secondDay->getEvent();

    std::cout << "\n--------- 3 Bridge ---------\n";

    DrawingImplementor* drawB = new DrawBrush();
    DrawingImplementor* drawP = new DrawPencil();

    Shape* shapeB = new Square(drawB);
    shapeB->draw();
    shapeB->resize(2);

    Shape* shapeP = new Square(drawP);
    shapeP->draw();
    shapeP->resize(-2);

    return 0;
}


