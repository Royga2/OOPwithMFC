#pragma once
#include "UnProEmploee.h"
class LogisticWorker :
    public UnProEmploee
{
private:
    int liftingCapability;
public:
    LogisticWorker();
    DECLARE_SERIAL(LogisticWorker)
    LogisticWorker(bool m_liftingCapability, bool m_doPhisicalWork, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion);
    virtual ~LogisticWorker() {};
    int getliftingCapability() const;
    void setliftingCapability(int newcapability);
    virtual void setDepartment(CString newDepartment);
    void Serialize(CArchive&);
};

