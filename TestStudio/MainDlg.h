#pragma once

#include "atl.h"
#include "atlctrls.h"
#include "atlmisc.h"
#include "atlcrack.h"
#include "resource.h"

#include <thread>

#include "airplay.h"

class CMainDlg : public CDialogImpl<CMainDlg>, public CMessageFilter
{
public:
    enum { IDD = IDD_MAINDIALOG };

    CMainDlg()
    {
    }

    virtual BOOL PreTranslateMessage(MSG* pMsg)
    {
        return ::IsDialogMessage(m_hWnd, pMsg);
    }

    BEGIN_MSG_MAP(CMainDlg)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_RANGE_HANDLER(IDOK, IDNO, OnCloseCmd)
        COMMAND_ID_HANDLER(IDC_AIRPLAY_START, OnClickAirPlayStart)
        COMMAND_ID_HANDLER(IDC_AIRPLAY_STOP, OnClickAirPlayStop)
        //COMMAND_ID_HANDLER(IDC_TOLINE, OnClickToLine)
        //COMMAND_ID_HANDLER(IDC_TOLIST, OnClickToList)
        //COMMAND_ID_HANDLER(IDC_TOBASE64, OnClickToBase64)
        //COMMAND_ID_HANDLER(IDC_FROMBASE64, OnClickFromBase64)
        //COMMAND_ID_HANDLER(IDC_OPENFILE, OnClickOpenFile)
        //COMMAND_ID_HANDLER(IDC_RANDOM100, OnClickRandom100)
    END_MSG_MAP()

    LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
    {
        CenterWindow(GetParent());

        m_serviceList = GetDlgItem(IDC_SERVICE_LIST);
        //m_base = GetDlgItem(IDC_BASEEDIT);

        //DBuffer buf(100);
        //buf.FillWithRandom();
        //std::string hexList = buf.ToHexList();
        //m_serviceList.SetWindowText(DXP::s2ws(hexList).c_str());
        return TRUE;
    }

    LRESULT OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    {
        ::EndDialog(m_hWnd, wID);
        m_hWnd = NULL;
        PostQuitMessage(0);
        return 0;
    }


    LRESULT OnClickAirPlayStart(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    {
        HHAirPlayStart("WL_AirPlay");

        //CString msg;
        //msg.Format(L"DNSServiceDiscovery returned %d\n", error);
        //MessageBox(msg, L"Tips", MB_OK);
        return 0;
    }

    LRESULT OnClickAirPlayStop(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    {
        HHAirPlayStop();

        //m_serviceList.SetWindowText(DXP::s2ws(hexList).c_str());
        return 0;
    }

    //LRESULT OnClickToLine(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    //{
    //    CString str;
    //    m_hex.GetWindowText(str);
    //    std::string strA = DXP::ws2s(std::wstring(str));
    //    DUInt32 reason = 0;
    //    DBool bOK = DBuffer::IsValidHexStr(strA.c_str(), &reason);
    //    if (!bOK)
    //    {
    //        CString err;
    //        err.Format(L"Not HEX, reason=%s", err_reason[reason]);
    //        MessageBox(err, L"Tips", MB_ICONERROR);
    //        return 0;
    //    }
    //    DBuffer buf;
    //    buf.InitWithHexString(strA);
    //    std::string strHA = buf.ToHexString();
    //    m_hex.SetWindowText(DXP::s2ws(strHA).c_str());
    //    return 0;
    //}

    //LRESULT OnClickToList(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    //{
    //    CString str;
    //    m_hex.GetWindowText(str);
    //    std::string strA = DXP::ws2s(std::wstring(str));
    //    DUInt32 reason = 0;
    //    DBool bOK = DBuffer::IsValidHexStr(strA.c_str(), &reason);
    //    if (!bOK)
    //    {
    //        CString err;
    //        err.Format(L"Not HEX, reason=%s", err_reason[reason]);
    //        MessageBox(err, L"Tips", MB_ICONERROR);
    //        return 0;
    //    }
    //    DBuffer buf;
    //    buf.InitWithHexString(strA);
    //    std::string strHA = buf.ToHexList();
    //    m_hex.SetWindowText(DXP::s2ws(strHA).c_str());
    //    return 0;
    //}

    //LRESULT OnClickToBase64(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    //{
    //    CString str;
    //    m_hex.GetWindowText(str);
    //    std::string strA = DXP::ws2s(std::wstring(str));
    //    DUInt32 reason = 0;
    //    DBool bOK = DBuffer::IsValidHexStr(strA.c_str(), &reason);
    //    if (!bOK)
    //    {
    //        CString err;
    //        err.Format(L"Not HEX, reason=%s", err_reason[reason]);
    //        MessageBox(err, L"Tips", MB_ICONERROR);
    //        return 0;
    //    }
    //    DBuffer buf;
    //    buf.InitWithHexString(strA);
    //    std::string strBA = buf.ToBase64String();
    //    m_base.SetWindowText(DXP::s2ws(strBA).c_str());
    //    return 0;
    //}

    //LRESULT OnClickFromBase64(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    //{
    //    CString str;
    //    m_base.GetWindowText(str);
    //    DBuffer buf;
    //    std::string strA = DXP::ws2s(std::wstring(str));
    //    buf.InitWithBase64String(strA);
    //    std::string strAList = buf.ToHexList();
    //    m_hex.SetWindowText(DXP::s2ws(strAList).c_str());
    //    return 0;
    //}

    //LRESULT OnClickOpenFile(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    //{
    //    CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"All Files\0*.*\0", m_hWnd);
    //    if (dlg.DoModal() == IDOK)
    //    {
    //        DFile file;
    //        file.OpenFileRead(DXP::ws2s(dlg.m_szFileName).c_str());
    //        DUInt32 readsize = 100 * 1024;  // Max 100KB 
    //        if (file.GetSize() < readsize) readsize = (DUInt32)file.GetSize();
    //        DBuffer buf = file.Read(readsize);
    //        std::string hexList = buf.ToHexList();
    //        m_hex.SetWindowText(DXP::s2ws(hexList).c_str());
    //    }
    //    return 0;
    //}

    //LRESULT OnClickRandom100(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
    //{
    //    DBuffer buf(100);
    //    buf.FillWithRandom();
    //    std::string hexList = buf.ToHexList();
    //    m_hex.SetWindowText(DXP::s2ws(hexList).c_str());
    //    return 0;
    //}

    CEdit m_serviceList;
    //CEdit m_base;

    //CButton m_tobase64;
    //CButton m_frombase64;
    //CButton m_ishex;
    //CButton m_toline;
    //CButton m_tolist;
    //CButton m_isbase64;
    LRESULT OnEnChangeBaseedit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
    LRESULT OnEnChangeHexedit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};