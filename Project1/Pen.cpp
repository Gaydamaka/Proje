﻿#include "Pen.h"
int Pen::pen_count = 0;

void Pen::pen_color()
{
	SetConsoleTextAttribute(h, 6);
	cout << "Pen is " << color << "\n";
	SetConsoleTextAttribute(h, 15);
}
void Pen::pen_material()
{
	SetConsoleTextAttribute(h, 13);
	cout << "Pen is " << material << "\n";
	SetConsoleTextAttribute(h, 15);
}
void Pen::pen_size()
{
	SetConsoleTextAttribute(h, 12);
	cout << "Pen is " << size << " mm long\n";
	SetConsoleTextAttribute(h, 15);
}
void Pen::is_pen_cap()
{
	SetConsoleTextAttribute(h, 9);

	if (cap == true)
	{
		cout << "Pen has a cap\n";
	}
	else
	{
		cout << "Pen has no cap\n";
	}
	SetConsoleTextAttribute(h, 15);

}
void Pen::is_pen_full()
{
	SetConsoleTextAttribute(h, 10);

	if (fullness < 30)
	{
		cout << "Pen is gonna be empty, buy new one\n";
	}
	else
	{
		cout << "Pen is full, everything OK\n";
	}
	SetConsoleTextAttribute(h, 15);

}
//__________________________________
// 
void Pen::set_color(const char* color)
{
	if (this->color != nullptr) delete[] this->color;
	int length = strlen(color) + 1;
	this->color = new char[length];
	strcpy_s(this->color, length, color);
}
string Pen::get_color() const
{
	return string(color);
}

void Pen::set_material(string material)
{
	this->material = material;
}
string Pen::get_material() const
{
	return material;
}

void Pen::set_size(double size)
{
	if (size >= 1 && size <= 300) this->size = size;
	else throw "��������� ����� ����� � ��������� �� 1 �� 300 ������������.\n";
}
double Pen::get_size() const
{
	return size;
}

void Pen::set_cap(bool cap)
{
	if (cap == true || cap == false) this->cap = cap;
	else throw "��������� true or false";
}
bool Pen::get_cap() const
{
	return cap;
}

void Pen::set_fullness(unsigned int fullness)
{
	if (fullness >= 0 && fullness <= 100)
	{
		this->fullness = fullness;
	}
	else
	{
		throw "��������� ����� ����� � ��������� �� 0 �� 100 ������������.\n";
	}
}
unsigned int Pen::get_fullness() const
{
	return fullness;
}

Pen::Pen() :Pen("green", "plastic", 160, true, 50) {}

Pen::Pen(const char* a, string b, double c, bool d, unsigned int e)
{
	set_color(a);
	set_material(b);
	set_size(c);
	set_cap(d);
	set_fullness(e);
	pen_count++;
}



void Pen::print() const
{
	cout << this->color << "\n" << this->material << "\n" << this->cap << "\n" << this->size << "\n" << this->fullness << "\n";
}

Pen::~Pen()
{
	if (color != nullptr) delete[] color;
	color = nullptr;
	pen_count--;
}

Pen::Pen(string a)
{
	set_material(a);
}

Pen::Pen(const Pen& original)
{
	set_color(original.color);
	material = original.material;
	size = original.size;
	cap = original.cap;
	fullness = original.fullness;
}



int Pen::get_count()
{
	return pen_count;
}
