//
// DlgDownloadGroup.h
//
// This file is part of Envy (getenvy.com) � 2016
// Portions copyright PeerProject 2008-2010 and Shareaza 2002-2008
//
// Envy is free software. You may redistribute and/or modify it
// under the terms of the GNU Affero General Public License
// as published by the Free Software Foundation (fsf.org);
// version 3 or later at your option. (AGPLv3)
//
// Envy is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Affero General Public License 3.0 for details:
// (http://www.gnu.org/licenses/agpl.html)
//

#pragma once

#include "DlgSkinDialog.h"
#include "CtrlIconButton.h"
#include "CtrlSchemaCombo.h"

class CDownloadGroup;


class CDownloadGroupDlg : public CSkinDialog
{
public:
	CDownloadGroupDlg(CDownloadGroup* pGroup, CWnd* pParent = NULL);

	enum { IDD = IDD_DOWNLOAD_GROUP };

protected:
	CIconButtonCtrl	m_wndBrowse;
	CIconButtonCtrl	m_wndCancel;
	CSchemaCombo	m_wndSchemas;
	CEdit			m_wndFolder;
	CButton			m_wndFilterAdd;
	CButton			m_wndFilterRemove;
	CComboBox		m_wndFilterList;
	CString			m_sName;
	CString			m_sFolder;
	BOOL			m_bTorrent;
	CDownloadGroup*	m_pGroup;
	CString			m_sOldSchemaURI;

	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	afx_msg void OnFilterAdd();
	afx_msg void OnFilterRemove();
	afx_msg void OnEditChangeFilterList();
	afx_msg void OnSelChangeFilterList();
	afx_msg void OnBrowse();
	afx_msg void OnCbnCloseupSchemas();
	afx_msg void OnBnClickedDownloadDefault();

	DECLARE_MESSAGE_MAP()
};
