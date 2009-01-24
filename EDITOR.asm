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

.NOLIST
#define     equ             .equ
#define     EQU             .equ
#define     END             .end
.LIST

_CLRLCDFULL             equ     4755h
_runIndicOff            equ     4795h
_clrScrnFull            equ     475Dh
_puts                   equ     470Dh
_CLOSEPROG              equ     4E06h
_ZEROOP1                equ     428Eh
_putmap                 equ     4701h
_OP1TOOP5               equ     41BEh
_OP5TOOP1               equ     419Eh
__bank_ret              equ     0000h
_ILINE                  equ     4AE4h
_getcsc                 equ     4014h
_GRBUFCPY               equ     4B9Ch
_vputmap                equ     477Dh
_cphlde                 equ     4004h
_divHLbyA               equ     400Ch
_HTIMESL                equ     4382h
_VPUTBLANK              equ     4C53h
_SFONT_LEN              equ     4A6Ch
_CHKFINDSYM             equ     442Ah
_EDITPROG               equ     4E02h
_GRBUFCLR               equ     515Bh
_CREATEPROG             equ     448Ah
_OP4TOOP1               equ     419Ah
_closeEditBuf           equ     4C2Bh
_putc                   equ     4705h
_RSTRSHADOW             equ     47A1h
_saveCmdShadow          equ     4799h
_OP1TOOP6               equ     41BAh
_FindAlphaup            equ     4E1Ah
_FindAlphadn            equ     4E1Eh
_CLRTXTSHD              equ     4765h

.org        9327h

     call _CLRLCDFULL
     call _runIndicOff
     res  6, (iy+09h)
     set  7, (iy+14h)
     res  1, (iy+02h)
     res  2, (iy+08h)
     ld   (0858Fh), sp 
     xor  a       
     ld   (iy+21h), a
     set  1, (iy+21h)
     ld   hl, 08592h
     ld   b, 15h

Label1:
     ld   (hl), 00h
     inc  hl      
     djnz Label1

Label10:
     call _clrScrnFull
     ld   hl, 00100h
     ld   (0800Ch), hl 
     ld   hl, Str1
     call _puts
     ld   hl, 0002h
     ld   (0800Ch), hl 
     ld   hl, Str2
     call _puts
     ld   hl, 0003h
     ld   (0800Ch), hl 
     ld   hl, Str3
     call _puts
     ld   hl, 0005h
     ld   (0800Ch), hl 
     ld   hl, Str4
     call _puts
     bit  0, (iy+21h)
     jp   z, Label2
     ld   hl, 0004h
     ld   (0800Ch), hl 
     ld   hl, Str5
     call _puts

Label2:
     call Label3
     cp   0Fh
     jp   z, Label4
     cp   22h
     jp   z, Label5
     cp   1Ah
     jp   z, Label6
     cp   23h
     jp   z, Label7
     bit  0, (iy+21h)
     jp   z, Label2
     cp   12h
     jp   z, Label8
     jp   Label2

Label6:
     bit  1, (iy+21h)
     call z, Label9
     jp   c, Label10
     bit  0, (iy+21h)
     call nz, _CLOSEPROG
     call _ZEROOP1
     ld   a, 05h
     ld   (08039h), a  
     call Label11
     jp   c, Label12

Label85:
     call _clrScrnFull
     ld   hl, 00200h
     ld   (0800Ch), hl 
     ld   a, 05h
     call _putmap
     ld   a, 0Dh
     ld   (0800Dh), a  
     ld   a, 0CFh
     call _putmap
     call _OP1TOOP5
     ld   b, 08h

Label14:
     ld   h, 04h
     ld   a, 08h
     sub  b       
     ld   l, a    
     ld   (0800Ch), hl 
     ld   hl, 0803Ah
     call _puts
     push bc      
     call Label11
     pop  bc      
     jp   c, Label13
     djnz Label14

Label13:
     call Label3
     cp   0Fh
     jp   z, Label10
     cp   04h
     jp   z, Label15
     cp   01h
     jp   z, Label16
     cp   09h
     jp   nz, Label13
     call _OP5TOOP1

Label87:
     call Label17

Label54:
     call Label18
     ld   hl, __bank_ret
     ld   (08252h), hl 

