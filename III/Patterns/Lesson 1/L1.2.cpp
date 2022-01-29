#include <iostream>
#include <map>
#include <ctime>

class ISellSystem
{
public:

    virtual double allMoneyReport() = 0;

    virtual const std::string& getLocationReport() = 0;

    virtual std::map <std::string, size_t> goodsCountReport() = 0;

    virtual  std::map <std::string, float> goodsPriceReport() = 0;
};


class Automaton: ISellSystem
{
private:
    std::string location;
    double recieved_money;
    double spent_money;
    std::map <std::string, float> goods_price;
    std::map <std::string, size_t> goods_count;


public:
   Automaton(const std::string &location, double recievedMoney) : location(location), recieved_money(recievedMoney)
   {
       spent_money = 0.0;
   }

   virtual ~Automaton() {}

   void changePrice(std::string name, float newPrice)
   {
       goods_price[name] = newPrice;
   }

   void sellProduct(std::string name)
   {
       if(goods_count[name] > 0){
           recieved_money += goods_price[name];
       }
       else{
           std::cerr << "Not enough goods" << std::endl;
       }
   }

   void addProduct(std::string name, size_t count)
   {
       goods_count[name] += count;
   }

   double allMoneyReport() override
   {
       return recieved_money - spent_money;
   }

   const std::string& getLocationReport() override
   {
       return location;
   }

   std::map <std::string, size_t> goodsCountReport() override
   {
       for (auto&[product, count] : goods_count)
       {
           std::cout << product << " " << count << std::endl;
       }
       return goods_count;
   }

   std::map <std::string, float> goodsPriceReport() override
   {
       for (auto&[product, price] : goods_price)
       {
           std::cout << product << " " << price << std::endl;
       }
       return goods_price;
   }
};

class Proxy : public ISellSystem
{
private:
   Automaton* _real_subject{};
   // Переменная для проверки времени последнего запроса данных
   std::time_t _start;
   // Переменные, необходимые для сохранения последней записи:
   std::string _location_cache;
   double _allMoneyReport_cache;
   std::map <std::string, float> _goods_price_cache;
   std::map <std::string, size_t> _goods_count_cache;

   bool _CheckAccess() const
   {
       if (std::difftime(std::time(nullptr), _start) > 3600) // Прошло меньше часа?
       {
           return true;
       }
       else
       {
           std::cout << "1 hour has passed" << std::endl; // Прошел 1 час
           return false;
       }
   }

public:
   Proxy(Automaton* real_subject): _real_subject(new Automaton(*real_subject))
   {
       _start = std::time_t(nullptr);
   }

   virtual ~Proxy() {}

   double allMoneyReport() override
   {
       if (this->_CheckAccess())
       {
           _allMoneyReport_cache = this->_real_subject->allMoneyReport();
       }
       return _allMoneyReport_cache;
   }

   const std::string& getLocationReport() override
   {
       if (this->_CheckAccess())
       {
           _location_cache = this->_real_subject->getLocationReport();
       }
       return _location_cache;
   }

   std::map <std::string, size_t> goodsCountReport() override
   {
       if (this->_CheckAccess())
       {
           _goods_count_cache = this->_real_subject->goodsCountReport();
       }
       return _goods_count_cache;
   }

   std::map <std::string, float> goodsPriceReport() override
   {
       if (this->_CheckAccess())
       {
           _goods_price_cache = this->_real_subject->goodsPriceReport();
       }
       return _goods_price_cache;
   }

};

int main()
{
    std::cout << "Real Object:" << std::endl;
    Automaton* water = new Automaton("Water", 12.5);
    water->addProduct("botеle05", 15);
    water->addProduct("botеle1", 10);
    water->changePrice("botеle05", 50);
    water->changePrice("botеle1", 75);
    std::cout << water->allMoneyReport() << std::endl;
    std::cout << std::endl;
    std::cout << "Proxy:" << std::endl;
    Proxy* proxyWater = new Proxy(water);
    //Проблема с проверкой времени
    std::cout << proxyWater->allMoneyReport() << std::endl;

    delete water;
    delete proxyWater;

    return 0;
}
