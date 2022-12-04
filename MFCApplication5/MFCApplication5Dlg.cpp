// MFCApplication5Dlg.cpp : implementation file
//
#include "pch.h"
#include "stdafx.h"
#include "afxdialogex.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "Emploee.h"
#include "NewEmploeeDlg.h"
#include "ManagerViewDlg.h"
#include "LogisticWorker.h"
#include "proEmploee.h"
#include "UnProEmploee.h"
#include "Programmer.h"
#include "Secretary.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//IMPLEMENT_SERIAL(Emploee, CObject, 1)

#define MAX_CFileDialog_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFileDialog_FILE_COUNT * (MAX_PATH + 1)) + 1)

// CAboutDlg dialog used for App About
int sizeofarray;

class CAboutDlg : public CDialogEx 
{
public:
	CAboutDlg();
	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication5Dlg dialog



CMFCApplication5Dlg::CMFCApplication5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION5_DIALOG, pParent)
	, passWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PassBox, passWord);
	DDX_Control(pDX, IDC_LIST1, Listing);
}

BEGIN_MESSAGE_MAP(CMFCApplication5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_PassBox, &CMFCApplication5Dlg::OnEnChangePassbox)
	ON_BN_CLICKED(IDC_empBut1, &CMFCApplication5Dlg::OnBnClickedempbut1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication5Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMFCApplication5Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication5Dlg message handlers
CStatic* holderimage;
BOOL CMFCApplication5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	holderimage = (CStatic*)GetDlgItem(IDC_STATIC);
	CString str;
	str = CString(_T("office.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 855, 495, LR_LOADFROMFILE);
	holderimage->SetBitmap(pic1);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.



// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication5Dlg::OnEnChangePassbox()
{
	CString key = CString(_T("1234"));
	UpdateData(true);
	if (passWord == key)
	{
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
		MessageBox(_T("Please connect to a server!!\n... for now choose a file from your pc"));
		//newManagerPageDlg.Create(MAKEINTRESOURCE(IDD_ManagerViewDlg), this);
		//newManagerPageDlg.ShowWindow(SW_SHOW);
		UpdateData(false);
	}
}




void CMFCApplication5Dlg::OnBnClickedempbut1()
{
	//GetDlgItem(IDC_psswordText)->ShowWindow(SW_HIDE);
	//GetDlgItem(IDC_PassBox)->ShowWindow(SW_HIDE);
	newEmployeePageDlg.Create(MAKEINTRESOURCE(IDD_NewEmploeeDlg), this);
	newEmployeePageDlg.ShowWindow(SW_SHOW);
}


void CMFCApplication5Dlg::OnBnClickedmanebut()
{
	//GetDlgItem(IDC_psswordText)->ShowWindow(SW_SHOW);
	//GetDlgItem(IDC_PassBox)->ShowWindow(SW_SHOW);
}

void CMFCApplication5Dlg::upDate()
{
	sizeofarray = emploeesLoad.GetSize();
	//UpdateData(false); // update the form
}

void CMFCApplication5Dlg::OnBnClickedButton1()
{
	CPaintDC dc(this);
	CString m_strPathName;
	TCHAR szFilters[] = _T("Emploee (*.emp)| *.emp| All files (*.*) |*.*||");
	CFileDialog dlg(TRUE, _T("emp", ), _T(""),
		OFN_OVERWRITEPROMPT, szFilters);
	if (dlg.DoModal() == IDOK)
	{
		if (!(emploeesLoad.IsEmpty())) { emploeesLoad.RemoveAll(); } // clear the array if it got values
		m_strPathName = dlg.GetPathName();
		CFile file(m_strPathName, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		emploeesLoad.Serialize(ar);
		ar.Close();
		file.Close();
		upDate();
		m_strPathName.Format(_T("Loaded Succesfully %d emploees"), sizeofarray);
		MessageBox(m_strPathName, L"Loaded From File");
	}

	//int size = emploeesLoad.GetSize();
	CString str;

	for (int i = 0; i<sizeofarray; i++) 
	{
		CString name = emploeesLoad[i]->getName();
		Listing.AddString(name);
		//name.Format(L"%s", (emploeesLoad[i]->getName()));
	}


}


void CMFCApplication5Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
