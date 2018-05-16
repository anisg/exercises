#include <iostream>

using namespace std;

size_t treat(string s)
{
    size_t len = s.length();
    char *array = new char[len];
    size_t i;
    for (i=0; i<len; i++)
    {
        array[i] = (s[i] == 'a') || (s[i] == 'z') ? 1 : 0;
    }
    for (i=0; i<len; i++)
    {
        //cout << (array[i] ? '1' : '0');
    }
    //cout << endl;

    int sum = 0;
    for (i=0; i<len; i++)
    {
        // Potential len-i
        int pot = (int)(len-i);
        //cout << "Potential " << pot << endl;
        int j;
        for (j=i; j<len; j++)
        {
            if (array[j])
            {
                // Reached potential after (j-i) tries
                //cout << "Found at: " << (pot-(j-i)) << endl;
                sum += (pot - (j-i));
                break;
            }
        }
    }
    return sum;
}

int main()
{
    int n;

    cin >> n;

    string s;
    getline(cin, s);
    while (getline(cin, s))
    {
        //cout << s << endl;
        size_t ret = treat(s);
        cout << ret << endl;
        //break;////////////
    }
}
