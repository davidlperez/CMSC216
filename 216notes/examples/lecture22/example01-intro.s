# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# This program is just being shown now to illustrate a few assembly language
# features, so it's OK if you don't understand everything it's doing yet
# (several things it's doing haven't been covered yet, but will be shortly).
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

       .text

main:  li      $t0, 215        # register = 215

loop:  beqz    $t0, after      # if (register == 0) skip over next instruction

       add     $t0, $t0, 1     # register= register + 1

after: li      $v0, 1          # printf("%d", register);
       move    $a0, $t0
       syscall

       li      $v0, 10         # quit program
       syscall
