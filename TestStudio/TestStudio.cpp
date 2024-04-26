#include "atl.h"
#include "maindlg.h"

#include <stdio.h>            // For stdout, stderr
#include <string.h>            // For strlen(), strcpy(  ), bzero(  )
#include <errno.h>            // For errno, EINTR
#include <time.h>


#ifdef _WIN32
#include <process.h>
typedef    int    pid_t;
#define    getpid    _getpid
#define    strcasecmp    _stricmp
#define snprintf _snprintf
#else
#include <sys/time.h>        // For struct timeval
#include <unistd.h>            // For getopt(  ) and optind
#include <arpa/inet.h>        // For inet_addr(  )
#endif

CAppModule _Module;

int Run(LPTSTR /*lpCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
    CMessageLoop theLoop;
    _Module.AddMessageLoop(&theLoop);

    CMainDlg dlgMain;

    if (dlgMain.Create(NULL) == NULL)
    {
        ATLTRACE(_T("Main dialog creation failed!\n"));
        return 0;
    }

    dlgMain.ShowWindow(nCmdShow);

    int nRet = theLoop.Run();

    _Module.RemoveMessageLoop();
    return nRet;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nCmdShow)
{
    ::InitCommonControls();

    _Module.Init(NULL, hInstance);

    int nRet = Run(lpCmdLine, nCmdShow);

    _Module.Term();

    return nRet;
}
