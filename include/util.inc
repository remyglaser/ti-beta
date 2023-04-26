#IFDEF use_util.SubHLbyDE
util.SubHLbyDE:
 ld a,e
 neg
 ld e,a
 ld a,d
 neg
 ld d,a
 dec d
 add hl,de
 ret
#ENDIF

.end
END
