
//Made By: Lior Nissan 313428138
// And: Sagi Buria 313560252

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "ResTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	:CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, TablesPeople[0]);
	DDX_Text(pDX, IDC_EDIT2, TablesBills[0]);
	DDX_Text(pDX, IDC_EDIT3, TablesPeople[1]);
	DDX_Text(pDX, IDC_EDIT4, TablesBills[1]);
	DDX_Text(pDX, IDC_EDIT5, TablesPeople[2]);
	DDX_Text(pDX, IDC_EDIT6, TablesBills[2]);
	DDX_Text(pDX, IDC_EDIT7, TablesPeople[3]);
	DDX_Text(pDX, IDC_EDIT8, TablesBills[3]);
	DDX_Text(pDX, IDC_EDIT9, TablesPeople[4]);
	DDX_Text(pDX, IDC_EDIT10, TablesBills[4]);
	DDX_Text(pDX, IDC_EDIT11, TablesPeople[5]);
	DDX_Text(pDX, IDC_EDIT12, TablesBills[5]);
	DDX_Text(pDX, IDC_EDIT13, TotalPeopleAmount);
	DDX_Control(pDX, IDC_CHECK1, isSpareTable);
	DDX_Control(pDX, IDC_PROGRESS1, ResCapBar);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCprojectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCprojectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCprojectDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO7, &CMFCprojectDlg::OnBnClickedRadio7)
	ON_EN_CHANGE(IDC_EDIT13, &CMFCprojectDlg::OnEnChangeEdit13)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CMFCprojectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &CMFCprojectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_MFCBUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_MFCBUTTON5, &CMFCprojectDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO1); //checks the first radio by defualt
	pButton->SetCheck(true);


	return TRUE;  // return TRUE  unless you set the focus to a control
}


HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCprojectDlg::OnBnClickedButton4() //Add people  +
{
	CString str;
	CurrResturant[whichTable]->addPeople();
	str.Format(_T("%d"), CurrResturant[whichTable]->getPeople());
	TablesPeople[whichTable] = str; //prints to the right text box
	OnEnChangeEdit13();
	UpdateData(FALSE);

}


void CMFCprojectDlg::OnBnClickedButton6() //less People  -
{
	CString str;
	CurrResturant[whichTable]->lessPeople();
	str.Format(_T("%d"), CurrResturant[whichTable]->getPeople());
	TablesPeople[whichTable] = str; //prints to the right text box
	OnEnChangeEdit13();
	UpdateData(FALSE);
}


void CMFCprojectDlg::OnBnClickedButton3() //Add adult plate
{

	if (CurrResturant[whichTable]->getPeople() > 0) //No people = No FOOD!
	{
		CString str;
		CurrResturant[whichTable]->setBill(50);
		str.Format(_T("%d"), (int)(CurrResturant[whichTable]->getBill()));
		TablesBills[whichTable] = str;
		UpdateData(FALSE);
	}
}


void CMFCprojectDlg::OnBnClickedRadio1()
{
	whichTable = 0;
}

void CMFCprojectDlg::OnBnClickedRadio2()
{
	whichTable = 1;
}

void CMFCprojectDlg::OnBnClickedRadio3()
{
	whichTable = 2;
}

void CMFCprojectDlg::OnBnClickedRadio4()
{
	whichTable = 3;
}

void CMFCprojectDlg::OnBnClickedRadio5()
{
	whichTable = 4;
}

void CMFCprojectDlg::OnBnClickedRadio7() //Spare Table Radio
{
	if (isSpareTable.GetCheck() == BST_CHECKED)
		AfxMessageBox(_T("Error! Table Disabled"));
	else
		whichTable = 5;
}

void CMFCprojectDlg::OnBnClickedButton5() //checkout button
{
	CString str;
	CurrResturant[whichTable]->checkOut();
	str.Format(_T("%d"), CurrResturant[whichTable]->getPeople());
	TablesPeople[whichTable] = str;
	str.Format(_T("%d"), CurrResturant[whichTable]->getBill());
	TablesBills[whichTable] = str;
	OnEnChangeEdit13();
	UpdateData(FALSE);
}





void CMFCprojectDlg::OnBnClickedCheck1() //Disable Spare Table Checkbox
{
	int temp;
	if (isSpareTable.GetCheck() == BST_CHECKED)
	{
		temp = whichTable; //clears the spare table and checkout
		whichTable = 5;
		OnBnClickedButton5();
		whichTable = temp;

		free(CurrResturant[5]);
		GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);


		CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO7);
		pButton->SetCheck(false);
		if (whichTable == 5)
		{
			 pButton = (CButton*)GetDlgItem(IDC_RADIO1);
			pButton->SetCheck(true);
			whichTable = 0;
		}
	}
	else
	{
		CurrResturant[5] = new FamilyTable;
		GetDlgItem(IDC_RADIO7)->EnableWindow(TRUE);
	}
	OnEnChangeEdit13();
}





void CMFCprojectDlg::OnBnClickedButton7() //Children Plate button
{
	if ((int)CurrResturant[whichTable]->getPeople() > 0) // if number of People more than 0
	{
		CString ptr;
		CurrResturant[whichTable]->setBill(30);
		ptr.Format(_T("%d"), (int)CurrResturant[whichTable]->getBill());
		TablesBills[whichTable] = ptr;
		UpdateData(FALSE);
	}
}


void CMFCprojectDlg::OnEnChangeEdit13() //the people in the resturant meter
{
	ResCapBar.EnableWindow(TRUE);
	Amount_of_people = 0;
	CString ctr;
	if (isSpareTable.GetCheck() == BST_CHECKED)
	{
		ResCapBar.SetRange(0, 41);
		for (int i = 0; i <= 4; i++) //Without Spare Table
			Amount_of_people += CurrResturant[i]->getPeople();
		ctr.Format(_T("Total Costumers: %d/41"), Amount_of_people);
		TotalPeopleAmount = ctr;
		ResCapBar.SetPos(Amount_of_people);
	}
	else
	{
		ResCapBar.SetRange(0, 49);
		for (int i = 0; i <= 5; i++) //With Spare Table
			Amount_of_people += CurrResturant[i]->getPeople();
		ctr.Format(_T("Total Costumers: %d/49"), Amount_of_people);
		TotalPeopleAmount = ctr;
		ResCapBar.SetPos(Amount_of_people);

	}
	UpdateData(FALSE);
}

