#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>

using namespace std;

void generateCypherSheet();
char cypherSheet[26][26];
void printCypherSheet();
string toLower(string);
string encode(string, string);
string decode(string, string);
string enterKey();
string phraseToProcess();

/*
  TO RUN
  Compiled: clang++ -o shift shift.cpp
  Run: ./shift or ./shift.exe
*/

int main()
{
    char enOrDe = 'a';
    while (true)
    {
        cout << "Would you like to encode or decode a message? [e]/[d] : ";
        cin >> enOrDe;

        enOrDe = tolower(enOrDe);

        if (enOrDe == 'e' || enOrDe == 'd')
            break;
        else
            cout << "Not a valid response" << endl;
    }
    
    generateCypherSheet();

    if(enOrDe == 'e')
    {
        string key = enterKey();
        // cout << "Your key is: " << key << endl;
        string phrase = phraseToProcess();
        // cout << "Your phrase is: " << phrase << endl;
        phrase = toLower(phrase);
        cout << "Encoded: " << encode(key, phrase) << endl;
    }

    if(enOrDe == 'd')
    {
        string phrase = phraseToProcess();
        phrase = toLower(phrase);

        char yesNo = 'a';
        while (true)
        {
            cout << "Do you know the key? [y]/[n] : ";
            cin >> yesNo;

            yesNo = tolower(yesNo);

            if (yesNo == 'y' || yesNo == 'n')
                break;
            else
                cout << "Not a valid response" << endl;
        }

        if(yesNo == 'y')
        {
            string key = enterKey();
            cout << "Phrase entered: " << phrase << endl;
            cout << "Decoded: " << decode(key, phrase) << endl;
        }

        if(yesNo == 'n')
        {   
            cout << "I'm sorry, Dave, I can't do that" << endl;
        }
    }

    return 0;
}

string encode(string keyIndex, string phrase)
{
    string encodedPhrase = "";
    int index = 0;
    for (int i = 0; i < phrase.length(); i++)
    {
        if (phrase[i] < 'a' || phrase[i] > 'z')
        {
            encodedPhrase += phrase[i];
            continue;
        }

        // Encoding part
        int keyRow = keyIndex[index] - 'a';
        int currentI = phrase[i] - 'a';
        encodedPhrase += cypherSheet[keyRow][currentI];
        if(++index == keyIndex.length())
            index = 0;
    }

    return encodedPhrase;
}

string decode(string keyIndex, string phrase)
{
    string decodedPhrase = "";
    int index = 0;
    for(int i = 0; i < phrase.length(); i++)
    {
        if(phrase[i] < 'a' || phrase[i] > 'z')
        {
            decodedPhrase += phrase[i];
            continue;
        }

        // Decode
        int keyRow = keyIndex[index] - 'a';
        char character;
        
        for(int column = 0; column < 26; column++)
        {
            if(cypherSheet[keyRow][column] == phrase[i])
            {
                decodedPhrase += cypherSheet[0][column];
                break;
            }
        }
        if(++index == keyIndex.length())
            index = 0;
    }

    return decodedPhrase;
}

void generateCypherSheet()
{
    int size = 26;
    char alphabet[size];

    for (int i = 0; i < size; i++)
        alphabet[i] = (97 + i);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cypherSheet[i][j] = '0';
    }

    // Fill Right Half
    for (int column = 1; column < size; column++)
    {
        for (int row = size - 1; row > 0; row--)
        {
            cypherSheet[row][column + ((size - row) - 1)] = alphabet[column - 1];
        }
    }

    // Fill Left Half
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column <= row; column++)
        {
            cypherSheet[row - column][column] = alphabet[row];
        }
    }
}

void printCypherSheet()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
            cout << setw(2) << cypherSheet[i][j];
        cout << endl;
    }
}

string toLower(string message)
{
    string temp = "";
    char c;
    int i = 0;
    while (message[i])
    {
        c = message[i];
        temp += tolower(c);
        i++;
    }
    return temp;
}

string enterKey()
{
    string key = "";
    bool passed = true;
    while (true)
    {
        // getline(cin, key);
        cin.clear();
        cin.sync();
        cout << "Please enter a word without special symbols: ";
        getline(cin, key);

        key = toLower(key);

        for(int i = 0; i < key.length(); i++)
        {
            passed = true;
            if(key[i] < 'a' || key[i] > 'z')
            {
                cout << "Failed: " << key[i] << endl;
                passed = false;
                break;
            }
        }

        if (passed)
            break;
        else
            cout << "Not a valid key" << endl;
    }

    return key;
}

string phraseToProcess()
{
    string phrase = "";
    // getline(cin, phrase);
    cin.clear();
    cin.sync();
    cout << "Please enter a phrase: ";
    getline(cin, phrase);

    return phrase;
}