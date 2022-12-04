#pragma once
#include "Emploee.h"
class UnProEmploee :
    public Emploee
{
protected:
    bool doPhisicalWork;

public:
    DECLARE_SERIAL(UnProEmploee)
    UnProEmploee();
    UnProEmploee(bool m_doPhisicalWork,CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion);
    virtual ~UnProEmploee() {};
    virtual void setDepartment() {};
    void setDoPhisicalWork(bool b1);
    bool getPhisicalWork() const;
    void Serialize(CArchive&);
};

