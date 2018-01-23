
#include<iostream.h>

void main()
{
      long long a,b,c;

      while (cin>>a>>b) {
            if (b>a)
	            c=b-a;
            else
                    c=a-b;
            cout << c << endl;
      }
}

