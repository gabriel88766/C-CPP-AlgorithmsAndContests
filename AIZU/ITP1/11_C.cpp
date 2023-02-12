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

void rotate(int *vec, int dir){
    int aux[4];
    aux[0] = vec[2];
    aux[1] = vec[3];
    aux[2] = vec[5];
    aux[3] = vec[4];
    vec[2] = aux[(dir+4)%4];
    vec[3] = aux[(dir+5)%4];
    vec[5] = aux[(dir+6)%4];
    vec[4] = aux[(dir+7)%4];    
}

bool checkEq(int *u, int *v){
    for(int i=1;i<=6;i++) if(u[i] != v[i]) return false;
    return true;
}

bool checkEqual(int *u, int *v){
     for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            for(int k=1;k<=4;k++){
                if(checkEq(u, v)){
                    return true;
                }
                moveE(u, 1);
            }
            moveN(u, 1);
        }
        rotate(u, 1);
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f[7], e[7];
    for(int i=1;i<=6;i++) cin >> f[i];
    for(int j=1;j<=6;j++) cin >> e[j];
    //check repetitions
    if(checkEqual(f, e)) cout << "Yes\n";
    else cout << "No\n";

}

