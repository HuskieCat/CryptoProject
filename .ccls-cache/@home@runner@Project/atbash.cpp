#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

/*
Simple program that does atbash encoding and decoding
@Author: Bradley Henderson
*/

string atbash(string code);
char returnOpposite(char character);

int main() 
{
  cout << "Welcome to Atbash encoder/decoder. \nIf you would like to exit the program, enter !" << endl;
  string code = "";
  while(code != "!")
  {
    cout << endl;
    cout << "Please enter text to be encoded/decoded" << endl;
    cin >> code;

    if(code == "!")
      break;

    cout << "You entered: " << code << endl;
    string newCode = atbash(code);
    cout << "N-Coded code: " << newCode << endl;
  }
  return 0;
}

//Takes in a string, reading it character by character, gives back flipped string
string atbash(string code)
{
  string newCode = "";
  for(int i = 0; i < code.length(); i++)
    newCode += returnOpposite(tolower(code[i]));

  return newCode;
}

//Takes in a character and return its symmetric half (IE a = z)
char returnOpposite(char character)
{
  static char a2mArray[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m'};
  static char z2nArray[] = {'z','y','x','w','v','u','t','s','r','q','p','o','n'};
  static int arraySize = sizeof(a2mArray);
  int asciiValue = int(character);

  // a - m
  if(asciiValue >= int(a2mArray[0]) && asciiValue <= int(a2mArray[arraySize - 1]))
  {
    for(int i = 0; i < arraySize; i++)
      if(character == a2mArray[i])
        return z2nArray[i];
  }

  // n - z
  else if(asciiValue <= int(z2nArray[0]) && asciiValue >= int(z2nArray[arraySize - 1]))
  {
    for(int i = 0; i < arraySize; i++)
      if(character == z2nArray[i])
        return a2mArray[i];
  }
  return character;
}