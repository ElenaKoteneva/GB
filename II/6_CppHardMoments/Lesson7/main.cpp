//Урок 7. Бинарная сериализация. Котенева Е.В.
#include <iostream>
#include "Students.pb.h"
#include <fstream>
#include <string>

class IRepository {
public:
    virtual ~IRepository(){}
    virtual void Open() = 0; // бинарная десериализация в файл
    virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
public:
    virtual ~IMethods(){}
    virtual double GetAverageScore(const FullName& name) = 0;
    virtual const std::string& GetAllInfo(const FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

class Group : public StudentsGroup, public IMethods, public IRepository
{
public:
    void Open() override
    {
        std::ifstream in("./students.bin", std::ios::binary);
        if(this->ParseFromIstream(&in)){}
    }
    void Save() override
    {
        std::ofstream out("./students.bin", std::ios::binary);
        this->SerializePartialToOstream(&out);
    }
    double GetAverageScore(const FullName& name) override
    {
        for (const auto &stud: this->student())
        {
            if (std::tie(stud.fullname().name(), stud.fullname().surname(), stud.fullname().patronymic()) ==
                std::tie(name.name(), name.surname(), name.patronymic())) {
                return stud.average_score();
            }
            else return 0;
        }
    }
    const std::string& GetAllInfo(const FullName& name) override
    {
        std::string  result{};
        std::string  marks_to_string{};
        for (const auto& stud : this->student())
        {
            if (std::tie(stud.fullname().name(),stud.fullname().surname(),stud.fullname().patronymic()) ==
                std::tie(name.name(),name.surname(), name.patronymic()))
            {
                result = name.name() + name.surname() + name.patronymic(); //name.has_patronymic();

                for (auto const& mark : stud.marks())
                {
                    marks_to_string += std::to_string(mark);
                }
                result += marks_to_string + std::to_string(stud.average_score());
            }
            else return "Student not found/n";
        }
        return result;
    }
    std::string GetAllInfo() override
    {
        std::string  result{};
        std::string  marks_to_string{};
        for (const auto& stud : this->student())
        {
            if (this != nullptr)
            {
                result = stud.fullname().name() + stud.fullname().surname() + stud.fullname().patronymic(); //name.has_patronymic();
                for (auto const& mark : stud.marks())
                {
                    marks_to_string += std::to_string(mark);
                }
                result += marks_to_string + std::to_string(stud.average_score());
            }
            else return "Student group is empty/n";
        }
        return result;
    }
};

int main()
{
    FullName fn1, fn2, fn3;
    Student student1, student2, student3;
    StudentsGroup studentGroup;
    Group group;
    fn1.set_name("Artem");
    fn1.set_surname("Kopin");
    group.add_student();
    std::cout << fn1.name() << std::endl;

    return 0;
}