#pragma once
#include <vector>
#include <iostream>

class Shape
{
public:
	//virtual void setValues() = 0;
	virtual void outElement(std::ostream& out, int counter) = 0;
	virtual void outElement(std::ostream& out, int counter, int limit) = 0;
	virtual int getVolume() = 0;
	//Shape();
protected:
	float density;
private:
};

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(int radius, int temperature, float density);
	void setValues(int radius, int temperature, float density);
	void outElement(std::ostream& out, int counter);
	void outElement(std::ostream& out, int counter, int limit);
	int getVolume();
	int getRadius();
	float getDensity();
	int getTemperature();
protected:
	int radius;
	int temperature;
};

class Parallelepiped : public Shape
{
public:
	Parallelepiped();
	Parallelepiped(int heigth, int width, int depth, int temperature, float density);
	void setValues(int heigth, int width, int depth, int temperature, float density);
	void outElement(std::ostream& out, int counter);
	void outElement(std::ostream& out, int counter, int limit);
	int getVolume();
	int getHeigth();
	int getWidth();
	int getDepth();
	float getDensity();
	int getTemperature();
protected:
	int heigth;
	int width;
	int depth;
	int temperature;
};

class Tetraedr : public Shape
{
public:
	Tetraedr();
	Tetraedr(int heigth, int temperature, float density);
	void setValues(int heigth, int temperature, float density);
	void outElement(std::ostream& out, int counter);
	void outElement(std::ostream& out, int counter, int limit);
	int getVolume();
	int getHeigth();
	float getDensity();
	int getTemperature();

protected:
	int heigth;
	int temperature;
};


class HashArray
{
public:
	//kausda
	void fillContainer(std::istream& in);
	void saveContainer(std::ostream& out);
	void showContainer();
	// Adds element to array and return hash and place
	std::pair <int, int> addElement(Sphere* newElement);
	std::pair <int, int> addElement(Parallelepiped* newElement);
	std::pair <int, int> addElement(Tetraedr* newElement);
	// Delete element from array by hash and place
	void removeElement(int hash, int place);
	// Replace element with this hash and place with new 
	void replaceElement(int hash, int place, Sphere newShape);
	void replaceElement(int hash, int place, Parallelepiped newShape);
	void replaceElement(int hash, int place, Tetraedr newShape);
	// Return element by hash and place
	Shape* getElement(int hash, int place);
	Sphere* getSphere(int hash, int place);
	Parallelepiped* getParallelepiped(int hash, int place);
	Tetraedr* getTetraedr(int hash, int place);
	int getSizeOfVector(int hash);
	// Return hash of element
	int makeHashOfShape(Sphere shapeToHash);
	int makeHashOfShape(Parallelepiped shapeToHash);
	int makeHashOfShape(Tetraedr shapeToHash);
	void setCountOfElements(int count);
	int getCountOfElements();
	void sortElements();
	//std::pair <int, int> findElement();
protected:
	std::vector<Shape*> arrayOfVectorsOfElements[30];
	int countOfElements;
private:
	int size = 30;
	/*bool comp(Shape& a, Shape& b);*/
};