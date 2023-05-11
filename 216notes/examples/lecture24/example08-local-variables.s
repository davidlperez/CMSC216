# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# Illustrates an assembly program that could be generated for the program in
# example08-local-variables.c, which has a function that has local
# variables.  This illustrates how f()'s local variables are stored in the
# runtime stack, in f()'s activation record or stack frame.
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

      .text

main: li      $sp, 0x7ffffffc  # set up stack ptr

      jal     f                # call f

      li      $v0, 10          # quit program
      syscall

                               # prologue
f:    sub     $sp, $sp, 12     # set new stack ptr
      sw      $ra, 12($sp)     # save ret addr in stack
      sw      $fp, 8($sp)      # save old frame ptr in stack
      add     $fp, $sp, 12     # set new frame ptr

      li      $t0, 16          # x= 16
      sw      $t0, 4($sp)

      jal     g                # call g

      li      $v0, 1           # printf("%d", x);
      lw      $a0, 4($sp)      # need to reload x to print it!
      syscall

                               # epilogue
      lw      $ra, 12($sp)     # load ret addr from stack
      lw      $fp, 8($sp )     # restore old frame ptr from stack
      add     $sp, $sp, 12     # reset stack ptr
      jr      $ra              # ret to caller using saved ret addr

                               # prologue
g:    sub     $sp, $sp, 20     # set new stack ptr
      sw      $ra, 20($sp)     # save ret addr in stack
      sw      $fp, 16($sp)     # save old frame ptr in stack
      add     $fp, $sp, 20     # set new frame ptr

      li      $t0, 30          # a= 30
      sw      $t0, 12($sp)

      li      $t0, 25          # b= 25
      sw      $t0, 8($sp)

      lw      $t1, 12($sp)     # c= a + b
      add     $t0, $t0, $t1
      sw      $t0, 4($sp)

      li      $v0, 1           # printf("%d", c);
      move    $a0, $t0
      syscall

                               # epilogue
      lw      $ra, 20($sp)     # load ret addr from stack
      lw      $fp, 16($sp)     # restore old frame ptr from stack
      add     $sp, $sp, 20     # reset stack ptr
      jr      $ra              # ret to caller using saved ret addr
