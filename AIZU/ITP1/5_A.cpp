#include<bits/stdc++.h>

const double PI = acos(-1.);
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    while(a && b){
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cout << "#";
            }
            cout << "\n";
        }   
        cout << "\n";
        cin >> a >> b;
    }
}