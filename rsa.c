//Simon Partridge sp14960
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long modpow(long b, long e, long m) {
    long result = 1;

    while (e > 0) {
        if ((e & 1) == 1) {
            /* multiply in this bit's contribution while using modulus to keep
             * result small */
            result = (result * b) % m;
        }
        b = (b * b) % m;
        e >>= 1;
    }

    return result;
}

int encode(int message, int n, int e)
{
	return modpow(message,e,n);
}

int decode(long encoded, int p, int q, int e)
{
	int n = p*q;
	int totient = (p-1)*(q-1);
	int d, i;
	for (i=0; ((e*i)% totient)!=1; i++){}
	d = i;

	return(modpow(encoded, d, n));
}

int main()
{
	//mesage to be encrypted 

	int p = 13; //should be automatically generated
	int q = 17;	// ^as above
	int n = p * q;
	int e = 5; //generate automatically
	int message;


	char c = getchar();
	//printf("%d\n",c );
	//printf("%c\n",c);

	//int message = c;

	//printf("%d\n",message );
	int encoded;

	while( c!='.')
	 {
	 	if (c != '\n'){
	 	message = c-'0';
	 	encoded = encode(message, n, e);
	 	printf("Encoded:%3d\n", encoded);
	 	
	 }
	 c = getchar();
	 }


	
	while(encoded != '.')
	 {
	 	scanf("%d",&encoded);
	 	int decoded = decode(encoded, p, q ,e);
		printf("Decoded:%i\n",decoded);
	 }

	//printf("Modpow: %li\n",modpow(109,29,111) );

	
	//printf("divided: %f\n", (float)n/e);
	
	


	
	

	//int decoded = decode(encoded, p, q ,e);
	//printf("Decoded:%d\n",decoded);

	
	return 0;
}