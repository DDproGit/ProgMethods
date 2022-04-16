#pragma once
#include <vector>
#include <iostream>

class Shape
{
public:
	//virtual void setValues() = 0;
	virtual void outElement(std::ostream& out, int counted) = 0;
	virtual int getVolume() = 0;
	//Shape();
protected:
private:
};

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(int radius);
	void setValues(int radius);
	void outElement(std::ostream& out, int counter);
	int getVolume();
	int getRadius();
protected:
	int radius;
};

class Parallelepiped : public Shape
{
public:
	Parallelepiped();
	Parallelepiped(int heigth, int width, int depth);
	void setValues(int heigth, int width, int depth);
	void outElement(std::ostream& out, int counter);
	int getVolume();
	int getHeigth();
	int getWidth();
	int getDepth();
protected:
	int heigth;
	int width;
	int depth;
};

class HashArray
{
public:
	//kausda
	void fillContainer(std::istream& in);
	void showContainer(std::ostream& out);
	// Adds element to array and return hash and place
	std::pair <int, int> addElement(Sphere* newElement);
	std::pair <int, int> addElement(Parallelepiped* newElement);
	// Delete element from array by hash and place
	void removeElement(int hash, int place);
	// Replace element with this hash and place with new 
	void replaceElement(int hash, int place, Sphere newShape);
	void replaceElement(int hash, int place, Parallelepiped newShape);
	// Return element by hash and place
	Shape* getElement(int hash, int place);
	Sphere* getSphere(int hash, int place);
	Parallelepiped* getParallelepiped(int hash, int place);
	int getSizeOfVector(int hash);
	// Return hash of element
	int makeHashOfShape(Sphere shapeToHash);
	int makeHashOfShape(Parallelepiped shapeToHash);
	void setCountOfElements(int count);
	int getCountOfElements();
	std::pair <int, int> findElement();
protected:
	std::vector<Shape*> arrayOfVectorsOfElements[30];
	int countOfElements;
private:
};