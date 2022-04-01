#pragma once
#include <vector>
#include <iostream>

class Shape
{
public:
	Shape();
	Shape(int radius);
	Shape(int heigth, int width, int depth);
	~Shape();
	void setValues(int radius);
	void setValues(int heigth, int width, int depth);
	int getRadius();
	int getHeigth();
	int getWidth();
	int getDepth();
protected:
	int radius;
	int heigth;
	int width;
	int depth;
private:
};

class HashArray
{
public:
	// Adds element to array and return hash and place
	std::pair <int, int> addElement(Shape newElement);
	// Delete element from array by hash and place
	void removeElement(int hash, int place);
	// Replace element with this hash and place with new 
	void replaceElement(int hash, int place, Shape newShape);
	// Return element by hash and place
	Shape getElement(int hash, int place);
	int getSizeOfVector(int hash);
	// Return hash of element
	int makeHashOfShape(Shape shapeToHash);
	std::pair <int, int> findElement();
protected:
	std::vector<Shape> arrayOfVectorsOfElements[30];
private:
};