#include "turtleProgram.h"
#include <iostream>

using namespace std;

//constructor
TurtleProgram::TurtleProgram(string direction, string steps)
{
	//starting of array length - instructions are given in pairs
		Arrayturtle = new string[2]; 
		Arrayturtle[0] = direction;
		Arrayturtle[1] = steps;
	//starting of array length - instructions are given in pairs
		length = 2; 

}

//copy constructor
TurtleProgram::TurtleProgram(const TurtleProgram& obj)
{
		this->setLength(obj.length);
		Arrayturtle = new string[length];

		for (int i = 0; i < length; i++)
			Arrayturtle[i] = obj.Arrayturtle[i];
}

//Overloads ostream 
ostream& operator<< (ostream& outStream, const TurtleProgram& obj)
{
	
	for (int i = 0; i < obj.getLength(); i++)
	{
		 outStream  <<  obj.getIndex(i)  ;
		outStream << " ";
	}
	return outStream;
}

//Overloads for comparison
bool TurtleProgram::operator==(const TurtleProgram& obj) const
{
	string basePointTurtle = "";
	string comaparingTurtle = "";

	for (int i = 0; i < obj.getLength(); i++)
		basePointTurtle += obj.Arrayturtle[i];
	for (int l = 0; l < this->getLength(); l++)
		comaparingTurtle += this->Arrayturtle[l];

	return (basePointTurtle == comaparingTurtle);
}

bool TurtleProgram::operator!=(const TurtleProgram& obj) const
{
	bool resualt = false;
	if (obj == *this)
		resualt = true;
	return resualt;
}

//Overloads for assignment operations
TurtleProgram& TurtleProgram::operator=(const TurtleProgram& obj)
{
	
	if (this == &obj)
		return *this;
	else
	{
		this->setLength(obj.length);
		delete[] Arrayturtle;
		Arrayturtle = new string[length];
		
		for (int i = 0; i < length; i++)
			Arrayturtle[i] = obj.Arrayturtle[i];
	}
	return *this;
}

//Overloads for assignment operations

const TurtleProgram TurtleProgram::operator+(const TurtleProgram& obj) const
{
	TurtleProgram resualt;
	int size = obj.getLength() + this->getLength();
	resualt.setLength(size);
	resualt.Arrayturtle = new string[size];
	
	for (int i = 0; i < this->getLength(); i++)
		resualt.Arrayturtle[i] = this->Arrayturtle[i];
	for (int j = 0; j < obj.getLength(); j++)
		resualt.Arrayturtle[j + this->getLength()] = obj.Arrayturtle[j];
		
	return resualt;

}

TurtleProgram& TurtleProgram::operator+=(const TurtleProgram& obj)
{
	return *this = *this + obj;
}

const TurtleProgram TurtleProgram::operator*(int multiplication) const
{
	TurtleProgram resualt;

	for (int i = 0; i < multiplication; i++)
	{
		resualt += *this;
	}

	return resualt;
}

TurtleProgram& TurtleProgram::operator*=(int multiplication)
{
	TurtleProgram resualt;
	resualt = *this * multiplication;
	*this = resualt;
	return *this;
}