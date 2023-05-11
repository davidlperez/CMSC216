# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# Illustrates some I/O operations/system calls
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

       .text

main:  li      $v0, 5         # scanf("%d", &x) (read an integer)
       syscall
       move    $t1, $v0
       
       mul     $t1, $t1, 3    # x= x * 3

       li      $v0, 4         # printf("%s", msg) (print a string)
       la      $a0, msg
       syscall

       li      $v0, 1         # printf("%d", x) (print an integer)
       move    $a0, $t1
       syscall

       li      $v0, 11        # printf("%c", '\n') (print a character)
       li      $a0, 10        # (note that 10 == '\n')
       syscall

       li      $v0, 10        # quit program
       syscall

       .data

msg:   .asciiz "The number you entered times 3 is "
