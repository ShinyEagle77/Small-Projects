/*
 * Дана строка. Найдите в этой строке второе вхождение буквы f и выведите  индекс этого вхождения.
 * Если буква f в данной строке встречается только  один раз, выведите число -1, а если не встречается ни разу, выведите  число -2.
 * Индексы нумеруются с нуля.
 */

#include <iostream>
#include <string>

using namespace std;

int getIndex(std::string str)
{
    bool isSecond = false;
    for (int i = 0; i < str.size(); i++) 
    {
        if (str[i] == 'f') 
        {
            if (isSecond) 
            {
                return i;
            }
            isSecond = true;
        }
    }
    if (isSecond)
        return -1;
    else
        return -2;
}

int main()
{
    string str;
    cin >> str;
	
    cout << getIndex(str) << endl;

    return 0;
}