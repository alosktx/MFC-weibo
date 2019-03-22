; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWeiboDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Weibo.h"

ClassCount=6
Class1=CWeiboApp
Class2=CWeiboDlg

ResourceCount=6
Resource2=IDD_LOGIN_DLG
Resource1=IDR_MAINFRAME
Class3=CLoginDlg
Resource3=IDD_WINFO_DLG
Class4=CWInfoDlg
Resource4=IDD_WEIBO_DIALOG
Class5=CPriorDlg
Resource5=IDD_PRIOR_DLG
Class6=CAllDlg
Resource6=IDD_ALL_DLG

[CLS:CWeiboApp]
Type=0
HeaderFile=Weibo.h
ImplementationFile=Weibo.cpp
Filter=N

[CLS:CWeiboDlg]
Type=0
HeaderFile=WeiboDlg.h
ImplementationFile=WeiboDlg.cpp
Filter=D
LastObject=CWeiboDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_WEIBO_DIALOG]
Type=1
Class=CWeiboDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_INFO,button,1342242816
Control3=IDC_ADMIN,button,1342242816
Control4=IDC_ALL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_LOGIN_DLG]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON3,button,1342242816
Control4=IDC_NAME,edit,1350631552
Control5=IDC_BUTTON4,button,1342242816
Control6=IDC_PASS,edit,1350631552

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDlg
VirtualFilter=dWC

[DLG:IDD_WINFO_DLG]
Type=1
Class=CWInfoDlg
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDC_LIST1,SysListView32,1350664193
Control3=IDC_WINFO,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ADD,button,1342242816
Control6=IDC_DEL,button,1342242816
Control7=IDC_SAVE,button,1342242816
Control8=IDC_NUMB,combobox,1344340227
Control9=IDC_STATIC,static,1342308352
Control10=IDC_OPEN,button,1342242816
Control11=IDC_BUTTON1,button,1342242816
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352

[CLS:CWInfoDlg]
Type=0
HeaderFile=WInfoDlg.h
ImplementationFile=WInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CWInfoDlg
VirtualFilter=dWC

[DLG:IDD_PRIOR_DLG]
Type=1
Class=CPriorDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDC_LIST,SysListView32,1350664193
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PASS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_ADD,button,1342242816
Control9=IDC_DEL,button,1342242816
Control10=IDC_PRIOR,combobox,1344339971
Control11=IDC_MOD,button,1342242816

[CLS:CPriorDlg]
Type=0
HeaderFile=PriorDlg.h
ImplementationFile=PriorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPriorDlg
VirtualFilter=dWC

[DLG:IDD_ALL_DLG]
Type=1
Class=CAllDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_LIST,SysListView32,1350664193

[CLS:CAllDlg]
Type=0
HeaderFile=AllDlg.h
ImplementationFile=AllDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAllDlg
VirtualFilter=dWC

