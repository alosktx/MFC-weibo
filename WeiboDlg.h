// WeiboDlg.h : header file
//

#if !defined(AFX_WEIBODLG_H__B8C46FAA_9502_4B0B_91EA_E99B01A26867__INCLUDED_)
#define AFX_WEIBODLG_H__B8C46FAA_9502_4B0B_91EA_E99B01A26867__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWeiboDlg dialog

class CWeiboDlg : public CDialog
{
// Construction
public:
	CWeiboDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWeiboDlg)
	enum { IDD = IDD_WEIBO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeiboDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWeiboDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInfo();
	afx_msg void OnAdmin();
	afx_msg void OnAll();
	afx_msg void OnBackcol();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIBODLG_H__B8C46FAA_9502_4B0B_91EA_E99B01A26867__INCLUDED_)
