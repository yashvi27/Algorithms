#include <iostream>
#include <cstring>

using namespace std;

bool isSubString(string s, string sb)
{
    int len, sublen, i=0, j=0, temp;
    len=s.length();
    sublen=sb.length();

	while(i<len && j<sublen)
    {
			temp=j;
			while(s[i] != ',' && i<len)
			{
				if (s[i] == sb[j])
				{
					i++;
					j++;
				}
				else if (s[i] != sb[j])
				{
					j = temp;
					i++;
				}
			}
			if (s[i] == ',' && sb[j] == ',')
			{

				i++;
				j++;
			}
			else
				i++;
	}

    if(j==sublen && j != 0) //length should not be zero
        return true;
    else
        return false;
}
int main()
{
    string str, sub;
    bool b;

    cout<<"Enter the events(separated by comma): ";
    getline(cin,str);
    cout<<"\nEnter the sub events(separated by comma): ";
    getline(cin,sub);

    b=isSubString(str, sub); //checks whether string entered is sub string is not
    if(b==true)
        cout<<"\nIt is a sub string.";
    else
        cout<<"\nNot a sub string.";

    return 0;
}


