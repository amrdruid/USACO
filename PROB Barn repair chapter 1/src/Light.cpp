/*
LANG: C++
PROB: barn1
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

vector<int>myvec;
int c;
int sol = oo;
int dp[100][100];

void rec(int i , int m , int res){

	if( !m || res > sol){
		return ;
	}

	for( ; i < c ; i++){

		if(res > sol){
			return;
		}

		if(i + 1 != c && myvec[i + 1] - myvec[i] <= 1){
			res += 1;
		}else if(i + 1 != c && myvec[i + 1] - myvec[i] > 1){

			if(dp[i][m] > res){
				dp[i][m] = res;
				rec(i + 1 , m - 1 , res + 1);
			}

			res += (myvec[i + 1] - myvec[i]);
		}

		if(i + 1 == c){
			res++;
		}

		if(res > sol){
			return;
		}
	}

	sol = min(sol, res);
}

int main(){
    ios_base::sync_with_stdio(false);
  // freopen("barn1.in","r",stdin);
  // freopen("barn1.out","w",stdout);

   int m, s, c;
   cin >> m >> s >> c;
   ::c = c;
   memset(dp , 10000 , sizeof dp);

   myvec.resize(c);

   for(int i = 0 ; i < c ; i++) cin >> myvec[i];

   sort(all(myvec));

    rec(0 , m , 0);
    cout << sol << endl;
    return 0;
}
