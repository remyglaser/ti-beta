; Copyright (C) 2006  Remy Glaser
; 
; This program is free software; you can redistribute it and/or
; modify it under the terms of the GNU General Public License
; as published by the Free Software Foundation; either version 2
; of the License, or (at your option) any later version.
; 
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
; LICENSE.html for more details.
; 

.Nolist
#define equ .equ
#define EQU .equ
#define end .end
#define END .end

#IFDEF TI83P
#include "include/TI83P/ti83plus.inc"
#ELSE
#include "include/TI83/ti83asm.inc"
#ENDIF

#DEFINE use_file.open
#DEFINE use_file.skip
#DEFINE use_file.readByte

#define Square(aa,bb,cc,dd)	ld bc,aa*256+bb	\ ld de,cc*256+dd	\ call SQUARE

; Beta XP text format tags:

;tag_		equ	$00
tag_Return	equ	$D6	; D6
;tag_		equ	$ED
;tag_		equ	$EE
;tag_		equ	$EF
;tag_		equ	$F0
;tag_		equ	$F1
;tag_		equ	$F2
;tag_		equ	$F3
;tag_		equ	$F4
;tag_		equ	$F5
;tag_		equ	$F6
tag_Author	equ	$F7	; F7 [text] F7
tag_Title	equ	$F8	; F8 [text] F8
tag_Square	equ	$F9	; F9 [x1] [y1] [x2] [y2] [op]
tag_Line	equ	$FA	; FA [x1] [y1] [x2] [y2] [op]
tag_Picture	equ	$FB	; FB [x] [y] [width] [height] [pic] [length H] [length L]
tag_FreeText	equ	$FC	; FC [x] [y] [text] FC
tag_Invert	equ	$FD	; FD [text] FD
tag_Tab		equ	$FE	; FE
tag_Page_End	equ	$FF	; FF

; Flags:
SelectFlags	EQU	asm_flag1
;XWiskunde	EQU	7
;XNatuurkunde	EQU	6
;XScheikunde	EQU	5
;XNoSubject      EQU	4
xCalc		EQU	3
xText		EQU	2
;		EQU	1
;		EQU	0

Properties	EQU	asm_flag2
;XWiskunde	EQU	7
;XNatuurkunde	EQU	6
;XScheikunde	EQU	5
;XNoSubject     EQU	4
;xCalc		EQU	3
;xText		EQU	2
;		EQU	1
;		EQU	0

BetaFlags	EQU	asm_flag3
LftMenu		EQU	0
MenuInDisplay	EQU	1
;		EQU	2
;		EQU	3
;		EQU	4
;		EQU	5
;		EQU	6
;		EQU	7


; key equates:
key_down		EQU	$01
key_left		EQU	$02
key_right		EQU	$03
key_up			EQU	$04
key_enter		EQU	$09
key_clear		EQU	$0F
key_3			EQU	$12
key_2			EQU	$1A
key_1			EQU	$22
key_4			EQU	$23
key_comma		EQU	$25
key_log			EQU	$2C
key_graph		EQU	$31
key_trace		EQU	$32
key_zoom		EQU	$33
key_window		EQU	$34
key_Y			EQU	$35
key_quit		EQU	$37


; RAM area used by beta:

; System RAM (should never be cleared inside beta)
SAVESP		EQU	Statvars+00
;		EQU	Statvars+01
BetaName	EQU	Statvars+02
;		EQU	Statvars+03
;		EQU	Statvars+04
;		EQU	Statvars+05
;		EQU	Statvars+06
;		EQU	Statvars+07
;		EQU	Statvars+08
;		EQU	Statvars+09
;		EQU	Statvars+10
				 
; misc RAM			 
CURRENT_ADRESS	EQU	Statvars+11
;		EQU	Statvars+12
UP_OR_DOWN	EQU	Statvars+13
;		EQU	Statvars+14
ASAVE		EQU	Statvars+15
				 
; Navigation RAM		 
Cursor_Adress	EQU	Statvars+16
;		EQU	Statvars+17
Min_Adress	EQU	Statvars+18
;		EQU	Statvars+19
Max_Adress	EQU	Statvars+20
;		EQU	Statvars+21
				 
