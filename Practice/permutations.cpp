#include <iostream>

void permutation(std::string s,int begin,int end)
{
    int j;
    if (begin == end)
        std::cout << s << "\t";
    else
    {
        for (j = begin; j < s.length(); j++)
        {
            std::swap(s[begin],s[j]);
            permutation(s, begin + 1, end);
            std::swap(s[begin],s[j]);
        }  
    }
}
 
int main()
{
    std::string s;
    std::cout << "Enter the string : ";
    std::cin >> s;
    std::cout << '\n';
    permutation(s, 0, s.length() - 1);
    std::cout << endl;
}
