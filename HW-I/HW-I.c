#include <stdio.h>
#include <math.h>


float mean(float N1,float N2){
        return (N1+N2)/2;
}

float s_formula(int si_cur){
        float count = 0,si_snum=0,si_p;
        while (count<=si_cur-1) {
                // The Formula is (pow(-1.0, si_cur)) / (si_cur + 1.0) change this part
                si_p=pow(-1,count);
                si_snum=si_snum + (float)(si_p/(count+1));
                count+=1;
        }
        return si_snum;
}

float formula(float si_num,int si_cur,int si_last){
        int si_lc = si_last-si_cur;
        int count = 0;
        float si_list[si_lc][si_lc];
        while (count<=si_lc-1) {
                // The Formula is (pow(-1.0, si_cur)) / (si_cur + 1.0) change this part
                si_num = si_num + (float)(pow(-1.0,count))/(si_cur+1.0);
                si_list[si_lc - 1][count] = si_num;
                si_cur += 1;
                count += 1;
        }
        si_lc -= 1;
        while (1) {
                count = 0;
                while (1) {
                        si_list[si_lc - 1][count] = (float)mean(
                                si_list[si_lc][0 + count],
                                si_list[si_lc][1 + count]);
                        if (count >= si_lc-1) {
                                break;
                        }else{
                                count += 1;
                        }
                }
                if (si_lc==0) {
                        break;
                }else{
                        si_lc -= 1;
                }
        }
        printf("\n\nHere is your general total solution: %2.7f\n",si_list[0][0]);
        printf("Sems Turgut - 130106106054\n");
        return 0;
}

int main(void){
        int si_cur = 0;
        int si_last = 0;
        printf("Welcome to Numerical Analysis HW-I\n\n");
        printf("This program can calculate general total solution of given series.\n\n");
        printf("You can change The Series Formula(from the code of course),\n");
        printf("Variable's S Number and Last Variable's Number\n\n\n");
        printf("Please enter your variable's S number: ");
        scanf("%d",&si_cur);
        printf("Your S%d: %2.7f\n",si_cur,s_formula(si_cur));
        printf("Please enter your last variable's number: ");
        scanf("%d",&si_last);
        if (si_last>si_cur) {
                formula(s_formula(si_cur), si_cur, si_last);
        }else{
                printf("\n\nMake sure your last variable's number higher than your S number.\n");
        }
        return 0;
}
