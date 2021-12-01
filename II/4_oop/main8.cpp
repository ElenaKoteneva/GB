/* Написать класс «робот», моделирующий перемещения робота по сетке 10x10,
 * у которого есть метод, означающий задание переместиться на соседнюю позицию.
 * Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки,
 * и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне).
 * Объект исключения должен содержать всю необходимую информацию — текущую позицию и
 * направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую
 * все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.
 */

#include <iostream>
#include <exception>

#define FIELD_SZ 10;

using namespace std;



struct Pos
{
    int x, y;
};

enum Direction {RIGTH, LEFT, UP, DOWN, OTHER};

class Robot
{
private:
    Pos m_pos {0};
    Direction m_dir;
public:
    Robot() {}

    void move(Direction _dir)
    {
        m_dir = _dir;

        switch(m_dir)
        {
            case RIGTH:
            {
                ++m_pos.x;
                //throw OffTheField();
                break;
            }
            case LEFT:
            {
                --m_pos.x;
                break;
            }
            case UP:
            {
                --m_pos.y;
                break;
            }
            case DOWN:
            {
                ++m_pos.y;
                break;
            }
            case OTHER:
            {

            }
            default:
            {

            }
        }
    }

    void print()
    {
        for (int8_t i = 0; i < 10; ++i)
        {
            for (int8_t j = 0; j < 10; ++j)
            {
                if (m_pos.y == i && m_pos.x == j)
                {
                    cout << "*";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << endl;
        }

    }
};

class RobotException
{
friend iostream* operator<< (const iostream* out, const RobotException& ex);
private:
    string m_error;
public:
    RobotException(string _error = "") : m_error(_error)
    { }

    virtual ~RobotException() {}

    const char* getError()
    {
        return m_error.c_str();
    }


};

iostream* operator<< (iostream* out, RobotException& ex)
{
    out << ex.getError();
    return out;
}

class OffTheField : public RobotException
{
public:
    OffTheField(string _error = "Off The Field")
    { }

    virtual ~OffTheField() {}

};

class IllegalCommand : public RobotException
{
public:
    IllegalCommand(string _error = "Illegal Command")
    { }

    virtual ~IllegalCommand() {}

};

int main()
{
    Robot robot;
try
{
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.move(RIGTH);
    robot.print();
}
catch(const RobotException& ex)
{
    cerr << "Error: " << ex;
}


return 0;
}
