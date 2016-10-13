	.cpu arm7tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"test.cpp"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	.fnstart
.LFB1:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	mov	r0, #1
	mov	r1, #8
	bl	_Z6getBitIsEbiT_
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	ldmfd	sp!, {fp, lr}
	bx	lr
	.cantunwind
	.fnend
	.size	main, .-main
	.align	2
	.type	_Z6getBitIsEbiT_, %function
_Z6getBitIsEbiT_:
	.fnstart
.LFB2:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	mov	r3, r1
	strh	r3, [fp, #-10]	@ movhi
	ldr	r3, [fp, #-8]
	mov	r2, #16
	cmp	r3, r2
	bls	.L4
	mov	r3, #0
	b	.L5
.L4:
	ldrsh	r3, [fp, #-10]
	ldr	r2, [fp, #-8]
	rsb	r2, r2, #2
	mov	r3, r3, asr r2
	and	r3, r3, #1
	cmp	r3, #0
	movne	r3, #1
	moveq	r3, #0
	and	r3, r3, #255
.L5:
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_Z6getBitIsEbiT_, .-_Z6getBitIsEbiT_
	.ident	"GCC: (15:4.9.3+svn231177-1) 4.9.3 20150529 (prerelease)"
