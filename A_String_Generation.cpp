#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define all(a) a.begin(),a.end() 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
ll dec(string &s){
    ll r = 0;
    ll p = 1;
    for(ll i = s.size()-1;i >=0;i--){
        r += p *(s[i] - '0');
        p *=2;
    }
    return r;
}
bool isPalindrome(string &str){
    for(int i = 0;i<str.size()/2;i++){
        if(str[i] != str[str.size()-1-i])return 0;
    }
    return 1;
}
int check(int n){
    int temp = n;
    string str = "";
    while(n){
        if(n&1 == 1)str+="1";
        else str += "0";
        n >>= 1;
    }
    reverse(all(str));
    if(isPalindrome(str))return 0;
    int len = str.size();
    if(len %2 == 0){
        string temp1 = "",temp2 = "";
        string first = str.substr(0,len/2);
        string second = str.substr(len/2,len/2);
        string rfirst = first;
        string rsecond = second;
        reverse(all(rfirst));
        reverse(all(second));
        temp1 = first + rfirst;
        temp2 = rsecond + second;
        ll mini1 = abs(temp - dec(temp1));
        ll mini2 = abs(temp - dec(temp2));
        ll mini3 = temp;
        return min(mini1,min(mini2,mini3));
    }
    else{
         string temp1 = "",temp2 = "";
        string first = str.substr(0,len/2);
        string second = str.substr(len/2,len/2);
        string rfirst = first;
        string rsecond = second;
        reverse(all(rfirst));
        reverse(all(second));
        temp1 = first + str[len/2] +  rfirst;
        temp2 = rsecond + str[len/2] + second;
        ll mini1 = abs(temp - dec(temp1));
        ll mini2 = abs(temp - dec(temp2));
        ll mini3 = temp;
        return min(mini1,min(mini2,mini3));
    }
}
int main()
{
    //your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        ll diff = check(n);
        cout << diff << "\n";
    }
    return 0;
}
