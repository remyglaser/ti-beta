#define equ .equ
#define EQU .equ
#define end .end
#define END .end

;;;;;;;;;;;;
;; Macros ;;
;;;;;;;;;;;;

#define rcf scf \ ccf

#define bjump(xxxx)	jp xxxx
#define bjumpz(xxxx)	jp z,xxxx
#define bjumpnz(xxxx)	jp nz,xxxx
#define bjumpc(xxxx)	jp c,xxxx
#define bjumpnc(xxxx)	jp nc,xxxx

#define bcall(xxxx)     call xxxx
#define	bcallz(xxxx)	call z,xxxx
#define	bcallnz(xxxx)	call nz,xxxx
#define	bcallc(xxxx)	call c,xxxx
#define	bcallnc(xxxx)	call nc,xxxx

#define equ .equ
#define EQU .equ
#define end .end
#define END .end

#define Locate(yy,xx)		ld hl,xx-1*256+yy-1	\ ld (currow),hl
#define vLocate(yy,xx)		ld hl,xx*256+yy		\ ld (pencol),hl

#define Output(yy,xx,zzzz)	ld hl,xx-1*256+yy-1	\ ld (currow),hl	\ ld hl,zzzz	\ bcall(_puts)
#define Put(yy,xx,zz)		ld hl,xx-1*256+yy-1	\ ld (currow),hl	\ ld a,zz	\ bcall(_putc)
#define Text(yy,xx,zzzz)	ld hl,xx*256+yy		\ ld (pencol),hl	\ ld hl,zzzz	\ bcall(_vputs)
#define Txt(yy,xx,zz)		ld hl,xx*256+yy		\ ld (pencol),hl	\ ld a,zz	\ bcall(_vputmap)

#define LineOn			ld h,1
#define LineOff			ld h,0
#define LineChange		ld h,2
#define Line(aa,bb,cc,dd)	ld bc,aa*256+(63-bb)	\ ld de,cc*256+(63-dd)	\ bcall(_iline)

#define PixelOn(xx,yy)		ld bc,xx*256+yy	\ ld d,1
#define PixelOff(xx,yy)		ld bc,xx*256+yy	\ ld d,0
#define PixelChange(xx,yy)	ld bc,xx*256+yy	\ ld d,2
#define PixelTest(xx,yy)	ld bc,xx*256+yy	\ ld d,3

