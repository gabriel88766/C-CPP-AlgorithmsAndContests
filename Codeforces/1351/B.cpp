#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int t,a,b,c,d;
 
cin >> t;
char rect;
while(t--){
    rect = false;
    cin >> a >> b >> c >> d;
    if(a==c){
        if((b+d)==a){
            rect=true;
        }
    }
    if(a==d){
        if((b+c)==a)
            rect = true;
    }
    if(b==c){
        if((a+d)==b){
            rect=true;
        }
    }
    if(b==d){
        if((a+c)==b){
            rect = true;
        }
    }
    if(rect) cout << "Yes" << endl;
    else cout << "No" << endl;
}
 
    
    
}