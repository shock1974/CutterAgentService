; Script generated by the HM NIS Edit Script Wizard.
!include nsDialogs.nsh
; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "CutterAgent"
!define PRODUCT_VERSION "2.12(rel:20141210)"
!define PRODUCT_PUBLISHER "上海和鹰机电科技股份有限公司"
!define PRODUCT_WEB_SITE "http://www.yingroup.com"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\CutterAgent.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"
!define PRODUCT_HOME_KEY "Software\Yingroup\CutterAgent"

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "app.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; Language Selection Dialog Settings
!define MUI_LANGDLL_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_LANGDLL_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_LANGDLL_REGISTRY_VALUENAME "NSIS:Language"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE "License.txt"

Var Dialog
Var Label
Var Label2
Var assetid
Var cutterControlpath
Var browsePath
Var browseBtn
Var findPath


Page custom nsDialogsPage nsDialogsPageLeave

; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\CutterAgent.exe"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Japanese"
!insertmacro MUI_LANGUAGE "SimpChinese"

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "Setup.exe"
InstallDir "$PROGRAMFILES\Yingroup\CutterAgent"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

;RequestExecutionLevel admin ;Require admin rights on NT6+ (When UAC is turned on)

!include LogicLib.nsh
;!include AccecssControl.nsh

Function .onInit
  !insertmacro MUI_LANGDLL_DISPLAY
UserInfo::GetAccountType
pop $0
${If} $0 != "admin" ;Require admin rights on NT4+
        MessageBox mb_iconstop "请以管理员身份运行安装程序!Administrator rights required!"
        SetErrorLevel 740 ;ERROR_ELEVATION_REQUIRED
        Quit
${EndIf}
FunctionEnd

Function nsDialogsPage

	nsDialogs::Create 1018
	Pop $Dialog

	${If} $Dialog == error
		Abort
	${EndIf}

	ReadRegStr $0 HKLM "${PRODUCT_HOME_KEY}" "assetid"
	ReadRegStr $1 HKLM "${PRODUCT_HOME_KEY}" "cuttercontrolpath"

	${NSD_CreateLabel} 0 0 100% 12u "本裁剪机的资产标识"
	Pop $Label

	${NSD_CreateText} 0 13u 100% 12u "XXXXX-XXXXXX"
	Pop $assetid
	
	${NSD_CreateLabel} 0 30u 100% 12u "CutterControl软件路径"
	Pop $Label2
	
	${NSD_CreateDirRequest} 0 47u 90% 12u ""
	Pop $cutterControlpath

	${NSD_CreateBrowseButton} 90% 47u 10% 12u "浏览"
	Pop $browseBtn
	 ${NSD_OnClick} $browseBtn _GetPath
	 

	${NSD_SetText} $assetid $0
	${NSD_SetText} $cutterControlpath $1
	
         Pop $browsepath

        nsDialogs::Show
FunctionEnd

Function _GetPath
;nsDialogs::SelectFileDialog open initial_selection filter
nsDialogs::SelectFolderDialog title initial_selection
pop $findPath
;MessageBox MB_OK|MB_ICONINFORMATION "$findPath"
${NSD_SetText} $cutterControlpath $findPath
Functionend

Function nsDialogsPageLeave

	${NSD_GetText} $assetid $0
	${NSD_GetText} $cutterControlpath $1
	
        StrCmp $0 "" Assetid_error 0
        StrCmp $1 "" path_error 0

	MessageBox MB_YESNO "请确认是否正确:$\n资产编号：$\n$\t$0$\nCutterControl路径：$\n$\t$1" IDYES true IDNO false
Assetid_error:
              MessageBox MB_OK|MB_ICONSTOP "请输入资产编号"
              Abort
path_error:
           MessageBox MB_OK|MB_ICONSTOP "请输入CutterControl路径"

           abort
false:
        Abort
true:
        WriteRegStr HKLM "${PRODUCT_HOME_KEY}" "version" "${PRODUCT_VERSION}"
        WriteRegStr HKLM "${PRODUCT_HOME_KEY}" "assetid" "$0"
        WriteRegStr HKLM "${PRODUCT_HOME_KEY}" "cuttercontrolpath" "$1"
        WriteRegStr HKLM "${PRODUCT_HOME_KEY}" "server" "http://e-service.yingroup.com:808/DeviceManager"
        WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Run" "CutterAgent" "$INSTDIR\CutterAgent.exe"

FunctionEnd


Section "MainSection" SEC01
  SetOutPath "$INSTDIR"

  ExecWait 'taskkill /F /IM CutterAgent.exe'
  SetOverwrite on
  
  File "CutterAgent.exe"
  CreateDirectory "$SMPROGRAMS\Yingroup\CutterAgent"
  CreateShortCut "$SMPROGRAMS\Yingroup\CutterAgent\CutterAgent.lnk" "$INSTDIR\CutterAgent.exe"
  CreateShortCut "$DESKTOP\CutterAgent.lnk" "$INSTDIR\CutterAgent.exe"
  SetOverwrite ifnewer
  File "QtCore4.dll"
  File "mingwm10.dll"
  File "libqjson.dll"
  File "libgcc_s_dw2-1.dll"
  File "app.ico"
  File "QtGui4.dll"
  File "QtNetwork4.dll"
;add administrator previlege
;    ExecWait 'bcdedit /import "$INSTDIR\CutterAgent.exe"'
SectionEnd

Section -AdditionalIcons
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\Yingroup\CutterAgent\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\Yingroup\CutterAgent\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\CutterAgent.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\CutterAgent.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name) 已成功地从你的计算机移除。"
FunctionEnd

Function un.onInit
!insertmacro MUI_UNGETLANGUAGE
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "你确实要完全移除 $(^Name) ，其及所有的组件？" IDYES +2
  Abort
  ExecWait 'taskkill /F /IM CutterAgent.exe'
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\QtGui4.dll"
  Delete "$INSTDIR\app.ico"
  Delete "$INSTDIR\libgcc_s_dw2-1.dll"
  Delete "$INSTDIR\libqjson.dll"
  Delete "$INSTDIR\mingwm10.dll"
  Delete "$INSTDIR\QtCore4.dll"
  Delete "$INSTDIR\CutterAgent.exe"

  Delete "$INSTDIR\QtNetwork4.dll"

  Delete "$SMPROGRAMS\Yingroup\CutterAgent\Uninstall.lnk"
  Delete "$SMPROGRAMS\Yingroup\CutterAgent\Website.lnk"
  Delete "$DESKTOP\CutterAgent.lnk"
  Delete "$SMPROGRAMS\Yingroup\CutterAgent\CutterAgent.lnk"

  RMDir "$SMPROGRAMS\Yingroup\CutterAgent"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd