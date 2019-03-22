#if !defined(AFX_ALLDLG_H__A6F938CF_8CB4_4198_89C9_F282EE04D5E5__INCLUDED_)
#define AFX_ALLDLG_H__A6F938CF_8CB4_4198_89C9_F282EE04D5E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AllDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAllDlg dialog

class CAllDlg : public CDialog
{
// Construction
public:
	void ReadUser(CListCtrl *pList);
	CAllDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAllDlg)
	enum { IDD = IDD_ALL_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAllDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLDLG_H__A6F938CF_8CB4_4198_89C9_F282EE04D5E5__INCLUDED_)
