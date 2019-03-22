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
	m_List.InsertColumn(0,"微博编号",0,100);
	m_List.InsertColumn(1,"微博内容",0,500);

	CString str=theApp.m_us.sName;
    str+="的微博信息页";
    SetWindowText(str);	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWInfoDlg::OnAdd() 
{
	CString str;
	GetDlgItemText(IDC_NUMB,str);
	CListCtrl & list=m_List;                      //使用引用，减少代码量
	int i=0,nCount=list.GetItemCount();
	while(i<nCount)
	{
		if(list.GetItemText(i,0)==str)
		{
		AfxMessageBox("微博编号"+str+"已存在");              
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
		AfxMessageBox("请选中一微博编号再删除");
	    return;
	}
	if(IDNO==AfxMessageBox("确定删除此条微博吗？",MB_YESNO)) 
		return;
	m_List.DeleteItem(nSel);
}

void CWInfoDlg::OnSave() 
{
   	CString str=theApp.m_us.sName;
	str+="的微博";
	CFileDialog dlg(FALSE,"dat",str,OFN_OVERWRITEPROMPT);  
	if(IDCANCEL==dlg.DoModal())
	return;
	CString szFile=dlg.GetPathName();
	CFile file;
	if(!file.Open(szFile,CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("保存文件失败!");
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
	AfxMessageBox("选中××.dat文件打开查看微博");

	CFileDialog dlg(TRUE);  
	if(IDCANCEL==dlg.DoModal())
	return;
	CString szFile=dlg.GetPathName();
	CFile file;
	if(!file.Open(szFile,CFile::modeReadWrite|CFile::shareDenyNone))
	{
		AfxMessageBox("打开文件失败!");
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
	AfxMessageBox("点击查看微博可查看他人微博");
}
