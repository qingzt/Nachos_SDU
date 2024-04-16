/* noff.h 
 *     Data structures defining the Nachos Object Code Format
 *
 *     Basically, we only know about three types of segments:
 *	code (read-only), initialized data, and unitialized data
 */

#define NOFFMAGIC	0xbadfad 	/* magic number denoting Nachos 
					 * object code file 
					 */

typedef struct segment {//段的定义
  int virtualAddr;		/* location of segment in virt addr space 段在虚拟内存中的位置 */
  int inFileAddr;		/* location of segment in this file 段在该文件中的位置 */
  int size;			/* size of segment 段的大小 */
} Segment;

typedef struct noffHeader {
   int noffMagic;		/* should be NOFFMAGIC NOFF的魔数 */
   Segment code;		/* executable code segment 代码段 */ 
   Segment initData;		/* initialized data segment 数据段 */
   Segment uninitData;		/* uninitialized data segment --
				 * should be zero'ed before use 
				 */
} NoffHeader;
