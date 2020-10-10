#include <bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,a,b,cont=0;
cin >> n >> a >> b;
for(int i=1;i<=n;i++){
    if( (i>a) && (n-i) <= b) cont++;
}
cout << cont;
}

