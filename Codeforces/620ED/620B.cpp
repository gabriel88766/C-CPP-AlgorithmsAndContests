#include <bits/stdc++.h>

using namespace std;

int v[] = { 6,2,5,5,4,5,6,3,7,6};
int t[10];

int main(){
int a,b,aux,S=0;
cin >> a >> b;
while(a<=b){
    aux = a;
    while(aux!=0){
        t[aux%10]++;
        aux/=10;
    }
    a++;
}
for(int i=0;i<10;i++){
    S+=t[i]*v[i];
}
cout << S;

}

