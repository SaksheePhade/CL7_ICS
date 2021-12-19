/*
 * ASSIGNMENT 1
 * SAKSHEE PHADE BE 10 43244
 */
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
 
using namespace std;
 
long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);

void ce();
long int cd(long int);
void encrypt();
void decrypt();

int prime(long int pr) {
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++) {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    cout << "\nENTER FIRST PRIME NUMBER\n";
    cin >> p;
    flag = prime(p); //validate if prime
    if (flag == 0) {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    
    cout << "\nENTER ANOTHER PRIME NUMBER\n";
    cin >> q;
    flag = prime(q);
    if (flag == 0 || p == q) {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    
    cout << "\nENTER MESSAGE\n"; //msg to be encrypted
    fflush(stdin);
    cin >> msg;
    for (i = 0; msg[i] != '\0'; i++) {
    	//cout << "msg  " << i << " " << msg[i];
        m[i] = msg[i]; //convert char to long int
        
	}
        
    n = p * q; //modulus for encryption and decryption
    t = (p - 1) * (q - 1); //euler's totient, gives how many integers are coprime to n
    cout << "\nEULER'S TOTIENT : " << t << endl;
    
	ce(); //calculate c and d using phi(t)
    
	cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
    for (i = 0; i < j - 1; i++)
        cout << e[i] << "\t" << d[i] << "\n";
    
	encrypt();
    decrypt();
    return 0;
}


void ce() //solving eulers's function (calculating d such that [ ed mod phi(n) = 1 ] )
{
    int k;
    k = 0;
    for (i = 2; i < t; i++) {
    	
        if (t % i == 0)
            continue;
        
		flag = prime(i);
        
		if (flag == 1 && i != p && i != q) { //if i is prime,
            e[k] = i; //record e
            
            flag = cd(e[k]); 
            
			if (flag > 0) {
                d[k] = flag;
                k++;
            }
            
            if (k == 99) 
                break;
        }
    }
}


long int cd(long int x) {
    long int k = 1;
    while (1) {
        k = k + t;
        if (k % x == 0)
            return (k / x); //returns d (calculates multiplicative inverse)
    }
}


void encrypt() {
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    cout << "\ne : " << key << endl;
    
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    while (i != len) {
    	
        pt = m[i]; // pt has ASCII value of Msg
        //pt = pt - 96; //
        k = 1;
        
        // Ciphertext = Msg^e mod n
        for (j = 0; j < key; j++) {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        
        ct = k;
        //ct = k + 96; 
        en[i] = ct; //store ciphertext of ASCII value of char in Msg
        i++;
    }
    en[i] = -1;
    //cout << endl;
    
    for (i = 0; en[i] != -1; i++)
        printf("%d", en[i]); //print ciphertext
}
void decrypt()
{
    long int pt, ct, key = d[0], k;
    i = 0;
    
    cout << "\nd : " << key << endl;
    
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++) // Plaintext(M) = Ciphertext^d mod n
        {
            k = k * ct;
            k = k % n;
        }
        //pt = k + 96;
		pt = k;
        //cout << "\nPT k : " << pt << endl;
        //printf("\n%c", pt);
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]); //print plaintext
}
