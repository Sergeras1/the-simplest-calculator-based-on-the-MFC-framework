
// calculateDlg.h: файл заголовка
//

#pragma once

#include <optional>

// Диалоговое окно CcalculateDlg
class CcalculateDlg : public CDialogEx
{
// Создание
public:
	CcalculateDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic* text;
	std::optional<int> first, second;
	std::optional<double> doubleF, doubleS;
	std::optional<char> oper;
	bool flag = true;
	bool isDouble = false;

	void addNum(int id);
	void addOper(int id);

	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedCe();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMult();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedPc();
	afx_msg void OnBnClickedEq();
	afx_msg void OnBnClickedComma();
};
