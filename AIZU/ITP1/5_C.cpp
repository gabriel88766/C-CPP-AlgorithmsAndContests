#include<bits/stdc++.h>

const double PI = acos(-1.);
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    while(a && b){
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if((i + j) % 2) cout << ".";
                else cout << "#"; 
            }
            cout << "\n";
        }   
        cout << "\n";
        cin >> a >> b;
    }
}