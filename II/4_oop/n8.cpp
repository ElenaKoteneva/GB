#include <stdexcept>
//#include <cstdint>
//#include <string>
#include <iostream>

#define FIELD_SZ 10

/* 1. Написать шаблонную функцию div, которая должна вычислять результат
 * деления двух параметров и запускать исключение DivisionByZero,
 * если второй параметр равен 0. В функции main выводить результат
 * вызова функции div в консоль, а также ловить исключения.
 */

template <typename T>
T div(T dividend, T divider)
{
    if (divider == 0) throw "DivisionByZero";
    return (dividend) / divider;
}

/* 2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор
 * по вещественному числу, инициализирующий x значением параметра. Написать класс Bar,
 * хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и
 * имеющий метод set с единственным вещественным параметром a. Если y + a > 100,
 * возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a.
 * В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
 * Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0.
 * В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
 */

class Ex
{
private:
    double x;
public:
     Ex(double _x) : x(_x) {}
    ~Ex() = default;

    double what() const noexcept { return x; };
};

class Bar
{
private:
    double y;
public:
    Bar(double _y = 0) : y(_y) {}

    void set(double a)
    {
        if (y + a > 100)
        {
            throw Ex(a * y);
        }
        else
        {
            y = a;
        }
    }
};

/* 3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10,
 * у которого есть метод, означающий задание переместиться на соседнюю позицию.
 * Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки,
 * и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне).
 * Объект исключения должен содержать всю необходимую информацию — текущую позицию и
 * направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую
 * все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.
 */

struct Pos
{
    int16_t x, y;
};

enum Direction
{
    RIGHT, LEFT, DOWN, UP, other
};

class Robot
{
private:
    Pos m_Pos;
    Direction m_dir;
public:
    Robot() : m_Pos{}
    {};

    void move(Direction dir)
    {
        switch (dir)
        {
        case Direction::RIGHT:
            if (++currentPos.x >= FIELD_SZ)
            {
                --currentPos.x;
                throw OffTheField(currentPos, dir);
            }
            break;
        case Direction::LEFT:
            if (--currentPos.x < 0)
            {
                ++currentPos.x;
                throw OffTheField(currentPos, dir);
            }
            break;
        case Direction::DOWN:
            if (++currentPos.y >= FIELD_SZ)
            {
                --currentPos.y;
                throw OffTheField(currentPos, dir);
            }
            break;
        case Direction::UP:
            if (--currentPos.y < 0)
            {
                ++currentPos.y;
                throw OffTheField(currentPos, dir);
            }
            break;
        default: throw IllegalCommand();
            break;
        }
    }

    void print() const
    {
        for (uint8_t i = 0; i < FIELD_SZ; i++)
        {
            for (uint8_t j = 0; j < FIELD_SZ; j++)
            {
                if (j == currentPos.x && i == currentPos.y) std::cout << "X";
                else std::cout << "_";
            }
            std::cout << std::endl;
        }
    }

};

class RobotException
{
private:
    std::string m_error;
public:
    RobotException(const std::string &_error, const Robot& data)
        :std::logic_error("")
    {
        std::ostringstream s;
        s << _error << "pos(" << data->m_pos.x << "," << data->m_pos.y << ") direction = "
          << static_cast<int>(data->m_dir);
        m_error = s.str();
    }

    virtual RobotException() {};

    virtual const char* what() const noexcept override
    {
        return m_error.c_str();
    }
};

class OffTheField : public RobotException
{
public:
    OffTheField(const Robor& data)
        :RobotException(std::string{"off the field"}, data) {}

    virtual ~OffTheField() {}

};

class IllegalCommand : public std::exception
{
public:
    IllegalCommand(const Robor& data)
        :RobotException(std::string{"illegal command"}, data) {}

    virtual ~IllegalCommand() {}
};



int main()
{

    std::cout << "----1-----" << std::endl;

    try
    {
        double d = div<double>(5.32, 1.22);
        std::cout << "Div = " << d << std::endl;
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << std::endl;
    }
/*
    std::cout << "----2-----" << std::endl;
    Bar bar;
    int n;
    try
    {
        do
        {
            std::cout << "Enter a number ";
            std::cin.clear();
            std::cin >> n;
            bar.set(n);

        } while (n != 0);
    }
    catch(const Ex& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
*/
    std::cout << "----3-----" << std::endl;

    Robot robot;

    return 0;
}




