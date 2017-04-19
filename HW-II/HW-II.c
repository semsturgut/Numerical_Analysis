#include <stdio.h>
#include <math.h>
float Neo_A[4][4] = {
        {2, -1, -1, 3},
        {6, -2, 3, 0},
        {-4, 2, 3, -3},
        {2, 0, 4, -7}
};
float one_s[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
};
float mik[4][4];
int i=0,j=0;

void show_Neo() {
        for (int f_i = 0; f_i < 4; f_i++) {
                for (int f_j = 0; f_j < 4; f_j++) {
                        printf(" %f ",Neo_A[f_i][f_j]);
                }
                printf("\n");
        }
        printf("\n\n\n");
}

void MCross() {

}

void f_mik(int count) {
        for (int f_i = count; f_i < 3; f_i++) {
                for (int f_j = f_i+1; f_j < 4; f_j++) {
                        mik[f_j][f_i]=Neo_A[f_j][f_i]/Neo_A[f_i][f_i]; //Düzeltilecek kitaptan bak.
                }
        }
}

void f_Neo(int count) {
        for (int f_i = 0; f_i < 4; f_i++) {
                for (int f_j = 0; f_j < 4; f_j++) {
                        Neo_A[f_i+1][f_j]=Neo_A[f_i+1][f_j]-Neo_A[count][f_j]*mik[f_i+1][count]; //Düzeltilecek kitaptan bak.
                        one_s[f_i+1][f_j]=one_s[f_i+1][f_j]-one_s[count][f_j]*mik[f_i+1][count];
                }
        }
}


int main(void){
        f_mik(0);
        f_Neo(0);
        f_mik(1);
        f_Neo(1);
        f_mik(2);
        f_Neo(2);
        f_mik(3);
        f_Neo(3);
        show_Neo();

        return 0;
}
