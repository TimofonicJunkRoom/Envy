//
// RichFragment.h
//
// This file is part of Envy (getenvy.com) � 2016
// Portions copyright PeerProject 2008-2014 and Shareaza 2002-2007
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

class CRichElement;
class CRichViewCtrl;


class CRichFragment
{
public:
	CRichFragment(CRichElement* pElement, int nOffset, int nLength, CPoint* pPoint, CSize* pSize);
	CRichFragment(CRichElement* pElement, CPoint* pPoint);
	virtual ~CRichFragment();

public:
	CRichElement*	m_pElement;
	CPoint			m_pt;
	CSize			m_sz;
	WORD			m_nOffset;
	WORD			m_nLength;

public:
	void	Add(int nLength, CSize* pSize);
	void	Paint(CDC* pDC, CRichViewCtrl* pCtrl, int nFragment);
};
