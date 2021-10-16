
// CalculadoraDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CCalculadoraDlg
class CCalculadoraDlg : public CDialogEx
{
// Construcción
public:
	CCalculadoraDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULADORA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_resultado;
	int m_resultado_entero;
	CString m_base;
	afx_msg void OnBnClicked0Button();
	afx_msg void OnBnClicked1Button();
	afx_msg void OnBnClicked3Button();
	afx_msg void OnBnClicked4Button();
	afx_msg void OnBnClicked5Button();
	afx_msg void OnBnClicked6Button();
	afx_msg void OnBnClicked7Button();
	afx_msg void OnBnClicked8Button();
	afx_msg void OnBnClicked9Button();
	afx_msg void OnBnClickedSumaButton();
	afx_msg void OnBnClickedRestaButton();
	afx_msg void OnBnClickedMulButton();
	afx_msg void OnBnClickedDivButton();
	afx_msg void OnBnClicked2Button();
	afx_msg void OnBnClickedIgualButton();
	afx_msg void OnBnClickedClrButton();
	int m_resultado_enterobin;
	afx_msg void OnBnClickedBaseButton();
	afx_msg void OnBnClickedBaseButton2();
	afx_msg void OnCbnSelchangeBaseCombo();
};
