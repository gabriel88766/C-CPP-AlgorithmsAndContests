#include<bits/stdc++.h>

using namespace std;
const double PI = acos(-1.);

void moveN(int *vec, int dir){
    int aux[4];
    aux[0] = vec[1];
    aux[1] = vec[2];
    aux[2] = vec[6];
    aux[3] = vec[5];
    vec[1] = aux[(dir+4)%4];
    vec[2] = aux[(dir+5)%4];
    vec[6] = aux[(dir+6)%4];
    vec[5] = aux[(dir+7)%4];
}

void moveE(int *vec, int dir){
    int aux[4];
    aux[0] = vec[1];
    aux[1] = vec[4];
    aux[2] = vec[6];
    aux[3] = vec[3];
    vec[1] = aux[(dir+4)%4];
    vec[4] = aux[(dir+5)%4];
    vec[6] = aux[(dir+6)%4];
    vec[3] = aux[(dir+7)%4];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f[7];
    for(int i=1;i<=6;i++) cin >> f[i];
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        if(f[3] == b || f[4] == b){
            moveE(f, 1);
        }
        while(f[2] != b) moveN(f, 1);
        while(f[1] != a) moveE(f, 1);
        cout <<  f[3] << "\n";
    }    


}

