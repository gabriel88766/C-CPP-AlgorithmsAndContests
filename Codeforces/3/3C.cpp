#include <bits/stdc++.h>

using namespace std;

int main(){
int cX=0,c0=0;
char v[9],aux;
bool fpw=false,spw=false;
for(int i=0;i<9;i++){
    cin >> aux;
    if(aux == 'X') cX++;
    else if(aux == '0') c0++;
    v[i]=aux;
}

int dif = cX-c0;
if(!(dif==1 || dif==0)){
    cout << "illegal";
    return 0;
}
if( v[0]==v[3]&&v[3]==v[6]){
    if(v[0]=='X'){
        fpw=true;

    }else if(v[0]=='0'){
        spw=true;

    }
}
if( v[1]==v[4]&&v[4]==v[7]){
    if(v[1]=='X'){
        fpw=true;

    }else if(v[1]=='0'){
        spw=true;

    }
}
if( v[2]==v[5]&&v[5]==v[8]){
    if(v[2]=='X'){
        fpw=true;

    }else if(v[2]=='0'){
        spw=true;

    }
}
if( v[0]==v[1]&&v[1]==v[2]){
    if(v[0]=='X'){
        fpw=true;

    }else if(v[0]=='0'){
        spw=true;

    }
}
if( v[3]==v[4]&&v[4]==v[5]){
    if(v[3]=='X'){
        fpw=true;

    }else if(v[3]=='0'){
        spw=true;

    }
}
if( v[6]==v[7]&&v[7]==v[8]){
    if(v[6]=='X'){
        fpw=true;

    }else if(v[6]=='0'){
        spw=true;

    }
}
if( v[0]==v[4]&&v[4]==v[8]){
    if(v[0]=='X'){
        fpw=true;

    }else if(v[0]=='0'){
        spw=true;

    }
}
if( v[2]==v[4]&&v[4]==v[6]){
    if(v[2]=='X'){
        fpw=true;

    }else if(v[2]=='0'){
        spw=true;

    }
}
if(fpw){
    if(!spw){
        if(dif==1) cout << "the first player won";
        else cout << "illegal";
        return 0;
    }else{
        cout << "illegal";
        return 0;
    }
}
if(spw){
    if(dif==0) cout << "the second player won";
    else cout << "illegal";
    return 0;
}

if((cX+c0)==9){
    cout << "draw";
    return 0;
}
if(dif==0){
    cout << "first";
}else{
    cout << "second";
}

}
