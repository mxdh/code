	.file	"2018_4.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
.LFB2:
	.file 1 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/stdio.h"
	.loc 1 279 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$56, %rsp
	.seh_stackalloc	56
	.cfi_def_cfa_offset 80
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.cfi_def_cfa 6, -48
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	.loc 1 281 53
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	.loc 1 282 29
	movq	-96(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
.LVL0:
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	movl	%eax, -84(%rbp)
	.loc 1 284 10
	movl	-84(%rbp), %eax
	.loc 1 285 1
	addq	$56, %rsp
	popq	%rbx
	.cfi_restore 3
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, -40
	ret
	.cfi_endproc
.LFE2:
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB8:
	.loc 1 346 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$56, %rsp
	.seh_stackalloc	56
	.cfi_def_cfa_offset 80
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.cfi_def_cfa 6, -48
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	.loc 1 348 53
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	.loc 1 349 30
	movq	-96(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
.LVL1:
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -84(%rbp)
	.loc 1 351 10
	movl	-84(%rbp), %eax
	.loc 1 352 1
	addq	$56, %rsp
	popq	%rbx
	.cfi_restore 3
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, -40
	ret
	.cfi_endproc
.LFE8:
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d%d\0"
.LC1:
	.ascii "%d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB44:
	.file 2 "A+B Problem/2018_4.cpp"
	.loc 2 4 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	.loc 2 4 1
	call	__main
.LVL2:
	.loc 2 6 7
	leaq	-8(%rbp), %rdx
	leaq	-4(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	_Z5scanfPKcz
	.loc 2 7 8
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	_Z6printfPKcz
	.loc 2 8 9
	movl	$0, %eax
	.loc 2 9 1
	addq	$48, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE44:
	.seh_endproc
.Letext0:
	.file 3 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/cstdio"
	.file 4 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/x86_64-w64-mingw32/bits/c++config.h"
	.file 5 "C:/Program Files/mingw-w64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/include/crtdefs.h"
	.file 6 "<built-in>"
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0xa73
	.word	0x4
	.secrel32	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.ascii "GNU C++98 8.1.0 -mtune=core2 -march=nocona -g -std=gnu++98\0"
	.byte	0x4
	.ascii "A+B Problem/2018_4.cpp\0"
	.ascii "E:\\code\\C++\0"
	.secrel32	.Ldebug_ranges0+0
	.quad	0
	.secrel32	.Ldebug_line0
	.uleb128 0x2
	.ascii "std\0"
	.byte	0x6
	.byte	0
	.long	0x1ed
	.uleb128 0x3
	.ascii "__cxx11\0"
	.byte	0x4
	.word	0x104
	.byte	0x41
	.uleb128 0x4
	.byte	0x4
	.word	0x104
	.byte	0x41
	.long	0x86
	.uleb128 0x5
	.byte	0x3
	.byte	0x62
	.byte	0xb
	.long	0x39e
	.uleb128 0x5
	.byte	0x3
	.byte	0x63
	.byte	0xb
	.long	0x3ab
	.uleb128 0x5
	.byte	0x3
	.byte	0x65
	.byte	0xb
	.long	0x3bf
	.uleb128 0x5
	.byte	0x3
	.byte	0x66
	.byte	0xb
	.long	0x3dd
	.uleb128 0x5
	.byte	0x3
	.byte	0x67
	.byte	0xb
	.long	0x3f7
	.uleb128 0x5
	.byte	0x3
	.byte	0x68
	.byte	0xb
	.long	0x40f
	.uleb128 0x5
	.byte	0x3
	.byte	0x69
	.byte	0xb
	.long	0x429
	.uleb128 0x5
	.byte	0x3
	.byte	0x6a
	.byte	0xb
	.long	0x443
	.uleb128 0x5
	.byte	0x3
	.byte	0x6b
	.byte	0xb
	.long	0x45c
	.uleb128 0x5
	.byte	0x3
	.byte	0x6c
	.byte	0xb
	.long	0x482
	.uleb128 0x5
	.byte	0x3
	.byte	0x6d
	.byte	0xb
	.long	0x4a5
	.uleb128 0x5
	.byte	0x3
	.byte	0x6e
	.byte	0xb
	.long	0x4c9
	.uleb128 0x5
	.byte	0x3
	.byte	0x71
	.byte	0xb
	.long	0x501
	.uleb128 0x5
	.byte	0x3
	.byte	0x72
	.byte	0xb
	.long	0x52b
	.uleb128 0x5
	.byte	0x3
	.byte	0x73
	.byte	0xb
	.long	0x550
	.uleb128 0x5
	.byte	0x3
	.byte	0x74
	.byte	0xb
	.long	0x586
	.uleb128 0x5
	.byte	0x3
	.byte	0x75
	.byte	0xb
	.long	0x5a9
	.uleb128 0x5
	.byte	0x3
	.byte	0x76
	.byte	0xb
	.long	0x5cf
	.uleb128 0x5
	.byte	0x3
	.byte	0x78
	.byte	0xb
	.long	0x5e8
	.uleb128 0x5
	.byte	0x3
	.byte	0x79
	.byte	0xb
	.long	0x600
	.uleb128 0x5
	.byte	0x3
	.byte	0x7c
	.byte	0xb
	.long	0x611
	.uleb128 0x5
	.byte	0x3
	.byte	0x7e
	.byte	0xb
	.long	0x629
	.uleb128 0x5
	.byte	0x3
	.byte	0x7f
	.byte	0xb
	.long	0x63f
	.uleb128 0x5
	.byte	0x3
	.byte	0x83
	.byte	0xb
	.long	0x6b3
	.uleb128 0x5
	.byte	0x3
	.byte	0x84
	.byte	0xb
	.long	0x6cd
	.uleb128 0x5
	.byte	0x3
	.byte	0x85
	.byte	0xb
	.long	0x6ec
	.uleb128 0x5
	.byte	0x3
	.byte	0x86
	.byte	0xb
	.long	0x702
	.uleb128 0x5
	.byte	0x3
	.byte	0x87
	.byte	0xb
	.long	0x774
	.uleb128 0x5
	.byte	0x3
	.byte	0x88
	.byte	0xb
	.long	0x78f
	.uleb128 0x5
	.byte	0x3
	.byte	0x89
	.byte	0xb
	.long	0x7b9
	.uleb128 0x5
	.byte	0x3
	.byte	0x8a
	.byte	0xb
	.long	0x7eb
	.uleb128 0x5
	.byte	0x3
	.byte	0x8b
	.byte	0xb
	.long	0x81c
	.uleb128 0x5
	.byte	0x3
	.byte	0x8d
	.byte	0xb
	.long	0x82d
	.uleb128 0x5
	.byte	0x3
	.byte	0x8f
	.byte	0xb
	.long	0x847
	.uleb128 0x5
	.byte	0x3
	.byte	0x90
	.byte	0xb
	.long	0x866
	.uleb128 0x5
	.byte	0x3
	.byte	0x91
	.byte	0xb
	.long	0x8a5
	.uleb128 0x5
	.byte	0x3
	.byte	0x92
	.byte	0xb
	.long	0x8d5
	.uleb128 0x5
	.byte	0x3
	.byte	0xb9
	.byte	0x16
	.long	0x90e
	.uleb128 0x5
	.byte	0x3
	.byte	0xba
	.byte	0x16
	.long	0x948
	.uleb128 0x5
	.byte	0x3
	.byte	0xbb
	.byte	0x16
	.long	0x985
	.uleb128 0x5
	.byte	0x3
	.byte	0xbc
	.byte	0x16
	.long	0x9b3
	.uleb128 0x5
	.byte	0x3
	.byte	0xbd
	.byte	0x16
	.long	0x9f4
	.byte	0
	.uleb128 0x6
	.ascii "__gnu_cxx\0"
	.byte	0x4
	.word	0x106
	.byte	0xb
	.long	0x23f
	.uleb128 0x3
	.ascii "__cxx11\0"
	.byte	0x4
	.word	0x108
	.byte	0x41
	.uleb128 0x4
	.byte	0x4
	.word	0x108
	.byte	0x41
	.long	0x200
	.uleb128 0x5
	.byte	0x3
	.byte	0xaf
	.byte	0xb
	.long	0x90e
	.uleb128 0x5
	.byte	0x3
	.byte	0xb0
	.byte	0xb
	.long	0x948
	.uleb128 0x5
	.byte	0x3
	.byte	0xb1
	.byte	0xb
	.long	0x985
	.uleb128 0x5
	.byte	0x3
	.byte	0xb2
	.byte	0xb
	.long	0x9b3
	.uleb128 0x5
	.byte	0x3
	.byte	0xb3
	.byte	0xb
	.long	0x9f4
	.byte	0
	.uleb128 0x7
	.byte	0x8
	.ascii "__builtin_va_list\0"
	.long	0x257
	.uleb128 0x8
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x9
	.long	0x257
	.uleb128 0xa
	.ascii "size_t\0"
	.byte	0x5
	.byte	0x23
	.byte	0x2c
	.long	0x273
	.uleb128 0x8
	.byte	0x8
	.byte	0x7
	.ascii "long long unsigned int\0"
	.uleb128 0x8
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.uleb128 0x8
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x8
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x8
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0xb
	.byte	0x8
	.long	0x257
	.uleb128 0x8
	.byte	0x2
	.byte	0x7
	.ascii "wchar_t\0"
	.uleb128 0x8
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0x8
	.byte	0x4
	.byte	0x7
	.ascii "long unsigned int\0"
	.uleb128 0x8
	.byte	0x1
	.byte	0x8
	.ascii "unsigned char\0"
	.uleb128 0xc
	.ascii "_iobuf\0"
	.byte	0x30
	.byte	0x1
	.byte	0x1a
	.byte	0xa
	.long	0x39e
	.uleb128 0xd
	.ascii "_ptr\0"
	.byte	0x1
	.byte	0x1b
	.byte	0xb
	.long	0x2c7
	.byte	0
	.uleb128 0xd
	.ascii "_cnt\0"
	.byte	0x1
	.byte	0x1c
	.byte	0x9
	.long	0x2b4
	.byte	0x8
	.uleb128 0xd
	.ascii "_base\0"
	.byte	0x1
	.byte	0x1d
	.byte	0xb
	.long	0x2c7
	.byte	0x10
	.uleb128 0xd
	.ascii "_flag\0"
	.byte	0x1
	.byte	0x1e
	.byte	0x9
	.long	0x2b4
	.byte	0x18
	.uleb128 0xd
	.ascii "_file\0"
	.byte	0x1
	.byte	0x1f
	.byte	0x9
	.long	0x2b4
	.byte	0x1c
	.uleb128 0xd
	.ascii "_charbuf\0"
	.byte	0x1
	.byte	0x20
	.byte	0x9
	.long	0x2b4
	.byte	0x20
	.uleb128 0xd
	.ascii "_bufsiz\0"
	.byte	0x1
	.byte	0x21
	.byte	0x9
	.long	0x2b4
	.byte	0x24
	.uleb128 0xd
	.ascii "_tmpfname\0"
	.byte	0x1
	.byte	0x22
	.byte	0xb
	.long	0x2c7
	.byte	0x28
	.byte	0
	.uleb128 0xa
	.ascii "FILE\0"
	.byte	0x1
	.byte	0x24
	.byte	0x19
	.long	0x30e
	.uleb128 0xa
	.ascii "fpos_t\0"
	.byte	0x1
	.byte	0x68
	.byte	0x25
	.long	0x28d
	.uleb128 0x9
	.long	0x3ab
	.uleb128 0xe
	.ascii "clearerr\0"
	.byte	0x1
	.word	0x242
	.byte	0x10
	.long	0x3d7
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x39e
	.uleb128 0x10
	.ascii "fclose\0"
	.byte	0x1
	.word	0x243
	.byte	0xf
	.long	0x2b4
	.long	0x3f7
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x10
	.ascii "feof\0"
	.byte	0x1
	.word	0x24a
	.byte	0xf
	.long	0x2b4
	.long	0x40f
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x10
	.ascii "ferror\0"
	.byte	0x1
	.word	0x24b
	.byte	0xf
	.long	0x2b4
	.long	0x429
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x10
	.ascii "fflush\0"
	.byte	0x1
	.word	0x24c
	.byte	0xf
	.long	0x2b4
	.long	0x443
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x10
	.ascii "fgetc\0"
	.byte	0x1
	.word	0x24d
	.byte	0xf
	.long	0x2b4
	.long	0x45c
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x10
	.ascii "fgetpos\0"
	.byte	0x1
	.word	0x24f
	.byte	0xf
	.long	0x2b4
	.long	0x47c
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x47c
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3ab
	.uleb128 0x10
	.ascii "fgets\0"
	.byte	0x1
	.word	0x251
	.byte	0x11
	.long	0x2c7
	.long	0x4a5
	.uleb128 0xf
	.long	0x2c7
	.uleb128 0xf
	.long	0x2b4
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x10
	.ascii "fopen\0"
	.byte	0x1
	.word	0x258
	.byte	0x11
	.long	0x3d7
	.long	0x4c3
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x4c3
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x25f
	.uleb128 0x11
	.ascii "fprintf\0"
	.byte	0x1
	.word	0x14e
	.byte	0x5
	.ascii "_Z7fprintfP6_iobufPKcz\0"
	.long	0x2b4
	.long	0x501
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "fread\0"
	.byte	0x1
	.word	0x25d
	.byte	0x12
	.long	0x264
	.long	0x529
	.uleb128 0xf
	.long	0x529
	.uleb128 0xf
	.long	0x264
	.uleb128 0xf
	.long	0x264
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x13
	.byte	0x8
	.uleb128 0x10
	.ascii "freopen\0"
	.byte	0x1
	.word	0x25e
	.byte	0x11
	.long	0x3d7
	.long	0x550
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x11
	.ascii "fscanf\0"
	.byte	0x1
	.word	0x121
	.byte	0x5
	.ascii "_Z6fscanfP6_iobufPKcz\0"
	.long	0x2b4
	.long	0x586
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0x12
	.byte	0
	.uleb128 0x10
	.ascii "fseek\0"
	.byte	0x1
	.word	0x261
	.byte	0xf
	.long	0x2b4
	.long	0x5a9
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x2bb
	.uleb128 0xf
	.long	0x2b4
	.byte	0
	.uleb128 0x10
	.ascii "fsetpos\0"
	.byte	0x1
	.word	0x25f
	.byte	0xf
	.long	0x2b4
	.long	0x5c9
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x5c9
	.byte	0
	.uleb128 0xb
	.byte	0x8
	.long	0x3ba
	.uleb128 0x10
	.ascii "ftell\0"
	.byte	0x1
	.word	0x262
	.byte	0x10
	.long	0x2bb
	.long	0x5e8
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x10
	.ascii "getc\0"
	.byte	0x1
	.word	0x28f
	.byte	0xf
	.long	0x2b4
	.long	0x600
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x14
	.ascii "getchar\0"
	.byte	0x1
	.word	0x290
	.byte	0xf
	.long	0x2b4
	.uleb128 0x10
	.ascii "gets\0"
	.byte	0x1
	.word	0x292
	.byte	0x11
	.long	0x2c7
	.long	0x629
	.uleb128 0xf
	.long	0x2c7
	.byte	0
	.uleb128 0xe
	.ascii "perror\0"
	.byte	0x1
	.word	0x296
	.byte	0x10
	.long	0x63f
	.uleb128 0xf
	.long	0x4c3
	.byte	0
	.uleb128 0x15
	.ascii "printf\0"
	.byte	0x1
	.word	0x159
	.byte	0x5
	.ascii "_Z6printfPKcz\0"
	.long	0x2b4
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.uleb128 0x1
	.byte	0x9c
	.long	0x6b3
	.uleb128 0x12
	.uleb128 0x16
	.secrel32	.LASF2
	.byte	0x1
	.word	0x159
	.byte	0x19
	.long	0x4c3
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.uleb128 0x17
	.secrel32	.LASF0
	.byte	0x1
	.word	0x15b
	.byte	0x7
	.long	0x2b4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x17
	.secrel32	.LASF1
	.byte	0x1
	.word	0x15c
	.byte	0x15
	.long	0x23f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x18
	.quad	.LVL1
	.long	0xa6a
	.byte	0
	.uleb128 0x10
	.ascii "remove\0"
	.byte	0x1
	.word	0x2a4
	.byte	0xf
	.long	0x2b4
	.long	0x6cd
	.uleb128 0xf
	.long	0x4c3
	.byte	0
	.uleb128 0x10
	.ascii "rename\0"
	.byte	0x1
	.word	0x2a5
	.byte	0xf
	.long	0x2b4
	.long	0x6ec
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x4c3
	.byte	0
	.uleb128 0xe
	.ascii "rewind\0"
	.byte	0x1
	.word	0x2ab
	.byte	0x10
	.long	0x702
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x15
	.ascii "scanf\0"
	.byte	0x1
	.word	0x116
	.byte	0x5
	.ascii "_Z5scanfPKcz\0"
	.long	0x2b4
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x774
	.uleb128 0x12
	.uleb128 0x16
	.secrel32	.LASF2
	.byte	0x1
	.word	0x116
	.byte	0x17
	.long	0x4c3
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.uleb128 0x17
	.secrel32	.LASF0
	.byte	0x1
	.word	0x118
	.byte	0x7
	.long	0x2b4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x17
	.secrel32	.LASF1
	.byte	0x1
	.word	0x119
	.byte	0x15
	.long	0x23f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x18
	.quad	.LVL0
	.long	0xa6a
	.byte	0
	.uleb128 0xe
	.ascii "setbuf\0"
	.byte	0x1
	.word	0x2ad
	.byte	0x10
	.long	0x78f
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x2c7
	.byte	0
	.uleb128 0x10
	.ascii "setvbuf\0"
	.byte	0x1
	.word	0x2b1
	.byte	0xf
	.long	0x2b4
	.long	0x7b9
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x2c7
	.uleb128 0xf
	.long	0x2b4
	.uleb128 0xf
	.long	0x264
	.byte	0
	.uleb128 0x11
	.ascii "sprintf\0"
	.byte	0x1
	.word	0x164
	.byte	0x5
	.ascii "_Z7sprintfPcPKcz\0"
	.long	0x2b4
	.long	0x7eb
	.uleb128 0xf
	.long	0x2c7
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0x12
	.byte	0
	.uleb128 0x11
	.ascii "sscanf\0"
	.byte	0x1
	.word	0x10b
	.byte	0x5
	.ascii "_Z6sscanfPKcS0_z\0"
	.long	0x2b4
	.long	0x81c
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0x12
	.byte	0
	.uleb128 0x14
	.ascii "tmpfile\0"
	.byte	0x1
	.word	0x2cb
	.byte	0x11
	.long	0x3d7
	.uleb128 0x10
	.ascii "tmpnam\0"
	.byte	0x1
	.word	0x2cc
	.byte	0x11
	.long	0x2c7
	.long	0x847
	.uleb128 0xf
	.long	0x2c7
	.byte	0
	.uleb128 0x10
	.ascii "ungetc\0"
	.byte	0x1
	.word	0x2cd
	.byte	0xf
	.long	0x2b4
	.long	0x866
	.uleb128 0xf
	.long	0x2b4
	.uleb128 0xf
	.long	0x3d7
	.byte	0
	.uleb128 0x11
	.ascii "vfprintf\0"
	.byte	0x1
	.word	0x16f
	.byte	0x5
	.ascii "_Z8vfprintfP6_iobufPKcPc\0"
	.long	0x2b4
	.long	0x8a5
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x23f
	.byte	0
	.uleb128 0x11
	.ascii "vprintf\0"
	.byte	0x1
	.word	0x176
	.byte	0x5
	.ascii "_Z7vprintfPKcPc\0"
	.long	0x2b4
	.long	0x8d5
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x23f
	.byte	0
	.uleb128 0x11
	.ascii "vsprintf\0"
	.byte	0x1
	.word	0x17d
	.byte	0x5
	.ascii "_Z8vsprintfPcPKcS_\0"
	.long	0x2b4
	.long	0x90e
	.uleb128 0xf
	.long	0x2c7
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x23f
	.byte	0
	.uleb128 0x11
	.ascii "snprintf\0"
	.byte	0x1
	.word	0x184
	.byte	0x5
	.ascii "_Z8snprintfPcyPKcz\0"
	.long	0x2b4
	.long	0x948
	.uleb128 0xf
	.long	0x2c7
	.uleb128 0xf
	.long	0x264
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0x12
	.byte	0
	.uleb128 0x11
	.ascii "vfscanf\0"
	.byte	0x1
	.word	0x140
	.byte	0x5
	.ascii "_Z7vfscanfP6_iobufPKcPc\0"
	.long	0x2b4
	.long	0x985
	.uleb128 0xf
	.long	0x3d7
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x23f
	.byte	0
	.uleb128 0x11
	.ascii "vscanf\0"
	.byte	0x1
	.word	0x139
	.byte	0x5
	.ascii "_Z6vscanfPKcPc\0"
	.long	0x2b4
	.long	0x9b3
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x23f
	.byte	0
	.uleb128 0x11
	.ascii "vsnprintf\0"
	.byte	0x1
	.word	0x18f
	.byte	0x5
	.ascii "_Z9vsnprintfPcyPKcS_\0"
	.long	0x2b4
	.long	0x9f4
	.uleb128 0xf
	.long	0x2c7
	.uleb128 0xf
	.long	0x264
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x23f
	.byte	0
	.uleb128 0x11
	.ascii "vsscanf\0"
	.byte	0x1
	.word	0x132
	.byte	0x5
	.ascii "_Z7vsscanfPKcS0_Pc\0"
	.long	0x2b4
	.long	0xa2c
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x4c3
	.uleb128 0xf
	.long	0x23f
	.byte	0
	.uleb128 0x19
	.ascii "main\0"
	.byte	0x2
	.byte	0x3
	.byte	0x5
	.long	0x2b4
	.quad	.LFB44
	.quad	.LFE44-.LFB44
	.uleb128 0x1
	.byte	0x9c
	.long	0xa6a
	.uleb128 0x1a
	.ascii "a\0"
	.byte	0x2
	.byte	0x5
	.byte	0x6
	.long	0x2b4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1a
	.ascii "b\0"
	.byte	0x2
	.byte	0x5
	.byte	0x9
	.long	0x2b4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x1b
	.secrel32	.LASF3
	.secrel32	.LASF3
	.byte	0x1
	.byte	0x52
	.byte	0x17
	.byte	0
	.section	.debug_abbrev,"dr"
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x39
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x89
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x3a
	.byte	0
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x8
	.byte	0
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"dr"
	.long	0x4c
	.word	0x2
	.secrel32	.Ldebug_info0
	.byte	0x8
	.byte	0
	.word	0
	.word	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.quad	.LFB8
	.quad	.LFE8-.LFB8
	.quad	0
	.quad	0
	.section	.debug_ranges,"dr"
.Ldebug_ranges0:
	.quad	.Ltext0
	.quad	.Letext0
	.quad	.LFB2
	.quad	.LFE2
	.quad	.LFB8
	.quad	.LFE8
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
.LASF1:
	.ascii "__local_argv\0"
.LASF2:
	.ascii "__format\0"
.LASF0:
	.ascii "__retval\0"
.LASF3:
	.ascii "__acrt_iob_func\0"
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
