@echo off

cl /DLITTLE_ENDIAN /D_CRT_SECURE_NO_DEPRECATE /c /W4 /Wall /WX /wd4820 /wd4255 /wd4668 /nologo /Zi /Od /MP *.c && lib /nologo /out:casdb.lib *.obj