; Navigation RAM Backup		 
Cursor_Adress2	EQU	Statvars+22
;		EQU	Statvars+23
Min_Adress2	EQU	Statvars+24
;		EQU	Statvars+25
Max_Adress2	EQU	Statvars+26
;		EQU	Statvars+27
				 
; Picture RAM			 
X		EQU	Statvars+28
Y		EQU	Statvars+29
Width		EQU	Statvars+30
Height		EQU	Statvars+31
PIC_CURRENT	EQU	Statvars+32
;		EQU	Statvars+33
PIC_MAX		EQU	Statvars+34
;		EQU	Statvars+35
					 
; Square routine			 
sq_length	EQU	Statvars+36
sq_height	EQU	Statvars+37
point1bit	EQU	Statvars+38
point1		EQU	Statvars+39
;		EQU	Statvars+40
point2bit	EQU	Statvars+41
point2		EQU	Statvars+42
;		EQU	Statvars+43
operation	EQU	Statvars+44
				 	 
; Menu RAM			 
LeftMenuCur	EQU	Statvars+45
RightMenuCur	EQU	Statvars+46
String_Length	EQU	Statvars+47
String_Adress	EQU	Statvars+48
;		EQU	Statvars+49
Author		EQU	Statvars+50
;		EQU	Statvars+51
String_temp	EQU	Statvars+52

Statvars_max	EQU	Statvars+531





; RAM equates
LftMenuCur	EQU	LeftMenuCur
RgtMenuCur	EQU	RightMenuCur
Description	EQU	String_Temp



.LIST
.org progstart

; Save Beta's program name
 ld hl,Op1
 ld de,BetaName
 ld bc,9
 ldir

; Clear Screen
 bcall(_clrLCDFull)

; (re)set flags
#IFDEF TI83P
 res 2,(iy+50)			; No large font on graph screen
 set bufferonly,(iy+plotflag3)	; Draw to graph backup buffer only
#ENDIF
 res statsvalid,(IY+statflags)	; Make sure Statvars RAM area isn't used
 res plotLoc,(iy+plotflags)
 set textwrite,(iy+sgrflags)	; Write text only in graph backup buffer

; Save SP register
 ld (savesp),sp

; Get select flags
 ld a,(FlagsSave)
;| or %00001100		; make sure calcs and texts are selected
 ld (iy+SelectFlags),a

 ld hl,plotsscreen
 ld de,savesscreen
 ld bc,768
 ldir			; copy graph screen to buffer

; Start Beta
BETASHELL:


#include "menu.asm"




_ChkFindPlug:
; _ChkfindPlugin checks the validity of a plugin which name is in op1
; Input:
; Op1=name of plugin to check

; Output:

; carry flag set if invalid plugin
; carry flag reset if valid plugin
; (iy+Properties)=Plugin flags

 call file.open
 jp c,CS_INVALID
 xor a
 ld (op1+9),a		; Sometimes, _chkfindsym loads 5 or 6 into op1+9

 call CHK_INCCURSOR
 cp $D9			; STOP
 jr z,CS_TEXTPLUGIN
 cp $3F			; \n
 jr z,CS_CALCPLUGIN
 jp INVALID2

CS_TEXTPLUGIN:
 call CHK_INCCURSOR
 cp $3F			; \n
 jr nz,CS_INVALID

 call CHK_INCCURSOR
 or %00000100		; Make sure text flag is set
 ld (iy+properties),a

 rcf
 ret

CS_CALCPLUGIN:
 call CHK_INCCURSOR
 cp $2A
 jp nz,INVALID2

 call CHK_INCCURSOR
 ld hl,1
 cp $29				; space
 jr z,CS_SKIP_ONE
 cp $3F
 jr z,CS_SKIP_NONE
CS_SKIP_TWO:
 inc hl
CS_SKIP_ONE:
 call file.skip
 call file.readByte
 cp $3F
 jp nz,INVALID2
