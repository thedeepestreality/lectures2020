@echo off
VariadicTemplateArgs > out.txt
IF "%ERRORLEVEL%" EQU "0" (
echo Yes! 
) ELSE ( echo Fail! Error code: %ERRORLEVEL%)

rem CmdLineArgs < in.txt > out.txt

FOR /L %%i in (1,1,10) DO CmdLineArgs %%i