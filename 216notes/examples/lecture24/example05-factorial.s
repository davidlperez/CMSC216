# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# Illustrates an assembly program that could be generated for the program in
# example05-factorial.c.  It illustrates several features covered so far,
# including some branch/jump (flow of control) instructions.  Note the
# semantics of a side effect is that memory must be modified.
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

          .text

main:     li         $v0, 5              # scanf("%d", &n)
          syscall
          move       $t2, $v0
          sw         $t2, n

          li         $t1, 1              # f= 1
          sw         $t1, f
          li         $t0, 1              # i= 1
          sw         $t0, i

loop:     bgt        $t0, $t2, endwhile  # if (i > n) leave loop
          mul        $t1, $t1, $t0       # f= f * i
          sw         $t1, f
          add        $t0, $t0, 1         # i= i + 1
          sw         $t0, i
          j          loop                # repeat

endwhile: move       $a0, $t1            # printf("%d", f)
          li         $v0, 1
          syscall

          la         $a0, eoln           # printf("%s", "\n")
          li         $v0, 4
          syscall

          li         $v0, 10             # quit program
          syscall

          .data

i:        .word 0
f:        .word 0
n:        .word 0
eoln:     .asciiz "\n"
