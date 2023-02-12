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
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'S') moveN(f, -1);
        if(s[i] == 'N') moveN(f, 1);
        if(s[i] == 'W') moveE(f, -1);
        if(s[i] == 'E') moveE(f, 1);
    }    
    cout << f[1] << "\n";


}

