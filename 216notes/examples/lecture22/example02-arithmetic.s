# -*- mode: text -*-

#
# (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
# not to provide it to anyone else.
#
# Illustrates some integer (arithmetic) instructions.
#
# (The very first line above is to disable Emacs' ideas of how to indent
# assembly programs, which are inconvenient.)
#

       .text

main:  li      $t0, 0xd8
       li      $t1, 0x40

       mul     $t2  $t0, $t1  # multiplication

       rem     $t2, $t0, $t1  # modulus; note using $t2 as the destination
                              # register again

       div     $t3, $t0, $t1  # integer division


       srl     $t1  $t1, 2    # shift; note the destination register is the
                              # same as the first operand (source register),
                              # and the second operand is just a literal

       neg     $t4, $t3       # arithmetic negation; unary instruction

       li      $v0, 10        # quit program
       syscall
