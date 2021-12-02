#include <stdexcept>
#include <iostream>
#include <limits>

#define FIELD_SZ 10

using namespace std;

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
    int x, y;
};

enum Direction {RIGTH, LEFT, UP, DOWN, OTHER};

class RobotException
{
private:

    string m_error;

public:

    RobotException(Pos pos, Direction dir, string _error = "") : m_error(_error)
    {
        m_error += "Current Robot position (";
		m_error += to_string(pos.x);
		m_error += ",";
		m_error += to_string(pos.y);
		m_error += ") Direction: ";
		switch (dir)
		{
		case Direction::RIGTH:
			m_error += "RIGHT";
			break;
		case Direction::LEFT:
			m_error += "LEFT";
			break;
		case Direction::DOWN:
			m_error += "DOWN";
			break;
		case Direction::UP:
			m_error += "UP";
			break;
		default:
			break;
		}
    }

    virtual ~RobotException() {}

    const char* getError() const
    {
        return m_error.c_str();
    }

};

class OffTheField : public RobotException
{
public:
    OffTheField(Pos pos, Direction dir, string _error = "OFF THE FIELD\n")
        :RobotException(pos, dir, _error)
    {}

    virtual ~OffTheField() {}

};

class IllegalCommand : public RobotException
{
public:
    IllegalCommand(Pos pos, Direction dir, string _error = "ILLEGAL COMMAND\n")
        :RobotException(pos, dir, _error)
    {}

    virtual ~IllegalCommand() {}

};

class Robot
{
private:

    Pos m_pos {0,0};
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
                if (++m_pos.x >= FIELD_SZ)
                {
                    --m_pos.x;
                    throw OffTheField(m_pos, m_dir);
                    }
                break;
            }
            case LEFT:
            {
                if (--m_pos.x < 0)
                {
                    ++m_pos.x;
                    throw OffTheField(m_pos, m_dir);
                }
                break;
            }
            case UP:
            {
                if (--m_pos.y < 0)
                {
                    ++m_pos.y;
                    throw OffTheField(m_pos, m_dir);
                }
                break;
            }
            case DOWN:
            {
                if (++m_pos.y >= FIELD_SZ)
                {
                    --m_pos.y;
                    throw OffTheField(m_pos, m_dir);
                }
                break;
            }
            case OTHER:
            {
                throw IllegalCommand(m_pos, m_dir);
                break;
            }
            default:
            {
                break;
            }
        }
    }

    void print() const
    {
        for (int8_t i = 0; i < FIELD_SZ; ++i)
        {
            for (int8_t j = 0; j < FIELD_SZ; ++j)
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

int main()
{
    Robot* robot = new (Robot);
    char button;

    do
    {
        cout << "Use buttons AWSD for move. Q - exit.\n";
        robot->print();

        cin.get(button);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear");
        try
        {
            switch (button)
            {
            case 'w':
            case 'W':
                robot->move(Direction::UP);
                break;
            case 's':
            case 'S':
                robot->move(Direction::DOWN);
                break;
            case 'a':
            case 'A':
                robot->move(Direction::LEFT);
                break;
            case 'd':
            case 'D':
                robot->move(Direction::RIGTH);
                break;
            case 'q':
            case 'Q':
                break;
            default:
                robot->move(Direction::OTHER);
            }
        }
        catch (const OffTheField& ex)
        {
            cerr << "Error: " << ex.getError() << endl;
        }
        catch (const IllegalCommand& ex)
        {
            cerr << "Error: " << ex.getError() << endl;
        }

    } while (button != 'q' && button != 'Q');

    delete robot;
    return 0;
}