;;;;;;;;;;;;;;;;;;;;;
;; System Routines ;;
;;;;;;;;;;;;;;;;;;;;;
__bank_ret              equ     0000h
__bank_call             equ     0000h
__bank_entry            equ     0000h
__bank_jump             equ     0000h
_ldHLind                equ     4000h
_cphlde                 equ     4004h
_divHLby10              equ     4008h
_divHLbyA               equ     400Ch
_kbdScan                equ     4010h
_getcsc                 equ     4014h
_coorMon                equ     4018h
_mon                    equ     401Bh
_monForceKey            equ     401Eh
_sendKPress             equ     4021h
_JforceCmdNoChaR        equ     4024h
_JforceCmd              equ     4027h
_sysErrHandler          equ     402Ah
_newContext             equ     402Eh
_newContext0            equ     4032h
_A2POINTHLIND           equ     4036h
_POINTHLIND             equ     403Ah
_PPutAwayPrompt         equ     403Eh
_PPutAway               equ     4042h
_PutAway                equ     4046h
_SizeWind               equ     404Ah
_ErrorEP                equ     404Eh
_callMain               equ     4052h
_monErrHand             equ     4056h
_appInit                equ     405Ah
_appInitIfDec           equ     405Eh
_initialize             equ     4062h
_lcd_busy               equ     4066h
_MIN                    equ     406Ah
_MAX                    equ     406Eh
_ABSO1PABSO2            equ     4072h
_INTGR                  equ     4076h
_TRUNC                  equ     407Ah
_INVSUB                 equ     407Eh
_TIMES2                 equ     4082h
_PLUS1                  equ     4086h
_MINUS1                 equ     408Ah
_FPSUB                  equ     408Eh
_FPADD                  equ     4092h
_DTOR                   equ     4096h
_RTOD                   equ     409Ah
_CUBE                   equ     409Eh
_TIMESPT5               equ     40A2h
_FPSQUARE               equ     40A6h
_FPMULT                 equ     40AAh
_LJRND                  equ     40AEh
_INVOP1SC               equ     40B2h
_INVOP1S                equ     40B6h
_INVOP2S                equ     40BAh
_FRAC                   equ     40BEh
_FPRECIP                equ     40C2h
_FPDIV                  equ     40C6h
_SQROOT                 equ     40CAh
_RNDGUARD               equ     40CEh
_RNFX                   equ     40D2h
_INT                    equ     40D6h
_ROUND                  equ     40DAh
_LNX                    equ     40DEh
_LOGX                   equ     40E2h
_LJNORND                equ     40E6h
_ETOX                   equ     40EAh
_TENX                   equ     40EEh
_SINCOSRAD              equ     40F2h
_SIN                    equ     40F6h
_COS                    equ     40FAh
_TAN                    equ     40FEh
_SINHCOSH               equ     4102h
_TANH                   equ     4106h
_COSH                   equ     410Ah
_SINH                   equ     410Eh
_ACOSRAD                equ     4112h
_ATANRAD                equ     4116h
_ATAN2RAD               equ     411Ah
_ASINRAD                equ     411Eh
_ACOS                   equ     4122h
_ATAN                   equ     4126h
_ASIN                   equ     412Ah
_ATAN2                  equ     412Eh
_ATANH                  equ     4132h
_ASINH                  equ     4136h
_ACOSH                  equ     413Ah
_PTOR                   equ     413Eh
_RTOP                   equ     4142h
_HLTIMES9               equ     4146h
_CKOP1CPLX              equ     414Ah
_CKOP1REAL              equ     414Eh
_ANGLE                  equ     4152h
_COP1SET0               equ     4156h
_CPOP4OP3               equ     415Ah
_MOV9OP2CP              equ     415Eh
_ABSO1O2CP              equ     4162h
_CPOP1OP2               equ     4166h
_OP3TOOP4               equ     416Ah
_OP1TOOP4               equ     416Eh
_OP2TOOP4               equ     4172h
_OP4TOOP2               equ     4176h
_OP3TOOP2               equ     417Ah
_OP1TOOP3               equ     417Eh
_OP5TOOP2               equ     4182h
_OP5TOOP6               equ     4186h
_OP5TOOP4               equ     418Ah
_OP1TOOP2               equ     418Eh
_OP6TOOP2               equ     4192h
_OP6TOOP1               equ     4196h
_OP4TOOP1               equ     419Ah
_OP5TOOP1               equ     419Eh
_OP3TOOP1               equ     41A2h
_OP6TOOP5               equ     41A6h
_OP4TOOP5               equ     41AAh
_OP3TOOP5               equ     41AEh
_OP2TOOP5               equ     41B2h
_OP2TOOP6               equ     41B6h
_OP1TOOP6               equ     41BAh
_OP1TOOP5               equ     41BEh
_OP2TOOP1               equ     41C2h
_MOVREG                 equ     41C6h
_MOV10B                 equ     41CAh
_MOV9B                  equ     41CEh
_MOV18                  equ     41D2h
_MOV8B                  equ     41D6h
_MOV7B                  equ     41DAh
_MOV14                  equ     41DEh
_MOV6B                  equ     41E2h
_MOV5B                  equ     41E6h
_MOV4B                  equ     41EAh
_MOV3B                  equ     41EEh
_MOV2B                  equ     41F2h
_OP2TOOP3               equ     41F6h
_OP4TOOP3               equ     41FAh
_OP5TOOP3               equ     41FEh
_OP4TOOP6               equ     4202h
_MOV9TOOP1              equ     4206h
_MOV9OP1OP2             equ     420Ah
_MOV9TOOP2              equ     420Eh
_MOVFROP1               equ     4212h
_OP4SET1                equ     4216h
_OP3SET1                equ     421Ah
_OP2SET8                equ     421Eh
_OP2SET5                equ     4222h
_OP2SETA                equ     4226h
_OP2SET4                equ     422Ah
_OP2SET3                equ     422Eh
_OP1SET1                equ     4232h
_OP1SET4                equ     4236h
_OP1SET3                equ     423Ah
_OP3SET2                equ     423Eh
_OP1SET2                equ     4242h
_OP2SET2                equ     4246h
_SETNUM2                equ     424Ah
_SETMANT1               equ     424Eh
_OP2SET1                equ     4252h
_SETNUM1                equ     4256h
_SETNUM                 equ     425Ah
_SETNUMA                equ     425Eh
_SETMANT                equ     4262h
_ZERO16D                equ     4266h
_SET16A                 equ     426Ah
_SET14A                 equ     426Eh
_SET14D                 equ     4272h
_OP5SET0                equ     4276h
_OP4SET0                equ     427Ah
_OP3SET0                equ     427Eh
_OP2SET0                equ     4282h
_OP1SET0                equ     4286h
_SETNUM0                equ     428Ah
_ZEROOP1                equ     428Eh
_ZEROOOP1               equ     428Eh
_ZEROOP2                equ     4292h
_ZEROOP3                equ     4296h
_ZEROOP                 equ     429Ah
_CLRLP                  equ     429Eh
_SHRACC                 equ     42A2h
_SHLACC                 equ     42A6h
_SHR18                  equ     42AAh
_SHR18A                 equ     42AEh
_SHR16                  equ     42B2h
_SHR14                  equ     42B6h
_SHL16                  equ     42BAh
_SHL14                  equ     42BEh
_SRDO1                  equ     42C2h
_SHRDRND                equ     42C6h
_MANTPA                 equ     42CAh
_ADDPROP                equ     42CEh
_ADDPROPLP              equ     42D2h
_ADD16D                 equ     42D6h
_ADD14D                 equ     42DAh
_SUB16D                 equ     42DEh
_SUB14D                 equ     42E2h
_OP2EXOP6               equ     42E6h
_OP5EXOP6               equ     42EAh
_OP1EXOP5               equ     42EEh
_OP1EXOP6               equ     42F2h
_OP2EXOP4               equ     42F6h
_OP2EXOP5               equ     42FAh
_OP1EXOP3               equ     42FEh
_OP1EXOP4               equ     4302h
_OP1EXOP2               equ     4306h
_EXLP                   equ     430Ah
_CKOP1C0                equ     430Eh
_CKOP1FP0               equ     4312h
_CKOP2FP0               equ     4316h
_POSNO0INT              equ     431Ah
_CKPOSINT               equ     431Eh
_CKINT                  equ     4322h
_CKODD                  equ     4326h
_CKOP1M                 equ     432Ah
_GETCON1                equ     432Eh
_GETCON                 equ     4332h
_PIDIV2                 equ     4336h
_PIDIV4                 equ     433Ah
_TWOPI                  equ     433Eh
_PICON                  equ     4342h
_PIDIV4A                equ     4346h
_PIDIV2A                equ     434Ah
_EXPTOHEX               equ     434Eh
_OP1EXPTODEC            equ     4352h
_CKOP2POS               equ     4356h
_CKOP1POS               equ     435Ah
_CLROP2S                equ     435Eh
_CLROP1S                equ     4362h
_FDIV100                equ     4366h
_FDIV10                 equ     436Ah
_DECO1EXP               equ     436Eh
_INCO1EXP               equ     4372h
_INCEXP                 equ     4376h
_CKVALIDNUM             equ     437Ah
_GETEXP                 equ     437Eh
_HTIMESL                equ     4382h
_EOP1NOTREAL            equ     4386h
_THETANAME              equ     438Ah
_RNAME                  equ     438Eh
_REGEQNAME              equ     4392h
_RECURNNAME             equ     4396h
_XNAME                  equ     439Ah
_YNAME                  equ     439Eh
_TNAME                  equ     43A2h
_REALNAME               equ     43A6h
_SETesTOfps             equ     43AAh
_CHKTEMPDIRT            equ     43AEh
_OP1MOP2EXP             equ     43B2h
_OP1EXPMDE              equ     43B6h
_CHKERRBREAK            equ     43BAh
_ISA2BYTETOK            equ     43BEh
_GETLASTENTRY           equ     43C2h
_GETLASTENTRYPTR        equ     43C6h
_REGRCLRCHNG            equ     43CAh
_RESETWINTOP            equ     43CEh
_SETYUP                 equ     43D2h
_SETXUP                 equ     43D6h
_ISO1NONTLSTorPROG      equ     43DAh
_ISO1NONTEMPLST         equ     43DEh
_IS_A_LSTorCLST         equ     43E2h
_CHK_HL_999             equ     43E6h
_EQU_or_NEWEQU          equ     43EAh
_GET_PLUS1_SAVE         equ     43EEh
_ERRD_OP1NOTPOS         equ     43F2h
_ERRD_OP1NOT_R          equ     43F6h
_ERRD_OP1NOTPOSINT      equ     43FAh
_ERRD_OP1_LE_0          equ     43FEh
_ERRD_OP1_0             equ     4402h
_FINDSYM_GET_SIZE       equ     4406h
_STO_STATVAR            equ     440Ah
_RCL_STATVAR            equ     440Eh
_CKOP2REAL              equ     4412h
_GET_X_INDIRECT         equ     4416h
_MEMCHK                 equ     441Ah
_freemem                equ     441Ah
_memfree                equ     441Ah
_CMPPRGNAMLEN1          equ     441Eh
_CMPPRGNAMLEN           equ     4422h
_FINDPROGSYM            equ     4426h
_CHKFINDSYM             equ     442Ah
_FINDSYM                equ     442Eh
_INSERTMEM              equ     4432h
_INSERTMEMA             equ     4436h
_ENOUGHMEM              equ     443Ah
_CMPMEMNEED             equ     443Eh
_CREATEPVAR4            equ     4442h
_CREATEPVAR3            equ     4446h
_CREATEVAR3             equ     444Ah
_CREATECPLX             equ     444Eh
_CREATEREAL             equ     4452h
_CREATETRLIST           equ     4456h
_CREATERLIST            equ     445Ah
_CREATETCLIST           equ     445Eh
_CREATECLIST            equ     4462h
_CREATETRMAT            equ     4466h
_CREATERMAT             equ     446Ah
_CREATETSTRNG           equ     446Eh
_CREATESTRNG            equ     4472h
_CREATE0                equ     4476h
_CREATET                equ     447Ah
_CREATE                 equ     447Eh
_CREATEPICT             equ     4482h
_CREATEGDB              equ     4486h
_CREATEPROG             equ     448Ah
_CHKDEL                 equ     448Eh
_CHKDELA                equ     4492h
_ADJPARSER              equ     4496h
_ADJMATH                equ     449Ah
_ADJM7                  equ     449Eh
_DELMEMA                equ     44A2h
_GET_FORM_NUM           equ     44A6h
_DELVAR                 equ     44AAh
_DELVARIO               equ     44AEh
_DELMEM                 equ     44B2h
_DELVAR3D               equ     44B6h
_DELVAR3C               equ     44BAh
_DELVAR3DC              equ     44BEh
_SYM_PROG_NON_T_LST     equ     44C2h
_ADJSYMPTRS             equ     44C6h
_DATASIZEA              equ     44CAh
_DATASIZE               equ     44CEh
_POPMCPLXO1             equ     44D2h
_POPMCPLX               equ     44D6h
_MOVCPLX                equ     44DAh
_POPOP5                 equ     44DEh
_POPOP3                 equ     44E2h
_POPOP1                 equ     44E6h
_POPREALO6              equ     44EAh
_POPREALO5              equ     44EEh
_POPREALO4              equ     44F2h
_POPREALO3              equ     44F6h
_POPREALO2              equ     44FAh
_POPREALO1              equ     44FEh
_POPREAL                equ     4502h
_FPOPCPLX               equ     4506h
_FPOPREAL               equ     450Ah
_FPOPFPS                equ     450Eh
_DEALLOCFPS             equ     4512h
_DEALLOCFPS1            equ     4516h
_ALLOCFPS               equ     451Ah
_ALLOCFPS1              equ     451Eh
_PUSHREALO6             equ     4522h
_PUSHREALO5             equ     4526h
_PUSHREALO4             equ     452Ah
_PUSHREALO3             equ     452Eh
_PUSHREALO2             equ     4532h
_PUSHREALO1             equ     4536h
_PUSHREAL               equ     453Ah
_PUSHOP5                equ     453Eh
_PUSHOP3                equ     4542h
_PUSHMCPLXO3            equ     4546h
_PUSHOP1                equ     454Ah
_PUSHMCPLXO1            equ     454Eh
_PUSHMCPLX              equ     4552h
_EXMCPLXO1              equ     4556h
_EXCH9                  equ     455Ah
_CPYTO1FPS11            equ     455Eh
_CPYTO2FPS5             equ     4562h
_CPYTO1FPS5             equ     4566h
_CPYTO2FPS6             equ     456Ah
_CPYTO1FPS6             equ     456Eh
_CPYTO2FPS7             equ     4572h
_CPYTO1FPS7             equ     4576h
_CPYTO1FPS8             equ     457Ah
_CPYTO2FPS8             equ     457Eh
_CPYTO1FPS10            equ     4582h
_CPYTO1FPS9             equ     4586h
_CPYTO2FPS4             equ     458Ah
_CPYTO6FPS3             equ     458Eh
_CPYTO6FPS2             equ     4592h
_CPYTO2FPS3             equ     4596h
_CPYCTO1FPS3            equ     459Ah
_CPYTO1FPS3             equ     459Eh
_CPYFPS3                equ     45A2h
_CPYTO1FPS4             equ     45A6h
_CPYTO3FPS2             equ     45AAh
_CPYTO5FPST             equ     45AEh
_CPYTO6FPST             equ     45B2h
_CPYTO4FPST             equ     45B6h
_CPYTO3FPST             equ     45BAh
_CPYTO2FPST             equ     45BEh
_CPYTO1FPST             equ     45C2h
_CPYFPST                equ     45C6h
_CPYSTACK               equ     45CAh
_CPYTO3FPS1             equ     45CEh
_CPYTO2FPS1             equ     45D2h
_CPYTO1FPS1             equ     45D6h
_CPYFPS1                equ     45DAh
_CPYTO2FPS2             equ     45DEh
_CPYTO1FPS2             equ     45E2h
_CPYFPS2                equ     45E6h
_CPYO3TOFPST            equ     45EAh
_CPYO2TOFPST            equ     45EEh
_CPYO6TOFPST            equ     45F2h
_CPYO1TOFPST            equ     45F6h
_CPYTOFPST              equ     45FAh
_CPYTOSTACK             equ     45FEh
_CPYO3TOFPS1            equ     4602h
_CPYO5TOFPS1            equ     4606h
_CPYO2TOFPS1            equ     460Ah
_CPYO1TOFPS1            equ     460Eh
_CPYTOFPS1              equ     4612h
_CPYO2TOFPS2            equ     4616h
_CPYO3TOFPS2            equ     461Ah
_CPYO6TOFPS2            equ     461Eh
_CPYO1TOFPS2            equ     4622h
_CPYTOFPS2              equ     4626h
_CPYO5TOFPS3            equ     462Ah
_CPYO2TOFPS3            equ     462Eh
_CPYO1TOFPS3            equ     4632h
_CPYTOFPS3              equ     4636h
_CPYO1TOFPS6            equ     463Ah
_CPYO1TOFPS7            equ     463Eh
_CPYO1TOFPS5            equ     4642h
_CPYO2TOFPS4            equ     4646h
_CPYO1TOFPS4            equ     464Ah
_ERRNOTENOUGHMEM        equ     464Eh
_FPSMINUS9              equ     4652h
_HLMINUS9               equ     4656h
_ERROVERFLOW            equ     465Ah
_ERRDIVBY0              equ     465Dh
_errSingularMat         equ     4660h
_ERRDOMAIN              equ     4663h
_errIncrement           equ     4666h
_ERRNON_REAL            equ     4669h
_errSyntax              equ     466Ch
_ERRDATATYPE            equ     466Fh
_errArgument            equ     4672h
_errDimMismatch         equ     4675h
_ERRDIMENSION           equ     4678h
_ERRUNDEFINED           equ     467Bh
_ERRMEMORY              equ     467Eh
_ERRINVALID             equ     4681h
_ERRBREAK               equ     4684h
_errStat                equ     4687h
_errSignChange          equ     468Ah
_errIterations          equ     468Dh
_errBadGuess            equ     4690h
_errTolTooSmall         equ     4693h
_ERRSTATPLOT            equ     4696h
_errLinkXmit            equ     4699h
_JError                 equ     469Ch
_JErrorNo               equ     469Fh
_noErrorEntry           equ     46A2h
_pushErrorHandlER       equ     46A5h
_popErrorHandleR        equ     46A9h
_strCopy                equ     46ADh
_strCat                 equ     46B1h
_isInSet                equ     46B5h
_sDone                  equ     46B9h
_serrort                equ     46BDh
_sNameEq                equ     46C1h
_sUnderScr              equ     46C5h
_sFAIL                  equ     46C9h
_sName                  equ     46CDh
_sOK                    equ     46D1h
_seqn                   equ     46D5h
_Sselect                equ     46D9h
_STransmit              equ     46DDh
_SRECURN                equ     46E1h
_GEQNAMEA               equ     46E5h
_RECNAME                equ     46E9h
___bank_call            equ     46EDh
___bank_ret             equ     46F1h
___bank_jump            equ     46F5h
___bank_entry           equ     46F9h
_READDISP2              equ     46FDh
_putmap                 equ     4701h
_putc                   equ     4705h
_dispHL                 equ     4709h
_puts                   equ     470Dh
_putpsb                 equ     4711h
_putps                  equ     4715h
_wputps                 equ     4719h
_putbuf                 equ     471Dh
_putbuf1                equ     4721h
_wputc                  equ     4725h
_wputs                  equ     4729h
_wputsEOL               equ     472Dh
_wdispEOL               equ     4731h
_whomeUp                equ     4735h
_setNumWindow           equ     4739h
_newline                equ     473Dh
_moveDown               equ     4741h
_scrollUp               equ     4745h
_shrinkWindow           equ     4749h
_moveup                 equ     474Dh
_scrollDown             equ     4751h
_CLRLCDFULL             equ     4755h
_clrLCD                 equ     4759h
_clrScrnFull            equ     475Dh
_clrScrn                equ     4761h
_CLRTXTSHD              equ     4765h
_clrWindow              equ     4769h
_eraseEOL               equ     476Dh
_eraseEOW               equ     4771h
_homeUp                 equ     4775h
_getcurloc              equ     4779h
_vputmap                equ     477Dh
_vputs                  equ     4781h
_vputsn                 equ     4785h
_vputsnG                equ     4789h
_vputsnT                equ     478Dh
_runIndicOn             equ     4791h
_runIndicOff            equ     4795h
_saveCmdShadow          equ     4799h
_SAVESHADOW             equ     479Dh
_RSTRSHADOW             equ     47A1h
_rstrpartial            equ     47A5h
_rstrCurRow             equ     47A9h
_rstrUnderMenu          equ     47ADh
_rstrbotrow             equ     47B1h
_saveTR                 equ     47B5h
_restoreTR              equ     47B9h
_GETKEYPRESS            equ     47BDh
_GETTOKLEN              equ     47C1h
_GET_TOK_STRNG          equ     47C5h
_GETTOKSTRING           equ     47C9h
_PUTBPATBUF2            equ     47CDh
_PUTBPATBUF             equ     47D1h
_putbPAT                equ     47D5h
_putcCheckScrolL        equ     47D9h
_dispEOL                equ     47DDh
_fdispEOL               equ     47E1h
_MAKEROWCMD             equ     47E5h
_TOTOSTRP               equ     47E9h
_SETVARNAME             equ     47EDh
_dispDone               equ     47F1h
_finishoutput           equ     47F5h
_curBlink               equ     47F9h
_CURSOROFF              equ     47FDh
_hideCursor             equ     4801h
_cursorOn               equ     4805h
_showCursor             equ     4809h
_KEYTOSTRING            equ     480Dh
_PULLDOWNCHK            equ     4811h
_MenuCatCommon          equ     4815h
_ZIfCatalog             equ     4819h
_ZIfMatrixMenu          equ     481Dh
_loadCurCat             equ     4821h
_NCifprgmedmode         equ     4825h
_LoadMenuNum            equ     4829h
_LoadMenuNumL           equ     482Dh
_MenuEdKey              equ     4831h
_MenCatRet              equ     4835h
_notalphnum             equ     4839h
_SaveSavedFlags         equ     483Dh
_SetMenuFlags           equ     4841h
_RstrSomeFlags          equ     4845h
_RstrSmallText          equ     4849h
_dispListName           equ     484Dh
_SeeIfErrorCx           equ     4851h
_RstrOScreen            equ     4855h
_SaveOscreen            equ     4859h
_DispLAlphaName         equ     485Dh
_AbortPrgmode           equ     4861h
_IS_FULLCNTX            equ     4865h
_ADRMROW                equ     4869h
_ADRMELE                equ     486Dh
_GETMATOP1A             equ     4871h
_GETM1TOOP1             equ     4875h
_GETM1TOP1A             equ     4879h
_GETMTOOP1              equ     487Dh
_PUTTOM1A               equ     4881h
_PUTTOMA1               equ     4885h
_PUTTOMAT               equ     4889h
_MAT_EL_DIV             equ     488Dh
_CMATFUN                equ     4891h
_ROWECH_POLY            equ     4895h
_ROWECHELON             equ     4899h
_ADRLELE                equ     489Dh
_GETL1TOOP1             equ     48A1h
_GETL1TOP1A             equ     48A5h
_GETLTOOP1              equ     48A9h
_GETL1TOOP2             equ     48ADh
_GETL1TOP2A             equ     48B1h
_GETL2TOP1A             equ     48B5h
_PUTTOLA1               equ     48B9h
_PUTTOL                 equ     48BDh
_MAXMINLST              equ     48C1h
_LLOW                   equ     48C5h
_LHIGH                  equ     48C9h
_LSUM                   equ     48CDh
_CUMSUM                 equ     48D1h
_TOFRAC                 equ     48D5h
_SEQSET                 equ     48D9h
_SEQSOLVE               equ     48DDh
_CMP_NUM_INIT           equ     48E1h
_BINOPEXEC              equ     48E5h
_EXMEAN1                equ     48E9h
_SET2MVLPTRS            equ     48EDh
_SETMAT1                equ     48F1h
_CREATETLIST            equ     48F5h
_UNOPEXEC               equ     48F9h
_THREEEXEC              equ     48FDh
_RESTOREERRNO           equ     4901h
_FOUREXEC               equ     4904h
_FIVEEXEC               equ     4908h
_CPYTO2ES1              equ     490Ch
_CPYTO6ES1              equ     4910h
_CPYTO1ES1              equ     4914h
_CPYTO3ES1              equ     4918h
_CPYTO3ES2              equ     491Ch
_CPYTO2ES2              equ     4920h
_CPYTO1ES2              equ     4924h
_CPYTO2ES3              equ     4928h
_CPYTO1ES3              equ     492Ch
_CPYTO3ES4              equ     4930h
_CPYTO6ES3              equ     4934h
_CPYTO2ES4              equ     4938h
_CPYTO1ES4              equ     493Ch
_CPYTO2ES5              equ     4940h
_CPYTO1ES5              equ     4944h
_CPYTO4EST              equ     4948h
_CPYTO2EST              equ     494Ch
_CPYTO1EST              equ     4950h
_CPYTO2ES6              equ     4954h
_CPYTO1ES6              equ     4958h
_CPYTO2ES7              equ     495Ch
_CPYTO1ES7              equ     4960h
_CPYTO2ES8              equ     4964h
_CPYTO1ES8              equ     4968h
_CPYTO1ES9              equ     496Ch
_CPYTO2ES9              equ     4970h
_CPYTO2ES10             equ     4974h
_CPYTO1ES10             equ     4978h
_CPYTO2ES11             equ     497Ch
_CPYTO1ES11             equ     4980h
_CPYTO2ES12             equ     4984h
_CPYTO1ES12             equ     4988h
_CPYTO2ES13             equ     498Ch
_CPYTO1ES13             equ     4990h
_CPYTO1ES14             equ     4994h
_CPYTO1ES16             equ     4998h
_CPYTO1ES17             equ     499Ch
_CPYTO1ES18             equ     49A0h
_CPYTO1ES15             equ     49A4h
_CPYTO2ES15             equ     49A8h
_CPYO1TOEST             equ     49ACh
_CPYO1TOES1             equ     49B0h
_CPYO6TOES1             equ     49B4h
_CPYO6TOES3             equ     49B8h
_CPYO1TOES2             equ     49BCh
_CPYO2TOES2             equ     49C0h
_CPYO1TOES3             equ     49C4h
_CPYO1TOES4             equ     49C8h
_CPYO1TOES5             equ     49CCh
_CPYO1TOES6             equ     49D0h
_CPYO1TOES7             equ     49D4h
_CPYO2TOES4             equ     49D8h
_CPYO2TOES5             equ     49DCh
_CPYO2TOES6             equ     49E0h
_CPYO2TOES7             equ     49E4h
_CPYO2TOES8             equ     49E8h
_CPYO2TOES9             equ     49ECh
_CPYO1TOES8             equ     49F0h
_CPYO1TOES9             equ     49F4h
_CPYO1TOES10            equ     49F8h
_CPYO1TOES11            equ     49FCh
_CPYO1TOES12            equ     4A00h
_CPYO1TOES13            equ     4A04h
_CPYO1TOES14            equ     4A08h
_CPYO1TOES15            equ     4A0Ch
_EVALF3A                equ     4A10h
COMPLEX_EXEC            equ     4A14h
_GetK                   equ     4A18h
_setTitlE               equ     4A1Ch
_dispVarVal             equ     4A20h
_RecallEd               equ     4A24h
_setupBuffer            equ     4A28h
_createNumEditBUF       equ     4A2Ch
_CallCommon             equ     4A30h
_CommonKeys             equ     4A34h
_Leftmore               equ     4A37h
_fDel                   equ     4A3Ah
_fClear                 equ     4A3Eh
_finsDisp               equ     4A42h
_FinsDisp02             equ     4A45h
_setIndicator           equ     4A49h
_CloseEditBufNo         equ     4A4Dh
_releaseBuffer          equ     4A51h
_varnameToOP1hl         equ     4A55h
_nameToOP1              equ     4A59h
_numPPutAway            equ     4A5Dh
_numRedisp              equ     4A61h
_numError02             equ     4A65h
_LOAD_SFONT             equ     4A68h
_SFONT_LEN              equ     4A6Ch
_InitNumVec             equ     4A70h
_SETXXOP1               equ     4A74h
_SETXXOP2               equ     4A78h
_SETXXXXOP2             equ     4A7Ch
_UCLINES                equ     4A80h
_CLine                  equ     4A84h
_XROOTY                 equ     4A8Ch
_YTOX                   equ     4A90h
_ZMSTATS                equ     4A94h
_POINT_STAT_HLP         equ     4A98h
_DRAWSPLOT              equ     4A9Ch
_INITNEWTRACEP          equ     4AA0h
_SPLOTCOORD             equ     4AA4h
_SPLOTRIGHT             equ     4AA8h
_SPLOTLEFT              equ     4AACh
_CMPBOXINFO             equ     4AB0h
_NEXTPLOT               equ     4AB4h
_PREVPLOT               equ     4AB8h
_CLRPREVPLOT            equ     4ABCh
_PUT_INDEX_LST          equ     4AC0h
_GET_INDEX_LST          equ     4AC4h
_HEAP_SORT              equ     4AC8h
_STOGDB2                equ     4ACCh
_RCLGDB2                equ     4AD0h
_CIRCCMD                equ     4AD4h
_GRPHCIRC               equ     4AD8h
_MOV18B                 equ     4ADCh
_DARKLINE               equ     4AE0h
_ILINE                  equ     4AE4h
_IPOINT                 equ     4AE8h
_XYRNDBOTH              equ     4AECh
_XYRND                  equ     4AF0h
_CheckTOP               equ     4AF4h
_CheckXY                equ     4AF8h
_DARKPNT                equ     4AFCh
_CPointS                equ     4B00h
_WTOV                   equ     4B04h
_VtoWHLDE               equ     4B08h
_XItoF                  equ     4B0Ch
_YFTOI                  equ     4B10h
_XFTOI                  equ     4B14h
_TraceOff               equ     4B18h
_GrRedisp               equ     4B1Ch
_GDISPTOKEN             equ     4B20h
_GRDECODA               equ     4B24h
_LABCOOR                equ     4B28h
_COORDISP               equ     4B2Ch
_TMPEQUNOSRC            equ     4B30h
_GRLABELS               equ     4B34h
_YPIXSET                equ     4B38h
_XPIXSET                equ     4B3Ch
_COPYRNG                equ     4B40h
_VALCUR                 equ     4B44h
_GRPUTAWAY              equ     4B48h
_RSTGFLAGS              equ     4B4Ch
_GRReset                equ     4B50h
_XYCENT                 equ     4B54h
_ZOOMXYCMD              equ     4B58h
_CPTDELY                equ     4B5Ch
_CPTDELX                equ     4B60h
_SETFUNCM               equ     4B64h
_SETSEQM                equ     4B68h
_SETPOLM                equ     4B6Ch
_SETPARM                equ     4B70h
_ZMINT                  equ     4B74h
_ZMDECML                equ     4B78h
_ZMPREV                 equ     4B7Ch
_ZMUSR                  equ     4B80h
_SETUZM                 equ     4B84h
_ZMFIT                  equ     4B88h
_ZMSQUARE               equ     4B8Ch
_ZMTRIG                 equ     4B90h
_SetXMinMax             equ     4B94h
_ZooDefault             equ     4B98h
_GRBUFCPY               equ     4B9Ch
_DRAWSPLITLINE          equ     4BA0h
_RestoreDisp            equ     4BA4h
_FNDDB                  equ     4BA8h
_ALLEQ                  equ     4BACh
_fndallseleq            equ     4BB0h
_NEXTEQ                 equ     4BB4h
_PREVEQ                 equ     4BB8h
_BLINKGCUR              equ     4BBCh
_NBCURSOR               equ     4BC0h
_STATMARK               equ     4BC4h
_CHKTEXTCURS            equ     4BC8h
_REGRAPH                equ     4BCCh
_DOREFFLAGS02           equ     4BD0h
_INITNSEQ               equ     4BD4h
_YRES                   equ     4BD8h
_PLOTPTXY2              equ     4BDCh
_Ceiling                equ     4BE0h
_PUTXY                  equ     4BE4h
_PUTEQUNO               equ     4BE7h
_PDspGrph               equ     4BEBh
_HORIZCMD               equ     4BEFh
_VERTCMD                equ     4BF3h
_LINECMD                equ     4BF7h
_UNLINECMD              equ     4BFBh
_POINTCMD               equ     4BFFh
_PIXELTEST              equ     4C03h
_PIXELCMD               equ     4C07h
_TANLNF                 equ     4C0Bh
_DRAWCMD_INIT           equ     4C0Fh
_DRAWCMD                equ     4C13h
_SHADECMD               equ     4C17h
_INVCMD                 equ     4C1Bh
_STATSHADE              equ     4C1Fh
_dspmattable            equ     4C23h
_dsplsts                equ     4C27h
_closeEditBuf           equ     4C2Bh
_parseEditBuf           equ     4C2Fh
_putsm                  equ     4C33h
_DspCurTbl              equ     4C37h
_DSPGRTBL               equ     4C3Bh
_ZeroTemplate           equ     4C3Fh
_settblrefs             equ     4C43h
_dispTblBot             equ     4C47h
_DispTblTop             equ     4C4Bh
_dispTblbody            equ     4C4Fh
_VPUTBLANK              equ     4C53h
_TBLTRACE               equ     4C57h
_dispListNameY          equ     4C5Bh
_CurNameLength          equ     4C5Fh
_NameToBuf              equ     4C63h
_jpromptcursor          equ     4C67h
_bufLeft                equ     4C6Ah
_BUFRIGHT               equ     4C6Eh
_bufInsert              equ     4C72h
_bufQueueChar           equ     4C76h
_bufReplace             equ     4C7Ah
_bufDelete              equ     4C7Eh
_BUFPEEK                equ     4C82h
_BUFPEEK1               equ     4C86h
_BUFPEEK2               equ     4C8Ah
_BUFPEEK3               equ     4C8Eh
_BufToBtm               equ     4C92h
_setupEditEqu           equ     4C96h
_bufToTop               equ     4C9Ah
_isEditFull             equ     4C9Eh
_isEditEmpty            equ     4CA2h
_ISATTOP                equ     4CA6h
_isAtBtm                equ     4CAAh
_bufClear               equ     4CAEh
_JcursorFirst           equ     4CB2h
_JcursorLast            equ     4CB5h
_cursorLeft             equ     4CB8h
_JcursorRight           equ     4CBCh
_JcursorUp              equ     4CBFh
_cursorDown             equ     4CC2h
_cursorToOffset         equ     4CC6h
_insDisp                equ     4CCAh
_FDISPBOL1              equ     4CCEh
_FDISPBOL               equ     4CD2h
_dispEOW                equ     4CD6h
_dispHead               equ     4CDAh
_dispTail               equ     4CDEh
_PutTokString           equ     4CE2h
_setupEditCmd           equ     4CE6h
_setEmptyEditEqU        equ     4CEAh
_setEmptyEditPtR        equ     4CEEh
_closeEditEqu           equ     4CF2h
_toggleIns              equ     4CF6h
_GETPREVTOK             equ     4CFAh
_getkey                 equ     4CFEh
_canIndic               equ     4D02h
_LCD_DRIVERON           equ     4D06h
_DFMIN2                 equ     4D0Ah
_formDisp               equ     4D0Eh
_formMatrix             equ     4D12h
_wscrollLeft            equ     4D16h
_wscrollUp              equ     4D1Ah
_wscrollDown            equ     4D1Eh
_wscrollRight           equ     4D22h
_formEReal              equ     4D26h
_formERealTOK           equ     4D2Ah
_formDCplx              equ     4D2Eh
_formReal               equ     4D32h
_formScrollUp           equ     4D36h
_setwinabove            equ     4D3Ah
_disarmScroll           equ     4D3Eh
_OP1toEdit              equ     4D42h
_MinToEdit              equ     4D46h
_rclVarToEdit           equ     4D4Ah
_rclVarToEditPtR        equ     4D4Eh
_RCLENTRYTOEDIT         equ     4D52h
_rclToQueue             equ     4D56h
_FORMTOTOK              equ     4D5Ah
_DISP_INTERVAL          equ     4D5Eh
_DisplstName            equ     4D62h
_dispSLstNameHL         equ     4D66h
_Edit                   equ     4D6Ah
_closeEquField          equ     4D6Eh
_AutoSelect             equ     4D72h
_DISPYEOS               equ     4D76h
_dispNumEOS             equ     4D7Ah
_setupdispeq            equ     4D7Eh
_dispForward            equ     4D82h
_DispYPrompt2           equ     4D86h
_stringwidth            equ     4D8Ah
_dispErrorScreeN        equ     4D8Eh
_POPCX                  equ     4D92h
_loadnoeentry           equ     4D96h
_SaveScreen             equ     4D9Ah
_RETSCREEN              equ     4D9Eh
_RetScreenErr           equ     4DA2h
_SplitChange            equ     4DA6h
_SolveRedisp            equ     4DAAh
_SolveDisp              equ     4DAEh
_itemName               equ     4DB2h
_SETNORM_VALS           equ     4DB6h
_SETVERT_VALS           equ     4DBAh
_CONVKEYTOTOK           equ     4DBEh
_KEYTOTOKNEW2B          equ     4DC2h
_KEYTOTOK2BYTE          equ     4DC6h
_TOKTOKEY               equ     4DCAh
_LOAD_LFONT             equ     4DCEh
_SEND1BERR              equ     4DD2h
_GETVARCMD              equ     4DD6h
_SENDVARCMD             equ     4DDAh
_PRINTSCREEN            equ     4DDEh
_KEYSCNLNK              equ     4DE2h
_IORESETALL             equ     4DE6h
_DELRES                 equ     4DEAh
_CONVLCTOLR             equ     4DEEh
_REDIMMAT               equ     4DF2h
_INCLSTSIZE             equ     4DF6h
_insertlist             equ     4DFAh
_dellistel              equ     4DFEh
_EDITPROG               equ     4E02h
_CLOSEPROG              equ     4E06h
_CLRGRAPHREF            equ     4E0Ah
_FIXTEMPCNT             equ     4E0Eh
_SAVEDATA               equ     4E12h
_RESTOREDATA            equ     4E16h
_FindAlphaup            equ     4E1Ah
_FindAlphadn            equ     4E1Eh
_CMPSYMS                equ     4E22h
_CREATETEMP             equ     4E26h
_CLEANALL               equ     4E2Ah
_MOVETONEXTSYM          equ     4E2Eh
_CONVLRTOLC             equ     4E32h
_TblScreenDn            equ     4E36h
_TblScreenUp            equ     4E3Ah
_SCREENUP               equ     4E3Eh
_SCREENUPDOWN           equ     4E42h
_ZifRclHandler          equ     4E46h
_zifrclkapp             equ     4E4Ah
_rclkeyRtn              equ     4E4Eh
_RCLKEY                 equ     4E52h
_RCLREGEQ_CALL          equ     4E55h
_RCLREGEQ               equ     4E59h
_initNamePrompt         equ     4E5Ch
_NamePrompt2            equ     4E60h
_CATALOGCHK             equ     4E64h
_clrTR                  equ     4E68h
_QUAD                   equ     4E6Ch
_GRAPHQUAD              equ     4E70h
_BC2NONREAL             equ     4E74h
_ERRNONREAL             equ     4E78h
_WRITE_TEXT             equ     4E7Ch
_FORSEQINIT             equ     4E80h
_GRPHPARS               equ     4E84h
_PLOTPARS               equ     4E88h
_PARSEinp               equ     4E8Ch
_PARSEOFF               equ     4E90h
_PARSESCAN              equ     4E94h
_GETPARSE               equ     4E98h
_SAVEPARSE              equ     4E9Ch
_InitPFlgs              equ     4EA0h
_CKENDLINERR            equ     4EA4h
_OP2SET60               equ     4EA8h
_GETSTATPTR             equ     4EACh
_CMP_STATPTR            equ     4EB0h
_VARSYSADR              equ     4EB4h
_STOSYSTOK              equ     4EB8h
_STOANS                 equ     4EBCh
_STOTHETA               equ     4EC0h
_STOR                   equ     4EC4h
_STOY                   equ     4EC8h
_STON                   equ     4ECCh
_STOT                   equ     4ED0h
_STOX                   equ     4ED4h
_STOOTHER               equ     4ED8h
_RCLANS                 equ     4EDCh
_RCLY                   equ     4EE0h
_RCLN                   equ     4EE4h
_RCLX                   equ     4EE8h
_RCLVARSYM              equ     4EECh
_RCLSYSTOK              equ     4EF0h
_StMatEl                equ     4EF4h
_STLSTVECEL             equ     4EF8h
_CONVOP1                equ     4EFCh
_isaletter              equ     4F00h
_Find_Parse_ForMULA     equ     4F04h
_PARSE_FORMULA          equ     4F08h
_STRNGENT1              equ     4F0Ch
_GETNUMLET              equ     4F15h
_INIT_PROG_LIST         equ     4F1Eh
_PRGRDLP                equ     4F27h
_VARENT                 equ     4F30h
_RCLSTAT                equ     4F39h
_PARSELOOP              equ     4F42h
_PARSEONC               equ     4F4Bh
_PARSEON                equ     4F52h
_PARSECMD               equ     4F5Ah
_STOTYPE                equ     4F61h
_CREATEPAIR             equ     4F6Ah
_PUSHNUM                equ     4F73h
_INCCURPCERREND         equ     4F7Ch
_ERREND                 equ     4F85h
_COMMAERRF              equ     4F8Eh
_COMMAERR               equ     4F97h
_STEQARG2               equ     4FA0h
_STEQARG                equ     4FA9h
_INPARG                 equ     4FB2h
_STEQARG3               equ     4FBBh
_NXTFETCH               equ     4FC4h
_CKFETCHVAR             equ     4FCDh
_FETCHVARA              equ     4FD6h
PARSER_EXEC             equ     4FDFh
_FETCHVAR               equ     4FE3h
_CKENDLIN               equ     4FECh
_CKENDEXP               equ     4FF5h
_CKPARSEND              equ     4FFEh
_STOTYPEARG             equ     5007h
_CONVDIM                equ     5010h
_CONVDIM00              equ     5019h
_AHEADEQUAL             equ     5022h
_PARSAHEADS             equ     502Bh
_PARSAHEAD              equ     5034h
_ANSNAME                equ     503Dh
_STOCMPREALS            equ     5046h
_GETDEPTR               equ     504Fh
_PUSH2BOPER             equ     5058h
_POP2BOPER              equ     5061h
_PUSHOPER               equ     506Ah
_POPOPER                equ     5073h
_FIND_E_UNDEF           equ     507Ch
_STTMPEQ                equ     5085h
_FINDEOL                equ     508Eh
_BRKINC                 equ     5097h
_INCFETCH               equ     50A0h
_CURFETCH               equ     50A9h
PGMIO_EXEC              equ     50B2h
_RANDOM                 equ     50B6h
_STORAND                equ     50BAh
_RandInit               equ     50BEh
_resetStacks            equ     50C2h
_FACTORIAL              equ     50C6h
_YONOFF                 equ     50CAh
_EQSELUNSEL             equ     50CEh
_ITSOLVER               equ     50D2h
_GRITSOLVER             equ     50D6h
_ITSOLVERB              equ     50DAh
_ITSOLVERNB             equ     50DEh
_ExTest_INT             equ     50E2h
_DIST_FUN               equ     50E6h
_LOGGAMMA               equ     50EAh
_ONEVAR                 equ     50EEh
_ONEVARS_0              equ     50F2h
_ORDSTAT                equ     50F6h
_INITSTATANS2           equ     50FAh
_ANOVA_SPEC             equ     50FEh
_EXEC_ASSEMBLY          equ     5102h
_outputExpr             equ     5106h
_CentCursor             equ     510Ah
_TEXT                   equ     5113h
_FINISHSPEC             equ     511Ch
_TRCYFUNC               equ     5125h
_RCL_SEQ_X              equ     512Eh
_RCLSEQ2                equ     5137h
_GRPPutAway             equ     5140h
_CKVALDELX              equ     5149h
_CKVALDELTA             equ     5152h
_GRBUFCLR               equ     515Bh
_GRBUFCPY_V             equ     5164h
_FNDSELEQ               equ     516Dh
_CLRGRAPHXY             equ     5176h
_NEXT_Y_STYLE           equ     517Fh
GRAPH_EXEC              equ     5188h
_PLOTPT                 equ     518Ch
_NEWINDEP               equ     5195h
_Axes                   equ     519Eh
_setPenX                equ     51A7h
_setPenY                equ     51B0h
_setPenT                equ     51B9h
_TAN_EQU_DISP           equ     51C2h
_putAns                 equ     51CBh
_DISPOP1A               equ     51D4h
_MATHTANLN              equ     51DDh
_ENDDRAW                equ     51E6h
IO_EXEC                 equ     51EFh
EXECUTE_Z80             equ     52E5h

