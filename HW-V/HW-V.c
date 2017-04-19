#include <stdio.h>
#include <math.h>

void Forward(int n){

        int i,j;
        float ax[10],ay[10],x,y=0,h,p,diff[20][20],y1,y2,y3,y4;

        for(i=0; i<n; i++) {
                printf("x%d: ",i+1);
                scanf("%f",&ax[i]);
        }

        for(i=0; i<n; i++) {
                printf("y%d: ",i+1);
                scanf("%f",&ay[i]);
        }

        printf("\n F(x) x = ?");
        printf("\n x: ");
        scanf("%f",&x);

        h=ax[1]-ax[0];
        for(i=0; i<n-1; i++) {
                diff[i][1]=ay[i+1]-ay[i];
        }

        for(j=2; j<=4; j++) {
                for(i=0; i<n-j; i++) {
                        diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
                }
        }

        i=0;
        do {
                i++;
        }
        while(ax[i]<x);

        i--;
        p=(x-ax[i])/h;
        y1=p*diff[i][1];
        y2=p*(p-1)*diff[i-1][2]/2;
        y3=(p+1)*p*(p-1)*diff[i-2][3]/6;
        y4=(p+1)*p*(p-1)*(p-2)*diff[i-3][4]/24;
        y=ay[i]+y1+y2+y3+y4;
        printf("\n\n\n x = %6.4f , y = %6.8f\n",x,y);
}

void Backward(int n){

        int i,j;
        float ax[10],ay[10],x,y=0,h,p,diff[20][20],y1,y2,y3,y4;
        for(i=0; i<n; i++) {
                printf("\n x%d: ",i+1);
                scanf("%f",&ax[i]);
        }
        for(i=0; i<n; i++) {
                printf("\ny%d: ",i+1);
                scanf("%f",&ay[i]);
        }

        printf("\n F(x) x = ?");
        printf("\n x: ");
        scanf("%f",&x);

        h=ax[1]-ax[0];
        for(i=0; i<n-1; i++) {
                diff[i][1]=ay[i+1]-ay[i];
        }

        for(j=2; j<=4; j++) {
                for(i=0; i<n-j; i++) {
                        diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
                }
        }
        i=0;
        do {
                i++;
        }
        while(ax[i]<x);

        i--;
        p=(x-ax[i])/h;
        y1=p*diff[i-1][1];
        y2=p*(p+1)*diff[i-1][2]/2;
        y3=(p+1)*p*(p-1)*diff[i-2][3]/6;
        y4=(p+2)*(p+1)*p*(p-1)*diff[i-3][4]/24;
        y=ay[i]+y1+y2+y3+y4;

        printf("\n x = %6.4f , y = %6.4f",x,y);
}

int main()
{
        int n,choose;

        printf("\n Sems Mustafa Turgut - 130106106054");
        printf("\n Hüseyin Atmaca - 131106106001");
        printf("\n Bilal Demir - 130106106009");
        printf("\n Taner Güden - 130106106057");

        printf("\n Numeric Analysis Homework-V ");
        printf("\n Enter how many values: ");
        scanf("%d",&n);

        printf("\n 1)Gauss Forward\n 2)Gauss Backward");
        scanf("%d",&choose );

        if (choose==1) {
                Forward(n);
        }
        else if (choose==2) {
                Backward(n);
        }

        return 0;
}
