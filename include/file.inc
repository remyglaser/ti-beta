#include include/util.inc

#IFDEF use_file.open
#DEFINE use_file.rom.incpointer
#DEFINE use_file.rom.readinc
file.open:
; input: OP1	filename
; output	none


; Program Symbol Table Entry:
; -14 -13 -12 -11 -10 -9 -8 -7 -6 -5   -4  -3  -2  -1 0
; Name                         NL Page DAH DAL Ver T2 T
; T	Type
; T2	Reserved for future use
; Ver	Version Number
; DAL	Data Structure Least Significant Byte
; DAH	Data Structure Most Significant Byte
; PAGE	ROM Page
; NL	Name file.length

 bcall(_chkfindsym)
 ret c			; program not found
 ld (file.symtableptr),hl
 ex de,hl
; xor a
; ld (op1+9),a		; Sometimes, _chkfindsym loads 5 or 6 into op1+9

#IFDEF TI83P
 ld a,b
; ld (file.start_page),a
; ld (file.current_page),a
 and a
 jr z,file.open.ram


file.open.rom:
 ld a,9
; skip first part of rom-stored symbol table
file.open.skiploop:
 push af
 call file.rom.incpointer
 pop af
 dec a
 jr nz,file.open.skiploop
 call file.rom.readinc
 ld a,c
; skip program name
file.open.skiploop2:
 push af
 call file.rom.incpointer
 pop af
 dec a
 jr nz,file.open.skiploop2
; length low byte
 call file.rom.readinc
 ld e,c
 bcall(_LoadCIndPaged)
; length high byte
 ld d,c
 ld a,b
 ld (file.start_page),a
 ld (file.current_page),a
 jr file.open.finish
#ENDIF

; hl symtable pointer
; de vardata pointer (only in ram)

file.open.ram:
 ld e,(hl)		; file.length low byte
 inc hl
 ld d,(hl)		; file.length high byte

file.open.finish:
 ld (file.start_adress),hl
 ld (file.current_adress),hl
 ex de,hl
 ld (file.length),hl
 ld hl,0
 ld (file.relative_adress),hl
 ret
#ENDIF

#IFDEF TI83P
#IFDEF use_file.rom.readinc
file.rom.readinc:
 bcall(_LoadCIndPaged)
 inc hl
 bit 7,h
 ret z
 inc b
 res 7,h
 set 6,h
 ret
#ENDIF

#IFDEF use_file.rom.incpointer
file.rom.incpointer:
 inc hl
 bit 7,h
 ret z
 inc b
 res 7,h
 set 6,h
 ret
#ENDIF

#IFDEF use_file.rom.decpointer
file.rom.decpointer:
 dec hl
 bit 6,h
 ret nz
 dec b
 set 6,h
 ret
#ENDIF
#ENDIF

#IFDEF use_file.readByte
file.readByte:
; reads one byte from program and advances cursor. Returns carry flag if EOF is reached.
; input		none
; output a	byte

#IFDEF TI83P
 ld a,(file.current_page)
 and a
 jr z,file.read.fromram

file.read.fromrom:
; check maximum length
 ld hl,(file.length)
 ex de,hl
 ld hl,(file.relative_adress)
 bcall(_cphlde)
 jr z,file.read.EOF

; increase adress
 inc hl
 ld (file.relative_adress),hl
 ld hl,(file.current_adress)
 inc hl
 ld a,(file.current_page)

 bit 7,h
 jr z,file.read.samepage
 res 7,h
 set 6,h
 inc a
 ld (file.current_page),a
file.read.samepage
 ld (file.current_adress),hl
 ld b,a
; read byte
 bcall(_LoadCIndPaged)
 ld a,c
 rcf
 ret
#ENDIF

file.read.fromram:
; check maximum length
 ld hl,(file.length)
 ex de,hl
 ld hl,(file.relative_adress)
 bcall(_cphlde)
 jr z,file.read.EOF

; increase adress
 inc hl
 ld (file.relative_adress),hl
 ld hl,(file.current_adress)
 inc hl
 ld (file.current_adress),hl
; read byte
 ld a,(hl)
 rcf
 ret

file.read.EOF
 scf
 ret
#ENDIF

#IFDEF use_file.readByteBackwards
file.readByteBackwards:
; reads one byte from program and decreases cursor. Returns carry flag if BOF is reached.
; input		none
; output a	byte

#IFDEF TI83P
 ld a,(file.current_page)
 and a
 jr z,file.readback.fromram

file.readback.fromrom:
; check maximum length
 ld hl,0
 ex de,hl
 ld hl,(file.relative_adress)
 bcall(_cphlde)
 jr z,file.readback.BOF

; decrease adress
 dec hl
 ld (file.relative_adress),hl
 ld hl,(file.current_adress)
 dec hl
 ld a,(file.current_page)

 bit 6,h
 jr nz,file.readback.samepage
 set 6,h
 dec a
 ld (file.current_page),a
file.readback.samepage
 ld (file.current_adress),hl
 ld b,a
; read byte
 bcall(_LoadCIndPaged)
 ld a,c
 rcf
 ret
#ENDIF

