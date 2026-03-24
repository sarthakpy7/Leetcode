using int4 = tuple<int, int, int, long long>;

const int N=12345;
constexpr int phiN=3288; // (3-1)*(5-1)*(823-1)
int inv[12345]={0};

int pow3[phiN+1], pow5[phiN+1], pow823[phiN+1];
bool flag=0;

class Solution {
public:
    static void preCompute() {
        if (flag) return;
        for (int x=1; x<N; x++) {
            if (x%3==0 || x%5==0 || x%823==0) continue;
            inv[x]=inv12345(x);
        }
        long long p3=1, p5=1, p823=1;
        for (int i=0; i<=phiN; i++) {
            pow3[i]=p3;
            pow5[i]=p5;
            pow823[i]=p823;
            p3*=3;
            if(p3>=N) p3%=N;
            p5*=5;
            if(p5>=N) p5%=N;
            p823*=823;
            if(p823>=N) p823%=N;
        }
        flag=1;
    //    cout<<"pow3[phiN]="<<pow3[phiN]<<", pow5[phiN]="<<pow5[phiN]<<", pow823[phiN]="<<pow823[phiN]<<endl;
    }

    static int4 factor(int x) {
        int e3=0, e5=0, e823=0, d=x;
        while (d%3==0) { d/=3; e3++; }
        while (d%5==0) { d/=5; e5++; }
        while (d%823==0) { d/=823; e823++; }
        return {e3, e5, e823, d%N};
    }

    static int inv12345(int a) {
        int b=N;// assume gcd(a, b)=1
        int x0=1, x1=0;
        while (b>0) {
            auto [q, r]=div(a, b);
            x0=exchange(x1, x0-q*x1);
            a=exchange(b, r);
        }
        return x0<0?x0+N:x0;
    }

    static int4 inverse(int4& xx) {
        auto [a, b, c, d]=xx;
        const long long x=inv[d];
        return {-a, -b, -c, x};
    }

    static long long mpow(long long x, int exp) {
        // use precomputed tables for 3, 5, and 823
        // Euler-Fermat+ Chinese Remainder=> a^k=a^((k-1)%phiN+1)(mod N) 
        // where phiN=Euler-Phi(N)
        if (exp==0) return 1;
        exp=(exp>phiN)?(exp-1)%phiN+1:exp;
        switch(x){
            case 3: return pow3[exp];
            case 5: return pow5[exp];
            case 823: return pow823[exp];
        }
        return 0;// never reach
    }

    static int mult(int4& x, int4& y) {
        int a=get<0>(x)+get<0>(y);
        if (a>phiN) a%=phiN;
        int b=get<1>(x)+get<1>(y);
        if (b>phiN) b%=phiN;
        int c=get<2>(x)+get<2>(y);
        if (c>phiN) c%=phiN;
        long long d=(get<3>(x)*get<3>(y))%N;
        long long ans=d;
        ans=ans*pow3[a]%N*pow5[b]%N*pow823[c]%N;
        return ans;
    }

    static vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) { 
        const int n=grid.size(), m=grid[0].size(), M=n*m;
        preCompute();
        
        int4 product={0, 0, 0, 1};
        vector<int4> inv_x(M);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                auto& [a, b, c, d]=product;
                auto xx=factor(grid[i][j]);
                a+=get<0>(xx);
                b+=get<1>(xx);
                c+=get<2>(xx);
                d=(d*get<3>(xx)%N);
                inv_x[i*m+j]=inverse(xx);
            }
        }

        vector<vector<int>> p(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                p[i][j]=mult(product, inv_x[i*m+j]);
            }
        }
        return p;
    }
};
static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();