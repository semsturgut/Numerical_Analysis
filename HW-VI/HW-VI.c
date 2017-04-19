#include <stdio.h>
#include <conio.h>
#include <math.h>

void ileri(){
								printf("ileriye dogru: Devam etmek icin bir tusa basiniz\n");
								char tus=0;
								tus=getch();
								s=(z-t[0])/h;
								a=((V[1]-V[0])+((2*s-1)*(V[2]-2*V[1]+V[0]))/2+((3*pow(s,2)-6*s+2)*(V[3]-3*V[2]+3*V[1]-V[0]))/6)/h;
								printf("V[%.1f] = %.4f dir.",z,a);
}

void geri(){
								printf("Geriye dogru: Devam etmek icin bir tusa basiniz\n");
								char tus=0;
								tus=getch();
								s=(z-t[5])/h;
								b=((V[5]-V[4])+((2*s+1)*(V[5]-2*V[4]+V[3]))/2+((3*pow(s,2)+6*s+2)*(V[5]-3*V[4]+3*V[3]-V[2]))/6)/h;
								printf("V[%.1f] = %.4f dir.",z,b);
}

void merkezi(){
								printf("Merkezi sonlu: Devam etmek icin bir tusa basiniz\n");
								char tus=0;
								tus=getch();
								s=(z-t[2])/h;
								c=((V[3]-V[1])/2+s*(V[3]-2*V[2]+V[1])+(3*pow(s,2)-1)*(V[4]-2*V[3]+2*V[1]-V[0])/12)/h;
								printf("V[%.2f] = %.4f dir.",z,c);
}

void main()
{
								int i;
								float t[6],V[6],z,a_ort,u_ort,h,s,a,b,c;
								for(i=0; i<6; i++)
								{
																printf("t[%d]=",i);
																scanf("%f",&t[i]);
																printf("\t");
																printf("V[%d]=",i);
																scanf("%f",&V[i]);
								}
								a_ort=(t[1]+t[2])/2;
								u_ort=(t[3]+t[4])/2;
								h=t[1]-t[0];
								printf("a_ort=%f	u_ort=%f\n",a_ort,u_ort);
								printf("Hangi hiz degerini = ");
								scanf("%f",&z);
								if(z<=a_ort) {ileri(); }
								else if(u_ort<=z) {geri(); }
								else {merkezi(); }
}
