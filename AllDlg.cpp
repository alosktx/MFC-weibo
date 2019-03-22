// AllDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Weibo.h"
#include "AllDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllDlg dialog


CAllDlg::CAllDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAllDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAllDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAllDlg, CDialog)
	//{{AFX_MSG_MAP(CAllDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllDlg message handlers

BOOL CAllDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0,"户名",0,150);
	pList->InsertColumn(1,"权限",0,150);

	ReadUser(pList);


	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAllDlg::ReadUser(CListCtrl *pList)
{
    CFile file;
	if(!file.Open("./user.dat",CFile::modeRead|CFile::shareDenyNone))
		return;
	pList->DeleteAllItems();

	SUser u;
	int i=0;
	while(file.Read(&u,sizeof(u))==sizeof(u))
	{
		pList->InsertItem(i,u.sName);
		pList->SetItemText(i,1,u.nPrior?"管理员":"普通");
		++i;
	}
	file.Close();
}