;;;;;;;;;;;;;;;;;;;
;; RAM Locations ;;
;;;;;;;;;;;;;;;;;;;

contrastvar             equ     8008h		;       Display contrast
apdvar                  equ     800Ah		;       Apd countdown value
CURROW                  equ     800Ch		;       RAM EQUATE DEALING WITH DISPLAY ROUTINES
CURCOL                  equ     800Dh		;       RAM EQUATE DEALING WITH DISPLAY ROUTINES
OP1                     equ     8039h		;       OP1 TO OP6 RAM EQUATE
OP1M                    equ     803Bh		;       OP1 TO OP6 RAM EQUATE
OP2                     equ     8044h		;       OP1 TO OP6 RAM EQUATE
op2exp                  equ     8045h		;       OP1 TO OP6 RAM EQUATE
op2m                    equ     8046H		;       OP1 TO OP6 RAM EQUATE
OP3                     equ     804Fh		;       OP1 TO OP6 RAM EQUATE
OP3EXP                  equ     8050h		;       OP1 TO OP6 RAM EQUATE
OP3M                    equ     8051h		;       OP1 TO OP6 RAM EQUATE
OP3EXT                  equ     8058h		;       OP1 TO OP6 RAM EQUATE
OP4                     equ     805Ah		;       OP1 TO OP6 RAM EQUATE
OP4EXP                  equ     805Bh		;       OP1 TO OP6 RAM EQUATE
OP4M                    equ     805Ch		;       OP1 TO OP6 RAM EQUATE
OP4EXT                  equ     8063h		;       OP1 TO OP6 RAM EQUATE
OP5                     equ     8065h		;       OP1 TO OP6 RAM EQUATE
OP5EXP                  equ     8066h		;       OP1 TO OP6 RAM EQUATE
OP5M                    equ     8067h		;       OP1 TO OP6 RAM EQUATE
OP5EXT                  equ     806Eh		;       OP1 TO OP6 RAM EQUATE
OP6                     equ     8070h		;       OP1 TO OP6 RAM EQUATE
OP6EXP                  equ     8071h		;       OP1 TO OP6 RAM EQUATE
OP6M                    equ     8072h		;       OP1 TO OP6 RAM EQUATE
OP6EXT                  equ     8079h		;       OP1 TO OP6 RAM EQUATE
IMATHPTR1               equ     8094h		;       POINTER
IMATHPTR2               equ     8096h		;       POINTER
IMATHPTR3               equ     8098h		;       POINTER
IMATHPTR4               equ     809Ah		;       POINTER
IMATHPTR5               equ     809Ch		;       POINTER
ASM_IND_CALL            equ     80C8h		;       INDIRECT CALL BYTE
TEXTSHADOW              equ     80C9h		;       SCREEN SHADOW
PENCOL                  equ     8252h		;       RAM EQUATE DEALING WITH DISPLAY ROUTINES
PENROW                  equ     8253h		;       RAM EQUATE DEALING WITH DISPLAY ROUTINES
SAVESSCREEN             equ     8265h		;       SAFE RAM LOCATION
usermem_offset          equ     8565h
STATVARS                equ     858Fh		;       SAFE RAM LOCATION
CURGY                   equ     886Dh		;       RAM EQUATE DEALING WITH DISPLAY ROUTINES
CURGX                   equ     886Eh		;       RAM EQUATE DEALING WITH DISPLAY ROUTINES
PLOTSSCREEN             equ     8E29h		;       GRAPH BACKUP BUFFER
CMDSHADOW               equ     9157h		;       SCREEN SHADOW
PROGPTR                 equ     9319h		;       POINTER TO START OF PROGRAM/LIST SYMBOL ENTRIES
Progstart               equ     9327h		;       Adress where asm program is executed
SYMTABLE                equ    0FE6Eh		;       START OF SYMBOL TABLE













