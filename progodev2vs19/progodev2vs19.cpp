/****************************************************************************
**
**				ÖĞRENCİ ADI...........................: Süleyman Behlül UYSAL
**				ÖĞRENCİ NUMARASI.............:			g171210080
**				DERS GRUBU…………………:						2/C
****************************************************************************/

#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int matris[25][25];
int boyut = 0;	//matris boyutu
int secim = 0; //menu icin
int satirsecim, sutunsecim;	//satir sutun degistirme icin
bool flagformatrix = true; //yeni matris olusturma islemi icin ek ozelliktir.

void matrisolustur();
void menuyazdir();
void secimbir();
void secimiki();
void secimuc();
void secimdort();

int main()
{

	//srand(time(NULL)); 

	do
	{
		if (flagformatrix)
		{
			matrisolustur();
			menuyazdir();
			flagformatrix = false;
		}

		switch (secim)
		{
		case 1:
			secimbir();

			menuyazdir();
			break;
		case 2:
			secimiki();
			menuyazdir();
			break;
		case 3:
			secimuc();
			menuyazdir();
			break;
		case 4:
			secimdort();
			menuyazdir();
			break;
		case 5:
			system("cls");
			flagformatrix = true;
			secim = 1;
			break;
		case 6:
			break;


		default:
			break;
		}

	} while (secim != 6);


}





