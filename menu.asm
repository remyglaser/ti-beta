
 set LftMenu,(iy+BetaFlags)
 set MenuInDisplay,(iy+BetaFlags)











 call DRAWMENU

 ld a,1
 ld (RgtMenuCur),a




UPDATE_MENU:
 call DELETE_LEFT

 ld a,1
 ld (LftMenuCur),a

 vLocate(44,6)
 ld a,$D0
 bit XText,(iy+SelectFlags)
 call z,LOAD_EMPTY
 bcall(_vputmap)

 vLocate(44,12)
 ld a,$D0
 bit XCalc,(iy+SelectFlags)
 call z,LOAD_EMPTY
 bcall(_vputmap)

;| vLocate(44,18)	; These are two extra menu items after the existing two. Now obsolete.
;| ld a,$D0
;| bit XScheikunde,(iy+SelectFlags)
;| call z,LOAD_EMPTY
;| bcall(_vputmap)

;| vLocate(44,24)
;| ld a,$D0
;| bit XNoSubject,(iy+SelectFlags)
;| call z,LOAD_EMPTY
;| bcall(_vputmap)

 bcall(_zeroop1)
 ld a,progobj
 ld (op1),a
 call _FindBetaUp
 jp c,NONE_FOUND

 call OUTPUT_PROGRAM_LIST_UP

 bit LftMenu,(iy+BetaFlags)
 call nz,PLACE_LEFT

LMENU_LOOP:

 call _chkfindplugin
 call CLEAR_PROGRAM_INFO
 vLocate(40,40)
 ld hl,(Author)
 bcall(_vPuts)

 vLocate(2,56)
 ld hl,Description
 bcall(_vPuts)


 bit LftMenu,(iy+BetaFlags)
 jp z,RMENU_LOOP

 bcall(_grbufcpy)
LMENU_KEYLOOP:
 call BETAKEY
 cp key_up
 jr z,LEFT_UP
 cp key_down
 jr z,LEFT_DOWN
 cp key_right
 jr z,RIGHT_MENU
 cp key_enter
 jr z,LEFT_ENTER
 jr LMENU_KEYLOOP

LEFT_UP:
 ld a,(LftMenuCur)
 cp 1
 jr z,PLUG_UP
 dec a
 ld (x),a
 call _FindBetaDown		; update op1
; jr c,LMENU_KEYLOOP		; should not be possible
 jp c,_errTolTooSmall
 call DELETE_LEFT
 ld a,(x)
 ld (LftMenuCur),a
 call PLACE_LEFT
 jr LMENU_LOOP

PLUG_UP:		; scroll list up
 call _FindBetaDown
 jr c,LMENU_KEYLOOP
 call OUTPUT_PROGRAM_LIST_UP
 jr LMENU_LOOP

LEFT_DOWN:
 ld a,(LftMenuCur)
 cp 9
 jr z,PLUG_DOWN
 inc a
 ld (x),a
 call _FindBetaUp
 jr c,LMENU_KEYLOOP
 call DELETE_LEFT
 ld a,(x)
 ld (LftMenuCur),a
 call PLACE_LEFT
 jp LMENU_LOOP

PLUG_DOWN:
 call _FindBetaUp
 jr c,LMENU_KEYLOOP
 call OUTPUT_PROGRAM_LIST_DOWN
 jp LMENU_LOOP

LEFT_ENTER:
 res MenuInDisplay,(iy+BetaFlags)
 bit xCalc,(iy+properties)
 jp nz,CALC_PLUG
 jp z,SIMPLE_SCROLL

LOAD_EMPTY:
 ld a,$06
 ret

RIGHT_MENU:
 res LftMenu,(iy+BetaFlags)
 call DELETE_LEFT
 call PLACE_RIGHT

RMENU_LOOP:
 bcall(_grbufcpy)

RMENU_KEYLOOP:
 call BETAKEY
 cp key_up
 jr z,RIGHT_UP
 cp key_down
 jr z,RIGHT_DOWN
 cp key_left
 jr z,LEFT_MENU
 cp key_enter
 jr z,RIGHT_ENTER
 jr RMENU_KEYLOOP

RIGHT_UP:
 ld a,(RightMenuCur)
 cp 1
 jr z,RMENU_KEYLOOP
 dec a
 push af
 call DELETE_RIGHT
 pop af
 ld (RightMenuCur),a
 call PLACE_RIGHT
 jr RMENU_LOOP

RIGHT_DOWN:
 ld a,(RightMenuCur)
 cp 2
 jr z,RMENU_KEYLOOP
 inc a
 push af
 call DELETE_RIGHT
 pop af
 ld (RightMenuCur),a
 call PLACE_RIGHT
 jr RMENU_LOOP

LEFT_MENU:
 ld a,(LeftMenuCur)
 and a
 jr z,RMENU_KEYLOOP
 
 set LftMenu,(iy+BetaFlags)
 call DELETE_RIGHT
 call PLACE_LEFT
 jp LMENU_LOOP

RIGHT_ENTER:
 ld a,(RightMenuCur)

