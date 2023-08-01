#include <bits/stdc++.h>
#define ll long long
#define sz(s) s.size()

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

// time complexity n

template <typename T = int>
struct linear_sieve
{
    vector<bool> is_prime;
    vector<T> primes;
    int n;
    linear_sieve(int n)
    {
        is_prime.assign(n + 5, true);

        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i < n; ++i)
        {
            if (is_prime[i])
                primes.push_back(i);
            for (int j = 0; j < sz(primes) && i * primes[j] < n; ++j)
            {
                is_prime[i * primes[j]] = false;
                if (!(i % primes[j]))
                    break;
            }
        }
    }

    vector<T> get_primes()
    {
        return primes;
    }
};

void solve()
{
    linear_sieve<int> a(100);
    cout << a.get_primes();
}

int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
