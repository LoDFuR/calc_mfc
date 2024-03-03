
// MFCApplication1Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString str1, str2;
// Диалоговое окно CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, NUMBER1(0)
	, NUMBER2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUMBER1, NUMBER1);
	DDV_MinMaxInt(pDX, NUMBER1, -100, 100);
	DDX_Text(pDX, IDC_NUMBER2, NUMBER2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication1Dlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_NUMBER1, &CMFCApplication1Dlg::OnChangeNumber1)
	//ON_EN_UPDATE(IDC_NUMBER1, &CMFCApplication1Dlg::OnUpdateNumber1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_NUMBER2, &CMFCApplication1Dlg::OnChangeNumber2)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: добавьте свой код обработчика уведомлений
	// Получение выбранных данных из ComboBox
	CComboBox* pMyComboBox = (CComboBox*)GetDlgItem(IDC_COMBO1); // Получение указателя на комбо-бокс
	int selectedIndex = pMyComboBox->GetCurSel(); // Получение индекса выбранного элемента
	if (selectedIndex != CB_ERR) // Проверка, что элемент выбран
	{
		CString selectedText;
		pMyComboBox->GetLBText(selectedIndex, selectedText); // Получение текста выбранного элемента
		// Далее вы можете использовать значение переменной selectedText
	}
	switch (selectedIndex) {
	case 0: operation = DIV;
		break;
	case 1: operation = MIN;
		break;
	case 2: operation = MULT;
		break;
	case 3: operation = SUM;
		break;
	default:
		operation = DIV;
	}
}


void CMFCApplication1Dlg::OnChangeNumber1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
	/*CString strText;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_NUMBER1); // IDCEDIT1 - ID вашего Edit Control
	pEdit->GetWindowText(strText);
	str1 = strText;
	std::ofstream file("output.txt");
	if (file.is_open()) {
		file << strText;
		file.close();
	} */
	CString str;
	GetDlgItemText(IDC_NUMBER1, str);
	int value = _ttoi(str);
	NUMBER1 = value;

}

void CMFCApplication1Dlg::OnBnClickedButton1()
{

	// TODO: добавьте свой код обработчика уведомлений
	//CString str;
	//str.Append(str1);
	//str.Append(s);
	//str.Append(str2);
	//str.Append(eq);
	CString str;
	//a = atoi(str1);
	//b = atoi(str2);
	//str = (str1 + "+" str2 + "=");
	//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT2); // IDC_EDIT1 - ID вашего Edit Control
	//pEdit->SetWindowText(str);
	int result;
	if (operation == MULT)
	{
		RESS = NUMBER1 * NUMBER2;
		
	}
	else
		if (operation == SUM)
		{
			RESS = NUMBER1 + NUMBER2;

		}
		else
			if (operation == MIN) {
				RESS = NUMBER1 - NUMBER2;
			}
			else
			{
				//RESS = NUMBER1 - NUMBER2;
				RESS = NUMBER1 / NUMBER2;
			}
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
		CEdit* ppEdit = (CEdit*)GetDlgItem(IDC_STATIC);
		CString res;
		res.Format(_T("%d"), RESS);
		pEdit->SetWindowText(res);
		ppEdit->SetWindowText(res);

	//IDC_EDIT2
}


void CMFCApplication1Dlg::OnChangeNumber2()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
	CString str;
	GetDlgItemText(IDC_NUMBER2, str);
	int value = _ttoi(str);
	NUMBER2 = value;
}
