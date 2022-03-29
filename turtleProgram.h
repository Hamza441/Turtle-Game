#ifndef TURTLE_H
#define TURTLE_H
#include<string>
#include <iostream>
using namespace std;


class TurtleProgram
{
	public:
		TurtleProgram() 
		{ 
			length = 0; Arrayturtle = NULL;
		};
		TurtleProgram(string direction, string steps);
		TurtleProgram(const TurtleProgram& obj);
		
		~TurtleProgram()
		 { 
			 delete[] Arrayturtle;
		 };

		
		string getIndex(int index) const 
		{ 
			return Arrayturtle[index] ;
		};
		int getLength() const 
		{ 
			return length;
		
		};
		void setIndex(int index, string movement) 
		{ 
			Arrayturtle[index] = movement;
			
	    };
		void setLength(int lng)
		{
			  length = lng; 
		};

		bool operator==(const TurtleProgram& obj) const;
		bool operator!=(const TurtleProgram& obj) const;

		TurtleProgram& operator=(const TurtleProgram& obj);

		const TurtleProgram operator+(const TurtleProgram& obj) const;
		TurtleProgram& operator+=(const TurtleProgram& obj);
		const TurtleProgram operator*(int multiplication) const;
		TurtleProgram& operator*=(int multiplication);

		
	private:
		string* Arrayturtle;
		int length;
};

ostream& operator<< (ostream& outStream, const TurtleProgram& obj);

#endif