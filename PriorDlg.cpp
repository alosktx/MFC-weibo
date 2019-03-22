// PriorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Weibo.h"
#include "PriorDlg.h"
extern CWeiboApp theApp;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg dialog


CPriorDlg::CPriorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPriorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPriorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPriorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPriorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPriorDlg, CDialog)
	//{{AFX_MSG_MAP(CPriorDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_MOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg message handlers

BOOL CPriorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CString str=theApp.m_us.sName;
    str+="管理员的用户信息页";
    SetWindowText(str);	
	
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0,"户名",0,150);
	pList->InsertColumn(1,"密码",0,150);
	pList->InsertColumn(2,"权限",0,150);

    ReadUser(pList);
	CComboBox*pComb=(CComboBox*)GetDlgItem(IDC_PRIOR);
	pComb->SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CPriorDlg::ReadUser(CListCtrl *pList)
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
		pList->SetItemText(i,1,u.sPass);
		pList->SetItemText(i,2,u.nPrior?"管理员":"普通");
		++i;
	}
	file.Close();
}

void CPriorDlg::OnAdd() 
{
	SUser u;

	GetDlgItemText(IDC_NAME,u.sName,sizeof(u.sName));
	strlwr(u.sName); //统一转换为小写
    CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	int i=0,nCount=pList->GetItemCount();
	while(i<nCount)  //遍历看是否已存在
	{
		if(pList->GetItemText(i,0)==u.sName)
		{
			AfxMessageBox("该用户名已存在!");
			return;
		}
		++i;

	}
	pList->InsertItem(nCount,u.sName);

	GetDlgItemText(IDC_PASS,u.sPass,sizeof(u.sPass));
	pList->SetItemText(nCount,1,u.sPass);

	CComboBox*pComb=(CComboBox*)GetDlgItem(IDC_PRIOR);
	int nSel=pComb->GetCurSel();
	//if(nSel)  //nSel==1;
	pList->SetItemText(nCount,2,nSel?"管理员":"普通");	
}

void CPriorDlg::OnDel() 
{
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
    POSITION pos=pList->GetFirstSelectedItemPosition();
    int nSel=pList->GetNextSelectedItem(pos); 
    if(nSel<0)
	{
		AfxMessageBox("请选中一个账户名再删除!");
		return;
	}
	

	if("wly"==pList->GetItemText (nSel,0))
	{
		AfxMessageBox("原始账户不可删除，只可修改密码");
	    return;
	}


	CString str;
	str.Format ("确认要删除%s吗？",pList->GetItemText (nSel,0));
	if(IDYES==AfxMessageBox(str,MB_YESNO))
	pList->DeleteItem(nSel);
}

void CPriorDlg::OnDestroy() 
{
	CDialog::OnDestroy();
		//文件保存工作
	CFile file;
	if(!file.Open("./user.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("保存文件失败!");
		return;
	}
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	int i=0,nCount=pList->GetItemCount();
	SUser u;
	while(i<nCount)
	{
		pList->GetItemText(i,0,u.sName,sizeof(u.sName));
		pList->GetItemText(i,1,u.sPass,sizeof(u.sPass));
		u.nPrior=pList->GetItemText(i,2)=="管理员";
		file.Write(&u,sizeof(u));
		++i;
	}
	file.Close();
	// TODO: Add your message handler code here
	
}

void CPriorDlg::OnMod() 
{
    CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);

	POSITION pos=pList->GetFirstSelectedItemPosition();
    int nSel=pList->GetNextSelectedItem(pos); 
    if(nSel<0)
	{
		AfxMessageBox("请选中一个账户名再修改!");
		return;
	}

	char sPass[20];
	GetDlgItemText(IDC_PASS,sPass,sizeof(sPass));
	pList->SetItemText(nSel,1,sPass);
	CComboBox*pComb=(CComboBox*)GetDlgItem(IDC_PRIOR);
	int nPrior=pComb->GetCurSel();
	if("wly"!=pList->GetItemText (nSel,0))
	pList->SetItemText (nSel,2,nPrior?"高级":"普通");	
}
