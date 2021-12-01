#include <iostream>
#include <cassert>
#include <vector>
#include <set>

using std::cout;
using std::endl;

class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length)
        :m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        // Если массив уже нужной длины — return
        if (newLength == m_length)
            return;

        // Если нужно сделать массив пустым — делаем это и затем return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Теперь знаем, что newLength >0
        // Выделяем новый массив
        int *data = new int[newLength];

        // Затем нужно разобраться с количеством копируемых элементов в новый массив
        // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // Поочередно копируем элементы
            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }

        // Удаляем старый массив, так как он нам уже не нужен
        delete[] m_data;

        // И используем вместо старого массива новый! Обратите внимание, m_data указывает
        // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
        // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // Проверка корректности передаваемого индекса
        assert(index >= 0 && index <= m_length);

        // Создаем новый массив на один элемент больше старого массива
        int *data = new int[m_length+1];

        // Копируем все элементы до index-а
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];

        // Вставляем новый элемент в новый массив
        data [index] = value;

        // Копируем все значения после вставляемого элемента
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];

        // Удаляем старый массив и используем вместо него новый
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value)
    {
        insertBefore(value, m_length);
    }

    /* Добавить в контейнерный класс, который был написан в этом уроке, методы:
     * - для удаления последнего элемента массива (аналог функции pop_back() в векторах)
     * - для удаления первого элемента массива (аналог pop_front() в векторах)
     * - для сортировки массива
     * - для вывода на экран элементов.
     * */

    void erase_before(int index)
    {
        assert(index >= 1 && index <= m_length);
        int *data = new int[m_length-1];

        for (int before = 0; before < index-1; ++before)
        {
            data[before] = m_data[before];
        }

        for (int after = index; after < m_length; ++after)
        {
            data[after-1] = m_data[after];
        }
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void pop_back()
    {
        erase_before(m_length);
    }

    void pop_front()
    {
        erase_before(1);
    }

    void sort()
    {
        int temp, pos;
        for (uint8_t i = 1; i < m_length; ++i){
            temp = m_data[i];
            pos = i - 1;
            while (pos >= 0 && m_data[pos] > temp){
                m_data[pos + 1] = m_data[pos];
                pos--;
            }
            m_data[pos + 1] = temp;
        }

    }

    void print() const
    {
        for (uint8_t i = 0; i < m_length; i++)
        {
            cout << m_data[i] << " ";
        }

        cout << endl;
    }
};

/* Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно поле:
 * вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив,
 *  а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
 *  - метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве
 *  параметра указатель на новую карту;
 *  - метод Clear, который очищает руку от карт;
 *  - метод GetValue, который возвращает сумму очков карт руки
 *  (здесь предусмотреть возможность того, что туз может быть равен 11).
 *  */

enum value {ace = 1, two, three, four, five, six, seven, eigth, nine, ten, jack, queen, king};
enum suit {diamonds, spades, cross, hearts};

class Card
{
    enum value m_value;
    enum suit m_suit;
    bool m_state; // 0 - закрыта,  1 - открыта

public:

    Card( enum value _value, enum suit _suit, bool _state = 0)
        :m_value(_value), m_suit(_suit), m_state(_state)
    {
        //cout << m_value << " " << m_suit << " " << m_state << endl;
    }

    bool Flip()
    {
       m_state = !m_state;
       return m_state;
    }

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
     return 0;
     }
};

class Hand
{
private:
    std::vector<Card*> m_Cards;

public:

    /* Добавляет карту в руку. Добавляет указатель на объект типа Сard в вектор m_Сards. */
    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    }

    /* Очищает руку от карт. Удаляет все указатели из вектора m_Сards,
     *  устраняя все связанные с ними объекты в куче. */
    void Clear()
    {
        m_Cards.clear();
    }

    /* Возвращает сумму очков карт руки */
    int GetValue()
    {
        int n_cards = m_Cards.size();
        int sum = 0;
        for (uint16_t i = 0; i < n_cards; i++)
        {
           if (m_Cards[i]->GetValue() == 1)
           {
               if (sum + 11 <= 21)
               {
                   sum+=11;
               }
               else
               {
                   sum+=1;
               }
           }
           else
           {
               sum += m_Cards[i]->GetValue();
           }
        }
        return sum;
    }
};

int main()
{
    //-----1-----

    ArrayInt myArray(0);
    myArray.push_back(5);
    myArray.push_back(45);
    myArray.push_back(59);
    myArray.push_back(24);
    myArray.push_back(7);
    myArray.sort();
    myArray.print();
    myArray.pop_back();
    myArray.print();
    myArray.erase_before(1);
    myArray.print();
    myArray.pop_front();
    myArray.print();

    //-----2-----

    /* Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать
     * максимально быстрый алгоритм.
     * */

    std::vector<int> int_vector = { 7, 5, 16, 8, 8, 15, 5 };
    cout << "Vector ";
    for (auto val : int_vector)
    {
        cout << val << " ";
    }
    cout << endl;
    
    std::set<int> s;
    for(int i = 0; i < (int)int_vector.size(); i++)
    {
        s.insert(int_vector.data()[i]);
    }
    cout << "An amount of different numbers ";
    cout << s.size() << endl;

    //-----3-----

    Card card1(king,cross,0), card2(two, cross, false), card3(ace, cross, false);
    Hand hand;
    hand.Add(&card1);
    hand.Add(&card2);
    hand.Add(&card3);
    cout << "Hand:" << hand.GetValue() << endl;
    hand.Clear();
    cout << "Hand: " << hand.GetValue() << endl;

    return 0;
}