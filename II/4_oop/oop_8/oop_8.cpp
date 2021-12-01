/* 1
#include<stdexcept>

class DivisionByZero : public std::exception
{
public:
	DivisionByZero(const std::string& err = "Division by zero detected!") : error(err)
	{};

	const char* what() const noexcept { return error.c_str(); }

private:
	std::string error;
};


template <typename T>
double_t div(T dividend, T divider)
{
	if (divider == 0) throw DivisionByZero();
	return static_cast<double_t>(dividend) / divider;
}*/

/* 3
#pragma once
#include <cstdint>
#include <stdexcept>
#include <string>
#include <iostream>

#define SIZE_FIELD 10


struct Pos
{
	int16_t x, y;
};

enum class Direction
{
	RIGHT, LEFT, DOWN, UP, other
};

class OffTheField : public std::exception 
{
public:	
	OffTheField(Pos pos, Direction dir)
	{
		error = "Текущая позиция робота (";
		error += std::to_string(pos.x);
		error += ",";
		error += std::to_string(pos.y);
		error += ") направление движения: ";
		switch (dir)
		{
		case Direction::RIGHT:
			error += "вправо";
			break;
		case Direction::LEFT:
			error += "влево";
			break;
		case Direction::DOWN:
			error += "вниз";
			break;
		case Direction::UP:
			error += "вверх";
			break;
		default:
			break;
		}
	};

	const char* what() const noexcept { return error.c_str(); };

private:
	std::string error;
};

class IllegalCommand : public std::exception
{
public:
	IllegalCommand() = default;
};

class Robot
{
public:
	Robot() : currPos{}
	{};

	void move(Direction dir);
	void print();	

private:
	Pos currPos;
};*/

/* 2
class Ex
{
public:
	Ex(double_t arg) : x(arg) 
	{};
	double_t what() const noexcept { return x; };

private:
	double_t x;
};

class Bar
{
public:
	Bar() : y(0)
	{};

	void set(double_t a)
	{
		if (y + a > 100) throw Ex(a * y);
		else y = a;
	}

private:
	double_t y;
};*/

#include<stdexcept>

class DivisionByZero : public std::exception
{
public:
	DivisionByZero(const std::string& err = "Division by zero detected!") : error(err)
	{};

	const char* what() const noexcept { return error.c_str(); }

private:
	std::string error;
};


template <typename T>
double_t div(T dividend, T divider)
{
	if (divider == 0) throw DivisionByZero();
	return static_cast<double_t>(dividend) / divider;
}


void Robot::move(Direction dir)
{
	switch (dir)
	{
	case Direction::RIGHT:
		if (++currPos.x >= SIZE_FIELD)
		{
			--currPos.x;
			throw OffTheField(currPos, dir);
		}
		break;
	case Direction::LEFT:
		if (--currPos.x < 0)
		{
			++currPos.x;
			throw OffTheField(currPos, dir);
		}
		break;
	case Direction::DOWN:
		if (++currPos.y >= SIZE_FIELD)
		{
			--currPos.y;
			throw OffTheField(currPos, dir);
		}
		break;
	case Direction::UP:
		if (--currPos.y < 0)
		{
			++currPos.y;
			throw OffTheField(currPos, dir);
		}
		break;
	default: throw IllegalCommand();
		break;
	}
}

void Robot::print()
{
	for (size_t i = 0; i < SIZE_FIELD; i++)
	{
		for (size_t j = 0; j < SIZE_FIELD; j++)
		{
			if (j == currPos.x && i == currPos.y) std::cout << "X";
			else std::cout << "_";
		}
		std::cout << std::endl;
	}
}
