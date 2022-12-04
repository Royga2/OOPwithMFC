#pragma once

//NewEmploeeDlg dialog
#include "pch.h"
//#include "MFCApplication5.h"
#include "afxdialogex.h"
#include "Emploee.h"
#include "LogisticWorker.h"
#include "proEmploee.h"
#include "UnProEmploee.h"
#include "Programmer.h"
#include "Secretary.h"


class NewEmploeeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewEmploeeDlg)

public:
	NewEmploeeDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewEmploeeDlg();

	CTypedPtrArray< CObArray, Emploee* > emploees;

	void updatearr();

	//CTypedPtrArray< CObArray, Emploee* > emploees;
	//void updatearr();
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NewEmploeeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();
	CString newEmploeeName;
	int newEmploeeAge;
	CString newEmploeeId;
	int eYearsWorked;
	int newEmploeeSaleryExp;
	afx_msg void OnBnClickedOk();
	int newEmploeeDegree;
	CString newEmploeeSchool;
	int newEmploeeAvarageScores;
	CString emploeeType;
	afx_msg void OnCbnCloseupEmploeecombo();
	afx_msg void OnBnClickedcheckpython();
	afx_msg void OnBnClickedCheckjava();
	afx_msg void OnBnClickedCheckcpp();
	BOOL know_python;
	BOOL know_java;
	BOOL know_cpp;
	int selType;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	int lifting;
	BOOL phisicalWork;
	int kilo;
	BOOL English_n;
	afx_msg void OnPaint();


	afx_msg void OnBnClickedsave2();
};