Label26:
     ld   a, (08253h)  
     ld   b, a    
     ld   a, 3Fh
     sub  b       
     ld   c, a    
     sub  05h
     ld   e, a    
     ld   h, 02h
     ld   a, (08252h)  
     ld   b, a    
     ld   d, a    
     call _ILINE
     ld   b, 28h
     res  2, (iy+12h)

Label25:
     ld   a, b    
     ld   (08592h), a  
     ld   b, 0FFh

Label24:
     push af      
     pop  af      
     call _getcsc
     bit  4, (iy+09h)
     jp   nz, Label19
     cp   01h
     jp   z, Label20
     cp   02h
     jp   z, Label21
     cp   03h
     jp   z, Label22
     cp   04h
     jp   z, Label23
     cp   0Fh
     jp   z, Label19
     djnz Label24
     ld   a, (08592h)  
     ld   b, a    
     djnz Label25
     jp   Label26

Label4:
     bit  0, (iy+21h)
     jp   z, Label10
     ld   a, (085A1h)  
     ld   (iy+05h), a
     call _GRBUFCPY
     jp   Label26

Label79:
     set  2, (iy+21h)
     ret          

Label23:
     bit  2, (iy+21h)
     jp   nz, Label26
     ld   a, (08252h)  
     push af      
     call Label27
     pop  af      
     ld   (08252h), a  
     ld   hl, (0859Bh) 
     ld   (0859Dh), hl 
     ld   a, (iy+05h)
     ld   (085A2h), a  
     call Label28
     jp   c, Label29
     ld   b, 02h

Label33:
     push bc      
     ld   a, (hl) 
     cp   0D6h
     jp   z, Label30
     cp   0FFh
     jp   z, Label31
     call Label28
     jp   c, Label32
     jp   Label33

Label32:
     pop  bc      
     ld   a, b    
     cp   02h
     jp   z, Label29
     ld   b, 00h
     jp   Label34

Label31:
     pop  bc      
     ld   a, b    
     cp   02h
     jp   z, Label35
     push bc      

Label30:
     pop  bc      
     call Label28
     jp   c, Label32
     djnz Label33
     call Label36
     ld   a, (08252h)  
     and  a       
     jp   z, Label37

Label39:
     call Label36
     jp   c, Label34
     ld   a, (hl) 
     cp   0D6h
     jp   z, Label34
     cp   0FFh
     jp   z, Label34
     call Label38
     ld   c, a    
     ld   a, b    
     add  a, c    
     ld   b, a    
     push bc      
     ld   a, 0FFh
     sub  b       
     ld   b, a    
     ld   a, (08252h)  
     add  a, b    
     pop  bc      
     jp   nc, Label37
     jp   Label39

Label37:
     ld   a, b    
     ld   (08252h), a  
     ld   a, (08253h)  
     sub  06h
     ld   (08253h), a  
     call Label36
     jp   Label26

Label34:
     ld   a, b    
     ld   (08252h), a  
     ld   a, (08253h)  
     sub  06h
     ld   (08253h), a  
     jp   Label26

Label20:
     bit  2, (iy+21h)
     jp   nz, Label26
     ld   a, (08252h)  
     push af      
     call Label27
     pop  af      
     ld   (08252h), a  
     ld   hl, (0859Bh) 
     ld   (0859Dh), hl 
     ld   a, (iy+05h)
     ld   (085A2h), a  

Label42:
     ld   a, (hl) 
     cp   0D6h
     jp   z, Label40
     cp   0FFh
     jp   z, Label41
     call Label36
     jp   nc, Label42

Label29:
     ld   hl, (0859Dh) 
     ld   (0859Bh), hl 
     ld   a, (085A2h)  
     ld   (iy+05h), a
     jp   Label26

Label40:
     ld   b, 00h
     ld   a, (08252h)  
     and  a       
     jp   z, Label43

Label45:
     call Label36
     jp   c, Label44
     ld   a, (hl) 
     cp   0D6h
     jp   z, Label44
     cp   0FFh
     jp   z, Label44
     call Label38
     ld   c, a    
     ld   a, b    
     add  a, c    
     ld   b, a    
     push bc      
     ld   a, 0FFh
     sub  b       
     ld   b, a    
     ld   a, (08252h)  
     add  a, b    
     pop  bc      
     jp   nc, Label43
     jp   Label45

Label43:
     ld   a, b    
     ld   (08252h), a  
     ld   a, (08253h)  
     add  a, 06h
     ld   (08253h), a  
     call Label36
     jp   Label26

