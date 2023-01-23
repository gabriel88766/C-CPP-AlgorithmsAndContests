#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5+3, INF = 0x3f3f3f3f;
int mem[105], sz[105], aux[105];
bool al[105];
int cont = 1, m;
 
 
int findblock(int sz){
    int cont2=0;
    for(int i=1;i<=m;i++){
        if(!mem[i]){
            cont2++;
            if(cont2 == sz) return i-sz+1;
        }else cont2 = 0;
    }
    return -1;
 
}
 
void defrag(){
    int cont2 = 0;
    for(int i=1;i<=m;i++){
        if(mem[i] != 0){
            aux[++cont2] = mem[i];
        }
    }
    for(int i=1;i<=cont2;i++) mem[i] = aux[i];
    for(int i=(cont2+1);i<=m;i++) mem[i] = 0;
}
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t >> m;
    while(t--){
        string s;
        cin >> s;
        if(s == "defragment") defrag();
        else if(s == "alloc"){
            int qt;
            cin >> qt;
            int ind = findblock(qt);
            if(ind != -1){
                for(int i=ind;i<(ind+qt);i++) mem[i] = cont;
                al[cont] = true;
                cout << cont << "\n";
                cont++;
            }else{
                cout << "NULL\n";
            }
        }else{
            int x;
            cin >> x;
            if( x <= 100 && x >= 0 && al[x]){
                for(int i=1;i<=m;i++) if(mem[i] == x) mem[i] = 0;
                al[x] = false;
            }else{
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
            }
        }
 
 
    }
}
 