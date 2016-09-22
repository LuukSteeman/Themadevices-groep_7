.global application

string:
  .asciz "Hello World!? [@]{\`} 12345=67890\n"
application:
	ldr R0, =string
	b print_asciz
	
