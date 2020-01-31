#include<stdio.h>
int gong(long long a,long long b)
{
	long long r,min,max;
	min=(a>b)?b:a;
	max=(a>b)?a:b;
	r=max%min;
	while(r)
	{
		max=min;
		min=r;
		r=max%min;
	}
	return min;
}
void print(long long a,long long b)
{
	long long flag=0,c,d,e;
	if(a<0){
		a=-a;
		flag=1;
	}
	if(a==0) printf("0");
	else{
		e=gong(a,b);
		a/=e;
		b/=e;
		c=a/b;
		d=a%b;
		if(flag==0){
			if(d==0) printf("%lld",c);
			else{
				if(c==0) printf("%lld/%lld",a,b);
				else printf("%lld %lld/%lld",c,d,b);
			}
		}
		else{
			if(d==0) printf("(-%lld)",c);
			else{
				if(c==0) printf("(-%lld/%lld)",a,b);
				else printf("(-%lld %lld/%lld)",c,d,b);
			}
		}
	}
}
void add(long long a1,long long b1,long long a2,long long b2)
{
	print(a1,b1);
	printf(" + ");
	print(a2,b2);
	printf(" = ");
	print(a1*b2+a2*b1,b1*b2);
	printf("\n");
}
void minus(long long a1,long long b1,long long a2,long long b2)
{
	print(a1,b1);
	printf(" - ");
	print(a2,b2);
	printf(" = ");
	print(a1*b2-a2*b1,b1*b2);
	printf("\n");
}
void muilt(long long a1,long long b1,long long a2,long long b2)
{
	print(a1,b1);
	printf(" * ");
	print(a2,b2);
	printf(" = ");
	print(a1*a2,b1*b2);
	printf("\n");
}
void divide(long long a1,long long b1,long long a2,long long b2)
{
	print(a1,b1);
	printf(" / ");
	print(a2,b2);
	printf(" = ");
	if(a2==0) printf("Inf\n");
	else{
		if(a2<0){
			a2=-a2;
			a1=-a1;
		}
		print(a1*b2,b1*a2);
		printf("\n");
	}
}
int main()
{
	long long a1,b1,a2,b2;
	while(~scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2))
	{
		add(a1,b1,a2,b2);
		minus(a1,b1,a2,b2);
		muilt(a1,b1,a2,b2);
		divide(a1,b1,a2,b2);
	}
	return 0;
}


/*#include<stdio.h>
int gong(int a,int b)
{
	int r,min,max;
	min=(a>b)?b:a;
	max=(a>b)?a:b;
	r=max%min;
	while(r)
	{
		max=min;
		min=r;
		r=max%min;
	}
	return min;
}
void print(int a,int b)
{
	int flag=0,c,d,e;
	if(a<0){
		a=-a;
		flag=1;
	}
	if(a==0) printf("0");
	else{
		e=gong(a,b);
		a/=e;
		b/=e;
		c=a/b;
		d=a%b;
		if(flag==0){
			if(d==0) printf("%d",c);
			else{
				if(c==0) printf("%d/%d",a,b);
				else printf("%d %d/%d",c,d,b);
			}
		}
		else{
			if(d==0) printf("(-%d)",c);
			else{
				if(c==0) printf("(-%d/%d)",a,b);
				else printf("(-%d %d/%d)",c,d,b);
			}
		}
	}
}
void add(int a1,int b1,int a2,int b2)
{
	print(a1,b1);
	printf(" + ");
	print(a2,b2);
	printf(" = ");
	print(a1*b2+a2*b1,b1*b2);
	printf("\n");
}
void minus(int a1,int b1,int a2,int b2)
{
	print(a1,b1);
	printf(" - ");
	print(a2,b2);
	printf(" = ");
	print(a1*b2-a2*b1,b1*b2);
	printf("\n");
}
void muilt(int a1,int b1,int a2,int b2)
{
	print(a1,b1);
	printf(" * ");
	print(a2,b2);
	printf(" = ");
	print(a1*a2,b1*b2);
	printf("\n");
}
void divide(int a1,int b1,int a2,int b2)
{
	print(a1,b1);
	printf(" / ");
	print(a2,b2);
	printf(" = ");
	if(a2==0) printf("Inf\n");
	else{
		if(a2<0){
			a2=-a2;
			a1=-a1;
		}
		print(a1*b2,b1*a2);
		printf("\n");
	}
}
int main()
{
	int a1,b1,a2,b2;
	while(~scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2))
	{
		add(a1,b1,a2,b2);
		minus(a1,b1,a2,b2);
		muilt(a1,b1,a2,b2);
		divide(a1,b1,a2,b2);
	}
	return 0;
}
*/
