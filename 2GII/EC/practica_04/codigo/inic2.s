
	.data   0

	.global a
a:      .double 3.14159265358979

	.global x
x:      .double 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
	.double 17,18,19,20,21,22,23

	.global xtop
xtop:   .double 24


	.text   256

start:  ld      f2,a
	add     r1,r0,xtop
loop:   ld      f0,0(r1)
	multd   f4,f0,f2
	sd      0(r1),f4
	ld      f6,-8(r1)
	multd   f8,f6,f2
	sd      -8(r1),f8
	ld      f10,-16(r1)
	multd   f12,f10,f2
	sd      -16(r1),f12
	ld      f14,-24(r1)
	multd   f16,f14,f2
	sd      -24(r1),f16
	ld      f18,-32(r1)
	multd   f20,f18,f2
	sd      -32(r1),f20
	ld      f22,-40(r1)
	multd   f24,f22,f2
	sd      -40(r1),f24
	ld      f26,-48(r1)
	multd   f28,f26,f2
	sd      -48(r1),f28
	ld      f30,-56(r1)
	multd   f16,f30,f2
	sd      -56(r1),f16
	sub     r1,r1,#64
	bnez    r1,loop
	nop
	trap    #0

