#
# David Perez
# dperez7
# 117915402
# CMSC216 (0107) Project 10 prog3.s
#
# I pledge on my honor that I have neither given or received any unauthorized
# assistance on this assignment.
#
# Converts prog3.c to MIPS R2000 assembly code, which takes two integer inputs 
# from the user: number and base. It then calls the function num_digits with 
# these inputs as arguments. The num_digits function calculates the number of 
# digits in the given number when it is represented in the given base. The 
# function returns this value to the main function, which then prints it to the 
# console. 
#
# The num_digits function first checks if the given base is less than or equal 
# to zero. If it is, the function returns -1 to indicate an error. Otherwise, 
# the function proceeds to calculate the number of digits in the given number.
# 
# If the given number is negative, the function converts it to a positive 
# number. If the given base is 1, the function simply returns the value of 
# number as the number of digits. Otherwise, if the given number is less than 
# the given base, the function returns 1 as the number of digits. Otherwise, the
# function recursively calls itself with the quotient of number divided by base 
# as the new number argument. The function adds 1 to the result of this 
# recursive call and returns the sum as the number of digits.
#

.data
number: .word 0
base: .word 0
result: .word 0
newline: .asciiz "\n"

.text

main:
    li $sp, 0x7ffffffc  # set stack pointer to top of stack

    li $v0, 5   # scanf("%d", &number)
    syscall
    sw $v0, number

    li $v0, 5   # scanf("%d", &base)
    syscall
    sw $v0, base

    lw $t0, number
    sw $t0, ($sp)
    sub $sp, $sp, 4    # push number onto stack

    lw $t1, base
    sw $t1, ($sp)
    sub $sp, $sp, 4   # push base onto stack
    
    jal num_digits  # num_digits(number, base)

    add $sp, $sp, 8  # pop number and base off stack

    sw $v0, result

    # print result
    li $v0, 1
    lw $a0, result
    syscall
    la $a0, newline
    li $v0, 4
    syscall

    # exit
    li $v0, 10
    syscall

num_digits:
    # prologue
    sub $sp, $sp, 12    # set $sp
    sw $ra, 12($sp) # save $ra
    sw $fp, 8($sp)  # save $fp
    add $fp, $sp, 12    # set new $fp

    li $t0, 0   # set result to 0
    sw $t0, 4($sp) # store result

    lw $t1, 8($fp)  # store n argument
    lw $t2, 4($fp)  # store base argument

    blez $t2, base_error    # check if base is negative
    bltz $t1, n_negative    # check if n is negative

    j count_digits

count_digits:
    beq $t2, 1, base_one    # check if base is 1
    blt $t1, $t2, n_lt_base # check if n < base

    div $t0, $t1, $t2   # n / base
    sw $t0, ($sp)       # store quotient
    sub $sp, $sp, 4     # push quotient onto stack

    move $t0, $t2   # push argument back on to stack
    sw $t0, ($sp)
    sub $sp, $sp, 4

    jal num_digits  # num_digits(quotient, base) recursive call

    add $sp, $sp, 8 # pop quotient and base off stack

    move $t0, $v0   # result = num_digits(quotient, base)

    add $t0, $t0, 1 # result = result + 1
    sw $t0, 4($sp)  # store result

    j exit_num_digits

base_error:
    li $t0, -1  # return -1 if base is negative
    sw $t0, 4($sp)   # store result
    j exit_num_digits

n_negative:
    neg $t1, $t1    # n = -n
    sw $t1, 8($fp)
    j count_digits

base_one:
    lw $t0, 8($fp)  # result = n
    sw $t0, 4($sp)
    j exit_num_digits
    
n_lt_base:
    li $t0, 1   # result = 1
    sw $t0, 4($sp)
    j exit_num_digits

exit_num_digits:
    move $v0, $t0

    # epilogue
    lw $ra, 12($sp)
    lw $fp, 8($sp)
    add $sp, $sp, 12
    jr $ra  # return to main
