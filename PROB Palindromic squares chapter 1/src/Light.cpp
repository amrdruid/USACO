/*
LANG: C++
PROB: palsquare
*/

#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define all(v) (v).begin( ), (v).end( )
double pi = 3.1415926536;
const int oo = (int) 1e9;
const long long OO = numeric_limits<long long>::max();

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int f1[] = { 0, 0, 0, 1, 1, 1, -1, -1, -1 };
int f2[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int b;
map<int,char>mymap;
vector<pair<string , string> >myvec;

void checkPalindrome(string s , string i){
	for(int i = 0 ; i <= sz(s) / 2 ; i++){
		if(s[i] != s[sz(s) - i - 1])
			return;
	}

	myvec.push_back(make_pair(i , s));
}

void transform(int x , int i){
	string s , p;
	while(x){
		if(x % b >= 10){
			s += mymap[x % b];
		}else{
			s += (x % b) + '0';
		}

		x /= b;
	}

	while(i){
		if(i % b >= 10){
			 p+= mymap[i % b];
		}else{
			p += ( i % b) + '0';
		}

		i /= b;
	}



	reverse(s.begin() , s.end());
	reverse(p.begin() , p.end());
	checkPalindrome(s , p);
}



int main(){
    ios_base::sync_with_stdio(false);
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);

    for(char c = 'A' ; c <= 'Z' ; c++){
    	mymap[(c - 'A') + 10] = c;
    }

    cin >> b;

    for(int i = 1 ; i <= 300 ; i++){
    	transform(i * i , i);
    }

    for(int i = 0 ; i < sz(myvec) ; i++){
    	cout << myvec[i].first << " " << myvec[i].second << endl;
    }

    return 0;
}
