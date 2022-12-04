// NewEmploeeDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "NewEmploeeDlg.h"
#include "afxdialogex.h"
#include "Emploee.h"
#include "MFCApplication5Dlg.h"
#include "LogisticWorker.h"
#include "proEmploee.h"
#include "UnProEmploee.h"
#include "Programmer.h"
#include "Secretary.h"

//CTypedPtrArray< CObArray, Emploee* > emploees;
// NewEmploeeDlg dialog
int arraysize;

IMPLEMENT_DYNAMIC(NewEmploeeDlg, CDialogEx)

NewEmploeeDlg::NewEmploeeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NewEmploeeDlg, pParent)
	, newEmploeeName(_T(""))
	, newEmploeeAge(0)
	, newEmploeeId(_T(""))
	, eYearsWorked(0)
	, newEmploeeSaleryExp(0)
	, newEmploeeDegree(0)
	, newEmploeeSchool(_T(""))
	, newEmploeeAvarageScores(0)
	, emploeeType(_T(""))
	, know_python(false)
	, know_java(false)
	, know_cpp(false)

	, selType(0)
	, lifting(0)
	, phisicalWork(FALSE)
	, kilo(0)
	, English_n(FALSE)

{
}
NewEmploeeDlg::~NewEmploeeDlg()
{
}


void NewEmploeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_eNameBox, newEmploeeName);
	DDX_Text(pDX, IDC_eAgeBox, newEmploeeAge);
	DDX_Text(pDX, IDC_eIdBox, newEmploeeId);
	DDX_Text(pDX, IDC_eYearsWorkedBox, eYearsWorked);
	DDX_Text(pDX, IDC_eSaleryExpBox, newEmploeeSaleryExp);
	DDX_Text(pDX, IDC_eDegreeBox, newEmploeeDegree);
	DDX_Text(pDX, IDC_eSchoolBox, newEmploeeSchool);
	DDX_Text(pDX, IDC_eAvarageScoresBox, newEmploeeAvarageScores);
	DDX_Check(pDX, IDC_checkPython, know_python);
	DDX_Check(pDX, IDC_CheckJava, know_java);
	DDX_Check(pDX, IDC_CheckCpp, know_cpp);
	DDX_Radio(pDX, IDC_RADIO1, selType);
	DDX_Check(pDX, IDC_phisicalworkcheak, phisicalWork);
	DDX_Text(pDX, IDC_liftingcap, kilo);
	DDX_Check(pDX, IDC_english, English_n);
}

BOOL NewEmploeeDlg::OnInitDialog()
{
	OnPaint();
	//CPaintDC dc(this);
	//CRect rect;
	//GetClientRect(&rect);
	//CFont font;
	//font.CreatePointFont(430, _T("Arial"));
	//CFont* oldFont = dc.SelectObject(&font);
	//dc.SetBkMode(TRANSPARENT);
	//CString string = _T("We are hiring!!");
	//rect.OffsetRect(0, -150);
	//dc.SetTextColor(RGB(51, 204, 204));
	//dc.DrawText(string, &rect, DT_SINGLELINE |
	//	DT_CENTER | DT_VCENTER);
	//rect.OffsetRect(-8, -8);
	//dc.SetTextColor(RGB(204, 255, 255));
	//dc.DrawText(string, &rect, DT_SINGLELINE |
	//	DT_CENTER | DT_VCENTER);
	//dc.SelectObject(oldFont);
	return 0;
}



BEGIN_MESSAGE_MAP(NewEmploeeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &NewEmploeeDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_checkPython, &NewEmploeeDlg::OnBnClickedcheckpython)
	ON_BN_CLICKED(IDC_CheckJava, &NewEmploeeDlg::OnBnClickedCheckjava)
	ON_BN_CLICKED(IDC_CheckCpp, &NewEmploeeDlg::OnBnClickedCheckcpp)
	ON_BN_CLICKED(IDC_RADIO1, &NewEmploeeDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &NewEmploeeDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &NewEmploeeDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_save2, &NewEmploeeDlg::OnBnClickedsave2)
END_MESSAGE_MAP()


// NewEmploeeDlg message handlers