Label44:
     ld   a, b    
     ld   (08252h), a  
     ld   a, (08253h)  
     add  a, 06h
     ld   (08253h), a  
     jp   Label26

Label21:
     bit  2, (iy+21h)
     jp   nz, Label26
     ld   a, (08252h)  
     push af      
     call Label27
     pop  af      
     ld   (08252h), a  
     call Label28
     jp   c, Label26
     ld   a, (hl) 
     cp   0D6h
     jp   z, Label46
     cp   0FFh
     jp   z, Label35
     call Label38
     ld   b, a    
     ld   a, (08252h)  
     sub  b       
     ld   (08252h), a  
     jp   Label26

Label35:
     ld   hl, (0859Bh) 
     push hl      
     ld   a, (iy+05h)
     push af      

Label48:
     call Label28
     jp   c, Label47
     ld   a, (hl) 
     cp   0FFh
     jr   nz, Label48
     call Label36

Label47:
     call Label18
     pop  af      
     pop  hl      
     ld   (0859Bh), hl 
     push hl      
     push af      
     xor  a       
     ld   (08252h), a  
     jp   Label49

Label46:
     pop  af      
     ld   a, (08253h)  
     sub  06h
     ld   (08253h), a  
     ld   hl, (0859Bh) 
     push hl      
     ld   a, (iy+05h)
     push af      
     xor  a       
     ld   (08252h), a  

Label49:
     call Label28
     jp   c, Label50
     ld   a, (hl) 
     cp   0D6h
     jp   z, Label50
     cp   0FFh
     jp   z, Label50
     call Label38
     ld   b, a    
     ld   a, (08252h)  
     add  a, b    
     ld   (08252h), a  
     jp   Label49

Label50:
     pop  af      
     ld   (iy+05h), a
     pop  hl      
     ld   (0859Bh), hl 
     jp   Label26

Label22:
     bit  2, (iy+21h)
     jp   nz, Label26
     call Label51
     jp   c, Label26
     ld   hl, (0859Bh) 
     ld   a, (hl) 
     cp   0D6h
     jr   z, Label52
     cp   0FFh
     jp   z, Label41
     call _vputmap
     call _GRBUFCPY
     call Label36
     jp   Label26

Label52:
     ld   a, (08253h)  
     add  a, 06h
     cp   3Ch
     jp   z, Label26
     push af      
     call Label53
     call _GRBUFCPY
     pop  af      
     ld   (08253h), a  
     xor  a       
     ld   (08252h), a  
     call Label36
     jp   Label26

Label41:
     call Label36
     jp   Label54

Label19:
     ld   a, (iy+05h)
     ld   (085A1h), a  
     res  3, (iy+05h)
     jp   Label10

Label51:
     set  0, (iy+23h)
     jr   Label55

Label36:
     res  0, (iy+23h)

Label55:
     ld   hl, (0859Bh) 
     ld   (0859Fh), hl 
     ld   a, (iy+05h)
     ld   (085A1h), a  

Label73:
     call Label56
     ret  c       
     ld   a, (hl) 
     cp   0F9h
     jp   z, Label57
     cp   0FAh
     jp   z, Label58
     cp   0FBh
     jp   z, Label59
     cp   0FCh
     jp   z, Label60
     cp   0FDh
     jp   z, Label61
     bit  0, (iy+23h)
     jp   nz, Label62
     jp   Label63
     set  0, (iy+23h)
     jr   Label64

Label28:
     res  0, (iy+23h)

Label64:
     ld   hl, (0859Bh) 
     ld   (0859Fh), hl 
     ld   a, (iy+05h)
     ld   (085A1h), a  

Label75:
     call Label65
     ret  c       
     ld   a, (hl) 
     cp   0F9h
     jp   z, Label66
     cp   0FAh
     jp   z, Label67
     cp   0FBh
     jp   z, Label68
     cp   0FCh
     jp   z, Label69
     cp   0FDh
     jp   z, Label70
     bit  0, (iy+23h)
     jp   nz, Label62

Label63:
     ld   hl, (0859Fh) 
     ld   (0859Bh), hl 
     ld   a, (085A1h)  
     ld   (iy+05h), a
     jp   Label62

Label56:
     ld   hl, (08096h) 
     ex   de, hl  
     ld   hl, (0859Fh) 
     inc  hl      
     call _cphlde
     jp   z, Label71
     ld   (0859Fh), hl 
     jp   Label62

