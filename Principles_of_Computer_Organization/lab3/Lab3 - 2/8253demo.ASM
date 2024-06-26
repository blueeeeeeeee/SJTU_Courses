;--------------------------------------------------------------------------
;
;              Build this with the "Source" menu using
;                     "Build All" option
;
;--------------------------------------------------------------------------
;
;                           实验三程序通用框架
;
;--------------------------------------------------------------------------
; 功能： 程序框架					                            				   |
; 编写：《嵌入式系统原理与实验》课程组                   				   |
; 版本：3.5
; 修订：B
;--------------------------------------------------------------------------


		DOSSEG
		.MODEL	SMALL		; 设定8086汇编程序使用Small model
		.8086				; 设定采用8086汇编指令集

;-----------------------------------------------------------
;	定义堆栈段                                             |
;-----------------------------------------------------------
	.stack 100h				; 定义256字节容量的堆栈

;-------------------------------------------------------------------------
;	符号定义                                                              |
;-------------------------------------------------------------------------
;
;
; 8253芯片端口地址 （Port Address):
L8253T0			EQU	100H			; Timer0's port number in I/O space
L8253T1			EQU 	102H			; Timer1's port number in I/O space
L8253T2			EQU 	104H			; Timer2's port number in I/O space
L8253CS			EQU 	106H			; 8253 Control Register's port number in I/O space
;
; 8255芯片端口地址 （Port Address):
L8255PA			EQU	129H			; Port A's port number in I/O space
L8255PB			EQU 	12BH			; Port B's port number in I/O space
L8255PC			EQU 	12DH			; Port C's port number in I/O space
L8255CS			EQU 	12FH			; 8255 Control Register's port number in I/O space
;
;  中断矢量号定义
IRQNum			EQU	4BH	;130		; 中断矢量号,要根据学号计算得到后更新此定义。

Patch_Protues	EQU	IN AL, 0	;	DImulation Patch for Proteus, please ignore this line

;=======================================================================
; 宏定义
;=======================================================================

; 修补Proteus仿真的BUG，参见程序段中的使用说明
    WaitForHWInt MACRO INTNum		; INTNum is the HW INT number
		MOV AL, INTNum   			;
		OUT 0,AL					;
		STI
		CLI
    ENDM



;-----------------------------------------------------------
;	定义数据段                                             |
;-----------------------------------------------------------
		.data					; 定义数据段;

DelayShort	dw	40				; 短延时参量	
DelayLong	dw	4000			; 长延时参量


; SEGTAB is the code for displaying "0-F", and some of the codes may not be correct. Find and correct the errors.
	SEGTAB  DB 3FH	; 7-Segment Tube
		DB 06H	;
		DB 5BH	;            a a a
		DB 4FH	;         f         b
		DB 66H	;         f         b
		DB 6DH	;         f         b
		DB 7DH	;            g g g 
		DB 07H	;         e         c
		DB 7FH	;         e         c
		DB 6FH	;         e         c
        	DB 77H	;            d d d     h h h
		DB 7CH	; ----------------------------------
		DB 39H	;       b7 b6 b5 b4 b3 b2 b1 b0
		DB 5EH	;       DP  g  f  e  d  c  b  a
		DB 79H	;
		DB 71H	;
		
	 ID	DB 3FH	
		DB 07H
		DB 5BH
		DB 7DH
		
	 LIGHT	DB 01EH
		DB 02DH
		DB 04BH
		DB 087H
		
;-----------------------------------------------------------
;	定义代码段                                             |
;-----------------------------------------------------------
		.code						; Code segment definition
		.startup					; Entrance of this program
;------------------------------------------------------------------------
		Patch_Protues					; DImulation Patch for Proteus,
								; Please ignore the above code line.
;------------------------------------------------------------------------

START:								; Modify the following codes accordingly
								; 
		CLI						; Disable interrupts
		MOV AX, @DATA					;
		MOV DS, AX					; Initialize DS

		CALL INIT8255					; Initialize 8255 
		CALL INIT8253					; Initialize 8253
		
		MOV  BL, IRQNum					; BL is used as a parameter to call the procedure INT_INIT
		CALL INT_INIT					; Procedure INT_INIT is used to set up the IVT
		
		
		STI
