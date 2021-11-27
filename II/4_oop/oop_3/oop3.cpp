#include <iostream>
#include <cstdint>
#include <string>

using std::string;
using std::cout;
using std::endl;


/* Создать абстрактный класс Figure (фигура). Его наследниками являются классы
 * Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый
 * для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
 * Для всех классов создать конструкторы. Для класса Figure добавить чисто
 * виртуальную функцию area() (площадь). Во всех остальных классах переопределить
 * эту функцию, исходя из геометрических формул нахождения площади.*/

class Figure
{

public:

    // В абстрактных классах конструкторы не нужны, а вот виртуальные деструкторы должны быть!
    Figure()
    {
    }

    virtual float area() = 0; // const
};

// Виртуальный деструктор писать очень важно!
class Parallelogram : public Figure
{
    // Желаетльно явно private писать

    // а стороны у нас только целые числа? :)
    uint16_t m_length; // лучше явно private
    uint16_t m_height;

public:

    Parallelogram(uint16_t _length, uint16_t _height)
        : m_length(_length), m_height(_height)
    {
    }

    float area() override
    {
        return m_length * m_height;
    }

    uint16_t getLength() const
    {
        return m_length;
    }

    uint16_t getHeigth() const
    {
        return m_height;
    }
};

class Circle : public Figure
{
    // Желаетльно явно private писать
    uint16_t m_radius;

public:

    Circle(uint16_t _radius)
        : m_radius(_radius)
    {
    }

    float area() override
    {
        return 3.14 * m_radius * m_radius;
    }
};

class Rectangle : public Parallelogram
{
    // Желаетльно явно private писать
    uint16_t m_width; // а чем нас не устраивает m_height в Parallelogram?

public:

    // Я бы тут посоветовал просто назвать входные параметры как side_a и side_b
    // И просто передал бы их в конструктор Parallelogram и все :)
    Rectangle(uint16_t _length, uint16_t _width)
        : Parallelogram(_length, _width), m_width(_width)
    {
    }

    float area() override
    {
        return getLength() * m_width;
    }
};

class Square : public Parallelogram
{

public:

    // Не, квадрату же достаточно просто одну сторону передать и вызвать Parallelogram(_side, _side)
    // В этом вся суть испольтзования наследования! Тут просто нужно правильно назвать и передать 
    // параметры в конструктор Parallelogram!
    Square(uint16_t _length = 0, uint16_t _heigth = 0)
        : Parallelogram(_length, _heigth)
    {
    }

    float area() override
    {
        return getLength() * getLength();
    }
};

class Rhombus : public Parallelogram
{

public:

    Rhombus(uint16_t _length, uint16_t _heigh)
        : Parallelogram(_length, _heigh)
    {
    }

    float area() override
    {
        return getLength() * getHeigth();
    }
};

/* Создать класс Car (автомобиль) с полями company (компания) и model (модель).
 * Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
 * От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов,
 * чтобы они выводили данные о классах. Создать объекты для каждого из классов и посмотреть,
 * в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
 *
 * Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего"
 * базового класса создает самый "дочерний" класс.
 * */

// Виртуальный деструктор писать очень важно!
class Car
{
    // Желаетльно явно private писать
    string m_company;
    string m_model;

public:

    Car(string _company, string _model)
        : m_company(_company), m_model(_model)
    {
        cout << m_company << " " << m_model << "\n";
    }

    string getCompany() const
    {
        return m_company;
    }

    string getModel() const
    {
        return m_model;
    }

};

// Виртуальный деструктор писать очень важно!
class PassengerCar : virtual public Car
{
    // Желаетльно явно private писать
     string m_body;
     string m_color;

public:

    PassengerCar(string _company, string _model, string _body, string _color)
        : Car(_company, _model), m_body(_body), m_color(_color)
    {
        cout << getCompany() << " " << getModel() << " " <<
                m_body << " " << m_color << "\n";
    }

    friend class Minivan; // Не, никаких friend классов в иерархии наследования!
};

// Виртуальный деструктор писать очень важно!
class Bus : virtual public Car
{
    // Желаетльно явно private писать
   std::string m_use;

public:

    Bus(string _company, string _model, string _use)
        : Car(_company, _model), m_use(_use)
    {
        cout << getCompany() << " " << getModel() << " " << m_use << "\n";
    }
    friend class Minivan;
};

class Minivan : public PassengerCar , public Bus
{

public:

