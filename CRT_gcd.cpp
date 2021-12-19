// 43244 Sakshee Phade BE 10, R 10

#include<bits/stdc++.h>
using namespace std;

int calcM(int m[], int k) {
	int M = 1;
	for(int i=0; i<k; i++) {
		M = M * m[i];
	}
	return M;
}

/*int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x; //returns M^-1
}*/

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}

int CRT(int a[], int m[], int k) {
	int y = 0;
	int M = calcM(m, k);
	int Mi, Mi_inv;
	cout << "\n\tM : " << M;
	for(int i=0; i<k; i++) {	
		Mi = M/m[i];
		Mi_inv = modInverse(Mi, m[i]);
		cout << "\n\tMi : " << Mi;
		cout << "\n\tMi^-1 : " << Mi_inv;
		y = y + (a[i] * Mi * Mi_inv);
	}
	int X = y % M;
	return X;
}

int main() {
	int a[100];	
	int m[100];
	int k;
	cout << "\n\tENTER NUMBER OF EQUATIONS : ";
	cin >> k;
	for(int i=0; i<k; i++) {
		cout << "\n\tENTER a, m, SUCH THAT x = a mod m : ";
		cin >> a[i] >> m[i]; 
	}
	//int k = sizeof(num)/sizeof(num[0]);
	cout << "\n\t------------------------------------" << endl;
	cout << "\n\tX is " << CRT(a, m, k);
	return 0;
}
