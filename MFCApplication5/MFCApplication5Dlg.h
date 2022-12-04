
// MFCApplication5Dlg.h : header file

#pragma once
#include "NewEmploeeDlg.h"
#include "ManagerViewDlg.h"
#include "afxtempl.h"


// CMFCApplication5Dlg dialog
class CMFCApplication5Dlg : public CDialogEx 
{
// Construction
public:
	CMFCApplication5Dlg(CWnd* pParent = nullptr);	// standard constructor
	
	CTypedPtrArray< CObArray, Emploee* > emploeesLoad;
	void upDate();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION5_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	

// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	NewEmploeeDlg newEmployeePageDlg;
	ManagerViewDlg newManagerPageDlg;
	CString passWord;
	afx_msg void OnEnChangePassbox();
	//void upDate();
	afx_msg void OnBnClickedempbut1();
	afx_msg void OnBnClickedmanebut();
	CListBox Listing;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};