;| ld b,%10000000		; Wiskunde
;| cp 1
;| jr z,XOR_IT

;| ld b,%01000000		; Natuurkunde
;| cp 2
;| jr z,XOR_IT

;| ld b,%00100000		; Scheikunde
;| cp 3
;| jr z,XOR_IT

;| ld b,%00010000		; Overigen

 ld b,%00000100			; Text
 cp 1
 jr z,XOR_IT

 ld b,%00001000			; Calc
XOR_IT:
 ld a,b
 xor (iy+SelectFlags)
 ld (iy+SelectFlags),a
 jp UPDATE_MENU

NONE_FOUND:
 ld a,(LftMenuCur)
 and a
 jr z,RMENU_KEYLOOP
 call CLEAR_PROGRAM_LIST
 call CLEAR_PROGRAM_INFO
 Text(6,1,NONE_TXT)
 
 res LftMenu,(iy+BetaFlags)
 call DELETE_LEFT
 call PLACE_RIGHT
 xor a
 ld (LeftMenuCur),a
 jp RMENU_LOOP




















DELETE_LEFT:
 call CALCULATE_LEFT
 ld a,$06
 bcall(_vputmap)
 ret

PLACE_LEFT:
 call CALCULATE_LEFT
 ld a,$05
 bcall(_vputmap)

CALCULATE_LEFT:
 ld a,(LeftMenuCur)
 and a
 jr z,CALCULATE_INVALID
 ld l,a
 ld h,6
 bcall(_htimesl)
 ld a,l
 sub 5
 ld h,a
 ld l,2
 ld (pencol),hl
 ret

CALCULATE_INVALID:
 pop hl
 ret

DELETE_RIGHT:
 call CALCULATE_RIGHT
 ld a,$06
 bcall(_vputmap)
 ret

PLACE_RIGHT:
 call CALCULATE_RIGHT
 ld a,$05
 bcall(_vputmap)

CALCULATE_RIGHT:
 ld a,(RightMenuCur)
 ld l,a
 ld h,6
 bcall(_htimesl)
 ld h,l
 ld l,40
 ld (pencol),hl
 ret
 

DRAWMENU:
 bcall(_GrBufClr)

; Vertical Lines
 LineOn
 Line(00,00,00,63)
 Line(38,00,38,55)
 Line(95,05,95,63)

; Horizontal Lines
 LineChange
 Line(00,00,38,00)
 Line(38,05,95,05)
 Line(38,31,95,31)
 Line(38,39,95,39)
 Line(38,47,95,47)
 Line(00,55,95,55)
 Line(00,63,95,63)




; Square(0,0,38,0)
; Square(38,5,94,5)
; Square(38,31,94,31)
; Square(38,39,94,39)
; Square(38,47,94,47)
; Square(0,55,94,55)

; Square(0,0,0,63)
; Square(38,0,38,55)
; Square(94,5,94,63)
; Square(0,63,94,63)

 Text(48,6,TEXT_TXT)
 Text(48,12,CALC_TXT)
 Text(40,32,AUTHOR_TXT)
 Text(40,48,DESCRIPTION_TXT)

 ret


OUTPUT_PROGRAM_LIST_UP:
 call CLEAR_PROGRAM_LIST


 bcall(_op1toop4)
 ld b,9		; there are 9 slots in the menu
UP_PROGRAM_LIST_LOOP:
 push bc
 ld h,b			; 55-(b*6)->penrow
 ld l,6
 bcall(_htimesl)
 ld a,55
 sub l
 ld h,a
 ld l,6
 ld (pencol),hl

 ld hl,op1+1
 bcall(_vputs)		; outputs plugin name
 call _FindBetaUp	; find next Plugin
 jr c,UP_PROGRAM_LIST_LOOP_END
 pop bc
 djnz UP_PROGRAM_LIST_LOOP
 push bc
UP_PROGRAM_LIST_LOOP_END:
 pop bc
 bcall(_op4toop1)
 ret




OUTPUT_PROGRAM_LIST_DOWN:
 call CLEAR_PROGRAM_LIST

 bcall(_op1toop4)
 ld b,9		; there are 9 slots in the menu
DN_PROGRAM_LIST_LOOP:
 push bc
 ld h,b			; (b*6)-5->penrow
 ld l,6
 bcall(_htimesl)
 ld a,l
 sub 5
 ld h,a
 ld l,6
 ld (pencol),hl

 ld hl,op1+1
 bcall(_vputs)		; outputs plugin name
 call _FindBetaDown	; Find next Plugin
 jr c,DN_PROGRAM_LIST_LOOP_END
 pop bc
 djnz DN_PROGRAM_LIST_LOOP
 push bc
DN_PROGRAM_LIST_LOOP_END:
 pop bc
 bcall(_op4toop1)
 ret

CLEAR_PROGRAM_LIST:
 LineOff
 Square(6,1,37,54)	; clear program list
 ret

CLEAR_PROGRAM_INFO:
 LineOff
 Square(2,56,93,61)	; clear author
 Square(40,40,93,45)	; clear description
 ret




