#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a, int N, int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if(i %M == (M-1)) cout << endl;
        else cout << " ";
    }
}

void randData(double *b,int N,int M){
	for(int i = 0; i < N*M; i++){
    	b[i] = (rand()%101);
		b[i] /= 100;
    }
}

void findRowSum(const double *c,double *d,int N,int M){
	for(int j = 0; j < N; j++){
		double l = 0;
    	for(int k = 0; k < M; k++){
			l += *((c+k)+(M*j));
		}
		d[j] = l ;
    }
}

void findColSum(const double *e,double *f,int N,int M){
	int i = 0, j = 0;
    f[j] = 0;
    for(int r = 0; r < M; r++){
        i = r;
        for(int k = 0; k < N; k++){
            f[j] += e[i];
            i += M;
        }
        j++;
        f[j] = 0;
    }
}