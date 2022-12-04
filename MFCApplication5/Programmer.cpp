#include "stdafx.h"
#include "pch.h"
#include "Programmer.h"

IMPLEMENT_SERIAL(Programmer, proEmploee, 1);

Programmer::Programmer() : knowCpp(false), knowPython(false), knowJava(false) {};
Programmer::Programmer(BOOL m_know_cpp, BOOL m_know_python, BOOL m_know_java, int m_degree, CString m_school, int m_avarageScores, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion)
    : proEmploee (m_degree,m_school,m_avarageScores,m_name,m_age,m_idNumber,m_department,m_yearsWorked,m_saleryExpectaion)
    //knowCpp(know_cpp), knowPython(know_python), knowJava(know_java) {};
{
    this->knowCpp = m_know_cpp;
    this->knowPython = m_know_python;
    this->knowJava = m_know_java;
}

void Programmer::setDepartment(CString newDepartment)
{
    newDepartment = "Programmer";
}
bool Programmer::GetknowCpp() const
{
    return this->knowCpp;
}
void Programmer::SetknowCpp(bool knowcpp)
{
    this->knowCpp = knowcpp;
}
bool Programmer::GetknowPython() const
{
    return this->knowPython;
}
void Programmer::SetknowPython(bool knowpython)
{
    this->knowPython = knowpython;
}
bool Programmer::GetknowPJava() const
{
    return this->knowJava;
}
void Programmer::SetknowJava(bool knowjava)
{
    this->knowJava = knowjava;
}


void Programmer::Serialize(CArchive& archive)
{
    // casting to cstring because of string serializtions problems
    proEmploee::Serialize(archive);
    if (archive.IsStoring())
    {   // contains information
        archive << knowCpp << knowPython << knowJava;
    }
    else
    {   // no info inside the file 
        archive >> knowCpp >> knowPython >> knowJava;
    }
}
