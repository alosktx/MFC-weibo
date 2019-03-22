#if !defined(AFX_PRIORDLG_H__41E598F5_5EBB_40E8_9234_A415AFB46993__INCLUDED_)
#define AFX_PRIORDLG_H__41E598F5_5EBB_40E8_9234_A415AFB46993__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PriorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg dialog

class CPriorDlg : public CDialog
{
// Construction
public:
	void ReadUser(CListCtrl *pList);
	CPriorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPriorDlg)
	enum { IDD = IDD_PRIOR_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPriorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPriorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnDestroy();
	afx_msg void OnMod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIORDLG_H__41E598F5_5EBB_40E8_9234_A415AFB46993__INCLUDED_)
