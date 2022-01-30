#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>


/* 1 Strategy . Представьте, что вы разрабатываете текстовый редактор и вам необходимо реализовать деление текста
 * на строки (перенос строк). Это удобный функционал, когда текст оказывается слишком длинным и приходится постоянно
 * выполнять горизонтальную прокрутку, чтобы его читать.
 * Для выполнения данной задачи было представлено 3 алгоритма:
 * - Деление текста на строки в зависимости от ширины клиентского окна
 * - Деление текста на строки указанной ширины (передается в качестве параметра)
 * - Автоматическое деление текста по предложениям (учитываются знаки препинания .!?)
 * Реализуйте паттерн стратегия, чтобы иметь возможность выбирать нужный алгоритм деления на предложения.

Сами методы DivideBy… реализовывать не обязательно. Главное сам паттерн. Но если хочется, то можно)
*/

enum class DivideMethod
{
    ByScreenWidth,
    ByUserWidth,
    BySentence
};

class DivideStrategy
{
public:
    virtual ~DivideStrategy() {}
    virtual void Divide(std::string&) = 0;
};

class DivideByScreenWidth : public DivideStrategy
{
public:
    void Divide(std::string& _text) override
    {
        std::cout << "DivideByScreenWidth" << std::endl;
    }
};

class DivideBySentence : public DivideStrategy
{
public:
    void Divide(std::string& _text) override
    {
        std::cout << "Divided by Sentences" << std::endl;
    }
};

class DivideByUserWidth : public DivideStrategy
{
public:
    void Divide(std::string& _text) override
    {
        std::cout << "DivideByUserWidth" << std::endl;
    }
};

class Data
{
protected:
    DivideStrategy* divideStrategy;
public:
    virtual void useStrategy() = 0;
    virtual void setStrategy(DivideStrategy*) = 0;
    virtual ~Data() {}
};

class TextEditor: public Data
{
private:
    static size_t EditorWidth, userWidth;
    std::string all_text;
    DivideStrategy* divideStrategy;
public:
    TextEditor(){};
    TextEditor(const std::string &text) : all_text(text) {};

    TextEditor(std::ifstream& file)
    {
        std::string line;
        if (file.is_open()){
            while (getline(file, line))
            {
                all_text+=line;
            }
        }
    }

    void PrintText() const
    {
        std::cout << all_text << std::endl;
    }

    void useStrategy() override
    {
        divideStrategy->Divide(all_text);
    }

    void setStrategy(DivideStrategy *strategy) override
    {
        divideStrategy = strategy;
    }
};



/* Iterator. Вспомните курс “Сложные моменты С++”.
 * Реализовать паттерн итератор, с помощью которого можно будет проитерироваться по контейнеру
 * с объектами (одного любого класса) в оба направления (возьмите контейнеры - список, массив, вектор, дек).
 * (Дополнительно) Попробуйте улучшить вашу реализацию, чтобы не было четкой привязки к классу объектов,
 * хранящихся в контейнерах
 * */


class IIterator{
public:
    virtual bool hasNext() const = 0;
    virtual bool hasPrev() const = 0;
    virtual int getNext() = 0;
    virtual int getPrev() = 0;

    virtual ~IIterator() {}
};

template <typename T>
class ContainerIterator : public IIterator
{
private:
    std::vector<T> m_vector;
    int position = 0;
public:
    ContainerIterator(std::vector<T>& _vector) : m_vector(_vector)
    {
        std::copy(m_vector.begin(), m_vector.end(), std::ostream_iterator<int>(std::cout, "  "));
        std:: cout << std::endl;

    };

    ~ContainerIterator()
    {
        m_vector.resize(0);
    };

    int getNext() override
    {
        if (hasNext())
        {
            ++position;
        }
        return m_vector[position-1];
    }

    int getPrev() override
    {
        if (hasPrev())
        {
            --position;
        }
        return m_vector[position];
    }

    bool hasNext() const override
    {
        return position < (int)m_vector.size();
    }