Label65:
     ld   hl, (08094h) 
     ex   de, hl  
     ld   hl, (0859Fh) 
     dec  hl      
     call _cphlde
     jp   z, Label71
     ld   (0859Fh), hl 
     jp   Label62

Label57:
     ld   b, 03h
     jp   Label72

Label58:
     ld   b, 05h

Label72:
     call Label56
     ret  c       
     djnz Label72
     jp   Label73

Label66:
     ld   b, 03h
     jp   Label74

Label67:
     ld   b, 05h

Label74:
     call Label65
     ret  c       
     djnz Label74
     jp   Label75

Label59:
     call Label57
     ret  c       
     ld   a, (hl) 
     ld   l, a    
     ld   h, 00h
     ld   a, 08h
     call _divHLbyA
     push hl      
     call Label56
     ret  c       
     ld   a, (hl) 
     pop  hl      
     ld   h, a    
     call _HTIMESL
     ld   de, __bank_ret

Label76:
     exx          
     call Label56
     ret  c       
     exx          
     dec  hl      
     call _cphlde
     jp   nz, Label76
     jp   Label57

Label68:
     call Label65
     ret  c       
     ld   a, (hl) 
     ld   c, a    
     call Label65
     ret  c       
     ld   a, (hl) 
     ld   b, a    

Label77:
     call Label65
     ret  c       
     dec  bc      
     ld   d, b    
     ld   e, c    
     ld   hl, __bank_ret
     call _cphlde
     jr   nz, Label77
     jp   Label67

Label60:
     call Label56
     ret  c       
     ld   a, (hl) 
     cp   0FCh
     jp   nz, Label60
     jp   Label73

Label69:
     call Label65
     ret  c       
     ld   a, (hl) 
     cp   0FCh
     jp   nz, Label69
     jp   Label75

Label61:
     ld   a, (085A1h)  
     xor  08h
     ld   (085A1h), a  
     jp   Label73

Label70:
     ld   a, (085A1h)  
     xor  08h
     ld   (085A1h), a  
     jp   Label75

Label27:
     ld   hl, (0859Bh) 
     ld   a, (hl) 
     cp   0D6h
     jp   z, Label53
     cp   0FFh
     jp   z, Label53
     call _vputmap
     jp   Label78

Label53:
     ld   a, (iy+05h)
     push af      
     res  3, (iy+05h)
     call _VPUTBLANK
     pop  af      
     ld   (iy+05h), a

Label78:
     call _GRBUFCPY
     ret          

Label71:
     scf          
     ld   hl, (0859Bh) 
     ret          

Label38:
     exx          
     ld   l, a    
     ld   h, 08h
     call _HTIMESL
     call _SFONT_LEN
     ld   a, b    
     exx          
     ret          

Label17:
     res  2, (iy+21h)
     set  1, (iy+21h)
     set  0, (iy+21h)
     call _CHKFINDSYM
     ld   a, (de) 
     ld   l, a    
     inc  de      
     ld   a, (de) 
     ld   h, a    
     push de      
     ld   de, 0003h
     call _cphlde
     call z, Label79
     pop  de      
     ld   b, 03h

Label80:
     inc  de      
     djnz Label80
     ld   a, (de) 
     ld   (iy+22h), a
     xor  a       
     call _EDITPROG
     ld   hl, (08094h) 
     ld   (0859Bh), hl 
     ex   de, hl  
     call Label36
     ret          

Label18:
     ld   hl, __bank_ret
     ld   (08252h), hl 
     call _GRBUFCLR
     ld   hl, (0859Bh) 
     ld   (0859Dh), hl 
     dec  hl      
     ld   (0859Bh), hl 
     ld   a, (iy+05h)
     ld   (085A2h), a  

Label83:
     call Label36
     jp   c, Label81
     ld   a, (hl) 
     cp   0D6h
     jp   z, Label82
     cp   0FFh
     jp   z, Label81
     call _vputmap
     jp   Label83

Label82:
     ld   a, (08253h)  
     add  a, 06h
     cp   3Ch
     jp   z, Label81
     ld   (08253h), a  
     xor  a       
     ld   (08252h), a  
     jp   Label83

Label81:
     call _GRBUFCPY
     ld   hl, (0859Dh) 
     ld   (0859Bh), hl 
     ld   a, (085A2h)  
     ld   (iy+05h), a
     ret          

