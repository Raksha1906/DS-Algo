#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b){
    if( b == 0) return a;
    else {
        a = a % b;
        return gcd(b, a);
    }
}
signed main(){
    int a, b, result;
    cin >> a >> b;
    result = gcd(a, b);
    cout << result;
}

