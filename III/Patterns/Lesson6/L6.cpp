#include <iostream>
#include <vector>
#include <assert.h>

/* Composite
 * Представьте, что кафе-мороженное решило объединиться с блинной. Ранее у них был простой код,
 * который позволял им работать всего с одним классом и разными объектами . Но теперь появилась
 * необходимость комбинировать разные элементы в меню, чтобы можно было предлагать комплексные
 * завтраки/обеды/ужины. Реализуйте паттерн компоновщик, исправив текущий код (внимание на main -
 * нужно будет избавиться от объектов превратив их в классы). И реализуйте комбо-наборы (скомбинировать
 * можно по своему усмотрению)
 * */

// Component
class Unit
{
public:
    virtual float getPrice() = 0;
    //virtual void addUnit(Unit* unit) ;
    virtual std::string getName() = 0;
    virtual ~Unit() {}
};

class Pancake: public Unit
{
private:
   std::string name;
   float price;
public:
   Pancake(const std::string &name, float price) : name(name), price(price) {}
   float getPrice() override { return price; }
   std::string getName() override { return name; }
};

class MorningPancake: public Pancake
{
public:
    MorningPancake(): Pancake("Morning pancake", 240.0f) {}
};

class LunchPancake: public Pancake
{
public:
    LunchPancake(): Pancake("Lunch pancake", 280.0f) {}
};

class MexicanPancake: public Pancake
{
public:
    MexicanPancake(): Pancake("Mexican pancake", 270.0f) {}
};

class PotatoPancake: public Pancake
{
public:
    PotatoPancake(): Pancake("Potato pancake", 210.0f) {}
};

class MushroomPancake: public Pancake
{
public:
    MushroomPancake(): Pancake("MushroomPancake", 220.0f) {}
};

class FalafelPancake: public Pancake
{
public:
   FalafelPancake(): Pancake("Falafel Pancake", 270.0f) {}
};

class ChocolatePancake: public Pancake
{
public:
    ChocolatePancake(): Pancake("Chocolate Pancake", 260.0f) {}
};

class BananaPancake: public Pancake
{
public:
    BananaPancake(): Pancake("Banana Pancake", 260.0f) {}
};

class JamPancake: public Pancake
{
public:
    JamPancake(): Pancake("Jam Pancake", 190.0f) {}
};

class Icecream: public Unit
{
private:
   std::string name;
   float price;
public:
   Icecream(const std::string &name, float price) : name(name), price(price) {}
   float getPrice() override { return price; }
   std::string getName() override { return name; }
};

class BananaSplit: public Icecream
{
public:
    BananaSplit(): Icecream("Banana Split", 260) {}
};

class BerryScream: public Icecream
{
public:
    BerryScream(): Icecream("Berry Scream", 260) {}
};

class HotBrauni: public Icecream
{
public:
    HotBrauni(): Icecream("Hot Brauni", 310) {}
};

class TuttiFruity: public Icecream
{
public:
    TuttiFruity(): Icecream("Tutti Fruity", 240) {}
};

class Vanilla: public Icecream
{
public:
    Vanilla(): Icecream("Vanilla cream", 180) {}
};

class Pistachio: public Icecream
{
public:
    Pistachio(): Icecream("Pistachio", 230) {}
};

class Beverage: public Unit
{
private:
   std::string name;
   float price;
public:
   Beverage(const std::string& _name, float _price) : name(_name), price(_price) {}
   float getPrice() override { return price; }
   std::string getName() override { return name; }
};

class Pepsi: public Beverage
{
public:
    Pepsi(): Beverage("Pepsi", 120) {}
};

class Espresso: public Beverage
{
public:
    Espresso(): Beverage("Coffee", 80) {}
};

class Tea: public Beverage
{
public:
    Tea(): Beverage("Tea", 50) {}
};

// Composite
class CompositeUnit: public Unit
{
private:
    std::vector<Unit*> components;
public:
    float getPrice() override
    {
        float total = 0;
        for (int i = 0; i < (int)components.size(); ++i)
        {
            total += components[i]->getPrice();
        }
        return total;
    }

    void addUnit(Unit* _unit)
    {
        components.push_back(_unit);
    }

    virtual ~CompositeUnit() override
    {
        for (int i = 0; i < (int)components.size(); ++i)
        {
            delete components[i];
        }
    }

    std::string getName() override
    {
        std::string foolName;
        for(const auto& i : components)
        {
            foolName += i->getName() + ' ';
        }
        return foolName;
    }
};

CompositeUnit* comboSet1()
{
     CompositeUnit* comboSet1 = new CompositeUnit;
     comboSet1->addUnit(new Pistachio);
     comboSet1->addUnit(new Espresso);
     return comboSet1;
}

CompositeUnit* comboSet2()
{
     CompositeUnit* comboSet2 = new CompositeUnit;
     comboSet2->addUnit(new BananaPancake);
     comboSet2->addUnit(new Pepsi);
     return comboSet2;
}

/* Mediator
 * Вам необходимо реализовать систему “Умный дом”. Все домашние приборы и устройства сконструированы так,
 * чтобы сделать жизнь максимально комфортной. У вас есть 2 объекта: Будильник и Кофеварка. Когда
 * выключается сигнал будильника, то будильник приказывает кофеварке приступить к приготовлению кофе.
 * Но возникают новые задачи - не варить кофе по выходным, ставить будильник на более раннее время в дни
 * вывоза мусора. А в выходные наоборот хочется поспать подольше. А утро начинать не с кофе, а с чая.
 * То есть необходимо подключить к системе еще два объекта - умный чайник и календарь, которые в
 * совокупности образуют сложную систему. Мы попытались связать всю систему вместе. И вроде работает,
 * но есть четкое понимание, что дальше будет хуже) Самое время реализовать паттерн Посредник, который
 * будет определять всю логику. А сами классы устройств будут только выполнять свою работу.
 * */
