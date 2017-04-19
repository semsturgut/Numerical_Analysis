#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define X 2

float SCM[4][4] = {{4,1,1,0},
                   {1,4,0,1},
                   {1,0,4,1},
                   {0,1,1,4}};
float Xc[4] = {1,2,0,1};
float Xold[4] = {0,0,0,0};
float Xnew[4];
int n=0;

int porcay(int i){
        int j=0;
        float Xtop;
        while (1) {
                Xtop += SCM[i][j]*Xold[j];
                if (j==3) {break; }
                else {j++; }
        }
        return Xtop-(SCM[i][i]*Xold[i]);
}

void jacobi(){
        int i=0;
        while (1) {
                Xnew[i]=(1/SCM[i][i])*(Xc[i]-porcay(i));
                printf("%f\n",Xnew[i] );
                if (abs(Xold[0]-Xnew[0])<=0.0001
                    && abs(Xold[1]-Xnew[1])<=0.0001
                    && abs(Xold[2]-Xnew[2])<=0.0001
                    && abs(Xold[3]-Xnew[3])<=0.0001 && n>0) {
                        printf("%d\n",n );
                        break;
                } else if (i==3) {i=0; Xold[0]=Xnew[0];
                                  Xold[1]=Xnew[1];
                                  Xold[2]=Xnew[2];
                                  Xold[3]=Xnew[3];
                                  n+=1; }
                else{i+=1; }
        }
}

void Gauss_Siedel(){
        float x[X][X+1],a[X], ae, max,t,s,e;
        int i,j,r,mxit;
        for(i=0; i<X; i++) a[i]=0;
        puts(" Eneter the elemrnts of augmented matrix rowwise\n");
        for(i=0; i<X; i++)
        {
                for(j=0; j<X+1; j++)
                {
                        scanf("%f",&x[i][j]);
                }
        }
        printf(" Eneter the allowed error and maximum number of iteration: ");
        scanf("%f%d",&ae,&mxit);
        printf("Iteration\tx[1]\tx[2]\n");
        for(r=1; r<=mxit; r++)
        {
                max=0;
                for(i=0; i<X; i++)
                {
                        s=0;
                        for(j=0; j<X; j++)
                                if(j!=i) s+=x[i][j]*a[j];
                        t=(x[i][X]-s)/x[i][i];
                        e=fabs(a[i]-t);
                        a[i]=t;
                }
                printf(" %5d\t",r);
                for(i=0; i<X; i++)
                        printf(" %9.4f\t",a[i]);
                printf("\n");
                if(max<ae)
                {
                        printf(" Converses in %3d iteration\n", r);
                        for(i=0; i<X; i++)
                                printf("a[%3d]=%7.4f\n", i+1,a[i]);
                        //return 0;
                }

        }
}

int main() {
        int a;
        printf("Jacobi=1\n");
        printf("Gauss Siedel=2\n");
        printf("Jacobi Aitken=3\n");
        scanf("%d\n",&a);
        switch (a) {
        case 1:
                jacobi();
                break;
        case 2:
                Gauss_Siedel();
                break;
        case 3:
                printf("Sorry we can't measure values.\n");
                break;
        }
        return 0;
}
