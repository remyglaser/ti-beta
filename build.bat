@ECHO OFF
cls
IF NOT EXIST beta.asm GOTO FILE_ERROR

copy beta.asm ..\..
copy scroll.asm ..\..

IF EXIST %1.asm GOTO LANGUAGE
echo assuming english language
copy en.asm ..\..\language.asm
goto CONTINUE
:LANGUAGE
copy %1.asm ..\..\language.asm

:CONTINUE
cd ..\..
Tasm32 -t80 -b -i -q beta.asm beta.bin
if errorlevel 1 goto ASM_ERROR
Linker -o -bin -squish -protect beta.bin ZBETA.8xp ZBETA 83p
if errorlevel 1 goto LINK_ERROR

del beta.asm
del scroll.asm
del beta.bin

cd beta3\8xp

copy ..\..\ZBETA.8xp
del ..\..\ZBETA.8xp

Echo assembly was succesfull!
goto END

:FILE_ERROR
Echo Error: The beta source code could not be found
goto END

:ASM_ERROR
cd beta3\8xp
Echo Error: The assembly failed
goto END

:LINK_ERROR
cd beta3\8xp
Echo Error: Binary link failed

:END