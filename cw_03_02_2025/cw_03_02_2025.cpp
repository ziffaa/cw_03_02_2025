// ����������� ������������� ��������� _UNICODE
#define _CRT_SECURE_NO_WARNINGS
#define _UNICODE

#include <iostream>
#include <tchar.h>// ��� �������� windows

//1.  ������������ ������ ������.���������, �������� �� ��� ������ �����������.
//2.   ���������� ���������� ���� �� ��������� �����������.
//3.  ������������ ������ �����, ������ ��� ������ � ������ ��� ������.����������� ����� � ������ �������� ������ � ������ �� �� �������� ���������.
//
//��� ���������� ������������ ������ �������(<tchar.h>)

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
    
    for (int i = 0; i < len; i++)
    {
        if (str[i] == _T(' ') || str[i] == _T(',') || str[i] == _T('.') || str[i] == _T(';') || str[i] == _T('-'))
        {
            count++;
        }
    }
    return count;
}

void replaceSubstring(_TCHAR str[], const _TCHAR sub[], const _TCHAR replace[])
{
    int strLen = _tcslen(str);
    int subLen = _tcslen(sub);
    int newLen = _tcslen(str) - _tcslen(sub) + _tcslen(replace) + 1;

    _TCHAR* p = str;
    _TCHAR* found = NULL;

    while ((found = _tcsstr(p, sub)))
    {
        _TCHAR* newStr = new _TCHAR[newLen];
        int offset = strLen - _tcslen(found);
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

    replaceSubstring(szBuf3, _T("o"), _T("ba"));

    wcout << szBuf3 << endl;
}