void NewEmploeeDlg::OnBnClickedOk()
{
	
	if (selType == 0) // programmer
	{
		emploees.Add(new Programmer(know_cpp,know_python,know_java,newEmploeeDegree,newEmploeeSchool,newEmploeeAvarageScores,newEmploeeName,newEmploeeAge,newEmploeeId,/*department*/L"Programmer",eYearsWorked,newEmploeeSaleryExp));
	}
	else if (selType == 1) //secretary
	{
		emploees.Add(new Secretary(English_n, phisicalWork,newEmploeeName, newEmploeeAge, newEmploeeId,/*department*/L"Secretary", eYearsWorked, newEmploeeSaleryExp));
	}
	else emploees.Add(new LogisticWorker(kilo,phisicalWork, newEmploeeName, newEmploeeAge, newEmploeeId,/*department*/L"Logistic Worker", eYearsWorked, newEmploeeSaleryExp));

	MessageBox(_T("Thanks!We Will be in contact"));
	UpdateData(false);
	//CDialogEx::OnOK();
}


void NewEmploeeDlg::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CFont font;
	font.CreatePointFont(430, _T("Arial"));
	CFont* oldFont = dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	CString string = _T("We are hiring!!");
	rect.OffsetRect(0, -150);
	dc.SetTextColor(RGB(51, 204, 204));
	dc.DrawText(string, &rect, DT_SINGLELINE |
		DT_CENTER | DT_VCENTER);
	rect.OffsetRect(-8, -8);
	dc.SetTextColor(RGB(204, 255, 255));
	dc.DrawText(string, &rect, DT_SINGLELINE |
		DT_CENTER | DT_VCENTER);
	dc.SelectObject(oldFont);

}

void NewEmploeeDlg::OnCbnCloseupEmploeecombo()
{

}


void NewEmploeeDlg::OnBnClickedcheckpython()
{
	know_python = true;
}


void NewEmploeeDlg::OnBnClickedCheckjava()
{
	know_java = true;
}


void NewEmploeeDlg::OnBnClickedCheckcpp()
{
	know_cpp = true;
}


void NewEmploeeDlg::OnBnClickedRadio1()
{
	selType = 0; // Programmer
	GetDlgItem(IDC_knowEnglish)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_english)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_phisicalworkcheak)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_unpro_text)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_lifting)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_liftingcap)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_eDegreeText)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_eDegreeBox)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_eDegreeText)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_eDegreeBox)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_eSchoolText)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_eSchoolBox)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_eAvarageScoresText)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_eAvarageScoresBox)->ShowWindow (SW_SHOW);
	GetDlgItem(IDC_eLangText)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_checkPython)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CheckJava)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CheckCpp)->ShowWindow(SW_SHOW);
}


void NewEmploeeDlg::OnBnClickedRadio2()
{
	selType = 1; // Secretray
	GetDlgItem(IDC_phisicalworkcheak)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_unpro_text)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_knowEnglish)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_english)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_lifting)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_liftingcap)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_eDegreeText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eDegreeBox)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eDegreeText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eDegreeBox)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eSchoolText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eSchoolBox)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eAvarageScoresText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eAvarageScoresBox)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eLangText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_checkPython)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CheckJava)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CheckCpp)->ShowWindow(SW_HIDE);

}


void NewEmploeeDlg::OnBnClickedRadio3()
{
	selType = 2; // Logistic
	GetDlgItem(IDC_phisicalworkcheak)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_unpro_text)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_lifting)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_liftingcap)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_knowEnglish)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_english)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_eDegreeText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eDegreeBox)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eDegreeText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eDegreeBox)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eSchoolText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eSchoolBox)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eAvarageScoresText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eAvarageScoresBox)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_eLangText)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_checkPython)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CheckJava)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CheckCpp)->ShowWindow(SW_HIDE);
}

void NewEmploeeDlg :: updatearr()
{
	arraysize = emploees.GetSize();
	//UpdateData(false); // update the form
}

void NewEmploeeDlg::OnBnClickedsave2()
{
	CString m_strPathName;
	TCHAR szFilters[] = _T("Emploee (*.emp)| *.emp| All files (*.*) |*.*||");
	CFileDialog dlg(FALSE, _T("emp", ), _T(""),
		OFN_OVERWRITEPROMPT, szFilters);
	if (dlg.DoModal() == IDOK)
	{
		m_strPathName = dlg.GetPathName();
		CFile file(m_strPathName, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		emploees.Serialize(ar);
		ar.Close();
		file.Close();
		updatearr();
		m_strPathName.Format(_T("Saved Succesfully %d emploees"), arraysize);
		MessageBox(m_strPathName, L"Saved");
	}
}
