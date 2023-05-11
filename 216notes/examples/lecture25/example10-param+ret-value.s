# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# Illustrates an assembly program that could be generated for the program in
# example09-param+ret-value.c, which has a function that has a parameter,
# and which also returns a value.  It illustrates how the parameter is
# passed to the function by the caller (main() in this case) pushing it onto
# the stack, in its own stack frame, before calling f(), and how the return
# value is passed back to the caller.
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

      .text

main: li      $sp, 0x7ffffffc  # set up stack ptr

      li      $t0, 15          # push arg. 15 onto stack
      sw      $t0, ($sp)
      sub     $sp, $sp, 4

      jal     f                # call f

      add     $sp, $sp, 4      # pop arg. from stack

      move    $t0, $v0         # store f()'s return value in n
      sw      $t0, n

      li      $v0, 1           # printf("%d", n)
      lw      $a0, n
      syscall

      li      $v0, 11          # printf("\n");
      li      $a0, 10
      syscall

      li      $v0, 10          # quit program
      syscall

                               # prologue
f:    sub     $sp, $sp, 8      # set new stack ptr
      sw      $ra, 8($sp)      # save ret addr in stack
      sw      $fp, 4($sp)      # save old frame ptr in stack
      add     $fp, $sp, 8      # set new frame ptr

      lw      $t0, 4($fp)      # get arg. (value of i) in caller's frame
      mul     $t0, $t0, 10     # compute i * 10

      move    $v0, $t0         # copy ret value to $v0 before exiting

                               # epilogue
      lw      $ra, 8($sp)      # load ret addr from stack
      lw      $fp, 4($sp)      # restore old frame ptr from stack
      add     $sp, $sp, 8      # reset stack ptr
      jr      $ra              # ret to caller using saved ret addr

      .data

n:    .word 0                  # static data is initialized to 0 if not
                               # explicitly initialized otherwise!