void matrisolustur() {
	int tempforui = 0;
	int maxdeger = 0;
	int matrisdeger = 0;
	if (flagformatrix)
		do
		{
			cout << "Matris Boyutu: ";
			cin >> boyut;
			if (cin.fail()) {
				cout << "Lutfen sayi giriniz. Harf degil." << endl;
				boyut = 0;
				cin.clear();
				cin.ignore(256, '\n');
			}
			else
				if (boyut < 5 || boyut > 25)
					cout << "matris boyutu 25'den kucuk 5'den buyuk olmalidir." << endl;
		} while (boyut < 5 || boyut>25);
		for (int i = 0; i < boyut; i++)
			for (int j = 0; j < boyut; j++)
			{
				if (flagformatrix)
					matris[i][j] = (rand() % 9) + 1;
				if (maxdeger < matris[i][j])
					maxdeger = matris[i][j];
			}
		maxdeger = maxdeger > 0 ? (int)log10((double)maxdeger) + 1 : 1; //basamak sayısını hesaplıyoruz
		for (int i = 0; i < boyut; i++)
		{
			if (i == 0)
			{
				cout << "    ";
				for (int k = 0; k < boyut; k++)
				{
					for (int bosluk = 0; bosluk < maxdeger; bosluk++)
						cout << " ";
					cout << k + 1;
				}
				cout << endl << "    ";

				if (boyut < 10) {
					for (int l = 0; l < boyut * (maxdeger + 1); l++)
					{
						cout << "_";
					}
				}
				else
				{
					tempforui = boyut - 9;
					for (int l = 0; l < (9 * (maxdeger + 1)) + (tempforui * (maxdeger + 2)); l++)
					{
						cout << "_";
					}
				}


				cout << endl;
			}
			for (int j = 0; j < boyut; j++)
			{
				matrisdeger = matris[i][j] > 0 ? (int)log10((double)matris[i][j]) + 1 : 1; //basamak sayısını hesaplıyoruz
				if (j < 9)
					if (j == 0)	//tablo için fix sabit bırak burayı
					{
						if (i < 9)
							cout << " " << i + 1 << " " << " |";
						else
							cout << " " << i + 1 << " " << "|";
						for (int boslukdeger = 0; boslukdeger < maxdeger - matrisdeger; boslukdeger++)
							cout << " ";
						cout << matris[i][j];
					}
					else if (j == boyut - 1)
					{
						for (int boslukdeger = 0; boslukdeger <= maxdeger - matrisdeger; boslukdeger++)
							cout << " ";
						cout << matris[i][j] << endl;
					}
					else
					{
						for (int boslukdeger = 0; boslukdeger <= maxdeger - matrisdeger; boslukdeger++)
							cout << " ";
						cout << matris[i][j];
					}
				if (j >= 9)
					if (j == boyut - 1)
					{
						for (int boslukdeger = 0; boslukdeger <= maxdeger - matrisdeger + 1; boslukdeger++)
							cout << " ";
						cout << matris[i][j] << endl;
					}
					else
					{
						for (int boslukdeger = 0; boslukdeger <= maxdeger - matrisdeger + 1; boslukdeger++)
							cout << " ";
						cout << matris[i][j];
					}

			}
		}
		cout << endl << endl;
}
void menuyazdir() {
	bool flag = true;
	cout << "-----Menu-----" << endl << "1-) Sutun Satir Degistir:" << endl << "2-) Tekleri basa al(satir)" << endl << "3-) Ters Cevir(Sutun)" << endl << "4-) Toplamlari yazdir" << endl << "5-)Yeni islem" << endl << "6-) Cikis";
	cout << endl << endl << "Seciminiz:  ";
	do {
		cin >> secim;
		if (cin.fail()) {
			cout << "Lutfen sayi giriniz. Harf degil." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else flag = false;
	} while (flag);

}
void secimbir()
{
	int flag = true;
	do {
		cout << "satir sutun: ";
		cin >> satirsecim >> sutunsecim;
		if (cin.fail()) {
			cout << "Lutfen sayi giriniz. Harf degil." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else flag = false;
	} while (flag);

	if ((satirsecim <= 0 || satirsecim > boyut) || (sutunsecim <= 0 || sutunsecim > boyut))
	{
		cout << "satir ve sutun matris boyutundan buyuk olamaz" << endl;
		cout << "Press any key to continue..." << endl;
		_getch(); //bekleme
		matrisolustur();
	}
	else
	{
		int toplam;
		int temp[25]; // satir sutun degisimi icin gecici dizi
		satirsecim--;
		sutunsecim--;
		toplam = matris[satirsecim][satirsecim] + matris[sutunsecim][sutunsecim];
		for (int j = 0; j < boyut; j++)	//matrisin satiri tempe aliniyor
		{
			temp[j] = matris[satirsecim][j];
		}
		for (int i = 0; i < boyut; i++) // sutun satir yerine yaziliyor
		{
			matris[satirsecim][i] = matris[i][sutunsecim];
			matris[i][sutunsecim] = temp[i];
		}
		matris[satirsecim][sutunsecim] = toplam;
		matrisolustur();
	}


}
void secimiki()
{
	int flag = true;
	do {
		cout << "satir numarasi...: ";
		cin >> satirsecim;
		if (cin.fail()) {
			cout << "Lutfen sayi giriniz. Harf degil." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else flag = false;
	} while (flag);

	if (satirsecim <= 0 || satirsecim > boyut)
	{
		cout << "satir matris boyutundan buyuk olamaz" << endl;
		matrisolustur();
	}
	else
	{
		int temptek[25]; //tek sayilar icin temp
		int tempcift[25] = {NULL};
		int teklenght = 0;
		int ciftlenght = 0;
		satirsecim--;
		cout << "Press any key to continue..." << endl;
		_getch(); //bekleme
		for (int i = 0; i < boyut; i++)
		{
			if (matris[satirsecim][i] % 2 != 0)
			{
				temptek[teklenght] = matris[satirsecim][i];
				teklenght++;
			}
		}
		for (int i = 0; i < boyut; i++)
		{
			if (matris[satirsecim][i] % 2 == 0)
			{
				tempcift[ciftlenght] = matris[satirsecim][i];
				ciftlenght++;
			}

		}
		for (int i = 0; i < teklenght; i++)
		{
			matris[satirsecim][i] = temptek[i];
		}
		for (int j = 0; j < boyut - teklenght; j++)
			matris[satirsecim][j + teklenght] = tempcift[j];
		matrisolustur();
	}
}

void secimuc()
{
	int flag = true;
	do {
		cout << "sutun numarasi...: ";
		cin >> sutunsecim;
		if (cin.fail()) {
			cout << "Lutfen sayi giriniz. Harf degil." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else flag = false;
	} while (flag);

	if (sutunsecim <= 0 || sutunsecim > boyut)
	{
		cout << "sutun matris boyutundan buyuk olamaz" << endl;
		matrisolustur();
	}
	else
	{
		int tempters;
		sutunsecim--;
		for (int i = 0; i < boyut / 2; i++)
		{
			tempters = matris[i][sutunsecim];
			matris[i][sutunsecim] = matris[boyut - i - 1][sutunsecim];
			matris[boyut - i - 1][sutunsecim] = tempters;
		}
		matrisolustur();
	}
}

void secimdort()
{
	int toplam = 0;
	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			toplam += matris[i][j];
		}
	}

	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			matris[i][j] = toplam - matris[i][j];
			toplam = matris[i][j];
		}
	}
	matrisolustur();

}

