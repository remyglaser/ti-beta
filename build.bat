@REM @ECHO OFF
@REM cls
@REM IF NOT EXIST beta.asm GOTO FILE_ERROR

@REM copy beta.asm ..\..
@REM copy scroll.asm ..\..

@REM IF EXIST %1.asm GOTO LANGUAGE
@REM echo assuming english language
@REM copy en.asm ..\..\language.asm
@REM goto CONTINUE
@REM :LANGUAGE
@REM copy %1.asm ..\..\language.asm

@REM :CONTINUE
@REM cd ..\..
@REM Tasm32 -t80 -b -i -q beta.asm beta.bin
@REM if errorlevel 1 goto ASM_ERROR
@REM Linker -o -bin -squish -protect beta.bin ZBETA.8xp ZBETA 83p
@REM if errorlevel 1 goto LINK_ERROR

@REM del beta.asm
@REM del scroll.asm
@REM del beta.bin

@REM cd beta3\8xp

@REM copy ..\..\ZBETA.8xp
@REM del ..\..\ZBETA.8xp

@REM Echo assembly was succesfull!
@REM goto END

@REM :FILE_ERROR
@REM Echo Error: The beta source code could not be found
@REM goto END

@REM :ASM_ERROR
@REM cd beta3\8xp
@REM Echo Error: The assembly failed
@REM goto END

@REM :LINK_ERROR
@REM cd beta3\8xp
@REM Echo Error: Binary link failed

@REM :END