Display_Again:
		CALL DISPLAY8255				; Procedure DISPLAY8255 is used to contrl 7-segment tubes
		

;===================================================================================
; Attention:
; The following codes is a Patching for Proteus 8086 Hardware DImulation Bug.
; Use these codes in the case you want the 8086 to halt and waiting for HW INT only! 
; You can treat it as if it doesn't exist. 
;
; If you need to use HW INT, please uncomment it, or
; Don't modify it, leave it here just as it is.
;		WaitForHWInt IRQNum				
;====================================================================================
		JMP	Display_Again

		HLT						; 
;=====================================================================================
	 




;--------------------------------------------
;                                           |
; INIT 8255 					            |
;                                           |
;--------------------------------------------
INIT8255 PROC

		; Init 8255 in Mode x,	L8255PA xPUT, L8255PB xPUT, L8255PCU xPUT, L8255PCL xPUT
; Init 8255 in Mode 0
; PortA Output, PortB Output
;

		
		MOV AL,10001001B
		MOV DX,L8255CS
		OUT DX,AL				  


	        MOV DX,L8255PC
		IN AL,DX
		MOV DL,AL
		
		AND DL,1H
		MOV CL,6H
		SHL DL,CL
		OR  DL,0BFH
		OR  AL,40H
		AND AL,DL
		MOV AH,AL
		
		MOV AL,10000001B
		MOV DX,L8255CS
		OUT DX,AL
		
		MOV AL,AH
		MOV DX,L8255PC
		OUT DX,AL
		CALL DELAY
		

		MOV AL,01EH
		MOV DX,L8255PA
		OUT DX,AL
		MOV AL,SEGTAB + 0
		MOV DX,L8255PB
		OUT DX,AL
		CALL DELAY
		
		MOV AL,02DH
		MOV DX,L8255PA
		OUT DX,AL
		MOV AL,SEGTAB + 7
		MOV DX,L8255PB
		OUT DX,AL
		CALL DELAY
		
		MOV AL,04BH
		MOV DX,L8255PA
		OUT DX,AL
		MOV AL,SEGTAB + 2
		MOV DX,L8255PB
		OUT DX,AL
		CALL DELAY
		
		MOV AL,087H
		MOV DX,L8255PA
		OUT DX,AL
		MOV AL,SEGTAB + 6
		MOV DX,L8255PB
		OUT DX,AL
		CALL DELAY
		
		

		RET
INIT8255 ENDP

;--------------------------------------------
;                                           |
; INIT 8253 					            |
;                                           |
;--------------------------------------------
INIT8253 PROC
; Set the mode and the initial count for Timer0
	        MOV AL,00110110B
		MOV DX,L8253CS
		OUT DX,AL
		
		MOV AX,10000
		MOV DX,L8253T0
		OUT DX,AL
		MOV AL,AH
		OUT DX,AL

; Set the mode and the initial count for Timer1
	        
		MOV AL,01110110B
		MOV DX,L8253CS
		OUT DX,AL
		
		MOV AX,100
		MOV DX,L8253T1
		OUT DX,AL
		MOV AL,AH
		OUT DX,AL
		
		
		

; Set the mode and the initial count for Timer2
		
		MOV AL,10110000B
		MOV DX,L8253CS
		OUT DX,AL
		
		MOV AX,50000
		MOV DX,L8253T2
		OUT DX,AL
		MOV AL,AH
		OUT DX,AL
		

		RET
INIT8253 ENDP



WATCHDOG	PROC FAR
		PUSH DX
		PUSH AX
		STI
		
		MOV AX,50000
		MOV DX,L8253T2
		OUT DX,AL
		MOV AL,AH
		OUT DX,AL
		
		POP AX
		POP DX
		INT IRQNum-1
		
		
		IRET

WATCHDOG	ENDP




