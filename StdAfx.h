// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A76ED622_AFA3_46B2_98A0_05E5DFB81B56__INCLUDED_)
#define AFX_STDAFX_H__A76ED622_AFA3_46B2_98A0_05E5DFB81B56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

struct SUser  //用以文件存储
{
	char sName[20];
	char sPass[20];
	int nPrior;

};


struct SInfo
{
	int nNumb;
	char sWei[100];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A76ED622_AFA3_46B2_98A0_05E5DFB81B56__INCLUDED_)
