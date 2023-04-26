; Copyright (C) 2006  Remy Glaser
; 
; This program is free software; you can redistribute it and/or
; modify it under the terms of the GNU General Public License
; as published by the Free Software Foundation; either version 3
; of the License, or (at your option) any later version.
; 
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
; gpl-3.0.txt for more details.
; 

SIMPLE_SCROLL:
 ld hl,(cursor_adress)
 dec hl
 ld (Min_adress),hl
 ld b,3


OUTPUT_PAGE:
 bcall(_grbufclr)
 xor a
 ld (penrow),a
 ld (pencol),a


OUTPUT_PAGE_LOOP:
 ld hl,(cursor_adress)
 ld a,(hl)

 cp tag_Return
 jp z,NEXT_LINE
 cp tag_freetext
 jp z,FREETEXT
 cp tag_invert
 jp z,INVERSE
 cp tag_tab
 jp z,TAB
 cp tag_picture
 jp z,PIC
 cp tag_page_end
 jp z,SCROLL_KEY
 cp tag_Square
 jp z,CUSTOM_SQUARE
 cp tag_line
 jp z,CUSTOM_LINE

 res 2,(iy+textflags)
 bcall(_vputmap)
 ld a,(iy+textflags)
; ld a,($942B)
; and a
; jp z,STRANGE_ERROR

 call INCCURSOR
 jp OUTPUT_PAGE_LOOP

;STRANGE_ERROR:
; jp _ERRLINKXMIT


INVERSE:
 ld a,(iy+Textflags)
 xor %00001000
 ld (iy+textFlags),a
 call INCCURSOR
 jp OUTPUT_PAGE_LOOP

FREETEXT:
 ld hl,(pencol)
 exx

 call INCCURSOR
 ld a,(hl)
 add a,255-94
 jp c,_ERRDOMAIN
 ld a,(hl)
 ld (penrow),a

 call INCCURSOR
 ld a,(hl)
 add a,255-63
 jp c,_ERRDOMAIN
 ld a,(hl)
 ld (pencol),a

FREETEXTLOOP:
 call INCCURSOR
 ld a,(hl)
 cp tag_invert
 jp z,FREE_INVERSE
 cp tag_freetext
 jp z,FREE_END
 bcall(_vputmap)
 jp FREETEXTLOOP

FREE_INVERSE:
 ld a,(iy+Textflags)
 xor %00001000
 ld (iy+textFlags),a
 jp FREETEXTLOOP

FREE_END:
 exx
 ld (pencol),hl
 call INCCURSOR
 jp OUTPUT_PAGE_LOOP


PIC:
 call INCCURSOR
 ld a,(hl)
 ld l,a
 ld h,0
 ld a,8
 bcall(_divhlbya)
 ld a,l
 ld (x),a

 call INCCURSOR
 ld a,(hl)
 ld (y),a

 call INCCURSOR
 ld a,(hl)
 ld l,a
 ld h,0
 ld a,8
 bcall(_divhlbya)
 and a
 jp nz,_ERRDIMENSION
 ld a,l
 ld (width),a

 call INCCURSOR
 ld a,(hl)
 ld (height),a

 ld a,(x)
 ld b,a
 ld a,(width)
 add a,b
 add a,255-12
 jp c,_ERRDOMAIN

 ld a,(y)
 ld b,a
 ld a,(height)
 add a,b
 add a,255-64
 jp c,_ERRDOMAIN

 ld a,(y)
 ld l,a
 ld h,12
 bcall(_htimesl)
 ld a,(x)
 dec a
 cp $FF
 call z,A_0
 add a,l
 call c,INC_H
 ld l,a
 ld de,plotsscreen
 add hl,de
 bcall(_cphlde)
 call z,DEC_HL
 ld (pic_current),hl

 ld a,(y)
 ld b,a
 ld a,(height)
 add a,b
 dec a
 ld l,a
 ld h,12
 bcall(_htimesl)
 ld a,(x)
 ld b,a
 ld a,(width)
 add a,b
 ld b,l
 add a,b
 ld l,a
 call c,INC_H
 ld de,plotsscreen
 add hl,de
 ld (PIC_MAX),hl

 

DRAW_LOOP:
 ld a,(width)
 ld b,a
DRAW_MINILOOP:

 call INCCURSOR
 ld a,(hl)
 call PIC_INC
 ld c,(hl)
 or c			; Transparency
 ld (hl),a


 djnz DRAW_MINILOOP
 ld a,(width)
 ld b,a
 ld a,12
 sub b
 and a
 jp z,DRAW_LOOP
 ld b,a
DRAW_SKIPLOOP:
 call PIC_INC
 djnz DRAW_SKIPLOOP
 jp DRAW_LOOP