;
;       ADDRESS OF LCD DRIVER INSTRUCTION PORT
;
LCDINSTPORT       equ           10h


;
;       LINK PORT WRITE EQUATES
;
D0LD1L           equ         0C3h
D0LD1H           equ         0C1h
D0HD1L           equ         0C2h
D0HD1H           equ         0C0h
BPORT            equ         0
;
;       SYSTEM FLAG EQUATES
;       ALL OF THESE FLAGS CAN BE ACCESSED THROUGH THE 'IY' REGISTER
;
trigflags       EQU       0           ; IY OFFSET VALUE
trigdeg         EQU       2
;
plotflags       EQU       2           ; IY OFFSET VALUE
plotloc         EQU       1
plotdisp        EQU       2
;
grfmodeflags    EQU       2           ; IY OFFSET VALUE
grffuncm        EQU       4
grfpolarm       EQU       5
grfparamm       EQU       6
grfrecurm       EQU       7
;
graphflags      EQU       3           ; IY OFFSET VALUE
graphdraw       EQU       0
graphcursor     EQU       2
;
grfdbflags      EQU       4           ; IY OFFSET VALUE
grfdot          EQU       0
grfsimul        EQU       1
grfgrid         EQU       2
grfpolar        EQU       3
grfnocoord      EQU       4
grfnoaxis       EQU       5
grflabel        EQU       6
;
textflags       EQU       5           ; IY OFFSET VALUE
textEraseBelow  EQU       1
textScrolled    EQU       2
textInverse     EQU       3
;
NewDispF        EQU       8           ; IY OFFSET VALUE
ProgExecuting   EQU       1
;
onflags         EQU       9           ; IY OFFSET VALUE
onRunning       EQU       3
onInterrupt     EQU       4
;
statflags       EQU       9           ; IY OFFSET VALUE
statsvalid      EQU       6
;
fmtflags        EQU       10          ; IY OFFSET VALUE
fmtExponent     EQU       0
fmtEng          EQU       1
;
nummode         EQU       10          ; IY OFFSET VALUE
FMTREAL         EQU       5
FMTRECT         EQU       6
FMTPOLAR        EQU       7
;
curflags        EQU       12          ; IY OFFSET VALUE
curAble         EQU       2
curOn           EQU       3
curLock         EQU       4
;
appflags        EQU       13          ; IY OFFSET VALUE
appTextSave     EQU       1
appAutoScroll   EQU       2
;
PLOTFLAG2       EQU       17          ; IY OFFSET VALUE
EXPR_PARAM      EQU       3
EXPR_WRITING    EQU       4
;
indicflags      EQU       18          ; IY OFFSET VALUE
indicRun        EQU       0
indicOnly       EQU       2
;
shiftflags      EQU       18          ; IY OFFSET VALUE
shift2nd        EQU       3
shiftAlpha      EQU       4
shiftALock      EQU       6
;
tblflags        EQU       19          ; IY OFFSET VALUE
AutoFill        EQU       4
AutoCalc        EQU       5
;
sgrflags        EQU       20          ; IY OFFSET VALUE
grfSplit        EQU       0
VertSplit       EQU       1
WRITE_ON_GRAPH  EQU       4
textwrite       EQU       7
;
asm_flag1       EQU       33          ; IY OFFSET VALUE
asm_flag1_0     EQU       0
asm_flag1_1     EQU       1
asm_flag1_2     EQU       2
asm_flag1_3     EQU       3
asm_flag1_4     EQU       4
asm_flag1_5     EQU       5
asm_flag1_6     EQU       6
asm_flag1_7     EQU       7
;
asm_flag2       EQU       34          ; IY OFFSET VALUE
asm_flag2_0     EQU       0
asm_flag2_1     EQU       1
asm_flag2_2     EQU       2
asm_flag2_3     EQU       3
asm_flag2_4     EQU       4
asm_flag2_5     EQU       5
asm_flag2_6     EQU       6
asm_flag2_7     EQU       7
;
asm_flag3       EQU       35          ; IY OFFSET VALUE
asm_flag3_0     EQU       0
asm_flag3_1     EQU       1
asm_flag3_2     EQU       2
asm_flag3_3     EQU       3
asm_flag3_4     EQU       4
asm_flag3_5     EQU       5
asm_flag3_6     EQU       6
asm_flag3_7     EQU       7










