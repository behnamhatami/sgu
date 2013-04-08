#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define sh(s) cout << #s << " --> " << s << endl

inline void put(ll &a, ll val_a, ll &b, ll val_b){
	a = val_a;
	b = val_b;
}

inline void put(ll &a, ll val_a){
	a = val_a;
}

void normalize(ll &a, ll &mn, ll &mx){
	if(a < 0){
		put(a, -a);
		put(mn, -mx, mx, -mn);
	}
}

ll gcd(ll a, ll b){
	put (a, max(a, b), b, min(a, b));
	while(a != 0 && b != 0)
		put(a, b, b, a % b);
	return a;
}

pll find_ans(ll a, ll b){
	if(b == 0)
		return pll(-1, 0);
	pll res = find_ans(b, a % b);
	return pll(res.second, res.first - (a / b) * res.second);
}

void answer(ll ans){
	cout << ans << endl;
	exit(0);
}

int main(){
	ll a, b, c;
	ll x1, x2;
	ll y1, y2;

	cin >> a >> b >> c;
	cin >> x1 >> x2;
	cin >> y1 >> y2;

	normalize(a, x1, x2);
	normalize(b, y1, y2);
	
	// sh(a); sh(b); sh(c); sh(x1); sh(x2); sh(y1); sh(y2);

	if(a == 0 && b == 0)
		answer((c == 0)? (y2 - y1 + 1) * (x2 - x1 + 1):0);

	ll com = gcd(a, b);
	if(c % com != 0)
		answer(0);
	a /= com;
	b /= com;
	c /= com;

	if(a == 0)
		answer((-c >= y1 && -c <= y2)?1:0);

	if(b == 0)
		answer((-c >= x1 && -c <= x2)?1:0);
		
	pll ans = find_ans(a, b);
	ll x0 = ans.first * c;
	ll y0 = ans.second * c;

	// sh(x0); sh(y0);


	ll mn = max(ceil (((ld)(x1-x0))/b), ceil (((ld)(y0-y2))/a));
	ll mx = min(floor(((ld)(x2-x0))/b), floor(((ld)(y0-y1))/a));

	answer((mx>=mn)?(mx-mn+1):0);
	return 0;
}