    Minivan(string _company, string _model, string _body, string _color, string _use)
        : Car(_company, _model), PassengerCar(_company, _model, _body, _color), Bus(_company, _model, _use)
    {
        // m_color - это нарушение инкапсуляции, данный класс за эту переменную не отвечает и НЕ должен ее вообще видеть!
        cout << getCompany() << " " << getModel() << " " << m_color << "\n";
    }
};

/* Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
 * Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
 * математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
 * унарный оператор (-)
 * логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
 * Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте
 * перегрузить один через другой. Продемонстрировать использование перегруженных операторов.
 * */

class Fraction
{
    // Желаетльно явно private писать

    int m_numerator; // вот тут я сомневаюсь, что нужны отрицательные значения
    int m_denominator; // лучше знак дроби хранить отдельно

public:

    Fraction()
      : m_numerator(0), m_denominator(1)
    {
    }

    Fraction(int numerator)
      : m_numerator(numerator), m_denominator(1)
    {
    }

    Fraction(int numerator, int denominator)
      : m_numerator(numerator), m_denominator(denominator)
    {
        check();
        simplify();
    }

    void check() const
    {
        // Да, но далее никакого исправления не происходит и он все равно будет 0!
        if (m_denominator == 0)
        {
        cout << "Denominator cannot be zero\n";
        }
    }

    unsigned int greatestCommonDivisor(unsigned int a, unsigned int b)
    {
      if (a % b == 0)
      {
          return b;
      }
      if (b % a == 0)
      {
          return a;
      }
      if (a > b)
      {
          return greatestCommonDivisor(a%b, b);
      }
      return greatestCommonDivisor(a, b%a);
    }

    void simplify()
    {
        int gcd = greatestCommonDivisor(std::abs(m_numerator), std::abs(m_denominator));

        m_numerator /= gcd;
        m_denominator /= gcd;
        if (m_denominator < 0)
        {
            m_denominator *= -1;
            m_numerator *= -1;
        }
    }

    int getNum() const
    {
        return m_numerator;
    }

    int getDen() const
    {
        return m_denominator;
    }

    float toReal() const
    {
      return float(m_numerator)/m_denominator;
    }

    Fraction operator-() const;
    Fraction operator+(const Fraction &fr) const;
    Fraction operator-(const Fraction &fr) const;
    Fraction operator*(const Fraction &fr) const;
    Fraction operator/(const Fraction &fr) const;

    bool operator==(const Fraction &fr) const;
    bool operator!=(const Fraction &fr) const;
    bool operator>(const Fraction &fr) const;
    bool operator<(const Fraction &fr) const;
    bool operator>=(const Fraction &fr) const;
    bool operator<=(const Fraction &fr) const;

};

Fraction Fraction::operator-() const
{
   return Fraction(-m_numerator, m_denominator);
}

Fraction Fraction::operator+(const Fraction &fr) const
{
   return Fraction(m_numerator * fr.m_denominator + fr.m_numerator * m_denominator,
                    m_denominator * fr.m_denominator);
}

Fraction Fraction::operator-(const Fraction &fr) const
{
   return *this + (-fr);
}

Fraction Fraction::operator*(const Fraction &fr) const
{
   return Fraction(m_numerator * fr.m_numerator,
                    m_denominator * fr.m_denominator);
}

Fraction Fraction::operator/(const Fraction &fr) const
{
   return Fraction(m_numerator * fr.m_denominator,
                    m_denominator * fr.m_numerator);
}

bool Fraction::operator==(const Fraction &fr) const
{
    return m_numerator == fr.m_numerator && m_denominator == fr.m_denominator;
}

bool Fraction::operator!=(const Fraction& fr) const {
  return !(*this == fr);
}

// Не-не-не, это читерный способ :)
// У нас тут работа только с дробями и мы ни о каких "действительных" числах не знаем
bool Fraction::operator>(const Fraction& fr) const {
  return toReal() > fr.toReal();
}

bool Fraction::operator>=(const Fraction& fr) const {
  return *this > fr || *this == fr;
}

bool Fraction::operator<(const Fraction& fr) const {
  return toReal() < fr.toReal();
}

bool Fraction::operator<=(const Fraction& fr) const {
  return *this < fr || *this == fr;
}

/* Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть
 * три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
 * Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool.
 * Также в этом классе должно быть два метода:
 * - метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх,
 * то он ее поворачивает лицом вверх, и наоборот.
 * - метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
 * */

