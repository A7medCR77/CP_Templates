#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
#define MOD 1000000007
#define ceil(n, m) (n + m - 1) / m
#define round(n, m) (n + m / 2) / m
#define sz(s) s.size()
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define sum_of_first_n_odd_number(n) ((n % MOD) * (n % MOD)) % MOD;
#define all(s) s.begin(), s.end()
#define OO 20000000000
#define ld long double
#define pi 3.141592653589793
#define rall(s) s.rbegin(), s.rend()
#define fixed(n) cout << fixed << setprecision(n)
#define mod_combine(a, b, m) (((a % m) * (b % m)) % m)
#define se second
#define fi first
#define eb emplace_back
#define pb push_back
#define pf push_front
#define nl '\n'
#define PI acos(-1.0)
#define EPS 1e-9
#define dot_prod(a, b) real(conj(a) * (b))
#define cross_prod(a, b) imag(conj(a) * (b))
#define rotateO(p, theta) (p) * polar(1.0, theta)
#define rotateA(p, a, theta) rotateO((p) - (a), theta) + (a)
#define reflectO(p, m) conj((p) / (m)) * (m)
#define reflectA(p, a, m) reflectO((p) - (a), m) + (a)
#define MAXll 9223372036854775807
#define E 2.71828182846
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)

using namespace std;

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << "\n";
    return out;
}


//______________________________________________CODE________________________________________________________________________________________________________________________________________

struct math
{

    math() {}

    // cmp double
    int dcmp(double x, double y)
    {
        return (fabs(x - y) <= EPS ? 0 : (x < y ? -1 : 1));
    }

    // summation of arithmetic sequence increase with constant number
    // 2 4 6 8.....
    // 1 3 5 7.....
    // 1 4 7 10.....
    ll arithmetic_summation(ll first = 1, ll last = 1)
    {
        ll x = last - first + 1;
        return ((first + last) * x) / 2;
    }

    // get kth element in sequence increase by multiple of constant
    // 1 4 16...
    // 1 3 9...
    ll kth(ll first, ll ratio, ll k)
    {
        // ratio->the constant number
        return first * pow(ratio, k - 1);
    }

    // get summation of geometry sequence increase by multiple of constant
    // 1 4 16...
    // 1 3 9...
    ll geometry_summation(ll first, ll ratio, int number_of_element)
    {
        return ((first * (1 - pow(ratio, number_of_element))) / (1 - ratio));
    }

    ll get_mul(ll a, ll b, ll mod)
    {
        ll res = 0;

        while (b)
        {
            if (b & 1)
                res = ((res % mod) + (a % mod)) % mod;
            a = ((a % mod) * 2) % mod;
            b /= 2;
        }

        return res % mod;
    }

    ll binary_exponential(ll a, ll b)
    {
        ll res = 1;

        while (b)
        {
            if (b & 1)
                res *= a;
            a *= a;
            b /= 2;
        }

        return res;
    }

    ll modular_exponential(ll a, ll b, ll mod = 1000000007)
    {
        ll res = 1;

        while (b)
        {
            if (b & 1)
                res = get_mul(res, a, mod);
            a = get_mul(a, a, mod);
            b /= 2;
        }

        return res % mod;
    }

    ll mod_inv(ll x)
    {
        return modular_exponential(x, MOD - 2);
    }

    vector<ll> divisors(ll n)
    {
        vector<ll> ans;

        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                ans.eb(i);
                if (i != n / i)
                    ans.eb(n / i);
            }
        }

        sort(all(ans));

        return ans;
    }

    vector<ll> prime_factorization(ll n)
    {
        vector<ll> ans;

        while (n % 2 == 0)
            ans.eb(2), n /= 2;

        for (int i = 3; i * i <= n; i += 2)
            while (n % i == 0)
                ans.eb(i), n /= i;

        if (n != 1)
            ans.eb(n);

        return ans;
    }

    ll GCD(ll a, ll b)
    {
        return (!b ? a : GCD(b, a % b));
    }

    ll LCM(ll a, ll b)
    {
        return a / GCD(a, b) * b;
    }

    int Extended_Euclidean(int a, int b, int &x, int &y)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }

        int x1, y1;
        int d = Extended_Euclidean(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    int reverse_summation(ll n)
    {
        ll a = (-1 + (ll)sqrtl(1 + 8 * n)) / 2;
        ll z = arithmetic_summation(1, a);
        return (n == z ? a : -1);
    }

    // if p is prime number then (a^(p-1))%p==1
    // a is a random number in range 0<a<p

    bool Fermat_Primality_Testing(ll p, ll k) // will take k random number to check
    {
        if (p <= 4)
            return (p == 2 || p == 3);
        for (int i = 0; i < k; ++i)
        {
            ll y = (rand() % ((p - 2) - 2 + 1)) + 2; // will make rand function get random value in range 2 to p-2
            ll x = modular_exponential(y, p - 1, p);
            if (x != 1)
                return false;
        }
        return true;
    }
};

void solve()
{
}

int main()
{
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