Label15:
     call _OP5TOOP1
     call Label84
     jp   c, Label13
     jp   Label85

Label16:
     call _OP5TOOP1
     call Label11
     jp   c, Label13
     jp   Label85

Label12:
     call _CLRLCDFULL
     ld   hl, 0001h
     ld   (0800Ch), hl 
     ld   hl, Str6
     call _puts
     call Label3
     jp   Label10

Label5:
     bit  1, (iy+21h)
     call z, Label9
     jp   c, Label10
     bit  0, (iy+21h)
     call nz, _CLOSEPROG
     call _ZEROOP1
     xor  a       
     ld   (iy+22h), a
     call Label86
     ld   hl, 0003h
     call _CREATEPROG
     ld   (hl), 06h
     inc  de      
     inc  de      
     ld   a, 0D9h
     ld   (de), a 
     inc  de      
     ld   a, 3Fh
     ld   (de), a 
     inc  de      
     ld   a, (iy+22h)
     ld   (de), a 
     call _OP4TOOP1
     jp   Label87

Label9:
     call _clrScrnFull
     ld   hl, __bank_ret
     ld   (0800Ch), hl 
     ld   hl, Str7
     call _puts
     set  4, (iy+12h)
     set  7, (iy+12h)
     call Label3
     cp   2Ch
     jp   z, Label88
     cp   25h
     jp   z, Label89
     cp   22h
     jp   z, Label89
     scf          
     ret          

Label89:
     call _CLOSEPROG
     res  0, (iy+21h)
     jp   Label62

Label8:
     call _CLOSEPROG
     call _CHKFINDSYM
     ld   a, (de) 
     ld   l, a    
     inc  de      
     ld   a, (de) 
     ld   h, a    
     inc  de      
     push de      
     push hl      
     call Label86
     pop  hl      
     push hl      
     call _CREATEPROG
     exx          
     call _OP4TOOP1
     exx          
     ld   (hl), 06h
     inc  de      
     inc  de      
     pop  bc      
     pop  hl      
     ldir         
     call Label17
     res  3, (iy+05h)
     ld   a, (iy+05h)
     ld   (085A1h), a  
     jp   Label10

Label90:
     inc  de      
     djnz Label90
     xor  a       
     call _EDITPROG
     jp   Label10

Label88:
     call _closeEditBuf
     res  0, (iy+21h)
     jp   Label62

Label86:
     call Label91
     call _clrScrnFull
     ld   hl, 00100h
     ld   (0800Ch), hl 
     ld   hl, Str8
     call _puts
     ld   hl, 00102h
     ld   (0800Ch), hl 
     ld   hl, Str9
     call _puts
     ld   hl, 00203h
     ld   (0800Ch), hl 
     ld   hl, Str10
     call _puts
     ld   hl, 00204h
     ld   (0800Ch), hl 
     ld   hl, Str11
     call _puts
     ld   hl, 00205h
     ld   (0800Ch), hl 
     ld   hl, Str12
     call _puts
     ld   hl, 00206h
     ld   (0800Ch), hl 
     ld   hl, Str13
     call _puts
     ld   hl, 00107h
     ld   (0800Ch), hl 
     ld   hl, Str14
     call _puts
     ld   a, 02h
     ld   (08591h), a  
     ld   hl, 0002h
     ld   (0800Ch), hl 
     ld   a, 05h
     call _putc
     bit  7, (iy+22h)
     call nz, Label92
     bit  6, (iy+22h)
     call nz, Label93
     bit  5, (iy+22h)
     call nz, Label94
     bit  4, (iy+22h)
     call nz, Label95

Label99:
     ld   a, (08591h)  
     cp   02h
     jp   z, Label96
     call Label3
     cp   04h
     jp   z, Label97
     cp   01h
     jp   z, Label98
     cp   09h
     jp   nz, Label99
     ld   a, (08591h)  
     cp   03h
     jp   z, Label100
     cp   04h
     jp   z, Label101
     cp   05h
     jp   z, Label102
     cp   06h
     jp   z, Label103
     cp   07h
     jp   nz, Label99
     ld   a, (0917Dh)  
     cp   20h
     jp   z, Label99
     ld   a, 06h
     ld   (08039h), a  
     call _CHKFINDSYM
     call nc, Label104
     ret          

