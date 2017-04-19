#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval stop, start;
int f_get,n=0;
float hmin = 0.000005,hcur,Xmin=0,Xmax=1.570796;
float Xn,Xo1=0,Xo0=1,fXn,fXn1,fXn0,fXndx;

float f_Xn(float);
float NRf_Xndx(float);
float NRhn(float,float);
void Newton_Raphson();
float KXn(float,float);
float Kf_Xndx(float,float);
float Khn(float,float);
void Kiris();


//f(Xn)=sin(Xn)-exp(-Xn)
float f_Xn(float Xn){
        return sin(Xn)-exp(-Xn);
}
//f'(Xn)=cos(Xn)+exp(-Xn)
float NRf_Xndx(float Xn){
        return cos(Xn)+exp(-Xn);
}
//NRhn=-f(Xn)/f'(Xn)
float NRhn(float f_Xn,float f_Xndx){
        if (f_Xndx!=0) {
                return -(f_Xn/f_Xndx);
        }
        else {return 0; }
}

void Newton_Raphson(){
        gettimeofday(&start, NULL);
        while (1) {
                if (n==0) {Xn=Xo0; }
                hcur=fabs(NRhn(f_Xn(Xn),NRf_Xndx(Xn)));
                if (hcur <= hmin) {
                        gettimeofday(&stop, NULL);
                        break;
                }
                else {
                        Xn=Xn+NRhn(f_Xn(Xn),NRf_Xndx(Xn));
                        n+=1;
                }
        }
        printf("Newton-Raphson Method Result\n");
        printf("X%d: %f & hn: %f<=0.000005\n",n,Xn,hcur );
        printf("took %lu useconds.\n",stop.tv_usec - start.tv_usec);
}

float KXn(float Xo1,float Xo0){
        return Xo1-(f_Xn(Xo1)/Kf_Xndx(Xo1,Xo0));
}

float Kf_Xndx(float Xo1, float Xo0){
        return (f_Xn(Xo1)-f_Xn(Xo0))/(Xo1-Xo0);
}

float Khn(float Xn, float Xo1){
        return -f_Xn(Xn)*((Xn-Xo1)/(f_Xn(Xn)-f_Xn(Xo1)));
}

void Kiris(){
        gettimeofday(&start, NULL);
        while (1) {
                if (n>1) {
                        Xo0=Xo1;
                        Xo1=Xn;
                }
                Xn=KXn(Xo1,Xo0);
                hcur=fabs(Khn(Xn,Xo1));
                if (hcur<=hmin) {
                        gettimeofday(&stop, NULL);
                        break;
                }
                n++;
        }
        printf("Kiris Method Result\n");
        printf("X%d: %f & hn: %f<=0.000005\n",n,Xn,hcur );
        printf("took %lu useconds.\n",stop.tv_usec - start.tv_usec);
}


int main(){
        printf("As a Senior Developer: Sems Mustafa Turgut - 130106106054\n" );
        printf("Bayram Ustabaş - 130106106006\n" );
        printf("Bilal Demir - 130106106009\n" );
        printf("Taner Güden - 130106106057\n" );
        printf("Muzaffer Duysal - 132106106005\n" );
        printf("Mustafa Samet Altun - 130106106042\n" );
        printf("Veli Oktay - 142106106008\n\n\n" );
        printf("Please enter the method number giving below.\n" );
        printf("1)Newton Raphson Method\n" );
        printf("2)Kiris Method\n" );
        printf("Please enter 1-2: ");
        scanf("%d",&f_get);
        printf("\n");
        switch (f_get) {
        case 1:
                Newton_Raphson();
                break;
        case 2:
                Kiris();
                break;
        default:
                printf("\nPlease enter only 1 or 2 as a number.");
                main();
        }
        return 0;
}
