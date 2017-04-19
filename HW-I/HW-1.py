import math


def mean(N1, N2):
    return (N1 + N2) / 2


def s_formula(si_cur):
    count = 0
    si_snum = 0
    while count <= si_cur - 1:
        # The Formula is (pow(-1.0, si_cur)) / (si_cur + 1.0) change this part
        si_snum = si_snum + (pow(-1.0, count) / (count + 1.0))
        count += 1
    return si_snum


def formula(si_num, si_cur, si_last):
    si_lc = si_last - si_cur
    count = 0
    si_list = [[0 for x in range(si_lc)] for y in range(si_lc)]
    while count <= si_lc - 1:
        # The Formula is (pow(-1.0, si_cur)) / (si_cur + 1.0) change this part
        si_num = si_num + (pow(-1.0, si_cur)) / (si_cur + 1.0)
        si_list[si_lc - 1][count] = si_num
        si_cur += 1
        count += 1
    si_lc -= 1
    while True:
        count = 0
        while True:
            si_list[si_lc - 1][count] = mean(
                si_list[si_lc][0 + count],
                si_list[si_lc][1 + count])
            if count >= si_lc - 1:
                break
            else:
                count += 1
        if si_lc == 0:
            break
        else:
            si_lc -= 1
    print "\n\nHere is your general total solution: " + str(si_list[0][0])
    print "Sems Turgut - 130106106054"

print "Welcome to Numerical Analysis HW-I\n"
print "This program can calculate general total solution of given series.\n"
print "You can change The Series Formula(from the code of course),"
print "Variable's S Number and Last Variable's Number\n\n"
si_cur = input("Please enter your variable's S number: ")
print "Your S" + str(si_cur) + ": " + str(s_formula(si_cur))
si_last = input("Please enter your last variable's number: ")
if si_last > si_cur:
    formula(s_formula(si_cur), si_cur, si_last)
else:
    print "\n\nMake sure your last variable's number higher than your S number."
