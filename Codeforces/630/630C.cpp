#include <bits/stdc++.h>

using namespace std;

int main(){
long long int aux,ans=0,pot=1;
cin >> aux;
for(long long int i=0;i<aux;i++){
    pot*=2;
    ans+=pot;
}
cout << ans;
}

