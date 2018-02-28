#include<bits/stdc++.h>

#include<string.h>

using namespace std;

bool icompare_pred(unsigned char a, unsigned char b)

{
	
    return std::tolower(a) == std::tolower(b);

}


bool icompare(string const& a, string const& b)

{
 	
	   if (a.length()==b.length()) 
		{
		  return std::equal(b.begin(), b.end(),a.begin(), icompare_pred);

	        }

	    else 
		{
	
        return false;
	
		}

}

int main()

{
	ifstream fin("Koderunners.txt");

	cout<<"Enter String:\n";

	string s;
	cin>>s;

	string ch;

	int c=0;

	while(fin>>ch)

	{	
		//fin.getline(ch,100);
	
		//fin>>ch;
		
		//if(strcmpi(s,ch))

		//if (boost::iequals(s,ch))

		if(icompare(s,ch))
	
		++c;
		
		cout<<ch;
	
	}
	
	cout<<'\n'<<c<<'\n';

	//fin.close();

	return 0;

}