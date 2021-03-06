/////////////////////////////////////////////////////////////////////////////
//    License (GPLv2+):
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful, but
//    WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
/////////////////////////////////////////////////////////////////////////////
/**
 * @file  WMGotoDlg.cpp
 *
 * @brief Implementation of the WMGotoDlg dialog.
 */

#include "stdafx.h"
#include "WMGotoDlg.h"
#include "TrDialogs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/**
 * @brief Class for Goto-dialog.
 * This dialog allows user to go to certain line or or difference in the file
 * compare. As there are two panels with different line numbers, there is a
 * choice for target panel. When dialog is opened, its values are initialized
 * for active file's line number.
 */
class WMGotoDlg::Impl : public CTrDialog
{
// Construction
public:
	Impl(WMGotoDlg *p, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(WMGotoDlg)
	enum { IDD = IDD_WMGOTO };
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WMGotoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(WMGotoDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	WMGotoDlg *m_p;
};

/////////////////////////////////////////////////////////////////////////////
// CGotoDlg dialog

/**
 * @brief Constructor.
 */
WMGotoDlg::Impl::Impl(WMGotoDlg *p, CWnd* pParent /*=NULL*/)
	: CTrDialog(WMGotoDlg::Impl::IDD, pParent), m_p(p)
{
}

void WMGotoDlg::Impl::DoDataExchange(CDataExchange* pDX)
{
	CTrDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(WMGotoDlg)
	DDX_Text(pDX, IDC_WMGOTO_PARAM, m_p->m_strParam);
	DDX_Radio(pDX, IDC_WMGOTO_FILELEFT, m_p->m_nFile);
	DDX_Radio(pDX, IDC_WMGOTO_TOLINE, m_p->m_nGotoWhat);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(WMGotoDlg::Impl, CTrDialog)
	//{{AFX_MSG_MAP(WMGotoDlg::Impl)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WMGotoDlg message handlers



WMGotoDlg::WMGotoDlg()
	: m_pimpl(new WMGotoDlg::Impl(this)), m_nFile(-1), m_nGotoWhat(-1) {}
WMGotoDlg::~WMGotoDlg() {}
int WMGotoDlg::DoModal() { return static_cast<int>(m_pimpl->DoModal()); }

