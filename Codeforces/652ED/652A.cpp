#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int h1,h2,a,b,cont;
cin >> h1 >> h2 >> a >> b;
h1+= 8*a;

if(h1>=h2) cout << 0;
else if(a<=b) cout << -1;
else{
    cont = 0;
    while(h1<h2){
        cont++;
        h1 -= 12*b;
        h1 += 12*a;
    }
    cout << cont;
}



}
