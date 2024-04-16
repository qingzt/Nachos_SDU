	.file	1 "exec.c"
gcc2_compiled.:
__gnu_compiled_c:
	.rdata
	.align	2
$LC0:
	.ascii	"../test/halt.noff\000" //用户地址空间
	.text
	.align	2   //2字节对齐
	.globl	main //全局变量
	.ent	main //main函数入口
main:
# 汇编伪指令  frame 用来声明堆栈布局。 
# 它有三个参数： 
# 1）第一个参数  framereg：声明用于访问局部堆栈的寄存器，一般为  $sp。 
# 2）第二个参数  framesize：申明该函数已分配堆栈的大小，应该符合  $sp + framesize ＝ 原来的 $sp。 
# 3）第三个参数  returnreg：这个寄存器用来保存返回地址。 
	.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32		# $sp - 32->$sp，构造mian()的栈frmae 
							# $sp的原值应该是执行main()之前的栈顶 
							# 上一函数对应栈frame的顶（最小地址处） 
	sw	$31,28($sp)		#$31->memory[$sp+28]  ; 函数返回地址 
	sw	$fp,24($sp)		#$fp ->memory[$sp+24] ; 保存fp 
	move	$fp,$sp		#$sp->$fp，设置新的栈帧
	jal	__main
	la	$4,$LC0			#将Exec("../test/halt.noff\000")的参数的地址传给$4 
						#$4-$7：传递函数的前四个参数给子程序，不够的用堆栈
	jal	Exec			#转到start.s 中的 Exec 处执行
	sw	$2,16($fp)		#这将 Exec 函数的返回值保存到栈帧的某个位置
	jal	Halt			#调用Halt函数
$L1:
	move	$sp,$fp		#恢复sp
	lw	$31,28($sp)
	lw	$fp,24($sp)		#恢复寄存器的值，并取到main的返回值
	addu	$sp,$sp,32	#释放栈空间
	j	$31				#返回到调用者
	.end	main
