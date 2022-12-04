#include "stdafx.h"
#include "pch.h"
#include "Emploee.h"

IMPLEMENT_SERIAL(Emploee, CObject, 1);

Emploee::Emploee() : name(""), age(0), idNumber("000"), department(""), yearsWorked(0), saleryExpectaion(0) {}

Emploee::Emploee(CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion) :
	name(m_name), age(m_age), idNumber(m_idNumber), department(m_department), yearsWorked(m_yearsWorked), saleryExpectaion(m_saleryExpectaion) {};

void Emploee::setName(CString n)
{
	this-> name = n;
}

CString Emploee::getName() const
{
	return this-> name;
}

void Emploee::setAge(int newAge)
{
	this-> age = newAge;
}

int Emploee::getAge() const
{
	return this-> age;
}

void Emploee::setID(CString idNum)
{
	this-> idNumber = idNum;
}
CString Emploee::getID() const
{
	return this-> idNumber;
}
void Emploee::setYears(int yrsWrkd)
{
	this-> yearsWorked = yrsWrkd;
	if (yearsWorked < 0)
	{
	this->	yearsWorked = 0;
	}
}

int Emploee::getYears() const
{
	return this-> yearsWorked;
}

CString Emploee::getDepartment() const
{
	return this-> department;
}

int Emploee::getSaleryExpectaion() const
{
	return this-> saleryExpectaion;
}

void Emploee::setSaleryExpectaion(int new_saleryExp)
{
	this-> saleryExpectaion = new_saleryExp;
}
void Emploee::Serialize(CArchive& archive)
{
    // casting to cstring because of string serializtions problems
    CObject::Serialize(archive);
    if (archive.IsStoring())
    {   // contains information
        archive << name << age << idNumber << department << yearsWorked << saleryExpectaion;
    }
    else
    {   // no info inside the file 
        CString c_string;
        archive >> name >> age >> idNumber >> department >> yearsWorked >> saleryExpectaion;
        /*CT2CA s(c_string);
        string str(s);
        this->setName(str);*/
    }
}
