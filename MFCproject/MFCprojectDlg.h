
// MFCprojectDlg.h : header file

#pragma once
#include "string.h"
#include <stdlib.h>
#include "FamilyTable.h"
#include "ResTable.h"
#include "PartyTable.h"
#include "StaffTable.h"

// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:
	CMFCprojectDlg(CWnd* pParent = nullptr);
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CArray < FamilyTable*, FamilyTable*> res;

	ResTable* CurrResturant [6]= { new FamilyTable,new FamilyTable ,new PartyTable,new StaffTable,new FamilyTable,new FamilyTable }; //all the tables
	int whichTable = 0; //which table to change
	int Amount_of_people = 0; // how much pepole on the resterunt
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnEnChangeEdit13(); //people in the resturant meter
	CButton isSpareTable;
	CString TotalPeopleAmount;
	CProgressCtrl ResCapBar;
	CString TablesPeople[6];
	CString TablesBills[6];

};
