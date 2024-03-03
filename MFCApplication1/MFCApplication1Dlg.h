
// MFCApplication1Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация

protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnChangeNumber1();
	//afx_msg void OnChangeNumber2();
	//afx_msg void OnUpdateNumber1();
	afx_msg void OnBnClickedButton1();
	int NUMBER1;
	int NUMBER2;
	int RESS;
	enum {MULT, SUM, DIV, MIN};
	int operation;
	afx_msg void OnChangeNumber2();
};
