.global switchCase

switchCase:
	push {lr}
# check Lower Case
	cmp r0, #'a'	
	bls checkUpperCase
	cmp r0, #'z'
	bhi checkUpperCase
# to Upper case
	sub	r0, r0, #('a'-'A')
	b done

checkUpperCase:
	cmp r0, #'A'
	bls done
	cmp r0, #'Z'
	bhi done
#to Lower case
	add r0, #('a'-'A')
	b done
done:	
	pop {pc}
