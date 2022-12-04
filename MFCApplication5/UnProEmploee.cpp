#include "stdafx.h"
#include "pch.h"
#include "UnProEmploee.h"

IMPLEMENT_SERIAL(UnProEmploee, Emploee, 1);

UnProEmploee::UnProEmploee() : doPhisicalWork(false) {}

UnProEmploee::UnProEmploee(bool m_doPhisicalWork, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion)
	: Emploee(m_name, m_age, m_idNumber, m_department, m_yearsWorked, m_saleryExpectaion)
{
	this->doPhisicalWork = m_doPhisicalWork;
}

void UnProEmploee:: setDoPhisicalWork(bool b1)
{
	this->doPhisicalWork = b1;
}
bool UnProEmploee:: getPhisicalWork() const
{
	return this->doPhisicalWork;
}
void UnProEmploee::Serialize(CArchive& archive)
{
    // casting to cstring because of string serializtions problems
    Emploee::Serialize(archive);
    if (archive.IsStoring())
    {   // contains information
        archive << doPhisicalWork;
    }
    else
    {   // no info inside the file 
        archive >> doPhisicalWork;
    }
}