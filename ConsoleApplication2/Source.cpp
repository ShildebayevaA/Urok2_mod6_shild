#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>
#include <cmath>

#define sz1  10
#define sz2  5

using namespace std;
int isPowerN(int * N, int A);
int isPrime(int N);
int Digit(int k, int n);
float DegToRad(int D);
int RadToDeg(float R);
float Fact(int N);

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "Urok_2__mod_6__HomeTask. Nomer zadania ot 1 do 6" << endl;
	cout << " Algoritm v funciax 1.isPowerN() i 2.isPrime() rabotaet ne strogo :((" << endl;
	cout << endl;

	srand(time(NULL));
	int number = 1;

	do
	{
		switch (number)
		{
		case 1: {
			cout << "1. Naiti kol-vo stepenei N v massive iz 10 chisel" << endl;
			cout << " ustanovlena razmernost 12 znakov, t.e. okolo pow(10, 10)" << endl;
			cout << endl;
			int N = 0, A = 0, cnt = 0;
			int m1[sz1] = { 0 };
			cout << " VVod chisla N: ";
			cin >> N;
			cout << "massiv 10 chisel:" << endl;
			for (int i = 0; i<sz1; i++)
			{
				m1[i] = pow(N, i) + rand() % 3;
				cout << " " << setw(12) << m1[i] << endl;
			}
			cout << endl;
			for (int i = 0; i<sz1; i++)
			{
				A = m1[i];
				if (isPowerN(&N, A) == 1)
					cnt++;
			}
			cout << "kol-vo stepenei N v massive = " << cnt << endl;
			break;
		}
		case 2: {
			cout << "2. Kolichestvo prostix chisel iz massiva 10 chisel:" << endl;
			int N, cnt = 0;
			int m2[sz1] = { 0 };
			cout << " massiv dlia poiska prostix chisel: " << endl;
			for (int i = 0; i<sz1; i++)
			{
				m2[i] = 2 + rand() % 999;
				if (m2[i] % 5 == 0) m2[i] += 3;
				cout << " " << setw(3) << m2[i];
				if ((i + 1) % 5 == 0) cout << endl;
			}
			cout << " prostie chisla iz massiva: " << endl;
			for (int i = 0; i<sz1; i++)
			{
				N = m2[i];
				if (isPrime(N) == 1)
					cnt++;
			}
			cout << "Kolichestvo prostix chisel iz massiva 10 chisel: " << cnt << endl;
			cout << endl;
			break;
		}
		case 3: {
			cout << "3. Vivod i-toi cifri (ot 1 do 5) iz 5 chisel int m3[i]>0 " << endl;
			int i, l, k = 5, N, C;
			int A = 0, B = 0;
			int m3[sz2] = { 0 };
			for (i = 0; i<k; i++)
			{
				A = rand() % 5;
				B = rand() % 26800;
				m3[i] = B + pow(10, A);
				cout << " " << setw(6) << m3[i];
			}
			cout << endl;
			for (l = 0; l<k; l++)
			{
				N = m3[l];
				C = Digit(l, N);
				if (C != -1)
					cout << " " << l + 1 << "-ia sprava nalevo cifra iz chisla " << N << " = " << C << endl;
				else
					cout << " v chisle " << N << "  cifr < 5" << endl;
			}
			cout << endl;
			break;
		}
		case 4: {
			cout << "4. Perevod iz gradusov v radian " << endl;
			int i;
			int D;
			int m4[sz2] = { 0 };
			for (i = 0; i<sz2; i++)
			{
				m4[i] = 45 + rand() % 136;
				cout << " " << m4[i];
			}
			cout << endl;
			for (i = 0; i<sz2; i++)
			{
				D = m4[i];
				cout << " " << D << " grad v radian = " << setprecision(3) << DegToRad(D) << endl;
			}
			cout << endl;
			break;
		}
		case 5: {
			cout << "5. Perevod iz radian v gradus " << endl;
			int i;
			float R;
			float m5[sz2] = { 0 };
			for (i = 0; i<sz2; i++)
			{
				m5[i] = 0.1826 + rand() % 4;
				cout << " " << setprecision(3) << m5[i];
			}
			cout << endl;
			for (i = 0; i<sz2; i++)
			{
				R = m5[i];
				cout << " " << setprecision(3) << R << " radian v grad = " << RadToDeg(R) << endl;
			}
			cout << endl;
			break;
		}
		case 6: {
			cout << "6. Factorial N  " << endl;
			int i = 0, N = 0;
			int m6[sz2] = { 0 };
			for (i = 0; i<sz2; i++)
			{
				m6[i] = 3 + rand() % 7;
				cout << " " << m6[i];
			}
			cout << endl;
			for (i = 0; i<sz2; i++)
			{
				N = m6[i];
				cout << " " << Fact(N) << " - factorial chisla " << N << endl;
			}
			break;
		}

		default: break;
		}
		cout << endl;
		cout << "Proverka zadanii ot 1 do 6, vixod - 0. Vvod nomera: " << endl;
		cin >> number;
	} while (number>0);
	cout << "End of Zadania 1-6 " << endl;
	system("pause");
	return(0);
}
// -----------------------------------------------------------------------------------
int isPowerN(int * N, int A)
{
	float K = 0, ost = 0;
	K = log(A) / log(N);
	ost = K - (int)K;
	if (ost == 0)
	{
		cout << "N= " << N << " stepen= " << K << " A=  " << setw(10) << A << endl;
		return 1;
	}
	else return 0;
}
//------------------------------------------------------------------------------------
int isPrime(int N)
{
	for (int i = 2; i <= sqrt((float)N); ++i)
	{
		if (N%i == 0) return 0;
		else
		{
			cout << "\t" << setw(3) << N << endl;
			return 1;
		}
	}
}
//------------------------------------------------------------------------------------
int Digit(int k, int n)
{
	int cnt = 1, poz = 0;
	int m_poz[5] = { 0 };
	for (int i = 0; i<5; i++)
	{
		m_poz[i] = n % 10;
		n /= 10;
		if (n != 0) cnt++;
	}
	if (cnt<5) return -1;
	poz = m_poz[k];
	return poz;
}
//------------------------------------------------------------------------------------
float DegToRad(int D)
{
	float pi = 3.14;
	float rad = 0;
	rad = pi*D / 180;
	return rad;
}
//------------------------------------------------------------------------------------
int RadToDeg(float R)
{
	int degr = 0;
	float pi = 3.14;
	degr = R * 180 / pi;
	return degr;
}
//------------------------------------------------------------------------------------
float Fact(int N)
{
	int i = 0;
	float Fctl = 1;
	for (i = 1; i <= N; i++)
		Fctl *= i;
	return Fctl;
}