Label104:
     call _clrScrnFull
     ld   hl, __bank_ret
     ld   (0800Ch), hl 
     ld   hl, Str15
     call _puts
     set  4, (iy+12h)
     set  7, (iy+12h)
     call Label3
     cp   25h
     ret  z       
     cp   22h
     ret  z       
     pop  hl      
     jp   Label86

Label100:
     ld   b, 80h
     jp   Label105

Label101:
     ld   b, 40h
     jp   Label105

Label102:
     ld   b, 20h
     jp   Label105

Label103:
     ld   b, 08h

Label105:
     push af      
     ld   a, (iy+22h)
     xor  b       
     ld   (iy+22h), a
     pop  af      
     ld   b, a    
     ld   hl, 080CAh

Label107:
     push bc      
     ld   b, 10h

Label106:
     inc  hl      
     djnz Label106
     pop  bc      
     djnz Label107
     ld   a, (hl) 
     cp   20h
     jp   z, Label108
     cp   0FFh
     jp   z, Label109

Label108:
     ld   a, 0FFh
     jp   Label110

Label109:
     ld   a, 20h

Label110:
     ld   (hl), a 
     call _RSTRSHADOW
     jp   Label99

Label97:
     ld   a, (08591h)  
     ld   l, a    
     ld   h, 00h
     ld   (0800Ch), hl 
     ld   a, 20h
     call _putmap
     ld   a, (08591h)  
     dec  a       
     ld   (08591h), a  
     ld   (0800Ch), a  
     ld   a, 05h
     call _putmap
     jp   Label99

Label98:
     ld   a, (08591h)  
     cp   07h
     jp   z, Label99
     ld   l, a    
     ld   h, 00h
     ld   (0800Ch), hl 
     ld   a, 20h
     call _putmap
     ld   a, (08591h)  
     inc  a       
     ld   (08591h), a  
     ld   (0800Ch), a  
     ld   a, 05h
     call _putmap
     jp   Label99

Label118:
     ld   a, 0E6h
     jp   Label111

Label117:
     res  1, (iy+23h)
     jp   Label112

Label96:
     call _saveCmdShadow
     call Label91
     call Label113

Label136:
     ld   hl, 0917Dh
     ld   b, 08h

Label116:
     ld   a, (hl) 
     inc  hl      
     add  a, 0A5h
     jp   c, Label114
     sub  0E6h
     add  a, 41h
     jp   c, Label114
     jp   Label115

Label114:
     djnz Label116
     pop  hl      
     jp   Label117

Label115:
     set  1, (iy+23h)

Label112:
     ld   hl, 0917Dh
     ld   de, 080EFh
     ld   bc, 0008h
     ldir         
     ld   hl, (0800Ch) 
     push hl      
     call _RSTRSHADOW
     pop  hl      
     ld   (0800Ch), hl 
     bit  4, (iy+12h)
     jp   nz, Label118

Label132:
     ld   a, 0E4h

Label111:
     call _putmap

Label125:
     call Label119
     cp   0FDh
     jp   z, Label120
     cp   0FEh
     jp   z, Label121
     call Label122
     cp   7Fh
     jp   z, Label123
     bit  4, (iy+12h)
     jp   nz, Label124
     bit  1, (iy+23h)
     jp   z, Label125
     ld   h, 02h
     call Label126
     cp   0FFh
     jp   nz, Label127
     ld   h, 01h
     call Label128
     cp   0FFh
     jp   nz, Label127
     ld   h, 00h
     call Label129
     cp   0FFh
     jp   z, Label125

Label127:
     ld   l, 37h
     cp   0F7h
     jp   z, Label130
     ld   l, 34h
     cp   0FBh
     jp   z, Label130
     ld   l, 31h
     cp   0FDh
     jp   z, Label130
     ld   l, 30h
     cp   0FEh
     jp   nz, Label125
     ld   a, h    
     and  a       
     jp   nz, Label125

Label130:
     ld   a, h    
     add  a, l    
     jp   Label131

Label123:
     ld   a, (iy+12h)
     xor  10h
     ld   (iy+12h), a
     bit  4, (iy+12h)
     jp   nz, Label118
     jp   Label132

Label124:
     ld   h, 04h
     call Label133
     cp   0FFh
     jp   nz, Label134
     ld   h, 03h
     call Label126
     cp   0FFh
     jp   nz, Label134
     ld   h, 02h
     call Label128
     cp   0FFh
     jp   nz, Label134
     ld   h, 01h
     call Label129
     cp   0FFh
     jp   nz, Label134
     ld   h, 00h
     call Label122
     cp   0FFh
     jp   z, Label125

