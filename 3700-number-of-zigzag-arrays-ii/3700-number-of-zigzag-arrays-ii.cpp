class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix multiply(const Matrix &A, const Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                ll val = A[i][k];
                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + val * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<ll> multiplyVec(const Matrix &A, const vector<ll> &v) {
        int n = A.size();
        vector<ll> res(n, 0);

        for (int i = 0; i < n; i++) {
            ll sum = 0;
            for (int j = 0; j < n; j++) {
                sum = (sum + A[i][j] * v[j]) % MOD;
            }
            res[i] = sum;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        
        Matrix T(sz, vector<ll>(sz, 0));

      
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < x; y++) {
                T[m + y][x] = 1;
            }
        }

        
        for (int x = 0; x < m; x++) {
            for (int y = x + 1; y < m; y++) {
                T[y][m + x] = 1;
            }
        }

       
        vector<ll> vec(sz, 0);

       
        for (int i = 0; i < m; i++)
            vec[i] = i;

      
        for (int i = 0; i < m; i++)
            vec[m + i] = m - 1 - i;

        int power = n - 2;

        while (power > 0) {
            if (power & 1)
                vec = multiplyVec(T, vec);

            T = multiply(T, T);
            power >>= 1;
        }

        ll ans = 0;
        for (ll x : vec)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};