// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Weibo.h"
#include "LoginDlg.h"
extern CWeiboApp theApp;
 int i=1;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{

	if(CheckUser())
	CDialog::OnOK();

	else
	{
		AfxMessageBox("用户名或密码错误!");
		i++;
		SetDlgItemText(IDC_PASS,"");
		GetDlgItem(IDC_PASS)->SetFocus();
		if(i>3)
		{
			CDialog::OnCancel();
		}
	
	}
}

BOOL CLoginDlg::CheckUser()
{
	CString szName,szPass;
	GetDlgItemText(IDC_NAME,szName);
    GetDlgItemText(IDC_PASS,szPass);
	szName.MakeLower();
	CFile file;
	if(!file.Open ("./user.dat",CFile::modeRead))
	{
		CreateUser();
		if(!file.Open ("./user.dat",CFile::modeRead))
		return FALSE;
	}
	
	SUser u;
	while(file.Read(&u,sizeof(u)))
	{
		if(szName==u.sName&&szPass==u.sPass)
		{
			theApp.m_us=u;

			return TRUE;
		}
	}
	return FALSE; 

}

void CLoginDlg::CreateUser()
{
	CFile file;
    if(!file.Open ("./user.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("创建文件失败");
		return;
	}
	SUser u={"wly","123",1};
	file.Write (&u,sizeof(u));
	file.Close ();

}