file.readback.fromram:
; check maximum length
 ld hl,0
 ex de,hl
 ld hl,(file.relative_adress)
 bcall(_cphlde)
 jr z,file.readback.BOF

; decrease adress
 dec hl
 ld (file.relative_adress),hl
 ld hl,(file.current_adress)
 dec hl
 ld (file.current_adress),hl
; read byte
 ld a,(hl)
 rcf
 ret

file.readback.BOF
 scf
 ret
#ENDIF


; Ti-83 Symbol Table Structure:
; [=================================================================================]
; |-11 - -4     |-3         |-2                       |-1                      |0   |
; |Variable Name|Name Length|Pointer to data High byte|Pointer to data Low byte|Type|
; [=================================================================================]
;
; Ti-83+ Symbol Table Structure:
; [=====================================================================================================]
; |-14 - -7     |-6         |-5  |-4                       |-3                      |-2     |-1    |0   |
; |Variable Name|Name Length|Page|Pointer to data High byte|Pointer to data Low byte|Version|unused|Type|
; [=====================================================================================================]
; flags:
; bit 0	Object Type
; bit 1	"
; bit 2	"
; bit 3	"
; bit 4	"
; bit 5	Graph equation selected
; bit 6	Variable used during graphing
; bit 7	Link Transfer Flag


#IFDEF use_file.getType
file.getType:
; input none
; output a	Program Type
 ld hl,(file.symtableptr)
 ld a,(hl)
 and $1F
 ret
#ENDIF

#IFDEF TI83P
#IFDEF use_file.getVersion
file.getVersion:
 ld hl,(file.symtableptr)
 dec hl
 dec hl
 ld a,(hl)
 ret
#ENDIF
#ENDIF

#IFDEF use_file.protect
#DEFINE use_file.getType
file.protect:
 call file.getType
 and %11100000		; preserve misc flags
 or 6			; protect
 ld (hl),a
 ret
#ENDIF

#IFDEF use_file.unprotect
#DEFINE use_file.getType
file.unprotect:
 call file.getType
 and %11100000		; preserve misc flags
 or 5			; unprotect
 ld (hl),a
 ret
#ENDIF

#IFDEF use_file.getName
#DEFINE use_util.subHLbyDE
file.getName:
 bcall(_ZerooOP1)
 ld hl,(file.symtableptr)
 ld a,(hl)
 ld (op1),a
#IFDEF TI83P
 ld de,6
#ENDIF
#IFDEF TI83
 ld de,3
#ENDIF
 call util.subHLbyDE
 ld b,(hl)
 ld de,op1+1
file.getName.loop:
 ld a,(hl)
 ld (de),a
 dec hl
 inc de
 djnz file.getName.loop
 ret
#ENDIF

#IFDEF use_file.skip
#DEFINE use_file.rom.incpointer
file.skip
; input hl	number of bytes to skip
; output	none
 push hl
 ex de,hl
 ld hl,(file.relative_adress)
 add hl,de
 ex de,hl
 ld hl,(file.length)
 bcall(_cphlde)
 jr c,file.skip.EOF
 ex de,hl
 ld (file.relative_adress),hl
 ex de,hl
 pop hl
#IFDEF TI83P
 ld a,(file.current_page)
 and a
 jr z,file.skip.ram

file.skip.rom:
 ld b,a
 ex de,hl
 ld hl,(file.current_adress)
 push hl
file.skip.rom_loop:
 pop hl
 call file.rom.incpointer
 push hl
 dec de
 ld hl,0
 bcall(_cphlde)
 jr nz,file.skip.rom_loop
 pop hl
 ld (file.current_adress),hl
 ret
#ENDIF

file.skip.ram:
 ld hl,(file.current_adress)
 add hl,de
 ld (file.current_adress),hl
 ret

file.skip.EOF:
 pop hl
 ret
#ENDIF

#IFDEF use_file.skipBackwards
#DEFINE use_util.subHLbyDE
#DEFINE use_file.rom.decpointer
file.skipBackwards
; input hl	number of bytes to skip
; output	none
 push hl
 ex de,hl
 ld hl,(file.relative_adress)
 call util.SubHLbyDE
 jr c,file.skipback.BOF
 ld (file.relative_adress),hl
 ex de,hl
 pop hl
#IFDEF TI83P
 ld a,(file.current_page)
 and a
 jr z,file.skipback.ram

file.skipback.rom:
 ld b,a
 ex de,hl
 ld hl,(file.current_adress)
 push hl
file.skipback.rom_loop:
 pop hl
 call file.rom.decpointer
 push hl
 dec de
 ld hl,0
 bcall(_cphlde)
 jr nz,file.skipback.rom_loop
 pop hl
 ld (file.current_adress),hl
 ret
#ENDIF

file.skipback.ram:
 ld hl,(file.current_adress)
 call util.SubHLbyDE
 ld (file.current_adress),hl
 ret

file.skipback.BOF:
 pop hl
 ret
#ENDIF

file.symtableptr
 .db 0,0
file.start_adress:
 .db 0,0
file.current_adress:
 .db 0,0
file.relative_adress:
 .db 0,0
file.length:
 .db 0,0

#IFDEF TI83P
file.start_page:
 .db 0
file.current_page:
 .db 0
#ENDIF

.end
END
