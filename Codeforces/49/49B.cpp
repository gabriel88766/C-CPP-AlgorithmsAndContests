#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second

using namespace std;

int toBase10(int base,int num){
    int totaldigit=0;
    int auxnum = num;
    while(num){
        num/=10;
        totaldigit++;
    }

}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int a,b,auxA,auxB,maxdig=0,totaldig=0,sum=0;
cin >> a >> b;
auxA=a;
auxB=b;
int v[]={0,0,0,0},u[]={0,0,0,0},cont=0;
while(auxA||auxB){
    if(maxdig < max(auxA%10,auxB%10))
        maxdig = max(auxA%10,auxB%10);
    v[cont]=auxA%10;
    u[cont]=auxB%10;
    cont++;
    auxA/=10;
    auxB/=10;
}
int base = maxdig+1;
cont=3;

while(cont!=-1){
    sum*=base;
    sum+=u[cont];
    sum+=v[cont];
    cont--;

}
if(sum >= base*base*base*base){
    cout << 5;
}else if(sum >= base*base*base){
    cout << 4;
}else if(sum >= base*base){
    cout << 3;
}else if(sum >= base){
    cout << 2;
}else
    cout << 1;

}
