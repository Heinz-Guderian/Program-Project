
// ProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgramDlg dialog



CProgramDlg::CProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	fg = true;

	SetWindowTextW(L"Program");

	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProgramDlg message handlers

BOOL CProgramDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProgramDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CClientDC dc(this);
		GetClientRect(&rc);
		GetClientRect(&w);
		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 12, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		x1 = w.left = rc.left + 275;
		x2 = w.right = rc.right - 120;
		y1 = w.top = rc.top + 70;
		y2 = w.bottom = rc.bottom - 180;

		dc.Rectangle(&w);
		//green 
		dc.FillSolidRect(&w, RGB(0, 255, 0));
		
		w.left = x1 - 170;
		w.top = y1 + 260;
		w.right = x2 - 40;
		w.bottom = y2 + 51;

		dc.Rectangle(&w);
		dc.FillSolidRect(&w, RGB(0, 255, 255));

		
		x = x2 - 200;
		y = y2;

		dc.Ellipse(x, y, x + r1, y + r1);
		

		
		x = x2 - 220;
		y = y2 - 20;
		dc.Ellipse(x + r2 / 2, y + r2 / 2, x + r2, y + r2);

		r1 = 110;
		x = x1 - 121;
		y = y2;
		dc.Ellipse(x, y, x + r1, y + r1);
 		r2 = 100;
		x = x1 - 141;
		y = y2 - 20;
		dc.Ellipse(x + r2 / 2, y + r2 / 2, x + r2, y + r2);

		dc.MoveTo(x1 - 120, y1 + 35);
		dc.LineTo(x2 - 410, y1 + 35);
		dc.LineTo(x2 - 410, y2 - 33);
		dc.LineTo(x1 - 170, y2 - 33);
		dc.LineTo(x1 - 170, y2 - 120);
		dc.LineTo(x1 - 120, y1 + 35);

		dc.MoveTo(x1 - 105, y1 + 60);
		dc.LineTo(x2 - 435, y1 + 60);
		dc.LineTo(x2 - 435, y2 - 90);
		dc.LineTo(x1 - 150, y2 - 90);
		dc.LineTo(x1 - 105, y1 + 60);





		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

