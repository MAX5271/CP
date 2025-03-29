// template for cp

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define MOD 1e9 + 7
const int N = 1e5 + 10;
int arr[N];


#define all(a) a.begin(), a.end()

int npr(int n, int r)
{
    r = min(r, (n - r));
    int a = 1;
    for (int i = 0; i < r; i++) {
        a *= (n - i);
    }
    for (int i = 1; i < r; i++) {
        a /= (i + 1);
    }
    return a;
}

vector < int > seive;

bool prime[1000001];
vector < int > v1(1000001);
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                if (v1[i] == 0) v1[i] = p;
                prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            seive.push_back(p);
}

void print(vector < int > & a) {
    for (auto element: a) cout << element << " ";
    cout << endl;
}

void sortfdsi(vector<pair<int, int>>& vec){
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        // Sort by first element in decreasing order
        if (a.first != b.first) {
            return a.first > b.first;
        }
        // If the first elements are equal, sort by the second element in increasing order
        return a.second < b.second;
    });

}

bool is_Prime(int n)
{
    if (n <= 1)
        return false;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;

    return true;
}

void swap(int * a, int * b)
{
    int temp = * a;
    * a = * b;
    * b = temp;
}

int factorial(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
        p *= i;

    return p;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve()
{
    int a,b;
    string s;
    cin>>a>>b;
    cin>>s;
    int n = a + b;

    for(int i = 0; i < n; i++) {
        if(s[i] != '?' && s[n - i - 1] != '?') {
            if(s[i] != s[n - i - 1]) {
                cout << -1 << endl;
                return;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '0' && s[n - i - 1] == '?') {
            s[n - i - 1] = '0';
        } else if(s[i] == '1' && s[n - i - 1] == '?') {
            s[n - i - 1] = '1';
        }
    }

    for(int i = 0; i < n / 2; i++) {
        if(n % 2 != 0 && i == n / 2) continue;
        if(s[i] == '0') {
            a -= 2;
        } else if(s[i] == '1') {
            b -= 2;
        }
    }

    if(n % 2 != 0) {
        if(s[n / 2] == '0') {
            a--;
        } else if(s[n / 2] == '1') {
            b--;
        }
    }

    for(int i = 0; i < n; i++) {
        if(n % 2 != 0 && i == n / 2) continue;
        if(s[i] == '?' && s[n - i - 1] == '?') {
            if(a > 0) {
                a -= 2;
                s[i] = s[n - i - 1] = '0';
            } else if(b > 0) {
                b -= 2;
                s[i] = s[n - i - 1] = '1';
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    if(n % 2 != 0) {
        if(a > 0) {
            a--;
            s[n / 2] = '0';
        } else if(b > 0) {
            b--;
            s[n / 2] = '1';
        }
    }

    if(a % 2 != 0 || b % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    if(a != 0 || b != 0) {
        cout << -1 << endl;
    } else {
        cout << s << endl;
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

}