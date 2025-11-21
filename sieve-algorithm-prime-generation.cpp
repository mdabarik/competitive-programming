
/* Bismillah hir Rohmanir Rohim */
/* La Hawala Wa Lakuata Illah Billah */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pinf LLONG_MAX
#define ninf LLONG_MIN
#define coutBit(x)  (int)__builtin_popcount(x)
#define lsb(x)  (int)__builtin_ctzll(x)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'
#define PI acos(-1.0)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define MOD 1000000007LL

int mx = 3*1e3 + 123;
vector<bool> prime(mx+123, true);
vector<int> primeNum;

void primeGeneration() {
    prime[0] = prime[1] = false;
    
    for (int i = 4; i <= mx; i += 2) {
        prime[i] = false;
    }

    int sq = sqrt(mx);
    for (int i = 3; i <= sq; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j <= mx; j += 2 * i) {
                prime[j] = false;
            }
        }
    }
    primeNum.push_back(2);
    for (int i = 3; i <= mx; i += 2) {
        if (prime[i]) primeNum.push_back(i);
    }
}

vector<int> primeFactors (int n ){
    vector<int> factors;
    for ( auto p : primeNum ) {
        if( 1LL * p * p > n ) break;
        if( n % p == 0 ) {
            while ( n % p == 0 ) {
                factors.push_back(p);
                n /= p;
            }
        }
    }
    if(n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int PHI (int n){
	int phi = n;
    for ( auto p : primeNum ) {
        if(p * p > n ) break;
        if( n % p == 0 ) {
            while ( n % p == 0 ) {
                n /= p;
            }
           	
           	phi /= p;
           	phi *= (p-1); 
        }
    }
    if(n > 1) {
        phi /= n;
        phi *= (n-1);
    }
    return phi;
}



/* Robbi Zidni Ilma */
void BarikSolution() {


}

signed main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);

	primeGeneration();
	cout << PHI(12) << endl;

	/* amdr main logic */
	int testcase; 
	cin>>testcase;
	while (testcase--) {
		BarikSolution();
	}
	
	return 0;
}
/*
0
1
2
6
1

*/
