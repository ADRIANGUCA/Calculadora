
// CalculadoraDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "Calculadora.h"
#include "CalculadoraDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
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


// Cuadro de diálogo de CCalculadoraDlg



CCalculadoraDlg::CCalculadoraDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_CALCULADORA_DIALOG, pParent)
	, m_resultado(_T(""))
	, m_resultado_entero(0)
	, m_base(_T(""))
	, m_resultado_enterobin(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculadoraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULT_EDIT, m_resultado);
	DDX_Text(pDX, IDC_RESULT_STATIC, m_resultado_entero);
	DDX_CBString(pDX, IDC_BASE_COMBO, m_base);
}

BEGIN_MESSAGE_MAP(CCalculadoraDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0_BUTTON, &CCalculadoraDlg::OnBnClicked0Button)
	ON_BN_CLICKED(IDC_1_BUTTON, &CCalculadoraDlg::OnBnClicked1Button)
	ON_BN_CLICKED(IDC_3_BUTTON, &CCalculadoraDlg::OnBnClicked3Button)
	ON_BN_CLICKED(IDC_4_BUTTON, &CCalculadoraDlg::OnBnClicked4Button)
	ON_BN_CLICKED(IDC_5_BUTTON, &CCalculadoraDlg::OnBnClicked5Button)
	ON_BN_CLICKED(IDC_6_BUTTON, &CCalculadoraDlg::OnBnClicked6Button)
	ON_BN_CLICKED(IDC_7_BUTTON, &CCalculadoraDlg::OnBnClicked7Button)
	ON_BN_CLICKED(IDC_8_BUTTON, &CCalculadoraDlg::OnBnClicked8Button)
	ON_BN_CLICKED(IDC_9_BUTTON, &CCalculadoraDlg::OnBnClicked9Button)
	ON_BN_CLICKED(IDC_SUMA_BUTTON, &CCalculadoraDlg::OnBnClickedSumaButton)
	ON_BN_CLICKED(IDC_RESTA_BUTTON, &CCalculadoraDlg::OnBnClickedRestaButton)
	ON_BN_CLICKED(IDC_MUL_BUTTON, &CCalculadoraDlg::OnBnClickedMulButton)
	ON_BN_CLICKED(IDC_DIV_BUTTON, &CCalculadoraDlg::OnBnClickedDivButton)
	ON_BN_CLICKED(IDC_2_BUTTON, &CCalculadoraDlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_IGUAL_BUTTON, &CCalculadoraDlg::OnBnClickedIgualButton)
	ON_BN_CLICKED(IDC_CLR_BUTTON, &CCalculadoraDlg::OnBnClickedClrButton)
	ON_BN_CLICKED(IDC_BASE_BUTTON, &CCalculadoraDlg::OnBnClickedBaseButton)
	ON_BN_CLICKED(IDC_BASE_BUTTON2, &CCalculadoraDlg::OnBnClickedBaseButton2)
	ON_CBN_SELCHANGE(IDC_BASE_COMBO, &CCalculadoraDlg::OnCbnSelchangeBaseCombo)
END_MESSAGE_MAP()


// Controladores de mensajes de CCalculadoraDlg

BOOL CCalculadoraDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CCalculadoraDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CCalculadoraDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CCalculadoraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//declarar variables
//realizar operaciones 
int conteo = 0;	 //almacen de numero 
int op1;	 //backup
int op2;	 //entero que almacena
int codigo_de_operacion = 1;	//suma es la operacion
								//backup
int op1SUMA = op1;
int op2SUMA = op2;
int resultadoSUMA;


