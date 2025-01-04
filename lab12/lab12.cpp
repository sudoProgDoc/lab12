#include <iostream>
using namespace std;

int S[21], R[39], L[41], Q[21], n, ch = 0; //S - занята ли колонка, R - занята ли диагональ /, L - занята ли диагональ \ 

void board_ou(void)
{
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
            if (Q[j] == i) cout << "Q "; else cout << ". ";
        cout << endl;
    }
    cout << endl;
}

void queen(int j)
{
    for (int i = 1; i <= n; i++)
    {
        if (S[i] == 0 && R[j - i + 19] == 0 && L[j + i] == 0)
        {
            S[i] = 1;
            R[j - i + 19] = 1;
            L[j + i] = 1;
            Q[j] = i;

            if (j == n)
            {
                ch++;
                board_ou();
            }
            else queen(j + 1);

            S[i] = 0;
            R[j - i + 19] = 0;
            L[j + i] = 0;
        }
    }
}

int main() {
    cout << "Введите n: ";
    cin >> n;
    if (n < 1) { cout << "Величина должна быть больше 0 и не больше 20"; return 1; };
    queen(1);
    cout << "Количество возможных расстановок = " << ch << endl;
}