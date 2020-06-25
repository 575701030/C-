#include<stdio.h>
#include<math.h>

#define error 5e-6

float f( float x )
{
	return 1/sqrt(x*x*x+1);
}

void R( float a,float b )
{
    long int k=0,i;
    float T[100],S[100],C[100],R[100];
    float sum=0,h;
    T[0]=(b-a)/2*( f(a)+f(b) );
    printf("k=%-2d区间数=%-3.0f T[%3.0f]=%-9f\n",k,pow(2,k),pow(2,k),T[0]);
    for( k=1; k<10 ;k++ )
    {
    	h=(b-a)/pow(2,k-1);
	    for( i=0; i<=pow(2,k-1)-1 ; i++ )
		{
			sum=sum+f( a+(i+0.5)*h );
		}
		if( k==1 )
    	{
    		T[k]=1.0/2*( T[k-1] + h*sum );
    		S[k]=T[k]+1.0/3*( T[k]-T[k-1] );
    		printf("k=%-2d区间数=%-3.0f T[%3.0f]=%-9fS[%3.0f]=%-9f\n",k,pow(2,k),pow(2,k),T[k],pow(2,k-1),S[k]);
    	}
    	else if( k==2 )
    	{
    		T[k]=1.0/2*( T[k-1] + h*sum );
    		S[k]=T[k]+1.0/3*( T[k]-T[k-1] );
    		C[k]=S[k]+1.0/15*( S[k]-S[k-1] );
    		printf("k=%-2d区间数=%-3.0f T[%3.0f]=%-9fS[%3.0f]=%-9fC[%3.0f]=%-9f\n",k,pow(2,k),pow(2,k),T[k],pow(2,k-1),S[k],pow(2,k-2),C[k]);
    	}
    	else
    	{
    		T[k]=1.0/2*( T[k-1] + h*sum );
    		S[k]=T[k]+1.0/3*( T[k]-T[k-1] );
    		C[k]=S[k]+1.0/15*( S[k]-S[k-1] );
    		R[k]=C[k]+1.0/63*( C[k]-C[k-1] );
    		printf("k=%-2d区间数=%-3.0f T[%3.0f]=%-9fS[%3.0f]=%-9fC[%3.0f]=%-9fR[%3.0f]=%-9f\n",k,pow(2,k),pow(2,k),T[k],pow(2,k-1),S[k],pow(2,k-2),C[k],pow(2,k-3),R[k]);
    	}
    	sum=0; 
    	if( k>3 && R[k]-R[k-1]<error ) 
		{
			printf("R=%f",R[k]);
			break;
		}
    }
}

int main()
{
	float a=0,b=1;	//a为积分下限   b为积分上限
	float s;
	R(a,b);
	return 0;
}
