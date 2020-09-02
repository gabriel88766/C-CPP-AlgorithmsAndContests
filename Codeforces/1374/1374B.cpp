#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second

using namespace std;

int fact(int n,int d){
    int cont=0;
    while(!(n%d)){
        cont++;
        n/=d;
    }
    return cont;
}
bool only2and3(int n){
    while(!(n%2)||!(n%3)){
        if(!(n%2)) n/=2;
        else n/=3;
    }
    if(n==1) return true;
    else return false;

}


int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int x,y,m2,m3,status;
cin >> x;
for(int i=0;i<x;i++){
    cin >> y;
    m2=fact(y,2);
    m3=fact(y,3);
    status = only2and3(y);
    if(status){
        if(m2>m3){
            cout << -1 << endl;
        }else{
            cout << 2*m3 - m2 << endl;
        }
    }else{
        cout << -1 << endl;
    }
}
}
