// ManagerViewDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "ManagerViewDlg.h"
#include "afxdialogex.h"
#include "NewEmploeeDlg.h"

//int sizeofarray;

// ManagerViewDlg dialog

IMPLEMENT_DYNAMIC(ManagerViewDlg, CDialogEx)

ManagerViewDlg::ManagerViewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ManagerViewDlg, pParent)
	, listBoxStr(_T(""))
{
}

ManagerViewDlg::~ManagerViewDlg()
{
}

void ManagerViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ListofEmploee, ListofWorkers);
	DDX_Control(pDX, IDC_editName, nameEdit);
	DDX_Control(pDX, IDC_empLisrBox, listBoxCtr);
	DDX_LBString(pDX, IDC_empLisrBox, listBoxStr);
	DDX_Control(pDX, IDC_LIST1, TestList);
}

BOOL ManagerViewDlg::OnInitDialog()
{
	//CPaintDC dc(this);
	//CString m_strPathName;
	//TCHAR szFilters[] = _T("Emploee (*.emp)| *.emp| All files (*.*) |*.*||");
	//CFileDialog dlg(TRUE, _T("emp", ), _T(""),
	//	OFN_OVERWRITEPROMPT, szFilters);
	//if (dlg.DoModal() == IDOK)
	//{
	//	if (!(emploeesLoad.IsEmpty())) { emploeesLoad.RemoveAll(); } // clear the array if it got values
	//	m_strPathName = dlg.GetPathName();
	//	CFile file(m_strPathName, CFile::modeRead);
	//	CArchive ar(&file, CArchive::load);
	//	emploeesLoad.Serialize(ar);
	//	ar.Close();
	//	file.Close();
	//	m_strPathName.Format(_T("Loaded Succesfully %d emploees"), sizeofarray);
	//	MessageBox(m_strPathName, L"Loaded From File");
		//listBoxCtr.AddString(_T("name: "));
		//for (int i = 0; i < emploeesLoad.GetSize(); i++)
		//{
		//		//.AddString(_T("name: "));
		//	//listBoxCtr.AddString(_T("name: ") + emploeesLoad[i]->getName() +
		//		//_T("ID: ") + emploeesLoad[i]->getID());
		//}
	//}
	
	return 0;
}


BEGIN_MESSAGE_MAP(ManagerViewDlg, CDialogEx)
	
	ON_BN_CLICKED(IDC_Load2, &ManagerViewDlg::OnBnClickedLoad2)
	ON_BN_CLICKED(IDC_CheckLogisticBox, &ManagerViewDlg::OnBnClickedChecklogisticbox)
END_MESSAGE_MAP()


// ManagerViewDlg message handlers


//void ManagerViewDlg ::upDate()
//{
//	sizeofarray = emploeesLoad.GetSize();
//	//UpdateData(false); // update the form
//}

void ManagerViewDlg::OnBnClickedLoad2()
{
	//CPaintDC dc(this);
	//	CString m_strPathName;
	//	TCHAR szFilters[] = _T("Emploee (*.emp)| *.emp| All files (*.*) |*.*||");
	//	CFileDialog dlg(TRUE, _T("emp", ), _T(""),
	//		OFN_OVERWRITEPROMPT, szFilters);
	//	if (dlg.DoModal() == IDOK)
	//	{
	//		if (!(emploeesLoad.IsEmpty())) { emploeesLoad.RemoveAll(); } // clear the array if it got values
	//		m_strPathName = dlg.GetPathName();
	//		CFile file(m_strPathName, CFile::modeRead);
	//		CArchive ar(&file, CArchive::load);
	//		emploeesLoad.Serialize(ar);
	//		ar.Close();
	//		file.Close();
	//		upDate();
	//		m_strPathName.Format(_T("Loaded Succesfully %d emploees"), sizeofarray);
	//		MessageBox(m_strPathName, L"Loaded From File");
	//	}
}


void ManagerViewDlg::OnBnClickedChecklogisticbox()
{

}