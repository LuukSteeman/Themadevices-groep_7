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
	.section	.text._ZN1XC2Ev,"axG",%progbits,_ZN1XC5Ev,comdat
	.align	2
	.weak	_ZN1XC2Ev
	.type	_ZN1XC2Ev, %function
_ZN1XC2Ev:
	.fnstart
.LFB1:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	mov	r2, #0
	str	r2, [r3]
	ldr	r3, [fp, #-8]
	mov	r2, #2
	str	r2, [r3, #4]
	ldr	r3, [fp, #-8]
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_ZN1XC2Ev, .-_ZN1XC2Ev
	.weak	_ZN1XC1Ev
	.set	_ZN1XC1Ev,_ZN1XC2Ev
	.section	.rodata
	.align	2
.LC0:
	.word	1
	.word	2
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	.fnstart
.LFB4:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	mov	r0, #1
	mov	r1, #8
	bl	_Z6getBitIsEbiT_
	mov	r0, #4
	mov	r1, #8
	bl	_Z6getBitIiEbiT_
	sub	r3, fp, #20
	mov	r0, r3
	bl	_ZN1XC1Ev
	mov	r0, #2
	sub	r3, fp, #20
	ldmia	r3, {r1, r2}
	bl	_Z6getBitI1XEbiT_
	ldr	r2, .L6
	sub	r3, fp, #12
	ldmia	r2, {r0, r1}
	stmia	r3, {r0, r1}
	mov	r0, #4
	sub	r3, fp, #12
	ldmia	r3, {r1, r2}
	bl	_Z6getBitI1zEbiT_
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	ldmfd	sp!, {fp, lr}
	bx	lr
.L7:
	.align	2
.L6:
	.word	.LC0
	.cantunwind
	.fnend
	.size	main, .-main
	.align	2
	.type	_Z6getBitIsEbiT_, %function
_Z6getBitIsEbiT_:
	.fnstart
.LFB5:
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
	bls	.L9
	mov	r3, #0
	b	.L10
.L9:
	mov	r3, #1
.L10:
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_Z6getBitIsEbiT_, .-_Z6getBitIsEbiT_
	.align	2
	.type	_Z6getBitIiEbiT_, %function
_Z6getBitIiEbiT_:
	.fnstart
.LFB6:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r3, [fp, #-8]
	mov	r2, #32
	cmp	r3, r2
	bls	.L12
	mov	r3, #0
	b	.L13
.L12:
	mov	r3, #1
.L13:
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_Z6getBitIiEbiT_, .-_Z6getBitIiEbiT_
	.align	2
	.type	_Z6getBitI1XEbiT_, %function
_Z6getBitI1XEbiT_:
	.fnstart
.LFB7:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	sub	r3, fp, #16
	stmia	r3, {r1, r2}
	ldr	r3, [fp, #-8]
	mov	r2, #64
	cmp	r3, r2
	bls	.L15
	mov	r3, #0
	b	.L16
.L15:
	mov	r3, #1
.L16:
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_Z6getBitI1XEbiT_, .-_Z6getBitI1XEbiT_
	.align	2
	.type	_Z6getBitI1zEbiT_, %function
_Z6getBitI1zEbiT_:
	.fnstart
.LFB8:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	sub	r3, fp, #16
	stmia	r3, {r1, r2}
	ldr	r3, [fp, #-8]
	mov	r2, #64
	cmp	r3, r2
	bls	.L18
	mov	r3, #0
	b	.L19
.L18:
	mov	r3, #1
.L19:
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.cantunwind
	.fnend
	.size	_Z6getBitI1zEbiT_, .-_Z6getBitI1zEbiT_
	.ident	"GCC: (15:4.9.3+svn231177-1) 4.9.3 20150529 (prerelease)"
