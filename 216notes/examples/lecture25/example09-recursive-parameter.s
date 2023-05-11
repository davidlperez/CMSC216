# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# Illustrates an assembly program that could be generated for the program in
# example10-recursive-parameter.c, which has a recursive function that has a
# parameter.  This illustrates how stack frames are pushed on and popped
# from the runtime stack, and how the frame ptr $fp and stack ptr
# $sp are manipulated to always point to the beginning and end of the
# currently-executing function's activation record or stack frame.
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

       .text
main:  li      $sp, 0x7ffffffc  # set up stack ptr

       li      $t0, 5           # push arg. 5 onto stack
       sw      $t0, ($sp)
       sub     $sp, $sp, 4

       jal     f                # call f

       add     $sp, $sp, 4      # pop arg. from stack

       li      $v0  11          # printf("%c", '\n')
       li      $a0, 10
       syscall

       li      $v0, 10          # quit program
       syscall

                                # prologue
f:     sub     $sp, $sp, 8      # set new stack ptr
       sw      $ra, 8($sp)      # save ret addr in stack
       sw      $fp, 4($sp)      # save old frame ptr in stack
       add     $fp, $sp, 8      # set new frame ptr

       lw      $t0, 4($fp)      # get value of arg. in caller's frame
       li      $t1, 1
       ble     $t0, $t1, endif  # if (i <= 1) skip recursive call

       sub     $t1, $t0, 2      # push arg. i - 2 onto stack
       sw      $t1, ($sp)
       sub     $sp, $sp, 4

       jal     f                # call f recursively

       add     $sp, $sp, 4      # pop arg. from stack

endif: li      $v0  1           # printf("%d", i)
       lw      $a0, 4($fp)      # load i (again) from memory, to print it
       syscall

                                # epilogue
ret:   lw       $ra, 8($sp)     # load ret addr from stack
       lw       $fp, 4($sp)     # restore old frame ptr from stack
       add      $sp, $sp, 8     # reset stack ptr
       jr       $ra             # ret to caller using saved ret addr
