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

void print(vector < pair<int,int> > & a) {
    for (auto element: a) cout << element.first << " "<<element.second<<endl;
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
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int count=0,s=0;
    int s0=accumulate(all(a),0ll);
    int start=0,end=0,s1,l;
    end=(x/s0)*n;
    s0=(x/s0)*s0;
    while(end<n*k){
        s0+=a[end%n];
        if(s0>=x){
            s0-=a[end%n];
            break;
        }
        end++;
    }
    s=s0;
    // cout<<s<<" "<<end<<endl;
    if(s>=x){
        end--;
        s-=a[end%n];
    }
    bool flag=true,con=true;
    vector<pair<int,int>> p;
    while(end<n*k&&con){
        // if(s<x)
        s+=a[end%n];
        while(s>=x){
            s-=a[start%n];
            if(flag){
                s1=start%n;
                l=end-start+1;
                flag=false;
            }else if(start%n==s1&&end-start+1==l){
                con=false;
                break;
            }
            p.push_back({start%n,end-start+1});
            start++;
        }
        end++;
    }
    for(int i=0;i<p.size();i++){
        count+=(k-(p[i].first+p[i].second-1)/n);
    }
    cout<<count<<endl;
    // print(p);
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