CS_SKIP_NONE:
 set xCalc,(iy+Properties)	; Make sure calc flag is set

 rcf
 ret

;| call CHK_INCCURSOR
;| cp $2A			; "
;| jp nz,INVALID2

;| call CHK_INCCURSOR
;| cp $29			; space
;| jr z,CS_NO_OK
;| cp 'W'
;| jr z,CS_WI
;| cp 'N'
;| jr z,CS_NA
;| cp 'S'
;| jr z,CS_SK
;| jp INVALID2
;|CS_WI:
;| call CHK_INCCURSOR
;| cp 'I'
;| ld a,%10001000
;| jr z,CS_OK
;| jp INVALID2
;|CS_NA:
;| call CHK_INCCURSOR
;| cp 'A'
;| ld a,%01001000
;| jr z,CS_OK
;| jp INVALID2
;|CS_SK:
;| call CHK_INCCURSOR
;| cp 'K'
;| ld a,%00101000
;| jr z,CS_OK
;| jp INVALID2
;|CS_NO_OK:		; no subject
;| ld a,%00011000

;|CS_OK:
;| ld (iy+Properties),a


CS_INVALID:
SCF:
 scf		; set carry flag
 ret




_ChkFindPlugin:
; _ChkfindPlugin checks the validity of a plugin which name is in op1
; and returns its flags and adress
; Input:
; Op1=name of plugin to detect

; Output:
; a: Plugin flags
; carry flag set if invalid plugin
; carry flag reset if valid plugin
; (iy+Properties)=Plugin flags
; (Current_adress)=pointer to plugin start in RAM
; Description=Program Description
; (Author)=Author

 call file.open
 jp c,INVALID2
 xor a
 ld (op1+9),a		; Sometimes, _chkfindsym loads 5 or 6 into op1+9

 call CHK_INCCURSOR
 cp $D9			; Stop
 jr z,TEXTPLUGIN
 cp $3F			; \n
 jp z,CALCPLUGIN
 jp INVALID2

TEXTPLUGIN:
 call CHK_INCCURSOR
 cp $3F			; \n
 jp nz,INVALID2

 call CHK_INCCURSOR
 or %00000100		; Make sure text flag is set, we don't really care for any actual settings in this byte, but it may be used again in the future
 ld (iy+Properties),a

 ; Search for Description

 xor a
 ld (String_length),a
 ld hl,String_temp
 ld (String_adress),hl

 call file.readByte
 jr c,TXT_TITLE_LOOP_END
 cp tag_title
 jr nz,TXT_TITLE_LOOP_END

TXT_TITLE_LOOP:
 call file.readByte
 jr c,TXT_TITLE_LOOP_END
 cp tag_title
 jr z,TXT_TITLE_LOOP_END

 push af
 ld l,a
 ld h,8
 bcall(_htimesl)
 bcall(_sFont_Len)	; calculate length
 ld a,(String_length)
 add a,b		; new string length
 add a,255-92		; Description max=92 pixels
 jr c,TXT_TITLE_TOO_LONG
 sub 255-92
 ld (String_length),a

 pop af
 ld hl,(String_adress)
 ld (hl),a
 inc hl
 ld (String_adress),hl

 jr TXT_TITLE_LOOP

TXT_TITLE_TOO_LONG:
 pop af			; cleans the stack a is not used here (we already known the length is too long)
TXT_TITLE_TOO_LONG_LOOP:
 call file.readByte
 jr c,TXT_TITLE_LOOP_END	; EOF
 cp tag_title
 jr nz,TXT_TITLE_TOO_LONG_LOOP	; loop until the tag end is found (or an EOF encountered). The last part of the description is ignored.

TXT_TITLE_LOOP_END:
 ld hl,(String_adress)
 ld (hl),0		; it's now a zero-terminated string
 inc hl
 ld (String_adress),hl
 ld (Author),hl


TXT_AUTHOR:

 ; Search for Author

 xor a
 ld (String_length),a
 call file.readByte
 jr c,TXT_AUTHOR_LOOP_END
 cp tag_author
 jr nz,TXT_AUTHOR_LOOP_END