PIC_EXIT:
 pop hl
 ld b,4
PIC_EXITLOOP:
 call INCCURSOR
 djnz PIC_EXITLOOP
 jp OUTPUT_PAGE_LOOP






INC_H:
 inc h
 ret
DEC_HL:
 dec hl
 ret
A_0:
 xor a
 ret
PIC_INC:
 ld hl,(PIC_MAX)
 ex de,hl
 ld hl,(PIC_CURRENT)
 inc hl
 bcall(_cphlde)
 jp z,PIC_EXIT
 ld (PIC_CURRENT),hl
 ret

		; Vector support
CUSTOM_SQUARE:
 call INCCURSOR
 ld b,(hl)

 call INCCURSOR
 ld c,(hl)

 call INCCURSOR
 ld d,(hl)
 push de

 call INCCURSOR
 pop de
 ld e,(hl)
 push de

 call INCCURSOR)
 ld h,(hl)
 pop de

 call SQUARE
 jp OUTPUT_PAGE_LOOP




CUSTOM_LINE:
 call INCCURSOR
 ld b,(hl)

 call INCCURSOR
 ld c,(hl)
 ld a,63
 sub c
 ld c,a

 call INCCURSOR
 ld d,(hl)
 push de

 call INCCURSOR
 pop de
 ld e,(hl)
 ld a,63
 sub e
 ld e,a
 push de

 call INCCURSOR
 ld h,(hl)

 pop de
 bcall(_Iline)
 call INCCURSOR
 jp OUTPUT_PAGE_LOOP






TAB:
 ld a,(pencol)
 add a,255-24
 jp c,LARGERTHAN24
 ld a,24
 jp END_TAB

LARGERTHAN24:
 ld a,(pencol)
 add a,255-48
 jp c,LARGERTHAN48
 ld a,48
 jp END_TAB

LARGERTHAN48:
 ld a,(pencol)
 add a,255-72
 jp c,END_TAB
 ld a,72

END_TAB:
 ld (pencol),a
 call INCCURSOR
 jp OUTPUT_PAGE_LOOP

INCCURSOR:
 call file.readByte
 jp c,RETTO__SCROLL_KEY
 ret

RETTO__SCROLL_KEY:
 pop hl
 jp SCROLL_KEY

NEXT_LINE:
 call INCCURSOR
 ld a,(penrow)
 add a,6
 ld b,255-58
 add a,b
 jp c,OUTPUT_PAGE_LOOP
 sub b
 ld (penrow),a
 xor a
 ld (pencol),a
 jp OUTPUT_PAGE_LOOP

SCROLL_KEY:
 bcall(_grbufcpy_v)
 ld a,(iy+textflags)
 ld (asave),a
 res textinverse,(iy+textflags)
SCROLL_KEYLOOP:
 call BETAKEY
 cp key_up
 jp z,UP
 cp key_down
 jp z,DOWN
 cp key_enter
 jp z,SCROLL_BETASHELL
 jp SCROLL_KEYLOOP

DOWN:
 ld a,(asave)
 ld (iy+textflags),a
 call INCCURSOR
 jp OUTPUT_PAGE


UP:
 ld a,(asave)
 ld (iy+textflags),a

 
 ld b,2
 ld hl,(cursor_adress)
 ld a,(hl)
 cp tag_picture
 jp z,SKIP_PICTURE

UP_LOOP:
 call DECCURSOR

 ld a,(hl)
 cp tag_picture
 jp z,SKIP_PICTURE

 cp tag_page_end
 jp nz,up_loop
 djnz UP_LOOP

 call INCCURSOR
 jp OUTPUT_PAGE

SKIP_PICTURE:
 call DECCURSOR
 ld a,(hl)
 ld c,a
 call DECCURSOR
 ld a,(hl)
 ld b,a
SKIP_PIC_LOOP:
 call DECCURSOR
 dec bc
 ld d,b
 ld e,c
 ld hl,0
 bcall(_cphlde)
 jp nz,SKIP_PIC_LOOP
 ld b,5
DECCURSOR_LOOP:
 call DECCURSOR
 djnz DECCURSOR_LOOP
 jp UP_LOOP


DECCURSOR:
 ld hl,(min_adress)
 ex de,hl
 ld hl,(cursor_adress)
 dec hl
 bcall(_cphlde)
 jp z,RETTO__OUTPUT_PAGE
 ld (cursor_adress),hl
 ret
RETTO__OUTPUT_PAGE:
 pop hl
 jp OUTPUT_PAGE




ScreenVPutMap:
 res textwrite,(iy+sgrflags)
 bcall(_vputmap)
 set textwrite,(iy+sgrflags)
 ret

SCROLL_BETASHELL:
 jp betashell