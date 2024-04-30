
// calculateDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "calculate.h"
#include "calculateDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CcalculateDlg



CcalculateDlg::CcalculateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalculateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalculateDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculateDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculateDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculateDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculateDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculateDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculateDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculateDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculateDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &CcalculateDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_CE, &CcalculateDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_DEL, &CcalculateDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_ADD, &CcalculateDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CcalculateDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MULT, &CcalculateDlg::OnBnClickedMult)
	ON_BN_CLICKED(IDC_DIV, &CcalculateDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_PC, &CcalculateDlg::OnBnClickedPc)
	ON_BN_CLICKED(IDC_EQ, &CcalculateDlg::OnBnClickedEq)
	ON_BN_CLICKED(IDC_COMMA, &CcalculateDlg::OnBnClickedComma)
END_MESSAGE_MAP()


// Обработчики сообщений CcalculateDlg

BOOL CcalculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	text = (CStatic*)GetDlgItem(IDC_STATIC);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CcalculateDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CcalculateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CcalculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CcalculateDlg::addNum(int id)
{
	if (oper.has_value() && flag == false) {
		text->SetWindowTextW(_T(""));
		isDouble = false;
	}
	CString str, thistext;
	GetDlgItemText(IDC_STATIC, thistext);
	GetDlgItemText(id, str);
	thistext += str;
	text->SetWindowTextW(thistext);
	flag = true;
}

void CcalculateDlg::OnBnClicked1()
{
	addNum(IDC_1);
}


void CcalculateDlg::OnBnClicked2()
{
	addNum(IDC_2);
}


void CcalculateDlg::OnBnClicked3()
{
	addNum(IDC_3);
}


void CcalculateDlg::OnBnClicked4()
{
	addNum(IDC_4);
}


void CcalculateDlg::OnBnClicked5()
{
	addNum(IDC_5);
}


void CcalculateDlg::OnBnClicked6()
{
	addNum(IDC_6);
}


void CcalculateDlg::OnBnClicked7()
{
	addNum(IDC_7);
}


void CcalculateDlg::OnBnClicked8()
{
	addNum(IDC_8);
}


void CcalculateDlg::OnBnClicked9()
{
	addNum(IDC_9);
}


void CcalculateDlg::OnBnClicked0()
{
	addNum(IDC_0);
}


void CcalculateDlg::OnBnClickedCe()
{
	text->SetWindowTextW(_T(""));
	first.reset();
	second.reset();
}


void CcalculateDlg::OnBnClickedDel()
{
	CString thistext;
	GetDlgItemText(IDC_STATIC, thistext);
	thistext.Delete(thistext.GetLength() - 1);
	text->SetWindowTextW(thistext);
}

void CcalculateDlg::addOper(int id)
{
	flag = false;
	CString str, thistext;
	GetDlgItemText(IDC_STATIC, thistext);
	GetDlgItemText(id, str);
	oper = str[0];
	if (!isDouble) {
		first = _wtoi(thistext);
	}
	else {
		for (int i = 0; i < thistext.GetLength(); i++) {
			if (thistext[i] == ',') {
				thistext.Delete(i);
				thistext.Insert(i, '.');
			}
		}
		doubleF = _tstof(thistext);
	}
	first = _wtoi(thistext);
	text->SetWindowTextW(str);
}

void CcalculateDlg::OnBnClickedAdd()
{
	addOper(IDC_ADD);
}


void CcalculateDlg::OnBnClickedSub()
{
	addOper(IDC_SUB);
}


void CcalculateDlg::OnBnClickedMult()
{
	addOper(IDC_MULT);
}


void CcalculateDlg::OnBnClickedDiv()
{
	addOper(IDC_DIV);
}


void CcalculateDlg::OnBnClickedPc()
{
	addOper(IDC_PC);
}


void CcalculateDlg::OnBnClickedEq()
{
	CString thistext;
	GetDlgItemText(IDC_STATIC, thistext);
	if (isDouble) {
		doubleS = _tstof(thistext);
	}
	else {
		second = _wtoi(thistext);
	}
	float a, b;
	if (first.has_value()) {
		 a = first.value();
	}
	else {
		 a = doubleF.value();
	}

	if (second.has_value()) {
		 b = second.value();
	}
	else {
		 b = doubleS.value();
	}
	float res = 0;
	try {
		switch (oper.value()) {
		case'+':
			res = a + b;
			break;
		case'-':
			res = a - b;
			break;
		case'*':
			if (b == 0) {
				throw "Деление на 0";
			}
			res = a * b;
			break;
		case'/':
			res = a / b;
			break;
		case'%':
			if (b == 0) {
				throw "Деление на 0";
			}
			if ((int)a != a && (int)b != b) {
				throw "Деление на дробное";
			}
			res = int(a) % int(b);
			break;
		}
	}
	catch (CString error) {
		AfxMessageBox(error);
	}
	catch (...) {
		AfxMessageBox(_T("Ошибка!"));
	}
	CString strRes;
	strRes.Format(_T("%f"), res);
	text->SetWindowTextW(strRes);
}


void CcalculateDlg::OnBnClickedComma()
{
	isDouble = true;
	CString str, thistext;
	GetDlgItemText(IDC_STATIC, thistext);
	GetDlgItemText(IDC_COMMA, str);
	thistext += str;
	text->SetWindowTextW(thistext);
}
