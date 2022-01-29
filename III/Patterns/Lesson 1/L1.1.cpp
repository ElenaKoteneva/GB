#include <iostream>

class ChocolateBoiler{
private:
   bool _empty;
   bool _boiled;
public:
   ChocolateBoiler(){
       _empty = true;
       _boiled = false;
   }

   bool isEmpty() const{
       return _empty;
   }

   bool isBoiled() const{
       return _boiled;
   }

   void fill(){
       if (isEmpty()){
           _empty = false;
           _boiled = false;
       }
   }

   void drain(){
       if (!isEmpty() && isBoiled()){
           _empty = true;
       }
   }

   void boil(){
       if (!isEmpty() && !isBoiled()){
           _boiled = true;
       }
   }
};


class Singleton : public ChocolateBoiler
{
private:
    Singleton(const std::string& name): _value(name) {}

public:
    virtual ~Singleton();

private:
    std::string _value;
    static Singleton* _uniqueInstance;
public:
    Singleton(Singleton& other) = delete;
    void operator=(Singleton&) = delete;
    static Singleton* GetInstance(const std::string& name);

    std::string value() const{
        return _value;
    }

    bool isEmpty() const;
    bool isBoiled() const;
    void fill();
    void drain();
    void boil();
};

Singleton* Singleton::_uniqueInstance = nullptr;

Singleton* Singleton::GetInstance(const std::string &name) {

    if (_uniqueInstance == nullptr){
        _uniqueInstance = new Singleton(name);
    }


    return _uniqueInstance;
}

Singleton::~Singleton() {
    delete _uniqueInstance;
}


int main() {

    std::cout<<Singleton::GetInstance("First")->ChocolateBoiler::isEmpty() <<std::endl;
    Singleton::GetInstance("Second")->ChocolateBoiler::fill();
    std::cout<<Singleton::GetInstance("Second")->ChocolateBoiler::isEmpty();

    return 0;
}