COUNT		PROC FAR
		STI
		PUSH DX
		PUSH AX
		PUSH BX
		
		MOV AL,10001001B
		MOV DX,L8255CS
		OUT DX,AL
		
		MOV AL,0FFH
		MOV DX,L8255PA
		OUT DX,AL
	
		MOV BX,OFFSET SEGTAB
		MOV DX,DI
		AND DX,0FH
		ADD BX,DX
		MOV AL,[BX]
		MOV DX,L8255PB
		OUT DX,AL
		
		MOV AL,0FEH
		MOV DX,L8255PA
		OUT DX,AL
		
		
		INC DI
		POP BX
		POP AX
		POP DX
		
		IRET
COUNT		ENDP
;--------------------------------------------
;                                           |
; DISPLAY  STUDENTS ID				 		|
;                                           |
;--------------------------------------------

DISPLAY8255 PROC
; Put your code here
	       


		RET
	
DISPLAY8255 ENDP


;--------------------------------------------------------------
;                                                             |                                                            |
; Function：DELAY FUNCTION                                    | 
; Input：None												  |
; Output: None                                                |
;--------------------------------------------------------------

DELAY 	PROC
    	PUSH CX
    	MOV CX, DelayShort
D1: 	LOOP D1
    	POP CX
    	RET
DELAY 	ENDP


DELAY1 	PROC
    	PUSH CX
    	MOV CX, DelayLong
D2: 	LOOP D2
    	POP CX
    	RET
DELAY1 	ENDP
;-------------------------------------------------------------
;                                                             |                                                            |
; Function：INTERRUPT Vector Table INIT						  |
; Input: BL = Interrupt number								  |
; Output: None			                                	  |
;                                                             |
;-------------------------------------------------------------	
INT_INIT	PROC FAR			; The code is not complete and you should finalize the procedure
		CLI				; Disable interrupt
		MOV AX, 0
		MOV ES, AX			; To set up the interrupt vector table
; Put your code here
; Hint: you can use the directives such as SEGMENT,OFFSET to get the segment value and the offset of a label
		MOV AX,IRQNum
		SHL AX,1
		SHL AX,1
		MOV BX,AX
		MOV AX,OFFSET MYIRQ
		MOV ES:[BX],AX
		MOV AX,SEG MYIRQ
		MOV ES:[BX+2],AX
		MOV SI,0H
		
		MOV AX,IRQNum+1
		SHL AX,1
		SHL AX,1
		MOV BX,AX
		MOV AX,OFFSET WATCHDOG
		MOV ES:[BX],AX
		MOV AX,SEG WATCHDOG
		MOV ES:[BX+2],AX
		
		MOV AX,IRQNum-1
		SHL AX,1
		SHL AX,1
		MOV BX,AX
		MOV AX,OFFSET COUNT
		MOV ES:[BX],AX
		MOV AX,SEG COUNT
		MOV ES:[BX+2],AX
		MOV DI,0H
		
		
		RET
 
						; Do not to forget to return back from a procedure		
INT_INIT	ENDP

		
;--------------------------------------------------------------
;                                                             |                                                            |
; FUNCTION: INTERRUPT SERVICE  Routine （ISR）				  | 
; Input::                                                     |
; Output:                                                     |
;                                                             |
;--------------------------------------------------------------	
		
MYIRQ 	PROC FAR				; The code is not complete and you should finalize the procedure
; Put your code here
	PUSH DX
	PUSH AX

	STI
	MOV AL,10001001B
	MOV DX,L8255CS
	OUT DX,AL
	
	MOV BX,OFFSET LIGHT
	ADD BX,SI
	MOV AL,[BX]
	MOV DX,L8255PA
	OUT DX,AL
	
	MOV AL,[BX+2]
	MOV DX,L8255PB
	OUT DX,AL
	
	MOV BX,OFFSET ID
	ADD BX,SI
	MOV AL,[BX]
	MOV DX,L8255PB
	OUT DX,AL
	
	INC SI
	AND SI,3H
	CALL DELAY1
	
	
		
	
	
	
	MOV DX,L8255PC
	IN AL,DX
	MOV AH,AL
	
	MOV AL,10000001B
	MOV DX,L8255CS
	OUT DX,AL
	MOV DX,L8255PC
	MOV AL,AH
	ADD AL,80H
	OUT DX,AX
	
	
	POP AX
	POP DX
	IRET
	
						; Do not forget to return back from a ISR
MYIRQ 	ENDP

	END	