// Enum - хорошо!
enum value {ace = 1, two, three, four, five, six, seven, eigth, nine, ten, jack, queen, king};
enum suit {diamonds, spades, cross, hearts};

class Card
{
    // Желаетльно явно private писать
    enum value m_value;
    enum suit m_suit;
    bool m_state; // 0 - закрыта,  1 - открыта

public:

    Card( enum value _value, enum suit _suit, bool _state = 0)
        :m_value(_value), m_suit(_suit), m_state(_state)
    {
        cout << m_value << " " << m_suit << " " << m_state << endl;
    }

    bool Flip()
    {
       // Во, краткость - сестра таланта!
       m_state = !m_state;
       return m_state;
    }

    // Думаю, что int - слишком много (да и отрицательные тут не нужны)
    int GetValue() const
    {
        switch(m_value)
        {
            case ace: return ace;
                break;
            case two: return two;
                break;
            case three: return three;
                break;
            case four: return four;
                break;
            case five: return five;
                break;
            case six: return six;
                break;
            case seven: return seven;
                break;
            case eigth: return eigth;
                break;
            case nine: return nine;
                break;
            case ten: return ten;
                break;
            case jack: return 10;
                break;
            case queen: return 10;
                break;
            case king: return 10;
                break;
        }
     }
};
int main()
{
    //-----1-----

    Parallelogram parallelogram(4, 6);
    std::cout << parallelogram.area() << std::endl;

    Square square(5);
    std::cout << square.area() << std::endl;

    Rhombus rhombus(5, 2);
    std::cout << rhombus.area() << std::endl;

    Rectangle rectangle(4,5);
    std::cout << rectangle.area() << std::endl;

    Circle circle(2);
    std::cout << circle.area() << std::endl;

    //-----2-----

    Car car("Lada", "2110");
    PassengerCar pasCar("Audi", "A5", "coupe", "red");
    Bus bus("Mersedes", "A", "Shcool");
    Minivan minivan("Toyota", "V", "yellow", "", "");

    //-----3-----

    Fraction fraction1(4, 14), fraction2(2, 7), fraction3, fraction_sum, fraction_sub,
            fraction_mul, fraction_div;
    cout << fraction1.getNum() << "/" << fraction1.getDen() << "\n";
    cout << fraction2.getNum() << "/" << fraction2.getDen() << "\n";
    fraction3 = -fraction1;
    cout << fraction3.getNum() << "/" << fraction3.getDen() << "\n";
    fraction_sum = fraction1 + fraction2;
    cout << fraction_sum.getNum() << "/" << fraction_sum.getDen() << "\n";
    fraction_sub = fraction1 - fraction2;
    cout << fraction_sub.getNum() << "/" << fraction_sub.getDen() << "\n";
    fraction_mul = fraction1 * fraction2;
    cout << fraction_mul.getNum() << "/" << fraction_mul.getDen() << "\n";
    fraction_div = fraction1 / fraction2;
    cout << fraction_div.getNum() << "/" << fraction_div.getDen() << "\n";

    if (fraction1 == fraction2) {
      cout << "fraction1 = fraction2" << std::endl;
    }
    else {
      cout << "fraction1 not = fraction2" << std::endl;
    }

    if (fraction1 < fraction2) {
         cout << "fraction1 < fraction2" << endl;
       }
       else {
         cout << "fraction1 not < fraction2" << endl;
       }

    if (fraction1 > fraction2) {
         cout << "fraction1 > fraction2" << endl;
       }
       else {
         cout << "fraction1 not > fraction2" << endl;
       }

       if (fraction1 <= fraction2) {
         cout << "fraction1 <= fraction2" << endl;
       }
       else {
         cout << "fraction1 not <= fraction2" << endl;
       }

       if (fraction1 >= fraction2) {
         cout << "fraction1 >= fraction2" << endl;
       }
       else {
         cout << "fraction1 not >= fraction2" << endl;
       }

       if (fraction1 != fraction2) {
         cout << "fraction1 != fraction2" << endl;
       }
       else {
         cout << "fraction1 not != fraction2" << endl;
       }

    //-----4-----

    Card card1(king, cross);
    Card card3(ace, cross, false);
    cout << card3.GetValue() << endl;
    Card card2(seven, cross, card1.Flip());

    return 0;
}
