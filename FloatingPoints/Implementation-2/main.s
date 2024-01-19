extern      printf
extern      exit
section      .data
      fmt  db "%f %f",10,0
      align 16
      val1 dq 1.1, 2.2
      align 16
      val2 dq 2.2, 3.3

section      .text
global      main
   main:
      push rbp
      mov rbp, rsp
     
      vmovapd   xmm0, [val1]
      vmovapd   xmm1, [val2]
      vaddpd   xmm0, xmm1  ;xmm0 contains 3.3 and 5.5
      
      vmovapd xmm1,xmm0  ;copy
      vpsrldq xmm1,8  ;shift right by 8 bytes
      mov rdi, fmt
      mov rax,2
      call   printf  ;print 3.3 and 5.5
      
      mov rax, 0
      mov rsp, rbp
      pop rbp
      ret