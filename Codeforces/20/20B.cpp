#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second

using namespace std;



double func(double x,int A,int B,int C){
    return (double)A*x*x + (double)B*x + (double)C;
}

void findlowerX(int A,int B,int C,double lx, double hx,double &x){
    if((hx-lx)> 0.000001) {
        if( (func(lx,A,B,C)>0 && func(lx+(hx-lx)/2,A,B,C)>0)|| (func(lx,A,B,C)<0 && func(lx+(hx-lx)/2,A,B,C)<0)  ){
            findlowerX(A,B,C,lx+(hx-lx)/2,hx,x);
        }else  {
            findlowerX(A,B,C,lx,hx-(hx-lx)/2,x);
        }
    }else{
        x = hx;
    }
}


int main(){

int A,B,C;
scanf("%d%d%d",&A,&B,&C);
double lx,hx,M,HX,LX;



if(A!=0){
    M = ((double)-B)/(2*(double)A);
    if((B*B-4*A*C) < 0){
            printf("0");
    }else{

        lx = M - B*B + 4 * A *C - 1;
        hx = M;
        findlowerX(A,B,C,lx,hx,LX);


        hx = M + B*B - 4 * A *C + 1;
        lx = M;

        findlowerX(A,B,C,lx,hx,HX);

        if(HX-LX>0.000001){
            printf("2\n");
            printf("%lf\n",LX);
            printf("%lf",HX);
        }else{
            printf("1\n");
            printf("%lf",HX);
        }
    }

}else if(B!=0){
    printf("1\n");
    M = ((double)-C)/B;
    printf("%lf",M);
}else{
    if(C!=0){
        printf("0");
    }else{
        printf("-1");
    }
}

}
