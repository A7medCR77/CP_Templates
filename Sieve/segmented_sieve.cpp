#include <bits/stdc++.h>
#define ll long long
#define ceil(n, m) (n + m - 1) / m
#define eb emplace_back
#define nl '\n'
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
        out << x << " ";
    return out;
}

// get prime numbers between L R
// Time complexity o(R-L+1)*log(log(R))
template <typename T>
struct segmented_sieve
{
private:
    ll lim;
    vector<bool> mark, is_prime;
    vector<T> primes;
    T L, R;

public:
    segmented_sieve(T _L, T _R) : L(_L), R(_R)
    {
        lim = sqrtl(R);
        mark.assign(lim + 1, true);

        for (T i = 2; i <= lim; ++i)
        {
            if (mark[i])
            {
                primes.eb(i);
                for (T j = i * i; j <= lim; j += i)
                    mark[j] = false;
            }
        }

        is_prime.assign(R - L + 1, true);
        for (auto &i : primes) // 2 3
            for (T j = max(i * i, ceil(L, i) * i); j <= R; j += i)
                is_prime[j - L] = false; // in case L and R are big numbers will subtract all number from L

        if (L == 1)
            is_prime[0] = false;
    };

    vector<T> get_primes()
    {
        vector<T> primes;
        for (T i = L; i <= R; ++i)
            if (is_prime[i - L])
                primes.eb(i);
        return primes;
    }

    vector<bool> get_boolean_primes()
    {
        return is_prime;
    }
};

void solve()
{
    segmented_sieve<ll> a(9, 100);
    cout << a.get_primes();
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
