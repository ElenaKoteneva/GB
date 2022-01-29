
#include <iostream>

//1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.

template <typename T>
class Pair1()
{
private:
    T m_data1;
    T m_data2;
public:
    Pair1(const T& _data1, const T& _data2)
    : m_data1(_data1), m_data2(_data2)
    {
    }

    T& first()
    {
        return m_data1;
    }

    const T& first() const
    {
        return m_data1;
    }


    T& second()
    {
        return m_data2;
    }
    const T& second() const
    {
        return m_data2;
    }

};

/* Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
Следующий код:

int main()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

… должен производить следующий результат:
Pair: 6 7.8
Pair: 3.4 5
Подсказка: чтобы определить шаблон с использованием двух разных типов, просто разделите параметры типа шаблона запято
*/


/* 3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.
 Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string,
  а второй — любого типа данных.
    Следующий код:
    int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
… должен производить следующий результат:
Pair: Amazing 7
Подсказка: при вызове конструктора класса Pair
 из конструктора класса StringValuePair не забудьте указать, что параметры относятся к классу Pair.
*/


/* 4. Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
IsBoosted() - возвращает bool значение, есть ли у игрока перебор
Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/








int main()
{
//-----1-----

    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n'

    //… должен производить результат:
    //Pair: 6 9
    //Pair: 3.4 7.8

//-----2-----







return 0;
}