Label134:
     ld   l, 41h
     cp   0BFh
     jp   z, Label135
     ld   l, 44h
     cp   0DFh
     jp   z, Label135
     ld   l, 49h
     cp   0EFh
     jp   z, Label135
     ld   l, 4Eh
     cp   0F7h
     jp   z, Label135
     ld   l, 53h
     cp   0FBh
     jp   z, Label135
     ld   l, 58h
     cp   0FDh
     jp   nz, Label125

Label135:
     ld   de, 00341h
     call _cphlde
     jp   z, Label125
     ld   de, 00441h
     call _cphlde
     jp   z, Label125
     ld   a, h    
     add  a, l    
     cp   5Ch
     jp   z, Label125

Label131:
     ld   b, a    
     ld   hl, 09177h
     ld   a, (0800Dh)  
     cp   0Eh
     jp   z, Label136
     add  a, l    
     ld   l, a    
     ld   (hl), b 
     ld   a, (0800Dh)  
     cp   0Dh
     call nz, Label137
     call z, Label138
     jp   Label136

Label137:
     inc  a       
     ld   (0800Dh), a  
     ret          

Label138:
     call Label137
     ld   a, 0F1h
     call _putmap
     ret          

Label121:
     ld   hl, 0917Dh
     ld   de, 080EFh
     ld   bc, 0009h
     ldir         
     call _RSTRSHADOW
     call Label139
     jp   Label98

Label120:
     ld   a, (0800Dh)  
     cp   06h
     jp   z, Label136
     cp   0Eh
     call z, Label140
     ld   a, (0800Dh)  
     dec  a       
     ld   (0800Dh), a  
     ld   hl, 09177h
     add  a, l    
     ld   l, a    
     ld   (hl), 20h
     jp   Label136

Label140:
     ld   a, 20h
     call _putmap
     ret          

Label92:
     ld   l, 03h
     jp   Label141

Label93:
     ld   l, 04h
     jp   Label141

Label94:
     ld   l, 05h
     jp   Label141

Label95:
     ld   l, 06h

Label141:
     ld   h, 01h
     ld   (0800Ch), hl 
     ld   a, 0FFh
     call _putc
     ret          

Label91:
     ld   hl, 08039h
     ld   de, 0917Ch
     ld   b, 08h

Label143:
     inc  hl      
     inc  de      
     ld   a, (hl) 
     and  a       
     call z, Label142
     ld   (de), a 
     djnz Label143
     ret          

Label142:
     ld   a, 20h
     ret          

Label139:
     call _ZEROOP1
     ld   hl, 0917Ch
     ld   de, 08039h
     ld   b, 08h

Label145:
     inc  hl      
     inc  de      
     ld   a, (hl) 
     cp   20h
     call z, Label144
     ld   (de), a 
     djnz Label145
     ret          

Label144:
     xor  a       
     ret          

Label113:
     ld   hl, 0917Ch
     ld   b, 08h
     ld   c, 05h

Label147:
     inc  hl      
     inc  c       
     ld   a, (hl) 
     cp   20h
     jp   z, Label146
     djnz Label147
     inc  c       
     ld   h, c    
     ld   l, 02h
     ld   (0800Ch), hl 
     ld   a, 0F1h
     call _putmap
     ret          

Label146:
     ld   h, c    
     ld   l, 02h
     ld   (0800Ch), hl 
     ret          

Label11:
     call _OP1TOOP6
     call _FindAlphaup
     ld   bc, Str11
     jp   Label148

Label84:
     call _OP1TOOP6
     call _FindAlphadn
     ld   bc, Str84

Label148:
     exx          
     ex   af, af' 
     ld   b, 0Bh
     ld   hl, 08038h
     ld   de, 0806Fh

Label150:
     inc  hl      
     inc  de      
     ld   a, (hl) 
     ex   de, hl  
     ld   c, (hl) 
     ex   de, hl  
     cp   c       
     jr   nz, Label149
     djnz Label150
     scf          
     ret          

Label149:
     exx          
     ex   af, af' 
     dec  hl      
     ld   e, (hl) 
     dec  hl      
     ld   d, (hl) 
     dec  hl      
     ex   de, hl  
     inc  hl      
     inc  hl      
     ld   a, (hl) 
     cp   0D9h
     jp   nz, Label151
     inc  hl      
     ld   a, (hl) 
     cp   3Fh
     jp   nz, Label151

