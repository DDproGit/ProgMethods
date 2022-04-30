#include "code.h"
#include <iostream>

Sphere::Sphere()
{
	radius = 0;
}
Sphere::Sphere(int radius)
{
	this->radius = radius;
}

void Sphere::setValues(int radius)
{
	this->radius = radius;
}

int Sphere::getRadius()
{
	return radius;
}

void Sphere::outElement(std::ostream& out, int counter)
{
	out << "Element number " << counter << " is a sphere with radius: ";
	out << radius << "\n";
};


Parallelepiped::Parallelepiped()
{
	heigth = 0;
	width = 0;
	depth = 0;
}
Parallelepiped::Parallelepiped(int heigth, int width, int depth)
{
	this->heigth = heigth;
	this->width = width;
	this->depth = depth;
}

void Parallelepiped::setValues(int heigth, int width, int depth)
{
	this->heigth = heigth;
	this->width = width;
	this->depth = depth;
}

int Parallelepiped::getHeigth()
{
	return heigth;
}
int Parallelepiped::getWidth()
{
	return width;
}
int Parallelepiped::getDepth()
{
	return depth;
}

void Parallelepiped::outElement(std::ostream& out, int counter)
{
	out << "Element number " << counter << " is a parallelepiped with edges: ";
	out << heigth << ", ";
	out << width << ", ";
	out << depth << "\n";
};
//dlkasdad
void HashArray::fillContainer(std::istream& in)
{
	int n = 0;
	in >> n;
	for (int i = 0; i < n; i++)
	{
		int type = 0;
		in >> type;
		switch (type)
		{
		case 0:
		{
			int radius = 0;
			in >> radius;
			Sphere* tmp = new Sphere(radius);
			std::cout << "Element number " << i << ": ";
			std::cout << tmp->getRadius() << ". That's a sphere.\n";
			this->addElement(tmp);
			break;
		}
		case 1:
		{
			int heigth, width, depth = 0;
			in >> heigth >> width >> depth;
			Parallelepiped* tmp = new Parallelepiped(heigth, width, depth);
			std::cout << "Element number " << i << ": ";
			std::cout << tmp->getHeigth() << ", ";
			std::cout << tmp->getWidth() << ", ";
			std::cout << tmp->getDepth() << ". That's a parallelepiped.\n";
			this->addElement(tmp);
			break;
		}
		}
	}
	setCountOfElements(n);
}
void HashArray::showContainer(std::ostream & out)
{
	int counter = 0;
	for (int i = 0; i < 30; i++)
	{
		if (this->getSizeOfVector(i) != 0)
		{
			int size = this->getSizeOfVector(i);
			for (int j = 0; j < size; j++)
			{
				Shape* tmp = this->getElement(i, j);
				tmp->outElement(out, counter);
				counter++;
			}
		}
	}
}
// Adds element to array and return hash
std::pair <int, int> HashArray::addElement(Sphere* newElement)
{
	Sphere* myElement = newElement;
	int hash = makeHashOfShape(*newElement);
	arrayOfVectorsOfElements[hash].push_back(myElement);
	std::pair <int, int> tmp;
	tmp = std::make_pair(hash, arrayOfVectorsOfElements[hash].size() - 1);
	return tmp;
}
std::pair <int, int> HashArray::addElement(Parallelepiped* newElement)
{
	Parallelepiped* myElement = newElement;
	int hash = makeHashOfShape(*newElement);
	arrayOfVectorsOfElements[hash].push_back(myElement);
	std::pair <int, int> tmp;
	tmp = std::make_pair(hash, arrayOfVectorsOfElements[hash].size() - 1);
	return tmp;
}
// Delete element from array by hash and place
void HashArray::removeElement(int hash, int place)
{
	if (30)
		if (place <= arrayOfVectorsOfElements[hash].size())
			arrayOfVectorsOfElements[hash].erase(arrayOfVectorsOfElements[hash].begin() + place);
		else
			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << arrayOfVectorsOfElements[hash].size() << "\n";
	else
		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
}
// Replace element with this hash and place with new element
void HashArray::replaceElement(int hash, int place, Sphere newShape)
{
	if (30)
		if (place <= arrayOfVectorsOfElements[hash].size())
		{
			Sphere* myElement = new Sphere();
			myElement = &newShape;
			arrayOfVectorsOfElements[hash][place] = myElement;
		}
		else
			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << arrayOfVectorsOfElements[hash].size() << "\n";
	else
		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
}
void HashArray::replaceElement(int hash, int place, Parallelepiped newShape)
{
	if (30)
		if (place <= arrayOfVectorsOfElements[hash].size())
		{
			Parallelepiped* myElement = new Parallelepiped();
			myElement = &newShape;
			arrayOfVectorsOfElements[hash][place] = myElement;
		}
		else
			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << arrayOfVectorsOfElements[hash].size() << "\n";
	else
		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
}
// Return element by hash and place
Shape* HashArray::getElement(int hash, int place)
{
	Shape* tmp = arrayOfVectorsOfElements[hash][place];
	return tmp;
};
Sphere* HashArray::getSphere(int hash, int place)
{
	Sphere* tmp = new Sphere;
	if (hash <= 30)
		if (place <= arrayOfVectorsOfElements[hash].size())
		{
			tmp = (Sphere*)arrayOfVectorsOfElements[hash][place];
		}
		else
			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << arrayOfVectorsOfElements[hash].size() << "\n";
	else
		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
	return tmp;
}
Parallelepiped* HashArray::getParallelepiped(int hash, int place)
{
	Parallelepiped* tmp = new Parallelepiped;
	if (hash <= 30)
		if (place <= arrayOfVectorsOfElements[hash].size())
		{
			tmp = (Parallelepiped*)arrayOfVectorsOfElements[hash][place];
		}
		else
			std::cout << "Wrong position in vector, pos = " << place << ", but size is " << arrayOfVectorsOfElements[hash].size() << "\n";
	else
		std::cout << "Wrong position in array, pos = " << hash << ", but size is " << 30 << "\n";
	return tmp;
}
// Return size of vector
int HashArray::getSizeOfVector(int hash)
{
	return arrayOfVectorsOfElements[hash].size();
}
// Return hash of element
int HashArray::makeHashOfShape(Sphere shapeToHash)
{
	int hash = 0;
	hash += shapeToHash.getRadius() * 23;
	hash = hash % 30;
	return hash;
}
int HashArray::makeHashOfShape(Parallelepiped shapeToHash)
{
	int hash = 0;
	hash += shapeToHash.getHeigth() * 17;
	hash += shapeToHash.getWidth() * 11;
	hash += shapeToHash.getDepth() * 7;
	hash = hash % 30;
	return hash;
}
void HashArray::setCountOfElements(int count)
{
	countOfElements = count;
}
int HashArray::getCountOfElements()
{
	return countOfElements;
}