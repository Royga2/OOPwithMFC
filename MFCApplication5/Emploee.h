#pragma once
#include <afx.h>
class Emploee :
    public CObject
{
protected:
    CString name;
    int age;
    CString idNumber;
    CString department;
    int yearsWorked;
    int saleryExpectaion;

public:
    DECLARE_SERIAL(Emploee)
    Emploee();
    Emploee(CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion);
    virtual ~Emploee() {};
    void setName(CString n);
    CString getName() const;
    void setAge(int newAge);
    int getAge() const;
    void setID(CString idNum);
    CString getID() const;
    virtual void setDepartment() {};
    CString getDepartment() const;
    void setYears(int yrsWrkd);
    int getYears() const;
    int getSaleryExpectaion() const;
    void setSaleryExpectaion(int new_saleryExp);
   void Serialize(CArchive&);



};


