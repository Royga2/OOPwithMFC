#include "stdafx.h"
#include "pch.h"
#include "proEmploee.h"

IMPLEMENT_SERIAL(proEmploee, Emploee, 1);

proEmploee::proEmploee() : degree(0), school(""), avarageScores(0) {}

proEmploee::proEmploee(int m_degree, CString m_school, int m_avarageScores, CString m_name, int m_age, CString m_idNumber, CString m_department, int m_yearsWorked, int m_saleryExpectaion)
	: Emploee(m_name, m_age, m_idNumber, m_department, m_yearsWorked,  m_saleryExpectaion)
{
	this->degree = m_degree;
	this->school = m_school;
	this->avarageScores = m_avarageScores;
}

	/*degree(m_degree), school(m_school), avarageScores(m_avarageScores) {};*/

int proEmploee::getDegree() const
{
	return this->degree;
}
void proEmploee::setDegree(int newdegree)
{
	this->degree = newdegree;
}
void proEmploee::setSchool(CString newschool)
{
	this->school = newschool;
}
CString proEmploee::getSchool() const
{
	return this->school;
}

int proEmploee::getAvarageScores() const
{
	return this->avarageScores;
}
void proEmploee::setAvarageScores(int newavarageScores)
{
	this->avarageScores = newavarageScores;
}
void proEmploee::Serialize(CArchive& archive)
{
	// casting to cstring because of string serializtions problems
	Emploee::Serialize(archive);
	if (archive.IsStoring())
	{   // contains information
		archive << degree << school << avarageScores;
	}
	else
	{   // no info inside the file 
		archive >> degree >> school >> avarageScores;
	}
}