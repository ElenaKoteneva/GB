#include <iostream>
#include <vector>
#include <fstream>
//#include <string>
#include <memory>
//#include <assert.h>

/* Memento
 * Сохранение состояния объектов не всегда связано с хранением в оперативной памяти. Иногда требуется выполнить
 * сохранение так, чтобы можно было вернуться к нему в любой момент, даже после перезапуска приложения. И в этом случае
 * очень подходит механизм сохранения в файл. Но, чтобы избежать проблем с запуском на разных платформах, рекомендуется
 * использовать сериализацию.
 * Реализуйте паттерн Хранитель для ниже расположенного кода так, чтобы данные об объекте player сериализировались
 * в бинарный файл. Тему по сериализации можно освежить из урока с курса по сложным моментам/
 * */

class Memento
{
private:
    float stateHp;
    int stateSpeed;
    std::string stateName;

public:
    Memento(float _hp, int _speed, std::string _name)
        : stateHp(_hp), stateSpeed(_speed), stateName(_name) {}

    float getStateHp() const { return stateHp; }
    int getStateSpeed() const { return stateSpeed; }
    std::string getStateName() const { return stateName; }
};

class Player
{
private:
   float hp;
   int speed;
   std::string name;
public:
   Player(float hp, int speed, const std::string &name) : hp(hp), speed(speed), name(name) {}

   void changeSpeed(int change) { speed += change; }

   void changeHp(float change) { hp += change; }

   float getHp() const { return hp; }

   int getSpeed() const { return speed; }

   const std::string &getName() const { return name; }

   Memento* createMemento() { return new Memento(hp, speed, name); }

};

class Command
{
private:
    Player player;
    std::vector<Memento*> mem;

public:
    Command(const Player& _player) : player(_player) {}

    ~Command() {}

    void serialize(const Player& data, std::string path)
    {
        std::ofstream out(path, std::ios::binary);
        std::string sData;
        sData = std::to_string(player.getHp()) + " " + std::to_string(player.getSpeed()) + " " + player.getName() + " ";
        out.write(sData.c_str(), sizeof (data));
    }

    void deserialize(std::string& result, std::string path)
    {
        std::ifstream in(path, std::ios::binary);
        result.resize(1024);
        in.read(result.data(), result.size());
        result.resize(in.gcount());
    }

    void changeSpeed(int change)
    {
        serialize(player, "player.bin");
        std::string result;
        deserialize(result, "player.bin");
        std::cout << result << std::endl;
        player.changeSpeed(change);
    }

    void changeHp(float change)
    {
        serialize(player, "player.bin");
        std::string result;
        deserialize(result, "player.bin");
        std::cout << result << std::endl;
        player.changeHp(change);
    }
};

/* PIMPL
 * Реализуйте шаблон Указатель на исполнителя разделив класс игрока из первого задания.
 * */

class User
{
private:
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    User(float hp, int speed, const std::string &name);

    ~User() {};

    void changeSpeed(int change);

    void changeHp(float change);

    float getHp() const;

    int getSpeed() const;

    const std::string &getName() const;

};

class User::Impl
{
public:
    float hp;
    int speed;
    std::string name;
    Impl(float hp, int speed, const std::string& _name) : hp(hp), speed(speed), name(_name) {}
};

User::User(float hp, int speed, const std::string &name): pImpl(new Impl(hp, speed, name)) {}

void User::changeSpeed(int change) { pImpl->speed += change; }

void User::changeHp(float change) { pImpl->hp += change; }

float User::getHp() const { return pImpl->hp; }

int User::getSpeed() const { return pImpl->speed; }

const std::string& User::getName() const { return pImpl->name; }

int main()
{
    std::cout << "-------------- Memento ---------------\n";

    Player player1(12, 20, "Jone");

    Command command(player1);
    command.changeSpeed(25);
    command.changeHp(12.3);

    std::cout << "-------------- PIMPL ---------------\n";

    User jone(12, 20, "Jone");
    jone.changeSpeed(15);
    jone.changeHp(12);
    std::cout << jone.getName() << " Hp=" << jone.getHp() << ", Speed=" << jone.getSpeed() << std::endl;

    return 0;
}


