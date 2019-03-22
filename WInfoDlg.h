#if !defined(AFX_WINFODLG_H__9263E13B_CE07_4217_B4F1_D15DCE56512D__INCLUDED_)
#define AFX_WINFODLG_H__9263E13B_CE07_4217_B4F1_D15DCE56512D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWInfoDlg dialog

class CWInfoDlg : public CDialog
{
// Construction
public:
	CListCtrl m_List;
	CWInfoDlg*m_pInfoDlg;
	CWInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWInfoDlg)
	enum { IDD = IDD_WINFO_DLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnSave();
	afx_msg void OnOpen();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINFODLG_H__9263E13B_CE07_4217_B4F1_D15DCE56512D__INCLUDED_)
