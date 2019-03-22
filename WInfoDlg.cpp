// WInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Weibo.h"
#include "WInfoDlg.h"
extern CWeiboApp theApp;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWInfoDlg dialog


CWInfoDlg::CWInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CWInfoDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWInfoDlg message handlers

BOOL CWInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_List.SubclassDlgItem(IDC_LIST1,this);
	m_List.InsertColumn(0,"΢�����",0,100);
	m_List.InsertColumn(1,"΢������",0,500);

	CString str=theApp.m_us.sName;
    str+="��΢����Ϣҳ";
    SetWindowText(str);	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWInfoDlg::OnAdd() 
{
	CString str;
	GetDlgItemText(IDC_NUMB,str);
	CListCtrl & list=m_List;                      //ʹ�����ã����ٴ�����
	int i=0,nCount=list.GetItemCount();
	while(i<nCount)
	{
		if(list.GetItemText(i,0)==str)
		{
		AfxMessageBox("΢�����"+str+"�Ѵ���");              
		return;
		}
		++i;
	}
	list.InsertItem(nCount,str);

	GetDlgItemText(IDC_WINFO,str);
	list.SetItemText(nCount,1,str);

	SetDlgItemText(IDC_NUMB,"1");  
	SetDlgItemText(IDC_WINFO,"");

	GetDlgItem(IDC_NUMB)->SetFocus();

}

void CWInfoDlg::OnDel() 
{
	int nSel=m_List.GetSelectionMark();
	if(nSel<0)
	{
		AfxMessageBox("��ѡ��һ΢�������ɾ��");
	    return;
	}
	if(IDNO==AfxMessageBox("ȷ��ɾ������΢����",MB_YESNO)) 
		return;
	m_List.DeleteItem(nSel);
}

void CWInfoDlg::OnSave() 
{
   	CString str=theApp.m_us.sName;
	str+="��΢��";
	CFileDialog dlg(FALSE,"dat",str,OFN_OVERWRITEPROMPT);  
	if(IDCANCEL==dlg.DoModal())
	return;
	CString szFile=dlg.GetPathName();
	CFile file;
	if(!file.Open(szFile,CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("�����ļ�ʧ��!");
		return;
	}
	int i=0,nCount=m_List.GetItemCount();
	SInfo info;
	while(i<nCount)
	{
		info.nNumb=atoi(m_List.GetItemText(i,0));
		m_List.GetItemText(i,1,info.sWei,sizeof(info.sWei));
		file.Write(&info,sizeof(info));
		++i;

	}
	
}
//OFN_HIDEREADONLY
void CWInfoDlg::OnOpen() 
{
	AfxMessageBox("ѡ�С���.dat�ļ��򿪲鿴΢��");

	CFileDialog dlg(TRUE);  
	if(IDCANCEL==dlg.DoModal())
	return;
	CString szFile=dlg.GetPathName();
	CFile file;
	if(!file.Open(szFile,CFile::modeReadWrite|CFile::shareDenyNone))
	{
		AfxMessageBox("���ļ�ʧ��!");
		return;
	}
	m_List.DeleteAllItems();
	SInfo info;
	int i=0;
	CString str;
	while(file.Read(&info,sizeof(info))==sizeof(info))
	{
		str.Format("%d",info.nNumb);
		m_List.InsertItem(i,str);

		m_List.SetItemText(i,1,info.sWei);
		++i;
	}
}

void CWInfoDlg::OnButton1() 
{
	AfxMessageBox("����鿴΢���ɲ鿴����΢��");
}
