rem signtool sign /f D:\Workspace\projects\sdk\DeviceSDK_Windows_VS2019\libxiaoweisdk\cs_test_basic\sign\csp.pfx /p 111111 D:\Workspace\projects\sdk\DeviceSDK_Windows_VS2019\libxiaoweisdk\cs_test_basic\x64\Release\libxiaoweisdk\libxiaoweisdk.dll

rem signtool sign /f D:\Workspace\projects\sdk\DeviceSDK_Windows_VS2019\libxiaoweisdk\cs_test_basic\sign\csp.pfx /p 111111 D:\Workspace\projects\sdk\DeviceSDK_Windows_VS2019\libxiaoweisdk\cs_test_basic\x64\Release\sdkrt\sdkrt.dll

set SOURCE=D:\Workspace\projects\sdk\DeviceSDK_Windows_VS2019\libxiaoweisdk\cs_test_basic\x64\Debug\libxiaoweisdk
set DEST=D:\Workspace\projects\libxiaoweisdk_git\XiaoweiSDK\Debug64
copy %SOURCE%\libxiaoweisdk.pdb %DEST%\libxiaoweisdk.pdb /y
copy %SOURCE%\libxiaoweisdk.lib %DEST%\libxiaoweisdk.lib /y
copy %SOURCE%\libxiaoweisdk.dll %DEST%\libxiaoweisdk.dll /y
copy %SOURCE%\libxiaoweisdk.winmd %DEST%\libxiaoweisdk.winmd /y

set SOURCE=D:\Workspace\projects\sdk\DeviceSDK_Windows_VS2019\libxiaoweisdk\cs_test_basic\x64\Release\libxiaoweisdk
set DEST=D:\Workspace\projects\libxiaoweisdk_git\XiaoweiSDK\Release64
copy %SOURCE%\libxiaoweisdk.pdb %DEST%\libxiaoweisdk.pdb /y
copy %SOURCE%\libxiaoweisdk.lib %DEST%\libxiaoweisdk.lib /y
copy %SOURCE%\libxiaoweisdk.dll %DEST%\libxiaoweisdk.dll /y
copy %SOURCE%\libxiaoweisdk.winmd %DEST%\libxiaoweisdk.winmd /y
