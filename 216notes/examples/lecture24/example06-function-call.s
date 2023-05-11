# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# Illustrates a sequence of instructions that could be generated for the
# program in example06-function-call.c, which contains function calls.
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

      .data

n:    .word 2

      .text

main: li      $sp, 0x7ffffffc  # set up stack pointer

      jal     f                # call f

      li      $t0, 1           # n= 1
      sw      $t0, n

      jal     g                # call g

      li      $v0, 10          # quit program
      syscall

                               # prologue
f:    sub     $sp, $sp, 8      # set new stack pointer
      sw      $ra, 8($sp)      # save return address in stack
      sw      $fp, 4($sp)      # save old frame pointer in stack
      add     $fp, $sp, 8      # set new frame pointer

      jal g                    # call g

                               # epilogue
      lw      $ra, 8($sp)      # load return address from stack
      lw      $fp, 4($sp)      # restore old frame pointer from stack
      add     $sp, $sp, 8      # reset stack pointer
      jr      $ra              # return to caller using saved return address

                               # prologue
g:    sub     $sp, $sp, 8      # set new stack pointer
      sw      $ra, 8($sp)      # save return address in stack
      sw      $fp, 4($sp)      # save old frame pointer in stack
      add     $fp,  $sp, 8     # set new frame pointer

      lw      $t0, n           # load the value of the global variable n

loop: blez    $t0, ret         # while (n > 0)

      move    $a0, $t0         # printf("%d", n)
      li      $v0, 1
      syscall

      sub     $t0, $t0, 1      # n--
      sw      $t0, n
      j       loop             # repeat

                               # epilogue
ret:  lw      $ra, 8($sp)      # load return address from stack
      lw      $fp, 4($sp)      # restore old frame pointer from stack
      add     $sp, $sp, 8      # reset stack pointer
      jr      $ra              # return to caller using saved return address