Label62:
     ld   de, __bank_ret
     push de      
     pop  af      
     ret          

Label151:
     push bc      
     ret          

Label3:
     bit  7, (iy+12h)
     jp   nz, Label152
     bit  6, (iy+12h)
     jp   nz, Label152
     bit  3, (iy+12h)
     jp   nz, Label153
     bit  4, (iy+12h)
     jp   nz, Label152
     ld   a, 20h

Label157:
     ld   hl, 00F00h
     ld   (0800Ch), hl 
     call _putmap

Label154:
     call _getcsc
     and  a       
     jp   z, Label154
     cp   36h
     jp   z, Label155
     cp   30h
     jp   z, Label156
     res  4, (iy+12h)
     res  3, (iy+12h)
     ret          

Label152:
     ld   a, 0E3h
     jp   Label157

Label153:
     ld   a, 0E1h
     jp   Label157

Label155:
     bit  7, (iy+12h)
     jp   nz, Label154
     bit  3, (iy+12h)
     jp   nz, Label158
     set  3, (iy+12h)
     jp   Label3

Label158:
     res  3, (iy+12h)
     jp   Label3

Label156:
     bit  7, (iy+12h)
     jp   nz, Label154
     bit  6, (iy+12h)
     jp   nz, Label159
     bit  4, (iy+12h)
     jp   nz, Label160
     bit  3, (iy+12h)
     jp   nz, Label161
     set  4, (iy+12h)
     jp   Label3

Label161:
     set  6, (iy+12h)
     res  3, (iy+12h)
     res  4, (iy+12h)
     jp   Label3

Label160:
     res  4, (iy+12h)
     jp   Label3

Label159:
     res  6, (iy+12h)
     jp   Label3

Label162:
     ld   a, 0FFh
     out  (01h), a  
     ret          

Label119:
     call Label162
     ld   a, 0FEh
     jp   Label163

Label133:
     call Label162
     ld   a, 0FDh
     jp   Label163

Label126:
     call Label162
     ld   a, 0FBh
     jp   Label163

Label128:
     call Label162
     ld   a, 0F7h
     jp   Label163

Label129:
     call Label162
     ld   a, 0EFh
     jp   Label163

Label122:
     call Label162
     ld   a, 0DFh
     jp   Label163
     call Label162
     ld   a, 0BFh

Label163:
     out  (01h), a  
     in   a, (01h)  
     ret          

Label7:
     bit  1, (iy+21h)
     call z, Label9
     jp   c, Label10
     bit  0, (iy+21h)
     call nz, _CLOSEPROG
     res  7, (iy+14h)
     res  4, (iy+09h)
     ld   sp, (0858Fh) 
     call _GRBUFCLR
     ld   hl, __bank_ret
     ld   (0800Ch), hl 
     ld   a, 20h
     call _putmap
     call _clrScrnFull
     call _CLRTXTSHD
     ret          

Str1:
     .db  0BCh
     .db  " Text editor", 00h

Str2:
     .db  "1: Nieuw", 00h

Str3:
     .db  "2: Openen", 00h

Str5:
     .db  "3: Opslaan als", 00h

Str4:
     .db  "4: Afsluiten", 00h

Str8:
     .db  "Eigenschappen", 00h

Str9:
     .db  "Naam:", 00h

Str10:
     .db  "Wiskunde", 00h

Str11:
     .db  "Natuurkunde", 00h

Str12:
     .db  "Scheikunde", 00h

Str13:
     .db  "Overig", 00h

Str14:
     .db  "Opslaan", 00h

Str15:
     .db  "Bestand bestaat al.           "
     .db  "  Overschrijven?  (J/N)", 00h

Str7:

Label169:
     .db  "Wijzigingen     opslaan? (J/N "
     .db  "  clear=annuleren)", 00h

Str6:
     .db  "Er zijn geen    plugins gevond"
     .db  "en", 00h

 ; Disassembled by Jimmy Conner - timagic@yahoo.com
 ; @ 24-4-2003 21:13:39
 ; Disassembler v1.7
 ; Total Opcodes: 1218
 ; Total Data: 264
 ; Z80 AC   -  z80.us.fornax.com
 ; Personal -  www.timagic.cjb.net
.end
end
