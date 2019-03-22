// Weibo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Weibo.h"
#include "WeiboDlg.h"
#include"LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeiboApp

BEGIN_MESSAGE_MAP(CWeiboApp, CWinApp)
	//{{AFX_MSG_MAP(CWeiboApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeiboApp construction

CWeiboApp::CWeiboApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWeiboApp object

CWeiboApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CWeiboApp initialization

BOOL CWeiboApp::InitInstance()
{
	CLoginDlg ld;
	if(IDCANCEL==ld.DoModal())
		return FALSE;
	CWeiboDlg dlg;
//	m_pMainWnd = &dlg;
    dlg.DoModal();
	return FALSE;
}

/*void CWeiboApp::SetDialogBkColor(COLORREF clrCtlBK,COLORREF clrCtlText)
{
	CWinApp::SetDialogBkColor(COLORREF clrCtlBK,COLORREF clrCtlText);

}*/
