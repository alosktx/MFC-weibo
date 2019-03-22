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
    str+="����Ա���û���Ϣҳ";
    SetWindowText(str);	
	
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0,"����",0,150);
	pList->InsertColumn(1,"����",0,150);
	pList->InsertColumn(2,"Ȩ��",0,150);

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
		pList->SetItemText(i,2,u.nPrior?"����Ա":"��ͨ");
		++i;
	}
	file.Close();
}

void CPriorDlg::OnAdd() 
{
	SUser u;

	GetDlgItemText(IDC_NAME,u.sName,sizeof(u.sName));
	strlwr(u.sName); //ͳһת��ΪСд
    CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	int i=0,nCount=pList->GetItemCount();
	while(i<nCount)  //�������Ƿ��Ѵ���
	{
		if(pList->GetItemText(i,0)==u.sName)
		{
			AfxMessageBox("���û����Ѵ���!");
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
	pList->SetItemText(nCount,2,nSel?"����Ա":"��ͨ");	
}

void CPriorDlg::OnDel() 
{
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
    POSITION pos=pList->GetFirstSelectedItemPosition();
    int nSel=pList->GetNextSelectedItem(pos); 
    if(nSel<0)
	{
		AfxMessageBox("��ѡ��һ���˻�����ɾ��!");
		return;
	}
	

	if("wly"==pList->GetItemText (nSel,0))
	{
		AfxMessageBox("ԭʼ�˻�����ɾ����ֻ���޸�����");
	    return;
	}


	CString str;
	str.Format ("ȷ��Ҫɾ��%s��",pList->GetItemText (nSel,0));
	if(IDYES==AfxMessageBox(str,MB_YESNO))
	pList->DeleteItem(nSel);
}

void CPriorDlg::OnDestroy() 
{
	CDialog::OnDestroy();
		//�ļ����湤��
	CFile file;
	if(!file.Open("./user.dat",CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("�����ļ�ʧ��!");
		return;
	}
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	int i=0,nCount=pList->GetItemCount();
	SUser u;
	while(i<nCount)
	{
		pList->GetItemText(i,0,u.sName,sizeof(u.sName));
		pList->GetItemText(i,1,u.sPass,sizeof(u.sPass));
		u.nPrior=pList->GetItemText(i,2)=="����Ա";
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
		AfxMessageBox("��ѡ��һ���˻������޸�!");
		return;
	}

	char sPass[20];
	GetDlgItemText(IDC_PASS,sPass,sizeof(sPass));
	pList->SetItemText(nSel,1,sPass);
	CComboBox*pComb=(CComboBox*)GetDlgItem(IDC_PRIOR);
	int nPrior=pComb->GetCurSel();
	if("wly"!=pList->GetItemText (nSel,0))
	pList->SetItemText (nSel,2,nPrior?"�߼�":"��ͨ");	
}
