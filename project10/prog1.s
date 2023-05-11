#
# David Perez
# dperez7
# 117915402
# CMSC216 (0107) Project 10 prog1.s
#
# I pledge on my honor that I have not given or received any unauthorized
# assistance on this assignment.
#
# Converts prog1.c to MIPS R2000 assembly code, which takes in values for the
# length and width of two rectangles, and prints out the result of comparing the
# areas of the two rectangles. It prints out -2 if any of the values are
# negative, -1 if the first rectangle is smaller than the second, 0 if the two
# rectangles are equal in area, and 1 if the first rectangle is larger than the
# second.
#

.data
l1: .word 0
w1: .word 0
l2: .word 0
w2: .word 0
rect1: .word 0
rect2: .word 0
result: .word 0
neg2: .word -2
neg1: .word -1
zero: .word 0
pos1: .word 1
newline: .asciiz "\n"

.text

main:
    lw $t0, zero    # initialize result to 0
    sw $t0, result 

    # prompt user for length and width of first rectangle
    li $v0, 5
    syscall
    sw $v0, l1

    li $v0, 5
    syscall
    sw $v0, w1

    # prompt user for length and width of second rectangle
    li $v0, 5
    syscall
    sw $v0, l2

    li $v0, 5
    syscall
    sw $v0, w2

    # check if any of the values are negative
    lw $t0, l1
    bltz $t0, negative

    lw $t0, w1
    bltz $t0, negative

    lw $t0, l2
    bltz $t0, negative

    lw $t0, w2
    bltz $t0, negative

    # calculate the area of each rectangle
    lw $t0, l1
    lw $t1, w1
    mul $t2, $t0, $t1
    sw $t2, rect1

    lw $t0, l2
    lw $t1, w2
    mul $t2, $t0, $t1
    sw $t2, rect2

    # compare the areas of the two rectangles
    lw $t0, rect1
    lw $t1, rect2
    blt $t0, $t1, less_than
    bgt $t0, $t1, greater_than

    # if the areas are equal, set result to 0
    li $t0, 0
    sw $t0, result
    j end

negative:   # if any of the values are negative, set result to -2
    lw $t0, neg2
    sw $t0, result
    j end

less_than:  # first rectangle is smaller than the second, set result to -1
    lw $t0, neg1
    sw $t0, result
    j end

greater_than:   # first rectangle is larger than the second, set result to 1
    lw $t0, pos1
    sw $t0, result
    j end
    
end:
    # print out the result
    lw $t0, result
    li $v0, 1
    move $a0, $t0
    syscall

    # print out a newline
    li $v0, 4
    la $a0, newline
    syscall

    # exit the program
    li $v0, 10
    syscall