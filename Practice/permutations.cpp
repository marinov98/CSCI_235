#include <iostream>

void permutation(std::string s,int begin,int end)
{
    int j;
    if (begin == end)
        cout << s << "\t";
    else
    {
        for (j = begin; j < s.length(); j++)
        {
            std::swap(s[begin],s[j]);
            permutation(s, begin + 1, n);
            std::swap(s[begin],s[j]);
        }  
    }
}
 
int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    cout << endl << "The permutations of the given string : " << endl;
    permutation(s, 0, s.length() - 1);
    cout << endl;
}
