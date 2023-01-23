#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5+3, INF = 0x3f3f3f3f;
char v[8][8];
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    bool ok;
    int cont = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> v[i][j];
        }
    }
    for(int i=0;i<8;i++){
        ok = true;
        for(int j=0;j<8;j++){
            if(v[i][j] != 'B') ok = false;
        }
        if(ok) cont++;
        ok = true;
        for(int j=0;j<8;j++){
            if(v[j][i] != 'B') ok = false;
        }
        if(ok) cont++;
    }
    if(cont != 16)cout << cont;
    else cout << 8;
}
 