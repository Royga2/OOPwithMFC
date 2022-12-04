#pragma once
#include "pch.h"
#include "afxdialogex.h"
#include "Emploee.h"
#include "LogisticWorker.h"
#include "proEmploee.h"
#include "UnProEmploee.h"
#include "Programmer.h"
#include "Secretary.h"


// ManagerViewDlg dialog

class ManagerViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerViewDlg)

public:
	ManagerViewDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ManagerViewDlg();

	CTypedPtrArray< CObArray, Emploee* > emploeesLoad;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ManagerViewDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListBox ListofWorkers;
	afx_msg void OnBnClickedLoad2();
	//void upDate();
	CEdit nameEdit;
	CString tempName;
	CListBox listBoxCtr;
	CString listBoxStr;
	afx_msg void OnBnClickedChecklogisticbox();
	CListBox TestList;
};