TXT_AUTHOR_LOOP:
 call file.readByte
 jr c,TXT_AUTHOR_LOOP_END
 cp tag_author
 jr z,TXT_AUTHOR_LOOP_END

 push af
 ld l,a
 ld h,8
 bcall(_htimesl)
 bcall(_sFont_Len)	; calculate length
 ld a,(String_length)
 add a,b		; new string length
 add a,255-54		; Description max=54 pixels
 jr c,TXT_AUTHOR_TOO_LONG
 sub 255-54
 ld (String_length),a

 pop af
 ld hl,(String_adress)
 ld (hl),a
 inc hl
 ld (String_adress),hl

 jr TXT_AUTHOR_LOOP

TXT_AUTHOR_TOO_LONG:
 pop af			; cleans the stack a is not used here (we already known the length is too long)
TXT_AUTHOR_TOO_LONG_LOOP:
 call file.readByte
 jr c,TXT_AUTHOR_LOOP_END	; EOF
 cp tag_author
 jr nz,TXT_AUTHOR_TOO_LONG_LOOP	; loop until the tag end is found (or an EOF encountered). The last part of the description is ignored.

TXT_AUTHOR_LOOP_END:
 ld hl,(String_adress)
 ld (hl),0		; it's now a zero-terminated string

 rcf
 ret




CALCPLUGIN:
 call CHK_INCCURSOR
 cp $2A
 jp nz,INVALID2

 call CHK_INCCURSOR
 cp $29				; space
 jr z,SKIP_ONE
 cp $3F
 jr z,SKIP_NONE
SKIP_TWO:
 call CHK_INCCURSOR
SKIP_ONE:
 call CHK_INCCURSOR
SKIP_NONE:
 cp $3F
 jp nz,INVALID2

 set xCalc,(iy+Properties)	; Make sure calc flag is set

;| call CHK_INCCURSOR
;| cp $2A			; "
;| jp nz,INVALID2
;|
;| call CHK_INCCURSOR
;| cp $29			; space
;| jr z,SU_NO_OK
;| cp 'W'
;| jr z,SU_WI
;| cp 'N'
;| jr z,SU_NA
;| cp 'S'
;| jr z,SU_SK
;| jp INVALID2
;|SU_WI:
;| call CHK_INCCURSOR
;| cp 'I'
;| ld a,%10001000
;| jr z,OKOK
;| jp INVALID2
;|SU_NA:
;| call CHK_INCCURSOR
;| cp 'A'
;| ld a,%01001000
;| jr z,OKOK
;| jp INVALID2
;|SU_SK:
;| call CHK_INCCURSOR
;| cp 'K'
;| ld a,%00101000
;| jr z,OKOK
;| jp INVALID2
;|SU_NO_OK:		; no subject
;| ld a,%00011000

;|OKOK:





 ; Search for Description

 xor a
 ld (String_length),a
 ld hl,String_temp
 ld (String_adress),hl

 call file.readByte
 jr c,CLC_TITLE_LOOP_END
 cp $2A
 jr nz,CLC_TITLE_LOOP_END

