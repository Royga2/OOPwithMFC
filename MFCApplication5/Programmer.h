#pragma once
#include "proEmploee.h"
class Programmer :
    public proEmploee
{
protected:
    bool knowCpp;
    bool knowPython;
    bool knowJava;

public:
    DECLARE_SERIAL(Programmer)
   Programmer();
    Programmer(BOOL m_know_cpp, BOOL m_know_python, BOOL m_know_java,int m_degree, CString m_school, int m_avarageScores, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion);
    virtual ~Programmer() {};
    virtual void setDepartment(CString newDepartment);
    bool GetknowCpp() const;
    void SetknowCpp(bool knowcpp);
    bool GetknowPython() const;
    void SetknowPython(bool knowpython);
    bool GetknowPJava() const;
    void SetknowJava(bool knowjava);
    void Serialize(CArchive&);
};



