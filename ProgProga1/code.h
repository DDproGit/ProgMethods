#pragma once
#include <vector>
#include <iostream>

class Shape
{
public:
	enum class type { sphere, parallelepiped, empty };
	type key;
	virtual void setValues();
	Shape();
	type getKey();
protected:
private:
};

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(type key);
	Sphere(type key, int radius);
	void setValues(type key, int radius);
	int getRadius();
	type getKey();
protected:
	int radius;
};

class Parallelepiped : public Shape
{
public:
	Parallelepiped();
	Parallelepiped(type key);
	Parallelepiped(type key, int heigth, int width, int depth);
	void setValues(type key, int heigth, int width, int depth);
	int getHeigth();
	int getWidth();
	int getDepth();
	type getKey();
protected:
	int heigth;
	int width;
	int depth;
};

class HashArray
{
public:
	// Adds element to array and return hash and place
	std::pair <int, int> addElement(Sphere newElement);
	std::pair <int, int> addElement(Parallelepiped newElement);
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
	std::pair <int, int> findElement();
protected:
	std::vector<Shape*> arrayOfVectorsOfElements[30];
private:
};