CLC_TITLE_LOOP:
 call file.readByte
 jr c,CLC_TITLE_LOOP_END
 cp $3F
 jr z,CLC_TITLE_LOOP_END

 push af
 ld l,a
 ld h,8
 bcall(_htimesl)
 bcall(_sFont_Len)	; calculate length
 ld a,(String_length)
 add a,b		; new string length
 add a,255-92		; Description max=92 pixels
 pop hl			; af pops out as hl because it causes a return error if title too long (don't pop as af because carry flag will change)
 jr c,CLC_TITLE_TOO_LONG
 push hl
 sub 255-92
 ld (String_length),a

 pop af
 ld hl,(String_adress)
 ld (hl),a
 inc hl
 ld (String_adress),hl

 jr CLC_TITLE_LOOP

CLC_TITLE_TOO_LONG:
 call file.readByte
 jr c,CLC_TITLE_LOOP_END
 cp $3F
 jr z,CLC_TITLE_LOOP_END
 jr CLC_TITLE_TOO_LONG

CLC_TITLE_LOOP_END:
 ld hl,(String_adress)
 ld (hl),0		; it's now a zero-terminated string
 inc hl
 ld (String_adress),hl
 ld (Author),hl











CLC_AUTHOR:

 ; Search for Author

 xor a
 ld (String_length),a
 call file.readByte
 jr c,CLC_AUTHOR_LOOP_END
 cp $2A
 jr nz,CLC_AUTHOR_LOOP_END

CLC_AUTHOR_LOOP:
 call file.readByte
 jr c,CLC_AUTHOR_LOOP_END
 cp $3F
 jr z,CLC_AUTHOR_LOOP_END

 push af
 ld l,a
 ld h,8
 bcall(_htimesl)
 bcall(_sFont_Len)	; calculate length
 ld a,(String_length)
 add a,b		; new string length
 add a,255-54		; Description max=54 pixels
 jr c,CLC_AUTHOR_TOO_LONG
 sub 255-54
 ld (String_length),a

 pop af
 ld hl,(String_adress)
 ld (hl),a
 inc hl
 ld (String_adress),hl

 jr CLC_AUTHOR_LOOP

CLC_AUTHOR_TOO_LONG:
 call file.readByte
 jr c,CLC_AUTHOR_LOOP_END
 cp $3F
 jr z,CLC_AUTHOR_LOOP_END
 jr CLC_AUTHOR_TOO_LONG

CLC_AUTHOR_LOOP_END:
 ld hl,(String_adress)
 ld (hl),0		; it's now a zero-terminated string

 rcf
 ret







INVALID2:
 xor a
 ld (iy+Properties),a
 scf		; set carry flag
 pop hl
 ret

CHK_INCCURSOR:
 call file.readByte
 jr c,INVALID2
 ret










_FindBetaUp:
; _FindBetaUp finds alphabetically the next valid beta plugin
; Input:
; Op1: previous program name

; Output:
; OP1: name of next plugin
; a: Plugin flags
; carry flag set if this was the last plugin
; carry flag reset this was not the last plugin
; (iy+Properties)=Plugin flags
; (Current_adress)=pointer to plugin start in RAM

 ld hl,Cursor_adress
 ld de,Cursor_adress2
 ld bc,6
 ldir
 bcall(_op1toop5)
FindBetaUp:
 bcall(_op1toop6)
 bcall(_findalphaup)
 ld hl,FindBetaUp		; Needs to be saved in case of invalid plugins
 ld (up_or_down),hl
 jr FINDBeta

_FindBetaDown:
; _FindBetaDown finds alphabetically the previous valid beta plugin
; Input:
; Op1: current program name

; Output:
; OP1: name of previous plugin
; carry flag set if this was the first plugin
; carry flag reset this was not the first plugin

 bcall(_op1toop5)
 ld hl,Cursor_adress
 ld de,Cursor_adress2
 ld bc,6
 ldir
FindBetaDown:
 bcall(_Op1toop6)
 bcall(_findalphadn)
 ld hl,FindBetaDown		; Needs to be saved in case of invalid plugins
 ld (up_or_down),hl

FINDBeta:
 exx
 ex af,af'
 bcall(_op6toop2)
 call cpop1op2
 jr nz,NO_BUG

FindBeta_Invalid:
 bcall(_op5toop1)		; restore original name
 ld hl,Cursor_adress2		; restore original flags & adresses
 ld de,Cursor_adress
 ld bc,6
 ldir
 scf
 ret

NO_BUG:
 exx
 ex af,af'

 call _chkfindplug
 jr c,INVALID

 ld a,(iy+selectflags)		; This code checks if this plug is what we asked for
 xor %11111111
 ld b,a
 ld a,(iy+Properties)
 and b
 jr nz,INVALID

 inc hl				; hl is at the actual beginning of the plugin
 ld (current_adress),hl
 rcf
 ret

INVALID:
 ld hl,(up_or_down)		; _FindBetaup or _FindBetadown
 push hl
 ret		; jump to _FindBetaup or _FindBetadown





















OPEN_PLUGIN:
 bcall(_op5toop1)		; op5= first plugin in the list
 call _chkfindplugin		; Gets plugin settings

 bit XText,(iy+Properties)
 jr nz,SIMPLE_SCROLL		; goto scroll engine for text plugins
 bit XCalc,(iy+Properties)
 jr nz,CALC_PLUG		; goto basic engine for programs







;;
;;		; Start calculator
;;


CALC_PLUG:

 bcall(_op1toop2)
 call SAVE_SELECT_FLAGS
 bcall(_op2toop1)

 res textwrite,(iy+sgrflags)	; Write text only in graph backup buffer
#IFDEF TI83P
 res bufferonly,(iy+plotflag3)	; Draw to graph backup buffer only
#ENDIF

 res oninterrupt,(iy+onflags)
 ld sp,(savesp)
 bcall(_grbufclr)
 ld hl,0
 ld (currow),hl
 ld a,$20
 bcall(_putmap)
 bcall(_clrscrnfull)
 bcall(_clrtxtshd)
; bcall(_JforceCmdnochar)		; This is the cause of the Beta NT memory bug

 set ProgExecuting,(iy+newDispf)
 bcall(_ParseInp)
 res progExecuting,(iy+newDispf)
 ret




#include "scroll.asm"









;BETAKEY:
; bcall(_runindicoff)
;#IFDEF TI83P
; bcall(_op1toop3)		; prevents MirageOS bug
;#ENDIF
; bcall(_getkey)
;#IFDEF TI83P
; bcall(_op3toop1)		; prevents MirageOS bug
;#ENDIF
;
; bit oninterrupt,(iy+onflags)	; On key
; jr nz,EXIT
;
; cp key_clear
; jr z,EXIT
; cp key_quit
; jr z,EXIT
; ld b,%10001100		; Wiskunde
; cp key_Y
; jr z,SHORTCUT
; ld b,%01001100		; Natuurkunde
; cp Key_window
; jr z,SHORTCUT
; ld b,%00101100		; Scheikunde
; cp Key_zoom
; jr z,SHORTCUT
; ld b,%00011100		; Overigen
; cp Key_Trace
; jr z,SHORTCUT
; ld b,%11111100		; Alles
; cp Key_graph
; jr z,SHORTCUT
; ret
;
;SHORTCUT:
; ld a,b
; ld (iy+SelectFlags),a
; bit MenuInDisplay,(iy+BetaFlags)
; jr z,BETASHELL
; jr UPDATE_MENU

BETAKEY:
 bcall(_runindicoff)

GETKEY_LOOP:
 bcall(_GetCSC)
 and a
 jr z,GETKEY_LOOP

 bit oninterrupt,(iy+onflags)	; On key
 jp nz,EXIT

 cp key_clear
 jp z,EXIT
 cp key_quit
 jp z,EXIT
; ld b,%10001100		; Wiskunde
; cp key_Y
; jr z,SHORTCUT
; ld b,%01001100		; Natuurkunde
; cp Key_window
; jr z,SHORTCUT
; ld b,%00101100		; Scheikunde
; cp Key_zoom
; jr z,SHORTCUT
; ld b,%00011100		; Overigen
; cp Key_Trace
; jr z,SHORTCUT
; ld b,%11111100		; Alles
; cp Key_graph
; jr z,SHORTCUT
 ret

;SHORTCUT:
; ld a,b
; ld (iy+SelectFlags),a
; bit MenuInDisplay,(iy+BetaFlags)
; jp z,BETASHELL
; jp UPDATE_MENU


CPOP1OP2:
; Compares the program names in op1 and op2, the _cpop1op2 routine compares them as floating point
; Input:
; op1: program name to compare
; op2: program name to compare
; Output:
; zero flag set if op1=op2
; zero flag reset if op1!=op2
; Destroys:
; Registers hl, de, b, a, c
 ld hl,op1+1
 ld de,op2+1
 ld b,8
CPOP1OP2_LOOP:
 ld a,(de)
 ld c,(hl)
 cp c
 ret nz
 inc hl
 inc de
 djnz CPOP1OP2_LOOP
 ret






SQUARE:
; Puts a rectangle in the graph backup buffer or a straight line
; Input:
; b: x coordinate of upper left corner
; c: y coordinate of upper left corner
; d: x coordinate of lower right corner
; e: y coordinate of lower right corner
; h: 0 - pixel off operation
;    1 - pixel on operation
;    2+ - pixel change operation (xor)
; @require b<96 && c<64 && d<96 && e<64 && b<=d && c<=e
; to draw a line, make sure b=d or c=e
; to draw a point, make sure b=d and c=e

 ld a,h
 cp 2
 jr nz,SQUARE_PIXELCHANGE1

 LineOn
SQUARE_PIXELCHANGE1:
; b=b
; c=c
; d=d
; e=c
 push de
 ld e,c
 bcall(_iline)
 pop de

; b=b
; c=e
; d=d
; e=e
 push bc
 ld c,e
 bcall(_iline)
 pop bc

 ld a,h
 cp 2
 jr nz,SQUARE_PIXELCHANGE2
 LineChange
SQUARE_PIXELCHANGE2:
; b=b
; c=c
; d=b
; e=e
 push de
 ld d,b
 bcall(_iline)
 pop de

; b=d
; c=c
; d=d
; e=e
 push bc
 ld b,d
 bcall(_iline)
 pop bc
 ret
















SAVE_SELECT_FLAGS:
 ld hl,BetaName
 ld de,Op1
 ld bc,9
 ldir

 bcall(_chkfindsym)
 ex de,hl
 ld e,(hl)
 inc hl
 ld d,(hl)
 push hl		; hl=program adress
#IFDEF TI83P
 ld hl,END_OF_BETA-progstart+2	; length squished+length bytes
#ELSE
 ld hl,END_OF_BETA-progstart	; length squished
#ENDIF
 bcall(_cphlde)		; check lenght to see if beta is unquished
 pop hl
 ret nz
 add hl,de
 ld a,(iy+SelectFlags)
 ld (hl),a
 ret

EXIT:

 call SAVE_SELECT_FLAGS

 res textwrite,(iy+sgrflags)	; Write text only in graph backup buffer
#IFDEF TI83P
 res bufferonly,(iy+plotflag3)	; Draw to graph backup buffer only
#ENDIF

 res oninterrupt,(iy+onflags)
 ld sp,(savesp)
 bcall(_grbufclr)
 ld hl,0
 ld (currow),hl
 ld a,$20
 bcall(_putmap)
 bcall(_clrscrnfull)
 bcall(_clrtxtshd)

 ld hl,savesscreen
 ld de,plotsscreen
 ld bc,768
 ldir			; restore graph screen

; bcall(_JforceCmdnochar)		; This is the cause of the famous Beta NT memory bug
 ret



#include "include/file.inc"




;;
;;	; Data
;;


#IFDEF LAN_EN
#include "en.asm"
#ENDIF
#IFDEF LAN_NL
#include "nl.asm"
#ENDIF
#IFDEF LAN_DE
#include "de.asm"
#ENDIF
#IFDEF LAN_FR
#include "fr.asm"
#ENDIF
#IFDEF LAN_ES
#include "es.asm"
#ENDIF
#IFDEF LAN_IT
#include "it.asm"
#ENDIF
#IFDEF LAN_LA
#include "la.asm"
#ENDIF

FlagsSave:
 .db $FF







; Appendix A:
; Textplugin should look like this:
;
; .db $D9,$3F				; Stop\n
; .db %10000000				; Flags
; .db tag_title,"[title]",tag_title
; .db tag_author,"[author]",tag_author

; .db "Dit is regel 1",tag_return		; Text itself
; .db "Dit is r...




; Appendix B: Calcplugin should look like this:
;
; .db $3F			; \n
; .db $2A,$3F			; "\n
; .db $2A,"[title]",$3F		; "[title]\n
; .db $2A,"[author]",$3F	; "[author]\n
;				; Beginning of calc


END_OF_BETA:
.end
END
