#include <bits/stdc++.h>
 
using namespace std;
 
long long int dp[64],pot2[64];
 
void init(){
    dp[0]=1;
    long long int aux = 1;
    pot2[0]=aux;
    for(int i=1;i<52;i++){
        dp[i] = dp[i-1]+dp[i-1]-1 + aux;
        aux <<= 1;
        pot2[i] = aux;
    }
}
 
int main(){
init();
long long int n,cont=0,aux2=51,ans=0;
cin >> n;
while(n){
    if(n<pot2[aux2]){
 
    }
    else{
        n -= pot2[aux2];
        ans += dp[aux2] + pot2[aux2]*cont++;
    }
    aux2--;
}
cout << ans;
}