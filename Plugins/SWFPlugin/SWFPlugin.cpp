//
// SWFPlugin.cpp : Implementation of DLL Exports.
//
// This file is part of Envy (getenvy.com) � 2016
// Portions copyright PeerProject 2008-2014 and Nikolay Raspopov 2005
//
// Envy is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation (fsf.org);
// either version 3 of the License, or later version (at your option).
//
// Envy is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
// (http://www.gnu.org/licenses/gpl.html)
//

#include "StdAfx.h"
#include "Resource.h"
#include "SWFPlugin.h"	// Generated

class CSWFPluginModule : public CAtlDllModuleT< CSWFPluginModule >
{
public :
	CSWFPluginModule()
	{
		InitializeCriticalSection(&_CS);
	}
	virtual ~CSWFPluginModule()
	{
		DeleteCriticalSection(&_CS);
	}
	DECLARE_LIBID(LIBID_SWFPluginLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SWFPLUGIN, "{6BC193A0-817A-4E64-BDB2-F7193DE36342}")
};

CSWFPluginModule	_AtlModule;
MY_DATA*			_Data = NULL;
CRITICAL_SECTION	_CS;

extern "C" BOOL WINAPI DllMain(HINSTANCE /*hInstance*/, DWORD dwReason, LPVOID lpReserved)
{
	return _AtlModule.DllMain( dwReason, lpReserved );
}

STDAPI DllCanUnloadNow(void)
{
	return _AtlModule.DllCanUnloadNow();
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return _AtlModule.DllGetClassObject( rclsid, riid, ppv );
}

STDAPI DllRegisterServer(void)
{
	return _AtlModule.DllRegisterServer();
}

STDAPI DllUnregisterServer(void)
{
	return _AtlModule.DllUnregisterServer();
}

STDAPI DllInstall(BOOL bInstall, LPCWSTR pszCmdLine)
{
	static const wchar_t szUserSwitch[] = L"user";

	if ( pszCmdLine && _wcsnicmp( pszCmdLine, szUserSwitch, _countof(szUserSwitch) ) == 0 )
		AtlSetPerUserRegistration( true );	// VS2008+

	HRESULT hr = bInstall ?
		DllRegisterServer() :
		DllUnregisterServer();
	if ( bInstall && FAILED( hr ) )
		DllUnregisterServer();

	return hr;
}
