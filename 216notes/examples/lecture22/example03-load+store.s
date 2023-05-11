# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# Illustrates some load and store instructions, and addressing modes.
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

        .text

main:  li      $t0, 55
       move    $t1, $t0         # illustrates the move instruction

       sw      $t0, 0x10010000  # we can use a hardcoded memory address
                                # but it is a real pain to keep track of
                                # specific memory addresses

       li      $t1, 0x10010000  # same effect as above (stores in
       rem     $t0, $t0, 12     # the same location) but with the
       sw      $t0, ($t1)       # memory address in a register

       lw      $t2, anint       # a label is much easier to use than a
                                # hardcoded memory address.  loads into
                                # $t2 the contents of the location
                                # labeled anint
       mul     $t0, $t0, 3      # this stores a value into that location
       sw      $t0, anint

       la      $t2, anint       # we can also get the same effect by
       add     $t0, $t0, 128    # putting an address in a register
       sw      $t0, ($t2)       # using la.  this also stores a value
                                # into location 0x10010000

       la      $t3, array       # as above, la loads the address of the
                                # labeled location, not the value in it
       lw      $t4, 0($t3)      # 0($t3) has the same effect as just ($t3)

       li      $t5, 4
       lw      $t6, array($t5)  # using a label as an offset (indexed mode)

       add     $t6, $t6, $t6
       lw      $t7, 8($t3)      # loads into $t7 the contents of the location
                                # 8 bytes away from the address in $t3

       add     $t7, $t7, $t6
       sw      $t7, ($t3)       # contents of register mode

       sll     $t8, $t7, 2
       sw      $t8, 8($t3)      # using indexed mode again

       li      $v0, 10          # quit program
       syscall

       .data

anint: .word  0x216

array: .word  0x80
       .word  0x38
       .word  0x20
