#include "stdafx.h"
#include "pch.h"
#include "Secretary.h"
IMPLEMENT_SERIAL(Secretary, UnProEmploee, 1);

Secretary::Secretary() : knowEnglish(false) {}

Secretary::Secretary(bool m_knowEnglish, bool m_doPhisicalWork, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion)
	: UnProEmploee(m_doPhisicalWork, m_name, m_age, m_idNumber, m_department, m_yearsWorked, m_saleryExpectaion)
{
	this->knowEnglish = m_knowEnglish;
}
bool Secretary:: Getknowenglish() const
{
	return this->knowEnglish;
}
void Secretary:: Setknowenglish(bool newKnowEnglish)
{
	this->knowEnglish = newKnowEnglish;
}
void Secretary:: setDepartment(CString newDepartment)
{
    this->department = newDepartment;
}

void Secretary::Serialize(CArchive& archive)
{
    // casting to cstring because of string serializtions problems
    UnProEmploee::Serialize(archive);
    if (archive.IsStoring())
    {   // contains information
        archive << knowEnglish;
    }
    else
    {   // no info inside the file 
        archive >> knowEnglish;
    }
}