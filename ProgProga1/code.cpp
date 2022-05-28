#include "code.h"
#include <iostream>
#include <string> 
#include <fstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>

Sphere::Sphere()
{
	radius = 0;
	temperature = 0;
	density = 0;
}
Sphere::Sphere(int radius, int temperature, float density)
{
	this->radius = radius;
	this->temperature = temperature;
	this->density = density;
}

void Sphere::setValues(int radius, int temperature, float density)
{
	this->radius = radius;
	this->temperature = temperature;
	this->density = density;
}
int Sphere::getRadius()
{
	return radius;
}
int Sphere::getTemperature()
{
	return temperature;
}
float Sphere::getDensity()
{
	return density;
}
int Sphere::getVolume()
{
	return 4 / 3 * 3.14 * getRadius();
}


void Sphere::outElement(std::ostream& out, int counter)
{
	out << "Element number " << counter << " is a sphere with radius: ";
	out << radius << ", ";
	out << temperature << ", density = ";
	out << density << ", volume = ";
	out << getVolume() << "\n";
};
void Sphere::outElement(std::ostream& out, int counter, int limit)
{
	if (limit == 1)
		return;
	outElement(out, counter);
};



Parallelepiped::Parallelepiped()
{
	heigth = 0;
	width = 0;
	depth = 0;
	temperature = 0;
	density = 0;
}
Parallelepiped::Parallelepiped(int heigth, int width, int depth, int temperature, float density)
{
	this->heigth = heigth;
	this->width = width;
	this->depth = depth;
	this->temperature = temperature;
	this->density = density;
}