    bool hasPrev() const override
    {
        return position > 0;
    }

    void setPosition(int pos)
    {
        position = pos;
    }
};

/* Adapter. Представьте графический редактор, благодаря которому пользователи могут рисовать
 * на экране графические элементы (линии, многоугольники, текст и т.д.). Каждый объект имеет
 * возможность быть отрисован на экране и подвержен изменению формы. Если с графическими объектами всё просто,
 * то текст всегда обрабатывается иначе. Разработайте адаптер для класса TextView, чтобы иметь возможность
 * работать со всеми объектами графического редактора одинаковыми методами.
 * */

class IShape{
public:
   virtual void scale(double scale_percentage) = 0;// Масштабируем фигуру
   virtual void rotate(double angle) = 0;          // Поворачиваем фигуру
   virtual void flip() = 0;                        // Отражаем фигуру
   virtual ~IShape() {}
};

class Figure: IShape{
private:
   int width;
   int height;
   double angle;
   bool isFlipped;
public:
   Figure(int width, int height) : width(width), height(height), angle(0.0), isFlipped(false) {}
   Figure (){}

   void scale(double scale_percentage) override {
       width *= scale_percentage;
       height *= scale_percentage;
   }

   void rotate(double angle) override {
       angle += angle;
   }

   void flip() override {
       isFlipped = !isFlipped;
   }
};

class IText{
   virtual void newSize(int size) = 0;      // Изменяем размер шрифта текста
   virtual void rotate(double angle) = 0;   // Поворачиваем текст
   virtual void reverse() = 0;              // Изменяем направление текста

};

class Text: IText{
private:
   int size;
   double angle;
   //bool isReversed;
   std::string text;
public:
   Text(const std::string text, int size, double angle) : text(text), size(size), angle(0.0) {}

   void newSize(int newSize) override {
       std::cout << "newSize\n";
       size = newSize;
   }

   void rotate(double newAngle) override {
       std::cout << "Rotate\n";
       angle = newAngle;
   }

   void reverse() override
   {
       std::cout << "Reverse\n";
       for (unsigned int i = 0; i < text.size()/2; ++i)
       {
           char c = text[i];
           text[i] = text[text.size() - 1 - i];
           text[text.size() - 1 - i] = c;
       }
   }
};

class TextAdapter : public Figure
{
private:
    Text* text;
public:
    TextAdapter(Text* _text) : text(_text) {}

    ~TextAdapter() {}

    virtual void scale(double scale_percentage)     // Изменяем размер шрифта текста
    {
        text->newSize(scale_percentage);
    }
    virtual void rotate(double angle)   // Поворачиваем текст
    {
        text->rotate(angle);
    }
    virtual void flip()              // Изменяем направление текста
    {
        text->reverse();
    }
};


int main()
{

    std::cout << "--------- 1 Strategy --------\n";
    TextEditor text;

    DivideByScreenWidth* divSW = new DivideByScreenWidth;
    DivideBySentence* divS = new DivideBySentence;
    DivideByUserWidth* divUW = new DivideByUserWidth;

    text.setStrategy(divSW);
    text.useStrategy();
    text.setStrategy(divS);
    text.useStrategy();
    text.setStrategy(divUW);
    text.useStrategy();

    std::cout << "\n-------- 2 Iterator ---------\n";

    std::vector<int> v {10, 20, 30, 40, 50};
    ContainerIterator it(v);

    while(it.hasNext())
    {
        std::cout << it.getNext() << " ";
    }
    std::cout << std::endl;
    it.setPosition(v.size());
    while(it.hasPrev())
    {
        std::cout << it.getPrev() << " ";
    }

    std::cout << "\n--------- 3 Adapter ---------\n";
    Figure figure(5, 2);
    Text atext("Hello World!", 12, 0);

    Figure* textAdapter = new TextAdapter(&atext);
    textAdapter->flip();
    textAdapter->rotate(90);
    textAdapter->scale(14);

    delete textAdapter;

    return 0;
}


