#pragma once
#include "UnProEmploee.h"
class Secretary :
    public UnProEmploee
{
private:
    bool knowEnglish;
public:
    DECLARE_SERIAL(Secretary)
    Secretary();
    Secretary(bool m_knowEnglish,bool m_doPhisicalWork, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion);
    virtual ~Secretary() {};
    bool Getknowenglish() const;
    void Setknowenglish(bool newknowenglish);
    virtual void setDepartment(CString newDepartment);
    void Serialize(CArchive&);
};



