#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string phrase = "";
    getline(cin, phrase);

    char alphabet[26];
    int counter[26];

    for(int i = 0; i < 26; i++)
    {
        alphabet[i] = i + 'A';
        counter[i] = 0;
    }
    
    string temp = "";
    for(int i = 0; i < phrase.length(); i++)
    {
        if (phrase[i] < 'A' || phrase[i] > 'Z')
            continue;
        temp += phrase[i];
    }
    phrase = temp;

    for(int i = 3; i < phrase.length(); i += 4)
    {
        int index = phrase[i] - 'A';
        counter[index]++;
    }

    for(int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << ":" << counter[i] << " " << endl;
    }
    cout << endl;

    return 0;
}