void CCalculadoraDlg::OnBnClicked0Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "0";
		m_resultado_entero = 0;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;
		op1 = op2;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked1Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "1";
		m_resultado_entero = 1;
		op1 = m_resultado_entero;
		
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 1;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked3Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "3";
		m_resultado_entero = 3;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 3;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked4Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "4";
		m_resultado_entero = 4;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 4;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked5Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "5";
		m_resultado_entero = 5;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 5;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked6Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "6";
		m_resultado_entero = 6;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 6;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked7Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "7";
		m_resultado_entero = 7;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 7;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked8Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "8";
		m_resultado_entero = 8;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 8;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked9Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "9";
		m_resultado_entero = 9;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 9;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedSumaButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 1;	//suma es la operacion
	//backup
	op1SUMA = op1;
	op2SUMA = op2;
	resultadoSUMA = m_resultado_entero;
	//borrador de variables
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;

	//ESCRIBIR LA OPERACION 
	CString MYCadenas;
	MYCadenas.Format(L"%d +", resultadoSUMA);
	m_resultado = MYCadenas;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedRestaButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 2;	//resta es la operacion
	//backup
	op1SUMA = op1;
	op2SUMA = op2;
	resultadoSUMA = m_resultado_entero;
	//borrador de variables
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;

	//ESCRIBIR LA OPERACION 
	CString MYCadenas;
	MYCadenas.Format(L"%d -", resultadoSUMA);
	m_resultado = MYCadenas;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedMulButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 3;	//multiplicacion es la operacion
	//backup
	op1SUMA = op1;
	op2SUMA = op2;
	resultadoSUMA = m_resultado_entero;
	//borrador de variables
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;

	//ESCRIBIR LA OPERACION 
	CString MYCadenas;
	MYCadenas.Format(L"%d X", resultadoSUMA);
	m_resultado = MYCadenas;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedDivButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 4;	//divicion es la operacion
	//backup
	op1SUMA = op1;
	op2SUMA = op2;
	resultadoSUMA = m_resultado_entero;
	//borrador de variables
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;

	//ESCRIBIR LA OPERACION 
	CString MYCadenas;
	MYCadenas.Format(L"%d /", resultadoSUMA);
	m_resultado = MYCadenas;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClicked2Button()
{
	// TODO: Agregue aquí su código de controlador de notificación de control 
	UpdateData(TRUE);
	if (conteo == 0) {
		m_resultado = "2";
		m_resultado_entero = 2;
		op1 = m_resultado_entero;
	}
	else {
		op2 = m_resultado_entero * 10;//convercion de decena
		op1 = op2 + 2;
		m_resultado_entero = op1;
		//imprimir resultado
		CString MyCadena;
		MyCadena.Format(L"%d", op1);
		m_resultado = MyCadena;
	}
	conteo++;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedIgualButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	switch (codigo_de_operacion)
	{
	case 1:
		m_resultado_entero = resultadoSUMA + op1;
		break;
	case 2:
		m_resultado_entero = resultadoSUMA - op1;
		break;
	case 3:
		m_resultado_entero = resultadoSUMA * op1;
		break;
	case 4:
		m_resultado_entero = resultadoSUMA / op1;
		break;
	case 5:
		m_resultado_entero = resultadoSUMA;
		break;
	case 6:
		m_resultado_entero = resultadoSUMA;
		break;
	default:
		break;
	}
	//imprimir resultado
	CString MYCadenas;
	MYCadenas.Format(L"%d ", m_resultado_entero);
	m_resultado = MYCadenas;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedClrButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;
	resultadoSUMA = 0;
	CString MYCadenas;
	MYCadenas.Format(L"%d ", m_resultado_entero);
	m_resultado = MYCadenas;
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnBnClickedBaseButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 5;	//hexadecimal es la operacion
//backup
	op1SUMA = op1;
	op2SUMA = op2;
	resultadoSUMA = m_resultado_entero;
	//borrador de variables
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;

	//ESCRIBIR LA OPERACION 
	CString MYCadenas;
	MYCadenas.Format(L"%x ", resultadoSUMA);
	m_resultado = MYCadenas;
	UpdateData(FALSE);

}


void CCalculadoraDlg::OnBnClickedBaseButton2()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	codigo_de_operacion = 6;	//binario es la operacion
//backup
	op1SUMA = op1;
	op2SUMA = op2;
	resultadoSUMA = m_resultado_entero;
	//borrador de variables
	conteo = 0;
	op1 = 0;
	op2 = 0;
	m_resultado_entero = 0;

	//ESCRIBIR LA OPERACION

	int a[10], n, i;

	/// "actualizamos el numero a convertir ";
	UpdateData(TRUE);
	n =m_resultado_entero;
	for (i = 0; n > 0; i++)
	{
		n = n / 2;
		a[i] = n % 2;
		n = n / 2;
		a[i] = n % 2; 
		
	}
	//limpiar cadena y generar ciclo para presentar dato convertido";
	m_resultado = "";
	UpdateData(FALSE);
	for (i = i - 1; i >= 0; i--)
	{
		resultadoSUMA = a[i], a[i];
		CString MyCadenas;
		MyCadenas.Format(L"%d", resultadoSUMA);
		m_resultado = MyCadenas;
	}
	UpdateData(FALSE);
}


void CCalculadoraDlg::OnCbnSelchangeBaseCombo()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
}
