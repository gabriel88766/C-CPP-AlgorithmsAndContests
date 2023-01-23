#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5+3, INF = 0x3f3f3f3f;
int v[N];
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n;
    cin >> n;
    if(n == 1){ cout << "1 0"; return 0;}
    for(int i=1;i<=n;i++) cin >> v[i];
    int ep = n, bp = 1,suma=v[1],sumb=v[n];
    while(ep!=(bp+1)){
        if(suma <= sumb){
            suma += v[++bp];
        }else{
            sumb += v[--ep];
        }
    }
    cout << bp << " " << n-bp;
}