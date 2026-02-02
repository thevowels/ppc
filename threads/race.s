	.text
	.file	"race.c"
	.globl	routine                         # -- Begin function routine
	.p2align	4, 0x90
	.type	routine,@function
routine:                                # @routine
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$0, -4(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$10000, -4(%rbp)                # imm = 0x2710
	jge	.LBB0_4
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movl	mails(%rip), %eax
	addl	$1, %eax
	movl	%eax, mails(%rip)
# %bb.3:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB0_1
.LBB0_4:
	xorl	%eax, %eax
                                        # kill: def $rax killed $eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	routine, .Lfunc_end0-routine
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	leaq	-16(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	routine(%rip), %rdx
	movq	%rcx, %rsi
	callq	pthread_create@PLT
	leaq	-24(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	routine(%rip), %rdx
	movq	%rcx, %rsi
	callq	pthread_create@PLT
	movq	-16(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	callq	pthread_join@PLT
	movq	-24(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	callq	pthread_join@PLT
	movl	mails(%rip), %esi
	leaq	.L.str(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	mails,@object                   # @mails
	.bss
	.globl	mails
	.p2align	2
mails:
	.long	0                               # 0x0
	.size	mails, 4

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Mail: %d\n"
	.size	.L.str, 10

	.ident	"Ubuntu clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym routine
	.addrsig_sym pthread_create
	.addrsig_sym pthread_join
	.addrsig_sym printf
	.addrsig_sym mails
