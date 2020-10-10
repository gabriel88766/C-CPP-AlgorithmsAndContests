#include <bits/stdc++.h>

using namespace std;

int divp[3005];
int dp[3005];
void init(){
memset(divp, 0, sizeof(divp));
int cont = 0;
for(int i=2;i<3005;i++){

    if(!divp[i]){
        for(int j=i;j<3005;j+=i){
            divp[j]++;
        }
    }
}
for(int i=2;i<3005;i++){
    if(divp[i]==2) cont++;
    dp[i] = cont;
}
}


int main(){
init();
int n;
cin >> n;
cout << dp[n];


}
