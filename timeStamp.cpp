#include <iostream>
#include <cstring>

using namespace std;

bool isSubString(string s, string sb)
{
    int len, sublen, i, j=0;
    len=s.length();
    sublen=sb.length();

    for(i=0; i<len; i++)
    {
        if(sb[j]==s[i])  //character by character comparison
            j++;
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

    cout<<"Enter the string: ";
    getline(cin,str);
    cout<<"\nEnter the sub string: ";
    getline(cin,sub);

    b=isSubString(str, sub); //checks whether string entered is sub string is not
    if(b==true)
        cout<<"\nIt is a sub string.";
    else
        cout<<"\nNot a sub string.";
}