void Parallelepiped::setValues(int heigth, int width, int depth, int temperature, float density)
{
	this->heigth = heigth;
	this->width = width;
	this->depth = depth;
	this->temperature = temperature;
	this->density = density;
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
int Parallelepiped::getTemperature()
{
	return temperature;
}
float Parallelepiped::getDensity()
{
	return this->density;
}
int Parallelepiped::getVolume()
{
	return this->heigth * this->width * this->depth;
}

void Parallelepiped::outElement(std::ostream& out, int counter)
{
	out << "Element number " << counter << " is a parallelepiped with edges: ";
	out << heigth << ", ";
	out << width << ", ";
	out << depth << ", ";
	out << temperature << ", density = ";
	out << density << ", volume = ";
	out << getVolume() << "\n";
};
void Parallelepiped::outElement(std::ostream& out, int counter, int limit)
{
	if (limit == 2)
		return;
	outElement(out, counter);
};


Tetraedr::Tetraedr()
{
	heigth = 0;
	temperature = 0;
	density = 0;
}
Tetraedr::Tetraedr(int heigth, int temperature, float density)
{
	this->heigth = heigth;
	this->temperature = temperature;
	this->density = density;
}
void Tetraedr::setValues(int heigth, int temperature, float density)
{
	this->heigth = heigth;
	this->temperature = temperature;
	this->density = density;
}
int Tetraedr::getHeigth()
{
	return heigth;
}
int Tetraedr::getTemperature()
{
	return temperature;
}
float Tetraedr::getDensity()
{
	return this->density;
}
int Tetraedr::getVolume()
{
	return ((pow(this->heigth, 3) * sqrt(2))/12);
}

void Tetraedr::outElement(std::ostream& out, int counter)
{
	out << "Element number " << counter << " is a tetraedr with edge: ";
	out << heigth << ", ";
	out << temperature << ", density = ";
	out << density << ", volume = ";
	out << getVolume() << "\n";
}
void Tetraedr::outElement(std::ostream& out, int counter, int limit)
{
	if (limit == 3)
		return;
	outElement(out, counter);
}

void HashArray::fillContainer(std::istream& in)
{
	std::string tmpstr;
	std::getline(in, tmpstr);
	int n = 0;
	try
	{
		n = stoi(tmpstr);
	}
	catch(...)
	{
		std::cout << "Invalid count of elements\n";
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		std::string inputline;
		std::getline(in, inputline);
		std::vector<std::string> splitVector;
		boost::split(splitVector, inputline, boost::is_any_of(" "), boost::token_compress_on);
		splitVector.erase(
			std::remove_if(splitVector.begin(), splitVector.end(),
				[](std::string const& s) { return s.size() == 0; }), splitVector.end());
		int caser = -1;
		try
		{
			if (splitVector.size()>0)
				caser = stoi(splitVector[0]);
		}
		catch (...)
		{
			std::cout << "Invalid type of shape in line " << i << std::endl;
			exit(0);
		}
		switch (caser)
		{
			case 0:
			{
				if (splitVector.size() == 4)
				{
					try
					{
						int radius, temperature = 0;
						float density = 0.00;
						density = stof(splitVector[1]);
						temperature = stoi(splitVector[2]);
						radius = stoi(splitVector[3]);
						Sphere* tmp = new Sphere(radius, temperature, density);
						tmp->outElement(std::cout, i);
						this->addElement(tmp);
					}
					catch (...)
					{
						std::cout << "Invalid arguments in line " << i+2;
						exit(0);
					}
				}
				else
				{
					std::cout << "Incorrect number of arguments \n";
				}
				break;
			}
			case 1:
			{
				if (splitVector.size() == 6)
				{
					try
					{
						int heigth, width, depth, temperature = 0;
						float density = 0.00;
						density = stof(splitVector[1]);
						temperature = stoi(splitVector[2]);
						heigth = stoi(splitVector[3]);
						width = stoi(splitVector[4]);
						depth = stoi(splitVector[5]);
						Parallelepiped* tmp = new Parallelepiped(heigth, width, depth, temperature, density);
						tmp->outElement(std::cout, i);
						this->addElement(tmp);
					}

					catch (...)
					{
						std::cout << "Invalid arguments in line " << i+2;
						exit(0);
					}
				}
				else
				{
					std::cout << "Incorrect number of arguments \n";
				}
				break;
			}
			case 2:
			{
				if (splitVector.size() == 4)
				{
					try
					{
						int heigth, temperature = 0;
						float density = 0.00;
						density = stof(splitVector[1]);
						temperature = stoi(splitVector[2]);
						heigth = stoi(splitVector[3]);
						Tetraedr* tmp = new Tetraedr(heigth, temperature, density);
						tmp->outElement(std::cout, i);
						this->addElement(tmp);
					}
					catch (...)
					{
						std::cout << "Invalid arguments in line " << i+2;
						exit(0);
					}
				}
				else
				{
					std::cout << "Incorrect number of arguments \n";
				}
				break;
			}
			default:
			{
				std::cout << "Wrong type of shape in line " << i+2 << std::endl;
				break;
			}
		}
	}
	setCountOfElements(n);
}
void HashArray::saveContainer(std::ostream & out)
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
void HashArray::showContainer()
{
	std::cout << "Show every element - 0, without spheres - 1, without parallelepipeds - 2, without tetraedrs - 3: ";
	int limiter = 0;
	std::cin >> limiter;
	int counter = 0;
	for (int i = 0; i < 30; i++)
	{
		if (this->getSizeOfVector(i) != 0)
		{
			int size = this->getSizeOfVector(i);
			for (int j = 0; j < size; j++)
			{
				Shape* tmp = this->getElement(i, j);
				tmp->outElement(std::cout, counter, limiter);
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
std::pair <int, int> HashArray::addElement(Tetraedr* newElement)
{
	Tetraedr* myElement = newElement;
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
void HashArray::replaceElement(int hash, int place, Tetraedr newShape)
{
	if (30)
		if (place <= arrayOfVectorsOfElements[hash].size())
		{
			Tetraedr* myElement = new Tetraedr();
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
Tetraedr* HashArray::getTetraedr(int hash, int place)
{
	Tetraedr* tmp = new Tetraedr;
	if (hash <= 30)
		if (place <= arrayOfVectorsOfElements[hash].size())
		{
			tmp = (Tetraedr*)arrayOfVectorsOfElements[hash][place];
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
int HashArray::makeHashOfShape(Tetraedr shapeToHash)
{
	int hash = 0;
	hash += shapeToHash.getHeigth() * 17;
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
bool comp(Shape* a, Shape* b)
{
	return a->getVolume() < b->getVolume();
}
void HashArray::sortElements()
{
	for (int i = 0; i < size; i++)
	{
		std::sort(arrayOfVectorsOfElements[i].begin(),
			arrayOfVectorsOfElements[i].end(), comp);
	}
}
