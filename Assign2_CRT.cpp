// 43244 Sakshee Phade BE 10, R 10
#include<bits/stdc++.h>
using namespace std;


int findMinX(int num[], int rem[], int k) {
	
	int x = 1; // Initialize result

	// As per the Chinese remainder theorem,
	// this loop will always break.
	while (true) {
		// Check if remainder of x % num[j] is
		// rem[j] or not (for all j from 0 to k-1)
		int j;
		for (j=0; j<k; j++ )
			if (x%num[j] != rem[j])
				break;

		// If all remainders matched, we found x
		if (j == k)
			return x;

		// Else try next number
		x++;
	}

	return x;
}

int main(void)
{
	int num[100];	
	int rem[100];
	int k;
	cout << "\n\tENTER NUMBER OF EQUATIONS : ";
	cin >> k;
	for(int i=0; i<k; i++) {
		cout << "\n\tENTER a, b, SUCH THAT x = a mod b : ";
		cin >> rem[i] >> num[i]; 
	}
	//int k = sizeof(num)/sizeof(num[0]);
	cout << "\n\tx Is " << findMinX(num, rem, k);
	return 0;
}

