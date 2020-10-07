#include<iostream>
using namespace std;

int sumofdigit(int x){
    int j, sum = 0;
    while( x > 0){
        j = x % 10;
        sum += j;
        x /= 10;
    }
    return sum;
}
int primefactor(int n){
    int sum = 0, i;
    for ( i = 2; i*i <= n; i++){
        while( n % i == 0){
            int val = sumofdigit(i);
            sum += val;
            n /= i;
        }
    }
    if( n > 1){
        sum += sumofdigit(n);
    }
    return  sum;

}
int main(){

    int n;
    cin >> n;
    int numsum = sumofdigit(n);
    int factsum = primefactor(n);
    if( numsum == factsum) cout << "YES\n";
    else cout << "NO\n";

}

