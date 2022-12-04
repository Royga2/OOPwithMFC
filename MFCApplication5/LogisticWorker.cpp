#include "stdafx.h"
#include "pch.h"
#include "LogisticWorker.h"
IMPLEMENT_SERIAL(LogisticWorker, UnProEmploee, 1);

LogisticWorker::LogisticWorker() : liftingCapability(0) {}
LogisticWorker::LogisticWorker(bool m_liftingCapability, bool m_doPhisicalWork, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion)
	: UnProEmploee(m_doPhisicalWork, m_name, m_age, m_idNumber, m_department, m_yearsWorked, m_saleryExpectaion)
{
	this->liftingCapability = m_liftingCapability;
}

int LogisticWorker:: getliftingCapability() const
{
	return this->liftingCapability;
}
void LogisticWorker:: setliftingCapability(int newcapability)
{
    this->liftingCapability = newcapability;
}
void LogisticWorker:: setDepartment(CString newDepartment)
{
    this->department = newDepartment;
}

void LogisticWorker::Serialize(CArchive& archive)
{
    // casting to cstring because of string serializtions problems
    UnProEmploee::Serialize(archive);
    if (archive.IsStoring())
    {   // contains information
        archive << liftingCapability;
    }
    else
    {   // no info inside the file 
        archive >> liftingCapability;
    }
}