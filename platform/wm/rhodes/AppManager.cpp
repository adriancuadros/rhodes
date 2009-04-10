#include "stdafx.h"

#include "AppManager.h"
#include "NetRequest.h"

#ifdef ENABLE_DYNAMIC_RHOBUNDLE

#include "HttpServer.h"

#include "unzip.h"
#include "rhoruby/rhoruby.h"

extern "C" wchar_t* wce_mbtowc(const char* a);

CAppManager::CAppManager(void)
{
}

CAppManager::~CAppManager(void)
{
}

bool CAppManager::RemoveFolder(LPCTSTR szPath) {

	if (szPath) {
		SHFILEOPSTRUCT fop;
		
		fop.hwnd = NULL;
		fop.wFunc = FO_DELETE;		
		fop.pFrom = szPath;
		fop.pTo = NULL;
		fop.fFlags = FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR;
		
		int result = SHFileOperation(&fop);
		return result == 0;
	}
	return false;
}

void CAppManager::ReloadRhoBundle(const char* szUrl, const char* szZipPassword)
{
	if ( szUrl )
	{
		//get zip file with rhodes
		DWORD dwDataSize = 0;
		CNetRequest request;
		char* zipData = request.doRequest( L"GET",const_cast<char*>(szUrl),NULL,0,NULL,0,false,true,false,&dwDataSize);

		//TODO: Add error handling
		if ( zipData && dwDataSize > 0 )
		{
			LPWSTR rootw = wce_mbtowc(RhoGetRootPath());

			bool ret = false;
			if (wcslen(rootw)<MAX_PATH) {
				TCHAR name[MAX_PATH+2];
				wsprintf(name,L"%sapps%c",rootw,'\0');
				if( RemoveFolder(name) ) {
					wsprintf(name,L"%slib%c",rootw,'\0');
					ret = RemoveFolder(name);
				}
			}

			if( ret ) {
				ZIPENTRY ze; 
				// Open zip file
				HZIP hz = OpenZip(zipData, dwDataSize, szZipPassword);
			
				if ( hz ) {
					//Stop HTTP Server
					CHttpServer::Instance()->FreezeThread();

					// Set base for unziping
					SetUnzipBaseDir(hz, rootw);
				
					// Get info about the zip
					// -1 gives overall information about the zipfile
					GetZipItem(hz,-1,&ze);
					int numitems = ze.index;
				
					// Iterate through items and unzip them
					for (int zi = 0; zi<numitems; zi++)
					{ 
						// fetch individual details, e.g. the item's name.
						GetZipItem(hz,zi,&ze); 
						// unzip item
						UnzipItem(hz, zi, ze.name);         
					}
				
					CloseZip(hz);

					//Show MessageBox
					MessageBox(NULL, _T("Rhobundle has been updated successfully.\n\nPlease restart application."), _T("Information"), MB_OK | MB_ICONINFORMATION );
				} else {
					MessageBox(NULL, _T("Can't unzip loaded rhobundle."), _T("Stop"), MB_OK | MB_ICONSTOP );
				}
			} else {
				MessageBox(NULL, _T("Can't remove old version of rhobundle. However, it may be corrupted. Exit application and reinstall rhobundle manualy."), _T("Stop"), MB_OK | MB_ICONSTOP );
			}

			if ( rootw )
				free(rootw);

		} else {
			MessageBox(NULL, _T("Error loading rhobundle."), _T("Stop"), MB_OK | MB_ICONSTOP );
		}

		if ( zipData )
			free( zipData );
	}

}

#endif