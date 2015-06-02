/*
LANG: C++
PROB: transform
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

vector<string>temp;
vector<string>orig;
int n;

bool rotate90(){
	vector<string>hold;
	hold = temp;

	for(int i = 0 ; i  < n ; i++){
		for(int j = 0 ; j < n ; j++){
			hold[i][j] = temp[n - j - 1][i];
		}
	}

	if(orig == hold){
		return true;
	}

	temp = hold;
	return false;
}

bool reflect(bool flag){
	vector<string>hold;
	hold = temp;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			hold[i][j] = temp[i][n - j - 1];
		}
	}

	if(flag){
		temp = hold;
		return false;
	}else if(hold == orig){
		return true;
	}

	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("transform.in","r",stdin);
  	freopen("transform.out","w",stdout);

    cin >> n;
    vector<string>myvec(n);
    vector<string>table(n);

    for(int i = 0 ; i < n ; i++){
    	cin >> myvec[i];
    }

    for(int i = 0 ; i < n ; i++){
    	cin >> table[i];
    }

    temp = myvec;
    orig = table;

    for(int i = 0 ; i < 3 ; i++){
    	if(rotate90()){
    		cout << i + 1 << endl;
    		return 0;
    	}
    }

    temp = myvec;

    if(reflect(0)){
    	cout << 4 << endl;
    	return 0;
    }

    reflect(1);
    for(int i = 0 ; i < 3 ; i++){
    	if(rotate90()){
    		cout << 5 << endl;
    		return 0;
    	}
    }


    if(myvec == orig){
    	cout << 6 << endl;
    	return 0;
    }

    cout << 7 << endl;
    return 0;
}
