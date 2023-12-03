#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Matrix {
    ll n; 
    vector<vector<ll>> ele;
    Matrix(ll a, bool xd) {
        n = a;
        ele = vector<vector<ll>> (a);
        for(ll i=0; i<a; i++) {
            for(ll j=0; j<a; j++) {
                ele[i].push_back({});
                ele[i][j] = 0;
            }
        }
        
    }
    Matrix(ll a) {
        n = a;
       ele = vector<vector<ll>> (a);
        for(ll i=0; i<a; i++) {
            for(ll j=0; j<a; j++) {
                ele[i].push_back({});
            }
        }
        for(int i=0; i<a; i++) {
            ele[i][i] = 1;
        }
    }
    Matrix(ll a, vector<ll> elements) {
       n = a;
       ele = vector<vector<ll>> (a);
       ll k = 0;
       for(ll i=0; i<a; i++) {
           for(ll j=0; j<a; j++) {
                ele[i].push_back(elements[k]);
                k++;
           }
       }
    }
   
    Matrix operator*(Matrix another) {
        Matrix result(n, false);
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                for(ll k=0; k<n; k++) {
                    result.ele[i][j] += ele[i][k] * another.ele[k][j];
                }
            }
        } 
        return result;
    }

    Matrix operator^(int expo) {
        Matrix res(n);
        Matrix base = *this;
        while(expo > 0) {
            if(expo % 2 == 1) res = res*base;
            base = base * base;
            expo/=2;
        }
        return res;
    }

};

ostream& operator<<(ostream& os, const Matrix& matrix) {
        for(ll i=0; i<matrix.n; i++) {
            for(ll j=0; j<matrix.n; j++) {
                os<<matrix.ele[i][j]<<' ';
            }
            os<<'\n';
        }
        return os;
}

Matrix fastExpo(ll n, Matrix base, ll expo) {
    Matrix res(n);
    while(expo > 0) {
        if(expo % 2 == 1) {
            res = (res * base);
        }
        base = (base * base);
        expo/=2;
    }

    return res;
}

int main() {

    ll n; cin>>n;
    vector<ll> nums;
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            ll a; cin>>a;
            nums.push_back(a);
        }
    }
    Matrix macierz(n, nums);
    cout<<macierz*macierz;
}
