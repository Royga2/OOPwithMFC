#pragma once
#include "Emploee.h"
class proEmploee :
    public Emploee
{
protected:
    int degree;
    CString school;
    int avarageScores;

public:
    DECLARE_SERIAL(proEmploee)
    proEmploee();
    proEmploee(int m_degree, CString m_school, int m_avarageScores, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion);
    virtual ~proEmploee() {};
    virtual void setDepartment() {};
    int getDegree() const;
    void setDegree(int newdegree);
    CString getSchool() const;
    void setSchool(CString newschool);
    int getAvarageScores() const;
    void setAvarageScores(int newavarageScores);
    void Serialize(CArchive&);
};

