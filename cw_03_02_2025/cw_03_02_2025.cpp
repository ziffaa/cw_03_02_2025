// определение символической константы _UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define _UNICODE

#include <iostream>
#include <tchar.h>// для макросов windows

//1.  пользователь вводит строку.проверить, является ли эта строка палиндромом.
//2.   подсчитать количество слов во введенном предложении.
//3.  пользователь вводит текст, строку для поиска и строку для замены.реализовать поиск в тексте заданной строки и замены ее на заданную подстроку.
//
//при выполнении использовать только макросы(<tchar.h>)

using namespace std;

bool isStringPalindrome(_TCHAR str[])
{
    int len = _tcslen(str);

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }

    return true; 
}

int wordCount(_TCHAR str[])
{
    int len = _tcslen(str);
    int count = 0;
    bool inWord = false;
    
    for (int i = 0; i < len; i++)
    {
        if ((str[i] == _T(' ') || str[i] == _T(',') || str[i] == _T('.') || str[i] == _T(';') || str[i] == _T('\0')))
        {
            if (inWord)
            {
                inWord = false;
            }
        }
        else if (!inWord)
        {
            inWord = true;
            count++;
        }
    }
    return count;
}

void replaceSubstring(_TCHAR str[], const _TCHAR sub[], const _TCHAR replace[])
{
    int strLen = _tcslen(str);
    int subLen = _tcslen(sub);
    int newLen = _tcslen(str);

    _TCHAR* p = str;
    _TCHAR* found = NULL;

    while ((found = _tcsstr(p, sub)))
    {
        newLen = newLen - subLen + _tcslen(replace);
        int offset = found - str;
        _TCHAR* newStr = new _TCHAR[newLen + 1];
        _tcsncpy(newStr, str, offset);
        newStr[offset] = _T('\0');
        _tcscat(newStr, replace);
        _tcscat(newStr, str + offset + subLen);
        p = str + offset + subLen;
        _tcscpy(str, newStr);
        
        delete[] newStr;
    }
}

void main()
{
	_TCHAR szBuf3[50] = _T("madam");

    if (isStringPalindrome(szBuf3))
    {
        wcout << _T("The string \"") << szBuf3 << _T("\" is a palindrome.") << endl;
    }
    else
    {
        wcout << _T("The string \"") << szBuf3 << _T("\" is not palindrome.") << endl;
    };

    _tcscpy(szBuf3, _T("hello, world!"));
    wcout << _T("The string \"") << szBuf3 << _T("\" contains ") << wordCount(szBuf3) << _T(" word(s).") << endl;

    replaceSubstring(szBuf3, _T("hello"), _T("goodbye"));

    wcout << szBuf3 << endl;
}