enum Week_days { Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

class IDevice
{
public:
    virtual void start(Week_days day) = 0;
    virtual ~IDevice() {}
};

// Mediator
class Calendar
{
private:
    std::vector<IDevice*> devices;

public:
    Calendar(){}
    ~Calendar(){}

    void  addDevice(IDevice* device)
    {
        devices.push_back(device);
    }

   void notify(IDevice* from, Week_days day)
   {
       for(const auto& dev : devices)
       {
           if (dev != from) dev->start(day);
       }
   }

   bool checkCalendar(Week_days day)
   {
       if (day == Saturday || day == Sunday) return false;
       else return true;
   }
};

class Coffee: public IDevice
{
private:
   Calendar* calendar;
public:
   Coffee(Calendar* _calendar) : calendar(_calendar) {}

   void start(Week_days day) override
   {
       if (calendar->checkCalendar(day)) std::cout << "Starting coffee" << std::endl;
   }
};

class TeaPot: public IDevice
{
private:
   Calendar* calendar;
public:
   TeaPot(Calendar* _calendar) : calendar(_calendar) {}

   void start(Week_days day)
   {
       if (!calendar->checkCalendar(day)) std::cout << "Starting tea" << std::endl;
   }
};

class Alarm: public IDevice
{
private:
   Calendar* calendar;
public:
   Alarm(Calendar* _calendar) : calendar(_calendar) {}
   void start(Week_days day)
   {
       if (calendar->checkCalendar(day)) std::cout << "Wake up 6:30\n";
       else std::cout << "Wake up 9:00\n";

       calendar->notify(this, day);
   }
};

/* Template_method
 * В сфере 2-мерной графики есть два основных направления. Растровая и векторная. И там и там картинки.
 * Но разница в том, что в растровой графике отрисовка картинки происходит посредством геометрических фигур
 * или их частей с указанием параметров. То есть по сути это текстовое описание картинки, которое
 * интерпретируется каждый раз графическим редактором и отрисовывает полученную информацию на экране.
 * А в растровой отрисовка происходит попиксельно. То есть каждый пиксель имеет параметры цвета и
 * координаты на экране. Ниже представлен код для работы с двумя типами график. Реализуйте класс,
 * который позволит вам отрисовывать соответствующую картинку с использованием паттерна Шаблонный метод.
 * */

struct Pixel
{
   int x;
   int y;
   std::string color;

   void draw(){ std::cout << "("<< x << ", " << y << ", " << color << ") "; }
};

struct Figure
{
   int x;
   int y;
   std::string figure;

   void draw(){ std::cout << "("<< x << ", " << y << ", " << figure << ") "; }
};

class Image
{
private:

public:

    void openFile(const std::string& filename) { std::cout << "Open file " << filename << std::endl; }
    //virtual void openFile(const std::string& filename) = 0;

    virtual void readFile() = 0;

    virtual void draw() = 0;

    virtual void final() = 0;

    virtual void drawing() final
    {
        openFile("File");
        readFile();
        draw();
        final();
    }

};

// Растровое изображение
class BitmapImage: public Image
{
private:
   std::vector<Pixel*> pixels;     // это пиксели, которые хранятся в файле
   std::vector<Pixel> buffer;      // это пиксели, которые мы читаем для отображение на экране
public:

   // Имитируем чтение пикселей из файла в буфер
   void readFile() override { for (const auto pixel: pixels) { buffer.push_back(*pixel); } }

   // Рисуем каждый пиксель из буфера
   void draw() override { for (const auto pixel: pixels) { pixel->draw(); } }

   void final() override { std::cout << "Drawing Bitmap image complete" << std::endl; }
};

// Векторное изображение
class VectorImage: public Image
{
private:
   std::vector<Figure*> figures;     // это описание фигур, которые хранятся в файле
   std::vector<Figure> buffer;       // это описание фигур, которые мы читаем для отображение на экране
public:

   // Имитируем чтение фигур из файла в буфер
   void readFile() override { for (const auto figure: figures) { buffer.push_back(*figure); } }

   // Рисуем каждую фигуру из буфера
   void draw() override { for (const auto figure: figures) { figure->draw(); } }

   void final() override { std::cout << "Drawing Vector image complete" << std::endl; }

};

int main()
{
    std::cout << "-------------- Composite ---------------\n";

    std::vector<CompositeUnit*> menu;
    menu.push_back(comboSet1());
    menu.push_back(comboSet2());
    for(const auto& unit : menu)
    {
        std::cout << unit->getName();
        std::cout << unit->getPrice() << std::endl;
    }

    std::cout << "-------------- Mediator ---------------\n";

    Calendar cal;
    TeaPot teaPot(&cal);
    Coffee coffee(&cal);
    Alarm alarm(&cal);

    cal.addDevice(&teaPot);
    cal.addDevice(&coffee);
    cal.addDevice(&alarm);

    alarm.start(Sunday);
    alarm.start(Monday);

    std::cout << "-------------- Template_method ---------------\n";

    BitmapImage bitmapImage;
    VectorImage vectorImage;

    bitmapImage.drawing();
    vectorImage.drawing();


    return 0;
}