;======================================================================
;           System and State Flags
;======================================================================
;


kbdFlags	EQU  0		;Keyboard scan
kbdSCR		EQU    3	; 1=scan code ready
kbdKeyPress	EQU    4	; 1=key has been pressed

doneFlags	EQU  0		;display "Done"
donePrgm	EQU    5	; 1=display "Done" after prgm

ioDelFlag	EQU  0
inDelete	EQU    0	;1 = DELETE SCREEN 

;----------------------------------------------------------------------
editFlags	EQU  1
editOpen	EQU    2	; 1=edit buffer is open

monFlags	EQU  1		;monitor flags
monAbandon	EQU    4	; 1=don't start any long process
				; in put away (#715)
;----------------------------------------------------------------------



textInsMode	EQU    4	; 0=overstrike, 1=insert mode

ParsFlag2	EQU  7		;PARSER flags
numOP1		EQU    0	; 1=RESULT IN OP1, 0=NO RESULT

preClrForMode   EQU    0	; 1=HELP BLINK ON MODE SCREEN

apdFlags	EQU  8		;Automatic power-down
apdAble 	EQU    2	; 1=APD enabled
apdRunning	EQU    3	; 1=APD clock running


web_err_mask    EQU  60h


statANSDISP	EQU  7		; 1=display stat results

fmtHex		EQU    2	; 1=hexadecimal
fmtOct		EQU    3	; 1=octal
fmtBin		EQU    4	; 1=binary
;

realMode        EQU    5
rectMode        EQU    6
polarMode       EQU    7
;					;   if Hex and Oct both = 1
;					;   then Bin=0 means >Frac
;					;	 Bin=1 means >DMS
fmtBaseMask     EQU  00011100B		; mask to base flags
fmtBaseShift    EQU  2			; offset to base flags
;
;       CHECK IF THESE ARE USED BY NUMFORM,
;
;               EQU  6
;               EQU  7

fmtOverride	EQU  11		;copy of fmtFlags with conversion override

fmtEditFlags	EQU  12		;numeric editing flags
fmtEdit 	EQU    0	; 1=format number for editing



seqFlags        EQU  15              ; Sequential Graph flags
webMode         EQU    0             ; 0 = NORMAL SEQ MODE, 1 = WEB MODE
webVert         EQU    1             ;
sequv           EQU    2             ; U vs V
seqvw           EQU    3             ; V vs W
sequw           EQU    4             ; U vs W


promptFlags	EQU  17		;prompt line flags
promptEdit	EQU    0	; 1=editing in prompt buffer

indicInUse	EQU    1	; indicator save area in use=1, free=0

shiftLwrAlph	EQU    5	; 1=lower case, 0=upper case
shiftKeepAlph	EQU    7	; 1=cannot cancel alpha shift


reTable         EQU    6	; 0=table is ok, 1=must recompute table.

grfSChanged     EQU    2	; 1=Graph just changed Split <-> normal
grfSplitOverride EQU   3	; 1 = ignore graph split flag if set
g_style_active  EQU    5	; 1 = GRAPH STYLES ARE ENABLED, USE THEM
cmp_mod_box     EQU    6	; 1 = DOING MOD BOX PLOT COMPUTATION
							; 0 = Small font writes to display
;

newIndicFlags   EQU  21
extraIndic      EQU    0
saIndic         EQU    1

newFlags2	    EQU  22
noRestores	    EQU  5

smartFlags      EQU  23
;
;----------------------------------------------------------------------
; Note: Fix these Equates if smartFlags are moved                            
;----------------------------------------------------------------------
;
smarter_mask    EQU  3
smarter_test    EQU  1
smartGraph      EQU  0
smartGraph_inv  EQU  1                                                 

more_Flags	EQU 26

No_Del_Stat	EQU 2
;----------------------------------------------------------------------
;           Available for ASM programming
;----------------------------------------------------------------------









;
;       SYSTEM VAR EQUATES, FOR STORING AND RECALLING THEM
;
XSCLt       EQU  2        ; XSCALE
YSCLt       EQU  3        ; YSCALE
XMINt       EQU  0AH      ; XMIN
XMAXt       EQU  0BH      ; XMAX
YMINt       EQU  0CH      ; YMIN
YMAXt       EQU  0DH      ; XMAX
TMINt       EQU  0EH      ; TMIN
TMAXt       EQU  0FH      ; TMAX
THETMINt    EQU  10H      ; THETA MIN
THETMAXt    EQU  11H      ; THETA MAX
TBLMINt     EQU  1AH      ; TABLE MIN
PLOTSTARTt  EQU  1BH      ; PLOT START
NMAXt       EQU  1DH      ; NMAX
nmint       EQU  1FH      ; NMIN
TBLSTEPt    EQU  21H      ; TABLE STEP
TSTEPt      EQU  22H      ; T STEP
THETSTEPt   EQU  23H      ; THETA STEP
DELTAXt     EQU  26H      ; DELTA X
DELTAYt     EQU  27H      ; DELTA Y
XFACTt      EQU  28H      ; X ZOOM FACTOR
YFACTt      EQU  29H      ; Y ZOOM FACTOR
FINnT       EQU  2Bh      ; TVM n
FINiT       EQU  2Ch      ; TVM i
FINpvT      EQU  2Dh      ; TVM pv
FINpmtT     EQU  2Eh      ; TVM pmt
FINfvT      EQU  2Fh      ; TVM fv
FINpyT      EQU  30h      ; TVM p/y
FINcyT      EQU  31h      ; TVM c/y
PLOTSTEPT   EQU  34h      ; PLOT STEP
XREST       EQU  36h      ; X RES













;
;       CHARACTER FONT EQUATES
;
LSEQ_N          equ     001h
LSEQ_U          equ     002h
LSEQ_V          equ     003h
LSEQ_W          equ     004h
Lconvert        equ     005h
LsqUp           equ     006h
LsqDown         equ     007h
Lintegral       equ     008h
Lcross          equ     009h
LBOXICON        equ     00Ah
LCROSSICON      equ     00Bh
LDOTICON        equ     00Ch
LsubT           equ     00Dh            ;small capital T for parametric mode.
LcubeR          equ     00Eh            ;slightly different 3 for cubed root.
LhexF           equ     00Fh
Lroot           equ     010h
Linverse        equ     011h
Lsquare         equ     012h
Langle          equ     013h
Ldegree         equ     014h
Lradian         equ     015h
Ltranspose      equ     016h
LLE             equ     017h
LNE             equ     018h
LGE             equ     019h
Lneg            equ     01Ah
Lexponent       equ     01Bh
Lstore          equ     01Ch
Lten            equ     01Dh
LupArrow        equ     01Eh
LdownArrow      equ     01Fh
Lspace          equ     020h
Lexclam         equ     021h
Lquote          equ     022h
Lpound          equ     023h
LFOURTH         equ     024h
Lpercent        equ     025h
Lampersand      equ     026h
Lapostrophe     equ     027h
LlParen         equ     028h
LrParen         equ     029h
Lasterisk       equ     02Ah
LplusSign       equ     02Bh
Lcomma          equ     02Ch
Ldash           equ     02Dh
Lperiod         equ     02Eh
Lslash          equ     02Fh
L0              equ     030h
L1              equ     031h
L2              equ     032h
L3              equ     033h
L4              equ     034h
L5              equ     035h
L6              equ     036h
L7              equ     037h
L8              equ     038h
L9              equ     039h
Lcolon          equ     03Ah
Lsemicolon      equ     03Bh
LLT             equ     03Ch
LEQ             equ     03Dh
LGT             equ     03Eh
Lquestion       equ     03Fh
LatSign         equ     040h
LcapA           equ     041h
LcapB           equ     042h
LcapC           equ     043h
LcapD           equ     044h
LcapE           equ     045h
LcapF           equ     046h
LcapG           equ     047h
LcapH           equ     048h
LcapI           equ     049h
LcapJ           equ     04Ah
LcapK           equ     04Bh
LcapL           equ     04Ch
LcapM           equ     04Dh
LcapN           equ     04Eh
LcapO           equ     04Fh
LcapP           equ     050h
LcapQ           equ     051h
LcapR           equ     052h
LcapS           equ     053h
LcapT           equ     054h
LcapU           equ     055h
LcapV           equ     056h
LcapW           equ     057h
LcapX           equ     058h
LcapY           equ     059h
LcapZ           equ     05Ah
Ltheta          equ     05Bh
Lbackslash      equ     05Ch
LrBrack         equ     05Dh
Lcaret          equ     05Eh
Lunderscore     equ     05Fh
Lbackquote      equ     060h
La              equ     061h
Lb              equ     062h
Lc              equ     063h
Ld              equ     064h
Le              equ     065h
Lf              equ     066h
Lg              equ     067h
Lh              equ     068h
Li              equ     069h
Lj              equ     06Ah
Lk              equ     06Bh
Ll              equ     06Ch
Lm              equ     06Dh
Ln              equ     06Eh
Lo              equ     06Fh
Lp              equ     070h
Lq              equ     071h
Lr              equ     072h
Ls              equ     073h
Lt              equ     074h
Lu              equ     075h
Lv              equ     076h
Lw              equ     077h
Lx              equ     078h
Ly              equ     079h
Lz              equ     07Ah
LlBrace         equ     07Bh
Lbar            equ     07Ch
LrBrace         equ     07Dh
Ltilde          equ     07Eh
LinvEQ          equ     07Fh
Lsub0           equ     080h
Lsub1           equ     081h
Lsub2           equ     082h
Lsub3           equ     083h
Lsub4           equ     084h
Lsub5           equ     085h
Lsub6           equ     086h
Lsub7           equ     087h
Lsub8           equ     088h
Lsub9           equ     089h
LcapAAcute      equ     08Ah
LcapAGrave      equ     08Bh
LcapACaret      equ     08Ch
LcapADier       equ     08Dh
LaAcute         equ     08Eh
LaGrave         equ     08Fh
LaCaret         equ     090h
LaDier          equ     091h
LcapEAcute      equ     092h
LcapEGrave      equ     093h
LcapECaret      equ     094h
LcapEDier       equ     095h
LeAcute         equ     096h
LeGrave         equ     097h
LeCaret         equ     098h
LeDier          equ     099h
LcapIAcute      equ     09Ah
LcapIGrave      equ     09Bh
LcapICaret      equ     09Ch
LcapIDier       equ     09Dh
LiAcute         equ     09Eh
LiGrave         equ     09Fh
LiCaret         equ     0A0h
LiDier          equ     0A1h
LcapOAcute      equ     0A2h
LcapOGrave      equ     0A3h
LcapOCaret      equ     0A4h
LcapODier       equ     0A5h
LoAcute         equ     0A6h
LoGrave         equ     0A7h
LoCaret         equ     0A8h
LoDier          equ     0A9h
LcapUAcute      equ     0AAh
LcapUGrave      equ     0ABh
LcapUCaret      equ     0ACh
LcapUDier       equ     0ADh
LuAcute         equ     0AEh
LuGrave         equ     0AFh
LuCaret         equ     0B0h
LuDier          equ     0B1h
LcapCCed        equ     0B2h
LcCed           equ     0B3h
LcapNTilde      equ     0B4h
LnTilde         equ     0B5h
Laccent         equ     0B6h
Lgrave          equ     0B7h
Ldieresis       equ     0B8h
LquesDown       equ     0B9h
LexclamDown     equ     0BAh
Lalpha          equ     0BBh
Lbeta           equ     0BCh
Lgamma          equ     0BDh
LcapDelta       equ     0BEh
Ldelta          equ     0BFh
Lepsilon        equ     0C0h
LlBrack         equ     0C1h
Llambda         equ     0C2h
Lmu             equ     0C3h
Lpi             equ     0C4h
Lrho            equ     0C5h
LcapSigma       equ     0C6h
Lsigma          equ     0C7h
Ltau            equ     0C8h
Lphi            equ     0C9h
LcapOmega       equ     0CAh
LxMean          equ     0CBh
LyMean          equ     0CCh
LsupX           equ     0CDh
Lellipsis       equ     0CEh
Lleft           equ     0CFh
Lblock          equ     0D0h
Lper            equ     0D1h
Lhyphen         equ     0D2h
Larea           equ     0D3h
Ltemp           equ     0D4h
Lcube           equ     0D5h
Lenter          equ     0D6h
LimagI          equ     0D7h
Lphat           equ     0D8h
Lchi            equ     0D9h
LstatF          equ     0DAh
Llne            equ     0DBh
LlistL          equ     0DCh
LfinanN         equ     0DDh


RealObj		EQU	$00
ListObj		EQU	$01
MatObj		EQU	$02
EquObj		EQU	$03
Strngobj	EQU	$04
progobj		EQU	$05
protprogobj	EQU	$06
PictObj		EQU	$07
GDBObj		EQU	$08
NewEquObj	EQU	$0B
CplxObj		EQU	$0C
CListObj	EQU	$0D





;                                             length (+80h for leading blank)
;       # TOKENS IN USE = 249
;						     (+40h for trailing blank)
EOSSTART        EQU       0
;
;
;   DISPLAY CONVERSIONS  COME IMMEDIATELY BEFORE 'TSTORE'
;
DCONV   EQU     01H
;
TTODMS          equ       DCONV       ; 01H
TTODEC          equ       DCONV+1     ; 02H
TTOAbc          EQU       DCONV+2     ; 03H    > A b/c
;
TSTORE          equ       DCONV+3     ; 04H Lstore                01
;
TBOXPLOT        EQU       05h
;
BRACKS          EQU       06H
;
tLBrack         equ       BRACKS      ; 06h '['
tRBrack         equ       BRACKS+1    ; 07h ']'
tLBrace         equ       BRACKS+2    ; 08h '{'
tRBrace         equ       BRACKS+3    ; 09h '}'
;
TPOST1          EQU       BRACKS+4
;
tFromRad        equ       TPOST1       ; 0Ah Lradian
tFromDeg        equ       TPOST1+1     ; 0Bh Ldegree
tRecip          equ       TPOST1+2     ; 0Ch Linverse
tSqr            equ       TPOST1+3     ; 0Dh Lsquare
tTrnspos        equ       TPOST1+4     ; 0Eh Ltranspose
TCUBE           EQU       TPOST1+5     ; 0Fh '^3'
;
tLParen         equ       10H         ; 10h '('
tRParen         equ       11H         ; 11h ')'
;
;
;   IMMEDIATE UNARY TOKENS GO FROM HERE TO 'EOSEL-1'
;
IMUN            EQU       12H
;
tRound          equ       IMUN        ; 12h 'round'
TPXTST          equ       IMUN+1      ; 13h 'PXL-TEST'
tAug            equ       IMUN+2      ; 14h 'aug'
tRowSwap        EQU       IMUN+3      ; 15h 'rSwap'
tRowPlus        equ       IMUN+4      ; 16h 'rAdd'
tmRow           EQU       IMUN+5      ; 17h 'multR'
tmRowPlus       EQU       IMUN+6      ; 18h 'mRAdd'
tMax            equ       IMUN+7      ; 19H 'max'
tMin            equ       IMUN+8      ; 1AH 'min'
TRTOPr          EQU       IMUN+9      ; 1BH 'R>Pr
TRTOPo          EQU       IMUN+10     ; 1CH 'R>Po
TPTORx          EQU       IMUN+11     ; 1DH 'P>Rx
TPTORy          EQU       IMUN+12     ; 1EH 'P>Ry
tMEDIAN         equ       IMUN+13     ; 1Fh 'MEDIAN
tRandM          equ       IMUN+14     ; 20h 'randM'
TMEAN           EQU       IMUN+15     ; 21h
TROOT           EQU       IMUN+16     ; 22h 'ROOT'
tSeries         equ       IMUN+17     ; 23h 'seq'
tFnInt          equ       IMUN+18     ; 24h 'fnInt'
tNDeriv         equ       IMUN+19     ; 25h 'fnIr'
TEVALF          EQU       IMUN+20     ; 26h
TFMIN           EQU       IMUN+21     ; 27h
TFMAX           EQU       IMUN+22     ; 28h
;
;
;
;  TOKEN 29H CANNOT BE AN EOS FUNCTION SINCE EL(=29H ALREADY
;
tEOSEL          EQU       IMUN+23
;
TSPACE          EQU       tEOSEL       ; 29h   ' '
tString         equ       tEOSEL+1     ; 2Ah  '"'
tComma          equ       tEOSEL+2     ; 2Bh  ','
;
;
;
Tii             equ       2Ch         ; i
;
; ===== Postfix functions
;
TPOST           EQU       2Dh
;
tFact           equ       TPOST       ; 2Dh '!'



TCUBICR         EQU       2Eh
TQUARTR         EQU       2Fh

;
;       NUMBER TOKENS
;
NUMS            EQU       30h
;
T0              EQU       NUMS        ; 30h
T1              EQU       NUMS+1      ; 31h
T2              EQU       NUMS+2      ; 32h
T3              EQU       NUMS+3      ; 33h
T4              EQU       NUMS+4      ; 34h
T5              EQU       NUMS+5      ; 35h
T6              EQU       NUMS+6      ; 36h
T7              EQU       NUMS+7      ; 37h
T8              EQU       NUMS+8      ; 38h
T9              EQU       NUMS+9      ; 39h
TDECPT          EQU       NUMS+10     ; 3Ah
Tee             EQU       NUMS+11     ; 3Bh
;
;   BINARY OP
;
tOr             equ       3Ch         ; 3Ch  '_or_'
TXOR            equ       3Dh         ; 3Dh
;
tColon          equ       3Eh         ; 3Eh ':'
tEnter          equ       3Fh         ; 3Fh  Lenter
;
;   BINARY OP
;
tAnd            equ       40h         ; 40h  '_and_'               05
;
;       LETTER TOKENS
;
LET             EQU       41h
;
TA              EQU       LET         ; 41h
TB              EQU       LET+1       ; 42h
TC              EQU       LET+2       ; 43h
TD              EQU       LET+3       ; 44h
TE              EQU       LET+4       ; 45h
TF              EQU       LET+5       ; 46h
TG              EQU       LET+6       ; 47h
TH              EQU       LET+7       ; 48h
TI              EQU       LET+8       ; 49h
TJ              EQU       LET+9       ; 4Ah
TK              EQU       LET+10      ; 4Bh
TL              EQU       LET+11      ; 4Ch
TM              EQU       LET+12      ; 4Dh
TN              EQU       LET+13      ; 4Eh
TO              EQU       LET+14      ; 4Fh
TP              EQU       LET+15      ; 50h
TQ              EQU       LET+16      ; 51h
TR              EQU       LET+17      ; 52h
TS              EQU       LET+18      ; 53h
TT              EQU       LET+19      ; 54h
TU              EQU       LET+20      ; 55h
TV              EQU       LET+21      ; 56h
TW              EQU       LET+22      ; 57h
TX              EQU       LET+23      ; 58h
TY              EQU       LET+24      ; 59h
TZ              EQU       LET+25      ; 5Ah
TTHETA          EQU       LET+26      ; 5Bh
;
;
;   THESE VAR TOKENS ARE 1ST OF A DOUBLE TOKEN
;
;   SEE 'VARS.DOC' FOR MORE INFO ON VARS
;
VTOKS   EQU     LET+27    ;
;
;       USER MATRIX TOKEN, 2ND TOKEN NEEDED FOR NAME
;
TVARMAT         EQU       VTOKS       ; 5Ch
;
;       USER LIST TOKEN, 2ND TOKEN NEEDED FOR NAME
;
TVARLST         EQU       VTOKS+1     ; 5Dh
;
;       USER EQUATION TOKEN, 2ND TOKEN NEEDED FOR NAME
;
TVAREQU         EQU       VTOKS+2     ; 5Eh
;
;       THIS IS A SINGLE TOKEN, I WILL HAVE TO READ THE NAME IN
;       EVERY SINGLE TIME I EXECUTE
;
TPROG           EQU       VTOKS+3     ; 5Fh
;
;       USER PICT TOKEN, 2ND TOKEN NEEDED FOR NAME
;
TVARPICT        EQU       VTOKS+4     ; 60h
;
;       USER GDB TOKEN, 2ND TOKEN NEEDED FOR NAME
;
TVARGDB         EQU       VTOKS+5     ; 61h
;
;       SYSTEM VARS THAT ARE USED FOR OUTPUT ONLY
;       CANNOT BE STORED TO BY THE USER
;
tVarOut         equ       VTOKS+6     ; 62h
;
;       SYSTEM VARS THAT ARE NOT IN THE SYMBOL TABLE
;       BUT THE USER CAN STORE TO THEM.
;
tVarSys         equ       VTOKS+7     ; 63h
;
;
; ===== Mode setting commands
;
MODESA          EQU       VTOKS+8     ; 64h
;
tRad            equ       MODESA      ; 64h 'Radian'
tDeg            equ       MODESA+1    ; 65h 'Degree'
tNormF          equ       MODESA+2    ; 66h 'Normal'
tSci            equ       MODESA+3    ; 67h 'Sci'
tEng            equ       MODESA+4    ; 68h 'Eng'
tFloat          equ       MODESA+5    ; 69h 'Float'
;
CMPS            EQU       6Ah
;
tEQ             equ       CMPS        ; 6Ah '=='
tLT             equ       CMPS+1      ; 6Bh '<'
tGT             equ       CMPS+2      ; 6Ch '>'
tLE             equ       CMPS+3      ; 6Dh LLE
tGE             equ       CMPS+4      ; 6Eh LGE
tNE             equ       CMPS+5      ; 6Fh LNE
;
;   BINARY OP
;
tAdd            equ       70h         ; 70h '+'
tSub            equ       71h         ; 71h '-'
;
TANS            EQU       72H         ; 72h
;
; ===== Mode setting commands
;
MODES           EQU       73h
;
tFix            equ       MODES       ; 73h 'Fix_'
TSPLITON        equ       MODES+1     ; 74h
TFULLSCREEN     EQU       MODES+2     ; 75h
tStndrd         EQU       MODES+3     ; 76h 'Func'
tParam          equ       MODES+4     ; 77h 'Param'
tPolar          EQU       MODES+5     ; 78h 'Pol'
TSEQG           equ       MODES+6     ; 79h
TAFILLON        equ       MODES+7     ; 7Ah 'AUTO FILL ON
TAFILLOFF       equ       MODES+8     ; 7Bh
TACALCON        EQU       MODES+9     ; 7Ch
TACALCOFF       equ       MODES+10    ; 7Dh 'AUTOFILL OFF
;
;
;       GRAPH FORMAT TOKENS ARE 2 BYTE TOKENS
;
TGFORMAT        EQU       MODES+11    ; 7Eh
;
TBOXICON        equ       7Fh
TCROSSICON      EQU       80h
TDOTICON        EQU       81h
;
;       BINARY OP
;
tMul            equ       82h         ; 82h  '*'
tDiv            equ       83h         ; 83h  '/'
;
;       SOME GRAPH COMMANDS
;
GRCMDS          EQU       84h
;
tTrace          equ       GRCMDS      ; 84h 'Trace'
tClDrw          equ       GRCMDS+1    ; 85h 'ClDrw'
tZoomStd        equ       GRCMDS+2    ; 86h 'ZStd'
tZoomtrg        equ       GRCMDS+3    ; 87h 'Ztrg'
tZOOMBOX        EQU       GRCMDS+4    ; 88h 'ZBOX'
tZoomIn         equ       GRCMDS+5    ; 89h 'ZIn'
tZoomOut        equ       GRCMDS+6    ; 8Ah 'ZOut'
tZoomSqr        equ       GRCMDS+7    ; 8Bh 'ZSqr'
tZoomInt        equ       GRCMDS+8    ; 8Ch 'ZInt'
tZoomPrev       equ       GRCMDS+9    ; 8Dh 'ZPrev'
tZoomDec        equ       GRCMDS+10   ; 8Eh 'ZDecm'
TZOOMSTAT       EQU       GRCMDS+11   ; 8Fh 'ZSTAT
tUsrZm          equ       GRCMDS+12   ; 90h 'ZRcl'
tPrtScrn        equ       GRCMDS+13   ; 91h 'PrtScrn'
tZOOMSTO        EQU       GRCMDS+14   ; 92H  ZOOM STORE
TTEXT           EQU       GRCMDS+15   ; 93h
;
;       BINARY OP
;
tnPr            equ       GRCMDS+16   ; 94h '_nPr_'
tnCr            equ       GRCMDS+17   ; 95h '_nCr_'
;
;       MORE GRAPH COMMANDS
;
tYOn            equ       GRCMDS+18   ; 96h 'FnOn_'
tYOff           equ       GRCMDS+19   ; 97h 'FnOff_'
tStPic          equ       GRCMDS+20   ; 98h 'StPic_'
tRcPic          equ       GRCMDS+21   ; 99h 'RcPic_'
tStoDB          equ       GRCMDS+22   ; 9Ah 'StGDB_'
tRclDB          equ       GRCMDS+23   ; 9Bh 'RcGDB_'
tLine           equ       GRCMDS+24   ; 9Ch 'Line'
tVert           equ       GRCMDS+25   ; 9Dh 'Vert_'
tPtOn           equ       GRCMDS+26   ; 9Eh 'PtOn'
tPtOff          equ       GRCMDS+27   ; 9Fh 'PtOff'
;
;  TOKEN A0 CANNOT BE AN EOS FUNCTION SINCE LOW MULT=A0 ALREADY
;
tPtChg          equ       GRCMDS+28   ; A0h 'PtChg'
TPXON           EQU       GRCMDS+29   ; A1h
TPXOFF          EQU       GRCMDS+30   ; A2h
TPXCHG          EQU       GRCMDS+31   ; A3h
tShade          equ       GRCMDS+32   ; A4h 'Shade'
tCircl          equ       GRCMDS+33   ; A5h 'Circl'
tHORZ           equ       GRCMDS+34   ; A6h 'HORIZONTAL'
tTanLn          equ       GRCMDS+35   ; A7h 'TanLn'
tDrInv          equ       GRCMDS+36   ; A8h 'DrInv_'
tDrawF          equ       GRCMDS+37   ; A9h 'DrawF_'
;
TVARSTRNG       EQU       0AAh
;
; ===== Functions with no arguments
;
NOARG   EQU     0ABh
;
tRand           equ       NOARG       ; ABh 'rand'
tPi             equ       NOARG+1     ; ACh  Lpi
tGetKey         equ       NOARG+2     ; ADh 'getKy'
;
;
TAPOST          EQU       TGETKEY+1   ; APOSTROPHY
TQUEST          EQU       TAPOST+1    ; QUESTION MARK
;
;
; ===== Unary functions
;
;       UNARY : THESE UNARY FUNCTIONS TAKE A COMBINATION OF
;               ARGUMENTS, REAL,LIST,MATRIX
;
UNARY   EQU     TQUEST+1              ; B0h
;
tChs            equ       UNARY       ; B0h
tInt            equ       UNARY+1     ; B1h
TABS            equ       UNARY+2     ; B2h
tDet            equ       UNARY+3     ; B3h
tIdent          equ       UNARY+4     ; B4h
tDim            equ       UNARY+5     ; B5h
tSum            equ       UNARY+6     ; B6h
tProd           equ       UNARY+7     ; B7h
tNot            equ       UNARY+8     ; B8h
tIPart          equ       UNARY+9     ; B9h
tFPart          equ       UNARY+10    ; BAh
;
;
;       NEW 2 BYTE TOKENS
;
T2BYTETOK       EQU       0BBh         ;
;
;
;       UNARYLR : UNARY FUNCTIONS THAT ONLY WORK WITH
;                 REAL NUMBERS AND LISTS
;
UNARYLR EQU     UNARY+12
;
tSqrt           equ       UNARYLR     ; BCh
TCUBRT          equ       UNARYLR+1   ; BDh
tLn             equ       UNARYLR+2   ; BEh
tExp            equ       UNARYLR+3   ; BFh
tLog            equ       UNARYLR+4   ; C0h
tALog           equ       UNARYLR+5   ; C1h
tSin            equ       UNARYLR+6   ; C2h
tASin           equ       UNARYLR+7   ; C3h
tCos            equ       UNARYLR+8   ; C4h
tACos           equ       UNARYLR+9   ; C5h
tTan            equ       UNARYLR+10  ; C6h
tATan           equ       UNARYLR+11  ; C7h
tSinh           equ       UNARYLR+12  ; C8h
tASinh          equ       UNARYLR+13  ; C9h
tCosh           equ       UNARYLR+14  ; CAh
tACosh          equ       UNARYLR+15  ; CBh
tTanh           equ       UNARYLR+16  ; CCh
tATanh          equ       UNARYLR+17  ; CDh
;
;       SOME PROGRAMMING COMMANDS
;
PROGTOK EQU     UNARYLR+18
;
tIf             equ       PROGTOK     ; CEh
tThen           equ       PROGTOK+1   ; CFh
tElse           equ       PROGTOK+2   ; D0h
tWhile          equ       PROGTOK+3   ; D1h
tRepeat         equ       PROGTOK+4   ; D2h
tFor            equ       PROGTOK+5   ; D3h
tEnd            equ       PROGTOK+6   ; D4h
tReturn         equ       PROGTOK+7   ; D5h
tLbl            equ       PROGTOK+8   ; D6h   'Lbl_'
tGoto           equ       PROGTOK+9   ; D7h   'Goto_'
tPause          equ       PROGTOK+10  ; D8h   'Pause_'
tStop           equ       PROGTOK+11  ; D9h   'Stop'
tISG            equ       PROGTOK+12  ; DAh   'IS>'
tDSL            equ       PROGTOK+13  ; DBh   'DS<'
tInput          equ       PROGTOK+14  ; DCh   'Input_'
tPrompt         equ       PROGTOK+15  ; DDh   'Prompt_'
tDisp           equ       PROGTOK+16  ; DEh   'Disp_'
tDispG          equ       PROGTOK+17  ; DFh   'DispG'
;
;  TOKEN E0 CANNOT BE AN EOS FUNCTION SINCE HI MU
;
tOutput         equ       PROGTOK+18  ; E0H    'Outpt'
tClLCD          equ       PROGTOK+19  ; E1H    'ClLCD'
tConst          equ       PROGTOK+20  ; E2H    'Fill'
tSortA          equ       PROGTOK+21  ; E3H    'sortA_'
tSortD          equ       PROGTOK+22  ; E4H    'sortD_'
TDISPTAB        EQU       PROGTOK+23  ; E5h    'DISP TABLE
tMenu           equ       PROGTOK+24  ; E6H    'Menu'
tSENDMBL        EQU       PROGTOK+25  ; E7H    'SEND'
tGETMBL         EQU       PROGTOK+26  ; E8H    'GET'
;
;       STAT PLOT COMMANDS
;
STATPCMD        EQU       PROGTOK+27
;
TPLOTON         EQU       STATPCMD    ; E9h     ' PLOTSON'
TPLOTOFF        EQU       STATPCMD+1   ; EAh     ' PLOTSOFF
;
TLISTNAME       EQU       0EBH        ; LIST DESIGNATOR
;
;
;
TPLOT1          EQU       0ECH
TPLOT2          EQU       0EDH
TPLOT3          EQU       0EEH
;
tPower          equ       0F0h        ;        '^'
tXRoot          equ       0F1h        ;        LsupX,Lroot

STATCMD         EQU       0F2h
;
tOneVar         equ       STATCMD     ; F2h    'OneVar_'
TTWOVAR         EQU       STATCMD+1   ; F3h
tLR             equ       STATCMD+2   ; F4h    'LinR(A+BX
tLRExp          equ       STATCMD+3   ; F5h    'ExpR_'
tLRLn           equ       STATCMD+4   ; F6h    'LnR_'
tLRPwr          equ       STATCMD+5   ; F7h    'PwrR_'
TMEDMED         EQU       STATCMD+6   ; F8h
TQUAD           EQU       STATCMD+7   ; F9h
tCLRLST         equ       STATCMD+8   ; FAh    'CLEAR LIST
TCLRTBL         EQU       STATCMD+9   ; FBH    CLEAR TABLE
tHist           equ       STATCMD+10  ; FCh    'Hist_'
txyLine         equ       STATCMD+11  ; FDH    'xyline_'
tScatter        equ       STATCMD+12  ; FEh    'Scatter_'
tLR1            equ       STATCMD+13  ; FFh    'LINR(AX+B
;
; 2ND HALF OF GRAPH FORMAT TOKENS
;
; ===== Format settings commands
;
GFMT            EQU       0
;
tSeq            equ       GFMT        ; 'SeqG'
tSimulG         equ       GFMT+1      ; 'SimulG'
tPolarG         equ       GFMT+2      ; 'PolarGC'
tRectG          equ       GFMT+3      ; 'RectGC'
tCoordOn        equ       GFMT+4      ; 'CoordOn'
tCoordOff       equ       GFMT+5      ; 'CoordOff'
tDrawLine       equ       GFMT+6      ; 'DrawLine'
tDrawDot        equ       GFMT+7      ; 'DrawDot'
tAxisOn         equ       GFMT+8      ; 'AxesOn'
tAxisOff        equ       GFMT+9      ; 'AxesOff'
tGridOn         equ       GFMT+10     ; 'GridOn'
tGridOff        equ       GFMT+11     ; 'GridOff'
tLblOn          equ       GFMT+12     ; 'LabelOn'
tLblOff         equ       GFMT+13     ; 'LabelOff'
tWebOn          equ       GFMT+14     ; 'WebOn'
tWebOff         equ       GFMT+15     ; 'WebOFF'
TUV             EQU       GFMT+16     ; U vs V
TVW             EQU       GFMT+17     ; V vs W
TUW             EQU       GFMT+18     ; U vs W
;
;       2ND HALF OF USER MATRIX TOKENS
;
TMATA           EQU       00h         ; MAT A
TMATB           EQU       01h         ; MAT B
TMATC           EQU       02h         ; MAT C
TMATD           EQU       03h         ; MAT D
TMATE           EQU       04h         ; MAT E
TMATF           EQU       05h         ; MAT F
TMATG           EQU       06h         ; MAT G
TMATH           EQU       07h         ; MAT H
TMATI           EQU       08h         ; MAT I
TMATJ           EQU       09h         ; MAT J
;
;       2ND HALF OF USER LIST TOKENS
;
TL1             EQU       00h         ; LIST 1
TL2             EQU       01h         ; LIST 2
TL3             EQU       02h         ; LIST 3
TL4             EQU       03h         ; LIST 4
TL5             EQU       04h         ; LIST 5
TL6             EQU       05h         ; LIST 6
;
;       2ND HALF OF USER EQUATION TOKENS
;
;
;       "Y" EQUATIONS HAVE BIT 4 SET
;
TY1             EQU       10h         ; Y1
TY2             EQU       11h         ; Y2
TY3             EQU       12h         ; Y3
TY4             EQU       13h         ; Y4
TY5             EQU       14h         ; Y5
TY6             EQU       15h         ; Y6
TY7             EQU       16h         ; Y7
TY8             EQU       17h         ; Y8
TY9             EQU       18h         ; Y9
TY0             EQU       19H         ; Y0
;
;       PARAM EQUATIONS HAVE BIT 5 SET
;
TX1T            EQU       20h         ; X1t
TY1T            EQU       21h         ; Y1t
TX2T            EQU       22h         ; X2t
TY2T            EQU       23h         ; Y2t
TX3T            EQU       24h         ; X3t
TY3T            EQU       25h         ; Y3t
TX4T            EQU       26h         ; X4t
TY4T            EQU       27h         ; Y4t
TX5T            EQU       28h         ; X5t
TY5T            EQU       29h         ; Y5t
TX6T            EQU       2Ah         ; X6t
TY6T            EQU       2Bh         ; Y6t
;
;       POLAR EQUATIONS HAVE BIT 6 SET
;
TR1             EQU       40h         ; R1
TR2             EQU       41h         ; R2
TR3             EQU       42h         ; R3
TR4             EQU       43h         ; R4
TR5             EQU       44h         ; R5
TR6             EQU       45h         ; R6
;
;       RECURSION EQUATIONS HAVE BIT 7 SET
;
TUN             EQU       80h         ; Un
TVN             EQU       81h         ; Vn
TWN             EQU       82h         ; Wn
;
;       2ND HALF OF USER PICTURE TOKENS
;
TPIC1           EQU       00h         ; PIC1
TPIC2           EQU       01h         ; PIC2
TPIC3           EQU       02h         ; PIC3
TPIC4           EQU       03h         ; PIC4
TPIC5           EQU       04h         ; PIC5
TPIC6           EQU       05h         ; PIC6
TPIC7           EQU       06h         ; PIC7
TPIC8           EQU       07h         ; PIC8
TPIC9           EQU       08h         ; PIC9
TPIC0           EQU       09h         ; PIC0
;
;       2ND HALF OF USER GRAPH DATABASE TOKENS
;
TGDB1           EQU       00h         ; GDB1
TGDB2           EQU       01h         ; GDB2
TGDB3           EQU       02h         ; GDB3
TGDB4           EQU       03h         ; GDB4
TGDB5           EQU       04h         ; GDB5
TGDB6           EQU       05h         ; GDB6
TGDB7           EQU       06h         ; GDB7
TGDB8           EQU       07h         ; GDB8
TGDB9           EQU       08h         ; GDB9
TGDB0           EQU       09h         ; GDB0
;
;       2ND HALF OF STRING VARS
;
TSTR1           EQU       00h
TSTR2           EQU       01h
TSTR3           EQU       02h
TSTR4           EQU       03h
TSTR5           EQU       04h
TSTR6           EQU       05h
TSTR7           EQU       06h
TSTR8           EQU       07h
TSTR9           EQU       08h
TSTR0           EQU       09h
;
;       2ND HALF OF SYSTEM OUTPUT ONLY VARIABLES
;
;
;   OPEN        EQU       00H
;
TREGEQ          EQU       01h         ; REGRESSION EQUATION
;
TSTATN          EQU       02h         ; STATISTICS N
;
TXMEAN          EQU       03h         ; X MEAN
TSUMX           EQU       04h         ; SUM(X)
TSUMXSQR        EQU       05h         ; SUM(X^2)
TSTDX           EQU       06h         ; STANDARD DEV X
TSTDPX          EQU       07h         ; STANDARD DEV POP X
TMINX           EQU       08h         ; MIN X VALUE
TMAXX           EQU       09h         ; MAX X VALUE
;
TMINY           EQU       0Ah         ; MIN Y VALUE
TMAXY           EQU       0Bh         ; MAX Y VALUE
TYMEAN          EQU       0Ch         ; Y MEAN
TSUMY           EQU       0Dh         ; SUM(Y)
TSUMYSQR        EQU       0Eh         ; SUM(Y^2)
TSTDY           EQU       0Fh         ; STANDARD DEV Y
TSTDPY          EQU       10h         ; STANDARD DEV POP Y
;
TSUMXY          EQU       11h         ; SUM(XY)
TCORR           EQU       12h         ; CORRELATION
TMEDX           EQU       13h         ; MED(X)
TQ1             EQU       14h         ; 1ST QUADRANT OF X
TQ3             EQU       15h         ; 3RD QUADRANT OF X
TQUADa          EQU       16h         ; 1ST TERM OF QUAD POLY REG/ Y-INT
TQUADb          EQU       17h         ; 2ND TERM OF QUAD POLY REG/ SLOPE
TQUADc          EQU       18h         ; 3RD TERM OF QUAD POLY REG
TCUBEd          EQU       19h         ; 4TH TERM OF CUBIC POLY REG
TQUARTe         EQU       1Ah         ; 5TH TERM OF QUART POLY REG
TMEDX1          EQU       1Bh         ; x1 FOR MED-MED
TMEDX2          EQU       1Ch         ; x2 FOR MED-MED
TMEDX3          EQU       1Dh         ; x3 FOR MED-MED
TMEDY1          EQU       1Eh         ; y1 FOR MED-MED
TMEDY2          EQU       1Fh         ; y2 FOR MED-MED
TMEDY3          EQU       20h         ; y3 FOR MED-MED
;
TRECURN           EQU       21h       ; RECURSION N
TSTATP          EQU       22h
TSTATZ          EQU       23h
TSTATT          EQU       24h
TSTATCHI        EQU       25h
TSTATF          EQU       26h
TSTATDF         EQU       27h
TSTATPHAT       EQU       28h
TSTATPHAT1      EQU       29h
TSTATPHAT2      EQU       2Ah
TSTATMEANX1     EQU       2Bh
TSTATSTDX1      EQU       2Ch
TSTATN1         EQU       2Dh
TSTATMEANX2     EQU       2Eh
TSTATSTDX2      EQU       2Fh
TSTATN2         EQU       30h
TSTATSTDXP      EQU       31h
TSTATLOWER      EQU       32h
TSTATUPPER      EQU       33h
TSTAT_S         EQU       34h
TLRSQR          EQU       35h         ; r^2
TBRSQR          EQU       36h         ; R^2
;
;       these next tokens are only used to acess the data
;       they are display only and the user cannot access them at all
;
TF_DF    EQU     37h       ; ANOFAV FACTOR DF
TF_SS    EQU     38h       ; ANOFAV FACTOR SS
TF_MS    EQU     39h       ; ANOFAV FACTOR MS
TE_DF    EQU     3Ah       ; ANOFAV ERROR DF
TE_SS    EQU     3Bh       ; ANOFAV ERROR SS
TE_MS    EQU     3Ch       ; ANOFAV ERROR MS
;
;
;       2ND HALF OF SYSTEM INPUT/OUTPUT VARIABLES
;

; SYSTEM VARIABLE EQUATES
;
;       VARS WITH NO RESTRICTION
;
TUXSCL       EQU  0
TUYSCL       EQU  1
TXSCL        EQU  2
TYSCL        EQU  3
TRECURU0     EQU  4        ; U 1ST INITIAL COND
TRECURV0     EQU  5        ; V 1ST INITIAL COND
TUN1         EQU  6        ; U(N-1)    ; NOT USED
TVN1         EQU  7        ; V(N-1)    ; NOT USED
TURECURU0    EQU  8        ;
TURECURV0    EQU  9        ;
;
;       VARS ROUNDED TO 10 DIGITS
;
TXMIN        EQU  0AH
TXMAX        EQU  0BH
TYMIN        EQU  0CH
TYMAX        EQU  0DH
TTMIN        EQU  0EH
TTMAX        EQU  0FH
TTHETAMIN    EQU  10H
TTHETAMAX    EQU  11H
TUXMIN       EQU  12H
TUXMAX       EQU  13H
TUYMIN       EQU  14H
TUYMAX       EQU  15H
TUTHETMIN    EQU  16H
TUTHETMAX    EQU  17H
TUTMIN       EQU  18H
TUTMAX       EQU  19H
TTBLMIN      EQU  1AH
TPLOTSTART   EQU  1BH
TUPLOTSTART  EQU  1CH
TNMAX        EQU  1DH
TUNMAX       EQU  1EH
TNMIN        EQU  1FH
TUNMIN       EQU  20H
;
;       VARS CANNOT BE 0
;
TTBLSTEP     EQU  21H
TTSTEP       EQU  22H
TTHETASTEP    EQU  23H
TUTSTEP      EQU  24H
TUTHETSTEP     EQU  25H
;
;       SPECIAL LIMITS ON THESE
;
TDELTAX      EQU  26H
TDELTAY      EQU  27H
;
;       SPECIAL LIMITS ON THESE
;
TXFACT       EQU  28H
TYFACT       EQU  29H
;
TTBLINPUT       EQU       2Ah
;
;       ANY RESTRICTIONS ??????
;
TFINn           EQU       2Bh
TFINi           EQU       2Ch
TFINpv          EQU       2Dh
TFINpmt         EQU       2Eh
TFINfv          EQU       2Fh
TFINpy          EQU       30h
TFINcy          EQU       31h
;
TRECURW0        EQU       32h         ; W0(1)
TURECURW0       EQU       33h
;
TPLOTSTEP       EQU       34h
TUPLOTSTEP      EQU       35h
;
TXRES           EQU       36h
TUXRES          EQU       37h
;
;       ALL THE TOKENS BELOW DO NOT HAVE STRINGS ASSOCIATED
;       THEY ARE HERE JUST FOR STORING AND RECALLING
;
TRECURU02       EQU       38h         ; U0(2)
TURECURU02      EQU       39h
TRECURV02       EQU       3Ch         ; V0(2)
TURECURV02      EQU       3Dh
TRECURW02       EQU       3Eh         ; W0(2)
TURECURW02      EQU       3Fh
;
; NO RESTRICTIONS
;
;TWN1           EQU       40h         ; W(N-1)
;UN2           EQU       41h         ; U(N-2)
;VN2           EQU       42h         ; V(N-2)
;WN2           EQU       43h         ; W(N-2)
;
;
;       DON'T KNOW IF NEED THESE YET ?
;
;TUI12
;TUI22
;TUUI12
;TUUI22
;
;

TFINnpv         EQU       00h         ; immediate unary
TFINirr         EQU       01h         ; immediate unary
TFINbal         EQU       02h         ; immediate unary
TFINprn         EQU       03h         ; immediate unary
TFINint         EQU       04h         ; immediate unary
TFINtonom       EQU       05h         ; immediate unary
TFINtoeff       EQU       06h         ; immediate unary
TFINdbd         EQU       07h         ; immediate unary
TLCM            EQU       08h         ; immediate unary
TGCD            EQU       09h         ; immediate unary
TRANDINT        EQU       0Ah         ; immediate unary
TRANDBIN        EQU       0Bh         ; immediate unary
TSUBSTRNG       EQU       0Ch         ; immediate unary
TSTDDEV         EQU       0Dh         ; immediate unary
TVARIANCE       EQU       0Eh         ; immediate unary
TINSTRNG        EQU       0Fh         ; immediate unary
TDNORMAL        EQU       10h         ; immediate unary
TINVNORM        EQU       11h         ; immediate unary
TDT             EQU       12h         ; immediate unary
TCHI            EQU       13h         ; immediate unary
TDF             EQU       14h         ; immediate unary
TBINPDF         EQU       15h         ; immediate unary
TBINCDF         EQU       16h         ; immediate unary
TPOIPDF         EQU       17h         ; immediate unary
TPOICDF         EQU       18h         ; immediate unary
TGEOPDF         EQU       19h         ; immediate unary
TGEOCDF         EQU       1Ah         ; immediate unary
TNORMALPDF      EQU       1Bh         ; immediate unary
TTPDF           EQU       1Ch         ; immediate unary
TCHIPDF         EQU       1Dh         ; immediate unary
TFPDF           EQU       1Eh         ; immediate unary
;TRANDBIN        EQU       1Fh         ; immediate unary
TRANDNORM       EQU       1Fh         ; immediate unary
TFINFpmt        EQU       20h         ; 0 or multy arg function
TFINFi          EQU       21h         ; 0 or multy arg function
TFINFpv         EQU       22h         ; 0 or multy arg function
TFINFn          EQU       23h         ; 0 or multy arg function
TFINFfv         EQU       24h         ; 0 or multy arg function
TCONJ           EQU       25h         ; unary
TREAL           EQU       26h         ; unary
TIMAG           EQU       27h         ; unary
TANGLE          EQU       28h         ; unary
TCUMSUM         EQU       29h         ; unary
TEXPR           EQU       2Ah         ; unary
TLENGTH         EQU       2Bh         ; unary
TDELTALST       EQU       2Ch         ; unary
TREF            EQU       2Dh         ; unary
TRREF           EQU       2Eh         ; unary
TTORECT         EQU       2Fh         ; display conversion
TTOPOLAR        EQU       30h         ; display conversion
TCONSTE         EQU       31h         ; function no arg
TSINREG         EQU       32h         ; command opt push
TLOGISTIC       EQU       33h         ; command opt push
TLINREGTTEST    EQU       34h         ; command opt push
TSHADENORM      EQU       35h         ; command pushed
TSHADET         EQU       36h         ; command pushed
TSHADECHI       EQU       37h         ; command pushed
TSHADEF         EQU       38h         ; command pushed
TMATTOLST       EQU       39h         ; command pushed
TLSTTOMAT       EQU       3Ah         ; command pushed
TZTEST          EQU       3Bh         ; command pushed
TTTEST          EQU       3Ch         ; command pushed
T2SAMPZTEST     EQU       3Dh         ; command pushed
T1PROPZTEST     EQU       3Eh         ; command pushed
T2PROPZTEST     EQU       3Fh         ; command pushed
TCHITEST        EQU       40h         ; command pushed
TZINTVAL        EQU       41h         ; command pushed
T2SAMPZINT      EQU       42h         ; command pushed
T1PROPZINT      EQU       43h         ; command pushed
T2PROPZINT      EQU       44h         ; command pushed
TGRAPHSTYLE     EQU       45h         ; command pushed
T2SAMPTTEST     EQU       46h         ; command opt pushed
T2SAMPFTEST     EQU       47h         ; command opt pushed
TTINTVAL        EQU       48h         ; command opt pushed
T2SAMPTINT      EQU       49h         ; command opt pushed
TSETUPLST       EQU       4Ah         ; command opt pushed
TFINpmtend      EQU       4Bh         ; mode command
TFINpmtbeg      EQU       4Ch         ; mode command
TREALM          EQU       4Dh         ; mode command
TPOLARM         EQU       4Eh         ; mode command
TRECTM          EQU       4Fh         ; mode command
TEXPRON         EQU       50h         ; mode command
TEXPROFF        EQU       51h         ; mode command
TCLRALLLST      EQU       52h         ; command not pushed
TGETCALC        EQU       53h         ; command not pushed
TDELVAR         EQU       54h         ; command not pushed
TEQUTOSTRNG     EQU       55h         ; command not pushed
TSTRNGTOEQU     EQU       56h         ; command not pushed
tdellast        EQU       57h         ; command not pushed
TSELECT         EQU       58h         ; command not pushed
TANOVA          EQU       59h         ; command not pushed
TMODBOX         EQU       5Ah         ; icon
TNORMPROB       EQU       5Bh         ; icon
;
;       tokens 5Ch to 63h CANNOT BE THE 2ND BYTE OF
;       TWO BYTE TOKENS. THESE ARE ALREADY THE 1ST BYTE VALUE
;       OF TWO BYTE TOKENS. READING TOKENS BACKWARDS WILL NOT
;       WORK IF THIS RESTRICTION IS NOT IN PLACE.
;
;
;       NO USE  EQU       5Ch
;       NO USE  EQU       5Dh
;       NO USE  EQU       5Eh
;       NO USE  EQU       5Fh
;       NO USE  EQU       60h
;       NO USE  EQU       61h
;       NO USE  EQU       62h
;       NO USE  EQU       63h
;
TMGT            EQU       64h         ; VERTICAL SPLIT
TZFIT           EQU       65h         ; ZOOM FIT
TDIAG_ON        EQU       66h         ; DIANOSTIC DISPLAY ON
TDIAG_OFF       EQU       67h         ; DIANOSTIC DISPLAY OFF
;
;



