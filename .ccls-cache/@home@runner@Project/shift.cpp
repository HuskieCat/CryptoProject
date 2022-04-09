#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>

using namespace std;

void generateCypherSheet();
char cypherSheet[26][26];
void printCypherSheet();
string toLower(string);
string encode(int, string);
string decode(int, string);
int findKeyIndex(char);

int main()
{
  char keyLetter = 'a';
  while(keyLetter == 'a')
  {
    cout << "Please enter a letter to be the key: ";
    cin >> keyLetter;

    keyLetter = tolower(keyLetter);
    
    if(keyLetter == 'a')
      cout << "a is not a valid key" << endl;
    else
      break;
  }

  cout << "You chose " << keyLetter << endl;

  generateCypherSheet();
  //printCypherSheet();

  string phrase = "";
  getline(cin, phrase);
  cout << "Please enter a phrase to be encoded: ";
  getline(cin, phrase);

  cout << "Your phrase is: " << phrase << endl;
  
  int keyIndex = findKeyIndex(keyLetter);

  phrase = toLower(phrase);

  cout << "Encoded: " << encode(keyIndex, phrase) << endl;
  
  return 0;
}

string encode(int keyIndex, string phrase)
{
  string encodedPhrase = "";
  for(int i = 0; i < phrase.length(); i++)
  {
    if(phrase[i] == ' ' || phrase[i] == '_' || phrase[i] == '-')
    {
      encodedPhrase += phrase[i];
      continue;
    }
    for(int j = 0; j < 26; j++)
    {
      if(cypherSheet[0][j] == phrase[i])
      {
        encodedPhrase += cypherSheet[j][keyIndex];
        break;
      }
    }
  }
  
  return encodedPhrase;
}

int findKeyIndex(char key)
{
  int keyIndex;
  for(int i = 0; i < 26; i++)
    if(cypherSheet[i][0] == key)
    {
      keyIndex = i;
      break;
    }
  return keyIndex;
}

void generateCypherSheet()
{
  int size = 26;
  char alphabet[size];
  
  for(int i = 0; i < size; i++)
    alphabet[i] = (97 + i);
  
  for(int i = 0; i < size; i++)
  {
      for(int j = 0; j < size; j++)
        cypherSheet[i][j] = '0';
  }

  //Fill Right Half
  for(int column = 1; column < size; column++)
  {
      for(int row = size - 1; row > 0; row--)
      {
        cypherSheet[row][column + ((size - row) - 1)] = alphabet[column-1];
      }
  }
  
  //Fill Left Half
  for(int row = 0; row < size; row++)
  {
    for(int column = 0; column <= row; column++)
    {
        cypherSheet[row-column][column] = alphabet[row];
    }
  }
}

void printCypherSheet()
{
  for(int i = 0; i < 26; i++)
  {
    for(int j = 0; j < 26; j++)
      cout << setw(2) << cypherSheet[i][j];
    cout << endl;
  }
}

string toLower(string message)
{
  string temp = "";
  char c;
  int i = 0;
  while(message[i])
  {
    c = message[i];
    temp += tolower(c);
    i++;
  }
  return temp;
}