// almaz.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Shape {
protected:
    string name;
    string type;
public:
    Shape(string name, string type){
        this->name = name;
        this->type = type;
    }
};

class Rectangle: public Shape {

};

class Square: public Rectangle {

};

class Triangle: public Shape {

};

class Circle: public Shape {

};

class Cube: public Square{

};

class Sphere: public Circle {

};

int main()
{
   
}

