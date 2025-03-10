#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define setpr(n) cout << fixed << setprecision(n)
#define vll vector<long long> 
#define all(x) x.begin(), x.end()  
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define MOD 1000000007
#define MAX LLONG_MAX
#define MIN LLONG_MIN

void solve() {
    ll x,y,result;
    cin >> x >> y;
    ll a = pow(x,2)+pow(x,2);
    ll b = pow(x,4)-(pow(x,2)*pow(y,2))+pow(y,4);
    result = (pow(x,2)-pow(y,2)) * gcd(a,b);
    cout << result << nl;
  }

int main() {
    io();  
    int T;
    cin >> T;  
    while (T--) {
        solve();
    }
    return 0;
}
