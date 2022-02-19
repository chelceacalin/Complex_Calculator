#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#define DIMENSIUNE 1000
using namespace std;

class StivaCaractere {
	int UP;
	char vec[DIMENSIUNE];

public:
	//constructor implicit
	StivaCaractere();
	//constructor cu toti parametrii
	StivaCaractere(int up, char vec[DIMENSIUNE]);

	//metode -SIMULARE STIVA
	bool eGol();
	bool push(char val);
	char pop();
	char toUP();

	//getteri
	int getUp();
	char* getvec();

	//setteri
	void setUp(int UP);
	void setVec(char* vec);

	//supraincare
	// ! pt a afisa daca UP e -1 sau 0
	bool operator!();
	StivaCaractere operator--();

	//<< , >> nu are sens pt stive
	friend ostream& operator<<(ostream& out, StivaCaractere& s);
};
class StivaNumere {
	int UP;
	double vec[DIMENSIUNE];

public:
	//constructor implicit
	StivaNumere();

	//constructor cu toti parametrii
	StivaNumere(int up, int vec[DIMENSIUNE]);

	//metode - SIMULARE STIVA
	bool push(double val);
	double pop();
	double toUP();
	bool eGol();

	//getteri
	int getUp();
	double* getvec();

	//setteri
	void setUp(int UP);
	void setvec(double* vec);

	//<< , >> nu are sens pt stive
	friend ostream& operator<<(ostream& out, StivaNumere& s);

	//supraincarcari
	StivaNumere operator+(int val);
	StivaNumere operator++();
};
bool isOkLogica(int cntvecParanteze, int cntvecNumere, int cntOperanzi, string ecuatie);
bool eSemn(char x);
bool eParanteza(char x);
int eValid(string ecuatie);
char eCifra(char c);
char eFloat(char c);
char conditie(char c);
int ImportantaSemn(char car);




class AfiseazaC {
public:
	virtual void AfisC() = 0;
};


class Calcul {
protected:
	double a, b;
	double* vec;
	vector<double>v;
public:
	//constructor implicit
	Calcul();
	//constructor cu  toti parametrii
	Calcul(double a, double b, double* vec, vector <double>v);
	//constructor cu  2 parametrii
	Calcul(double a, double b);

	//getteri
	double* getVec();
	double getA();
	double getB();
	int getV();
	vector<double> getv();

	//setteri
	void setVec(double* vec);
	void setA(double a);
	void setB(double b);
	void setV(vector<double>v);

	//supraincarcari
	explicit operator int();
	operator double();

	//constr de copiere
	Calcul(const Calcul& c);
	//operator =
	Calcul& operator=(const Calcul& c);

	// << >>
	friend ostream& operator<<(ostream& out, Calcul& c);
	friend istream& operator>>(istream& in, Calcul& c);

	//metode
	double evaluareSemn(char semn);
	double suma(double a, double b);


	//metode virtuale
	virtual void SetACuB(double a, double b);
	virtual void MicsoramB(double b);
	~Calcul();
};


class CalculCu3Operanzi :public Calcul, public AfiseazaC {
private:
	double c;
public:
	CalculCu3Operanzi();
	CalculCu3Operanzi(double a, double b, double c);
	CalculCu3Operanzi(const CalculCu3Operanzi& ca);
	CalculCu3Operanzi& operator=(const CalculCu3Operanzi& ca);
	friend ostream& operator<<(ostream& out, const CalculCu3Operanzi& ca);
	friend istream& operator>>(istream& in, const CalculCu3Operanzi& ca);

	double getC();
	void setC(double c);
	void AfisC() override;

	//metode virtuale;
	void SetACuB(double a, double b) override;
	virtual void MicsoramB(double b) override;
	~CalculCu3Operanzi();
};

class FisBin {
private:
	double RezultatBinar;

public:

	FisBin();
	FisBin(double RezultatBinar);

	FisBin(const FisBin& f);
	FisBin operator=(const FisBin& f);
	int getRezultatBinar() {
		return this->RezultatBinar;
	}

	friend ostream& operator<<(ostream& out, FisBin& o);
	friend ofstream& operator<<(ofstream& out, FisBin& o);

	friend istream& operator<<(istream& in, FisBin& o);
	friend ifstream& operator<<(ifstream& in, FisBin& o);

	void serializare(string numeFisier);
	void deserializare(string numeFisier);

	~FisBin();
};

class EvaluatorEcuatie {
	string ecuatia;
	char* conversie; //pt simplificarea calculului
	int lungime;
public:
	//constructor implicit
	EvaluatorEcuatie();

	//constructor cu toti parametrii;
	EvaluatorEcuatie(string ec, const char* conversie, int len);

	//constructor cu ecuatia
	EvaluatorEcuatie(string ec);

	//getteri
	string getEcuatia();
	char* getconversie();
	int getLungime();

	//setteri
	void setLungime(int lungime);
	void setConversie(const char* conversie);
	void setEcuatia(string ecuatia);

	//constructor de copiere
	EvaluatorEcuatie(const EvaluatorEcuatie& e);

	//operator =
	EvaluatorEcuatie& operator=(const EvaluatorEcuatie& e);

	//metode
	double calculare();
	void AranjeazaParanteze();

	//supraincarcare operator functie
	void operator() ();
	//supraincarcare >
	bool operator==(EvaluatorEcuatie& e);
	//supraincarcare[]
	string operator[](int pozitie);

	friend ostream& operator<<(ostream& out, const EvaluatorEcuatie& e);
	friend istream& operator>>(istream& in, EvaluatorEcuatie& e);
	//destructor
	~EvaluatorEcuatie();
};
class Rezultat {
private:
	const int NrRezultat;
	double rezultat;
public:
	static int contor;
	//constructor implicit
	Rezultat();

	//constructor cu toti parametrii
	Rezultat(double rezultat);

	//constructor de copiere
	Rezultat(const Rezultat& r);
	//operator =
	Rezultat& operator=(const Rezultat& r);

	static int getContor();
	static void setContor(int contor);
	const int getNrRezultat();
	double getRezultat();
	void setRezultat(double rezultat);


	static void AdaugUnuLaContor(int contor);
	//operator <<
	friend ostream& operator<<(ostream& out, Rezultat& r);
	friend istream& operator>>(istream& in, Rezultat& r);

	//supraincarcari
	bool operator >(Rezultat& r);
	double operator--();

	//metode 
	Rezultat Adaug1();
	Rezultat Scad1();

	//destructor
	~Rezultat();
};


int main(int argc, char* argv[]) {
	if (argc == 1) {
		int Continua;
		cout << endl;
		cout << "CODUL 1 ESTE PENTRU INTRODUCEREA ECUATIILOR DE LA TASTATURA" << endl;
		cout << "CODUL 2 ESTE PENTRU CITIREA ECUATIILOR DIN FISIER" << endl << endl;
		int CodOperatie;
		do {
			cout << "Introduceti codul operatiei: ";
			cin >> CodOperatie;
			if (CodOperatie == 1 || CodOperatie == 2) {
				switch (CodOperatie)
				{
				case 1: {
					cin.get();
					string ecuatie;
					do {
						cout << endl << "Introduceti ecuatia de evaluat( sau 'exit' pentru a iesi): ";
						getline(cin, ecuatie);
						if (eValid(ecuatie) || ecuatie == "exit") {
							EvaluatorEcuatie ec(ecuatie);
							ec.AranjeazaParanteze(), ec(); //supraincarcare operator ()
							Rezultat rez(ec.calculare());

							cout << "Rezultatul ecuatiei este: ";
							//pt a scapa de 0-uri din rezultat;
							string val = to_string(rez.getRezultat());
							val = val.substr(0, val.find_last_not_of('0') + 1);
							if (val.find('.') == val.size() - 1)
								val = val.substr(0, val.size() - 1);
							cout << val << " ";

							double aux = stod(val);
							FisBin a(aux);
							int Raspuns;
							cout << endl << endl;
							if (ecuatie != "exit")
							{
								cout << "Doriti sa salvati valoarea? ( in fisier binar ) " << endl;
								cout << "Pentru DA -> apasati 1" << endl;
								cout << "Pentru NU -> apasati 0" << endl;
								cin >> Raspuns;
								if (Raspuns == 1) {
									a.serializare("ValoareSalvataBinar.bin");
								}
							}
							else
								if (ecuatie == "exit")
								{
									cout << "Doriti sa vedeti valoarea ( ultima salvata ) pusa in fisierul binar?(1/0) ";
									int ans;
									cin >> ans;
									if (ans == 1) {
										FisBin afisare;
										afisare.deserializare("ValoareSalvataBinar.bin");
										cout << afisare;
									}
									else
									{
									}
								}
							cin.get();
						}
						else cout << endl << "Ecuatia are greseli de redactare" << endl;
					} while (ecuatie != "exit"); } break;

				case 2:
				{
					string ecTest;
					ifstream Fisier;
					ofstream FisierIesire("FisierTextRezultate.txt", ios::out);
					int option;
					int cnt = 0;
					cout << endl << endl;
					cout << " '1' Pentru a afisa in consola" << endl;
					cout << " '2' Pentru a afisa in fisier text ";

					cout << endl << "Introduceti optiunea: ";
					cin >> option;
					Fisier.open("Ecuatii.txt");

					while (getline(Fisier, ecTest))
					{
						cnt++;
						if (eValid(ecTest) || ecTest == "exit") {
							EvaluatorEcuatie ec5(ecTest);
							ec5.AranjeazaParanteze(), ec5(); //supraincarcare operator ()
							Rezultat rez2(ec5.calculare());

							if (option == 1) // afisare in consola
							{
								cout << "Rezultatul ecuatiei " << cnt << " este: ";
								//pt a scapa de 0-uri din rezultat;
								string val3 = to_string(rez2.getRezultat());
								val3 = val3.substr(0, val3.find_last_not_of('0') + 1);
								if (val3.find('.') == val3.size() - 1)
									val3 = val3.substr(0, val3.size() - 1);

								cout << val3;
								cout << endl;
							}
							else
								if (option == 2) {
									cout << endl << "Ecuatia " << cnt << " a fost scrisa in fisier";
									string val3 = to_string(rez2.getRezultat());
									val3 = val3.substr(0, val3.find_last_not_of('0') + 1);
									if (val3.find('.') == val3.size() - 1)
										val3 = val3.substr(0, val3.size() - 1);
									FisierIesire << "Rezultatul ecuatiei " << cnt << " este: " << val3 << endl;
								}
								else
								{
									cout << "-------------Optiune invalida-----------------";
								}
						}
						else
							cout << endl << "Ecuatia are greseli de redactare" << endl;
					}
					Fisier.close();
				} break;

				default: cout << "Optiune gresita"; break;
				}

			}
			else cout << "COD INVALID" << endl;;
			cout << endl << "Doriti sa efectuati si alte operatii (1/0)?: ";
			cin >> Continua;
		} while (Continua == 1);
	}
	else
		if (argc == 2)
		{
			string MyStr(argv[1]);
			cout << endl << "Ecuatia de evaluat este:  ";
			cout << MyStr;
			bool ok = true;
			for (int i = 0; i < MyStr.size() - 1; i++) {
				MyStr.erase(remove(MyStr.begin(), MyStr.end(), ' '), MyStr.end());
				if (MyStr[i] == '/' && MyStr[i + 1] == '0')
				{
					cout << "Nu puteti imparti la 0";
					ok = false;
				}
			}
			if (ok)
			{
				if (eValid(MyStr) || MyStr == "exit") {
					EvaluatorEcuatie ec(MyStr);
					ec.AranjeazaParanteze(), ec(); //supraincarcare operator ()
					Rezultat rez(ec.calculare());

					cout << endl << "Rezultatul ecuatiei este: ";
					//pt a scapa de 0-uri din rezultat;
					string val = to_string(rez.getRezultat());
					val = val.substr(0, val.find_last_not_of('0') + 1);
					if (val.find('.') == val.size() - 1)
						val = val.substr(0, val.size() - 1);
					cout << val;
				}
				else cout << endl << "Ecuatia are greseli de redactare" << endl;
			}
		}
		else
			if (argc > 2) {
				cout << endl << "Numar Invalid de Argumente / Apelare Gresita a programului ";
			}
}


//STIVACARACTERE
StivaCaractere::StivaCaractere() {
	UP = -1;
}
bool StivaCaractere::eGol() { //nu avem nimic in stiva
	if (UP < 0)
		return true;
	else
		return false;
}
char StivaCaractere::toUP() {
	if (UP < 0) {
		return 0;
	}
	else
	{
		return vec[UP];
	}
}
bool StivaCaractere::push(char val) {
	if ((DIMENSIUNE - 1) <= UP) {
		cout << "Valoare peste capacitatea stivei";
		return 0;
	}
	else
		if ((DIMENSIUNE - 1) >= UP)
		{
			UP++;
			vec[UP] = val;
			return true;
		}
}
char StivaCaractere::pop() {
	if (UP < 0) {
		return 0;
	}
	else {
		return vec[UP], UP--;
	}
}
int StivaCaractere::getUp() {
	return this->UP;
}
char* StivaCaractere::getvec() {
	return this->vec;
}
void StivaCaractere::setUp(int UP) {
	this->UP = UP;
}
void StivaCaractere::setVec(char* ceva) {
	strcpy(this->vec, ceva);
}
StivaCaractere::StivaCaractere(int up, char vec[DIMENSIUNE]) {
	this->UP = up;
	strcpy(this->vec, vec);
}
ostream& operator<<(ostream& out, StivaCaractere& s) {

	out << "S.UP: " << s.UP << endl;
	out << "Vec: ";
	for (int i = 0; i < DIMENSIUNE; i++)
		if (s.vec[i] == '+' || s.vec[i] == '-' || s.vec[i] == '/' || s.vec[i] == '*' || s.vec[i] == '^' || s.vec[i] == '#')
			out << s.vec[i] << " ";
	return out;
}
bool StivaCaractere::operator!() {
	if (this->UP == 0)
		return true;
	else
		return false;

}
StivaCaractere StivaCaractere:: operator--() {
	this->UP--;
	return *this;
}


//STIVANUMERE
StivaNumere::StivaNumere() {
	UP = -1;
}
bool StivaNumere::eGol() { //nu avem nimic in stiva
	if (UP < 0)
		return true;
	else
		return false;
}
double StivaNumere::toUP() {
	if (UP < 0) {
		return 0;
	}
	else
	{
		return vec[UP];
	}
}
bool StivaNumere::push(double val) {
	if ((DIMENSIUNE - 1) <= UP) {
		cout << "Valoare peste capacitatea stivei";
		return 0;
	}
	else
		if ((DIMENSIUNE - 1) >= UP)
		{
			UP++;
			vec[UP] = val;
			return true;
		}
}
double StivaNumere::pop() {
	if (UP < 0) {
		return 0;
	}
	else {
		return vec[UP], UP--;
	}
}
ostream& operator<<(ostream& out, StivaNumere& s) {

	out << "S.UP: " << s.UP << endl;
	out << "Vec: ";
	for (int i = 0; i < 10; i++)
		if (s.vec[i] != NULL)
			out << s.vec[i] << " ";
	return out;
}
StivaNumere::StivaNumere(int up, int vec[DIMENSIUNE]) {
	this->UP = up;
	for (int i = 0; i < DIMENSIUNE; i++)
		this->vec[i] = vec[i];
}
int StivaNumere::getUp() {
	return this->UP;
}
double* StivaNumere::getvec() {
	return this->vec;
}
void StivaNumere::setUp(int UP) {
	this->UP = UP;
}
void StivaNumere::setvec(double* vec) {
	for (int i = 0; i < DIMENSIUNE; i++) {
		if (vec[i])
			this->vec[i] = vec[i];
	}
}
StivaNumere StivaNumere::operator++() {
	this->UP++;
	return *this;
}
StivaNumere StivaNumere::operator+(int val) {
	//operator +
	StivaNumere copie = *this;
	this->UP += val;
	return copie;
}


//FUNCTII
bool isOkLogica(int cntvecParanteze, int cntvecNumere, int cntOperanzi, string ecuatie) {
	for (int i = 0; i < ecuatie.size() - 1; i++)
		if (ecuatie[i] == '/' and ecuatie[i + 1] == '0')
		{
			cout << "Nu puteti imparti la 0";
			return false;
		}
	if (cntvecParanteze % 2 == 0 && cntvecNumere > cntOperanzi)
		return true;
	else
		return false;
}
bool eSemn(char x)
{
	if (x == '*' || x == '/' || x == '-' || x == '+' || x == '^' || x == '#')
		return true;
	else
		return false;
}
bool eParanteza(char x) {
	if (x == '(' || x == '[' || x == '{' || x == ')' || x == ']' || x == '}')
		return true;
	else
		return false;
}
int eValid(string ecuatie) {
	string* vecNumere = new string[ecuatie.size()];
	string* operanzi = new string[ecuatie.size()];
	string* vecParanteze = new string[ecuatie.size()];
	int i = 0, j, cntvecNumere = 0, cntOperanzi = 0, cntvecParanteze = 0, ok = 0;;
	while (ecuatie[i] != '\0')
	{
		if (isdigit(ecuatie[i]))
		{
			do
			{
				vecNumere[cntvecNumere] += ecuatie[i];
				i++;
			} while (isdigit(ecuatie[i]));
			cntvecNumere++;
			i--;
		}
		else
			if (eSemn(ecuatie[i]))
			{
				operanzi[cntOperanzi] = ecuatie[i];
				cntOperanzi++;
			}
			else
				if (ecuatie[i] != ' ')
				{
					if (eParanteza(ecuatie[i]))
						vecParanteze[cntvecParanteze++] = ecuatie[i];
				}
		i++;
	}
	if (isOkLogica(cntvecParanteze, cntvecNumere, cntOperanzi, ecuatie)) {
		ok = 1;
	}
	else {
		ok = 0;
	}
	delete[] vecNumere;
	delete[] vecParanteze;
	delete[] operanzi;
	return ok;
}
char eCifra(char c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
char eFloat(char c) {
	if (c == '.')
		return 1;
	else return 0;
}
char conditie(char c) {
	if (eCifra(c) || eFloat(c))
		return 1;
	else return 0;
}
int ImportantaSemn(char car) {
	int ok = 0;

	if (car == '^' || car == '#')
		ok = 3;

	if (car == '/' || car == '*')
		ok = 2;

	if (car == '+' || car == '-')
		ok = 1;

	return ok;
}



//CALCUL
Calcul::Calcul() :a(0), b(0), vec(NULL) {}

Calcul::Calcul(double a, double b) : a(a), b(b) {}

Calcul::Calcul(double a, double b, double* vec, vector <double>v) : a(a), b(b) {
	this->vec = new double[2];
	vec[0] = a;
	vec[1] = b;
	v.push_back(a);
	v.push_back(b);
}

vector<double> Calcul::getv() {
	return this->v;
}

void  Calcul::setV(vector<double>v) {
	for (int i = 0; i < v.size(); i++)
		this->v[i] = v[i];
}
double* Calcul::getVec() {
	return this->vec;
}

void Calcul::setVec(double* vec) {
	if (this->vec != NULL)
		delete[]this->vec;

	this->vec = new double[2];
	for (int i = 0; i < 2; i++)
		this->vec[i] = vec[i];
}

void Calcul::setA(double a) {
	if (a != NULL) {
		this->a = a;
	}
}
void Calcul::setB(double b) {
	if (b != NULL) {
		this->b = b;
	}
}

double Calcul::getA() {
	return this->a;
}
double Calcul::getB() {
	return this->b;
}

Calcul::Calcul(const Calcul& c) {
	this->a = c.a;
	this->b = c.b;
	this->vec = new double[2];
	for (int i = 0; i < 2; i++)
		this->vec[i] = c.vec[i];
}
Calcul& Calcul:: operator=(const Calcul& c) {
	if (this != &c) {
		if (this->vec != NULL)
			delete[]this->vec;
		this->a = c.a;
		this->b = c.b;
		this->vec = new double[2];
		for (int i = 0; i < 2; i++)
			this->vec[i] = c.vec[i];
		return *this;
	}
}

double Calcul::suma(double a, double b) {
	return this->a + this->b;
}

double Calcul::evaluareSemn(char semn) {
	if (semn == '^')
		return pow(this->a, this->b);
	else
		if (semn == '#')
			return pow(this->a, 1 / this->b);
		else
			if (semn == '/')
				return this->a / this->b;
			else
				if (semn == '*')
					return this->a * this->b;
				else
					if (semn == '+')
						return this->a + this->b;
					else
						if (semn == '-')
							return this->a - this->b;
						else
							return -1;
}


void Calcul::SetACuB(double a, double b) {
	this->a += 2 * this->b;
}


void Calcul::MicsoramB(double b) {
	this->b = this->b - 1;
}
Calcul::operator int() {
	return this->a;
}
Calcul::operator double() {
	return this->a;
}

ostream& operator<<(ostream& out, Calcul& c) {
	cout << c.a << " " << c.b;
	return out;
}

istream& operator>>(istream& in, Calcul& c) {
	in >> c.a;
	in >> c.b;
	return in;
}

Calcul::~Calcul() {
	if (this->vec != NULL)
		delete[]this->vec;
}

// EVALUATOR ECUATIE
EvaluatorEcuatie::EvaluatorEcuatie() :ecuatia("Necunoscut"), conversie(NULL), lungime(0) {}
EvaluatorEcuatie::EvaluatorEcuatie(string ec, const char* conversie, int len) : ecuatia(ec), lungime(len) {
	this->conversie = new char[ecuatia.size() + 1];
	char* caractere = new char[ecuatia.size() + 1];
	strcpy(caractere, ecuatia.c_str());
	strcpy(this->conversie, caractere);
}
EvaluatorEcuatie::EvaluatorEcuatie(string ecuatia) : ecuatia(ecuatia) {
	this->conversie = new char[ecuatia.size() + 1];
	char* caractere = new char[ecuatia.size() + 1];
	strcpy(caractere, ecuatia.c_str());
	strcpy(this->conversie, caractere);
}
void EvaluatorEcuatie::operator() () {
	string newString = this->ecuatia;
	newString.erase(remove(newString.begin(), newString.end(), ' '), newString.end()), setEcuatia(newString);
}
string EvaluatorEcuatie::operator[](int pozitie) {

	if (pozitie >= 0 && pozitie < ecuatia.size())
	{
		int len = ecuatia.size();
		string* vecnou = new string[len];
		int k = 0;
		for (int i = 0; i < len; i++)
		{
			if (eCifra(ecuatia[i]))
			{
				vecnou[k++] = ecuatia[i];
			}
		}
		return vecnou[pozitie];
	}
}
bool EvaluatorEcuatie::operator==(EvaluatorEcuatie& e) {
	return this->ecuatia.size() > e.ecuatia.size();
}
string EvaluatorEcuatie::getEcuatia() {
	return this->ecuatia;
}
int EvaluatorEcuatie::getLungime() {
	return this->lungime;
}
char* EvaluatorEcuatie::getconversie() {
	return this->conversie;
}
void EvaluatorEcuatie::setEcuatia(string ecuatia) {
	if (this->conversie != NULL)
		delete[]this->conversie;

	this->ecuatia = ecuatia;
	this->lungime = ecuatia.size();

	this->conversie = new char[ecuatia.size() + 1];
	char* caractere = new char[ecuatia.size() + 1];
	strcpy(caractere, ecuatia.c_str());
	strcpy(conversie, caractere);
}
void EvaluatorEcuatie::setLungime(int lungime) {
	if (lungime) {
		this->lungime = lungime;
	}
}
void EvaluatorEcuatie::setConversie(const char* conversie) {
	if (this->conversie != NULL)
		delete[]this->conversie;

	this->conversie = new char[ecuatia.size() + 1];
	char* caractere = new char[ecuatia.size() + 1];
	strcpy(caractere, ecuatia.c_str());
	strcpy(this->conversie, caractere);
}
EvaluatorEcuatie::EvaluatorEcuatie(const EvaluatorEcuatie& e) :ecuatia(e.ecuatia), lungime(e.ecuatia.size()) {
	if (e.ecuatia.size()) {
		this->conversie = new char[ecuatia.size() + 1];
		char* caractere = new char[ecuatia.size() + 1];
		strcpy(caractere, ecuatia.c_str());
		strcpy(conversie, caractere);
	}
}
EvaluatorEcuatie& EvaluatorEcuatie::operator=(const EvaluatorEcuatie& e) {
	if (this != &e) {
		if (this->conversie != NULL)
			delete[]this->conversie;

		this->ecuatia = e.ecuatia;
		this->lungime = e.ecuatia.size();

		this->conversie = new char[e.ecuatia.size() + 1];
		char* caractere = new char[e.ecuatia.size() + 1];
		strcpy(caractere, e.ecuatia.c_str());
		strcpy(conversie, caractere);
		return *this;
	}
}
void EvaluatorEcuatie::AranjeazaParanteze() {
	int len = ecuatia.size();
	int i = 0;

	do
	{
		if (ecuatia[i] == '[')
			ecuatia[i] = '(';

		if (ecuatia[i] == ']')
			ecuatia[i] = ')';

		i++;
	} while (i < len);
}
ostream& operator<<(ostream& out, const EvaluatorEcuatie& e) {
	for (int i = 0; i < e.lungime; i++)
		cout << e.ecuatia[i];
	return out;
}
istream& operator>>(istream& in, EvaluatorEcuatie& e) {
	cout << "Ecuatia: ";
	getline(in, e.ecuatia);
	return in;
}
double EvaluatorEcuatie::calculare() {
	int cnt = 0, j, k;
	StivaNumere numere;

	int len = this->ecuatia.size();
	StivaCaractere caractere;

	while (cnt < len) {
		if (ecuatia[cnt] == '(') {
			char myStr = ecuatia[cnt];
			caractere.push(myStr);
		}
		else
			if (ecuatia[cnt] == ')')
			{
				while (!(caractere.toUP() == '(') && 0 == caractere.eGol())
				{
					char semn;
					double a, b;
					a = numere.toUP(), numere.pop();
					b = numere.toUP(), numere.pop();
					Calcul calcul(b, a);
					semn = caractere.toUP(), caractere.pop();
					double val = calcul.evaluareSemn(semn);
					numere.push(val);
				}
				if (caractere.eGol() == 0)
					caractere.pop();
			}
			else
				if (0 != eCifra(ecuatia[cnt]))
				{
					string newString;
					while (conditie(ecuatia[cnt]) && cnt < len)
						newString = newString + ecuatia[cnt], cnt++;
					numere.push(stod(newString)), cnt--;
				}
				else
				{
					while (ImportantaSemn(caractere.toUP()) >= ImportantaSemn(ecuatia[cnt]) && caractere.eGol() == 0)
					{
						char semn;
						double a, b;
						a = numere.toUP(), numere.pop();
						b = numere.toUP(), numere.pop();
						Calcul calcul(b, a);
						semn = caractere.toUP(), caractere.pop();
						double val = calcul.evaluareSemn(semn);
						numere.push(val);
					}
					caractere.push(ecuatia[cnt]);
				}
		cnt++;
	}



	while (0 == caractere.eGol()) {
		double a, b; char semn;
		a = numere.toUP(), numere.pop();
		b = numere.toUP(), numere.pop();
		Calcul calcul(b, a);
		semn = caractere.toUP(), caractere.pop();
		double val = calcul.evaluareSemn(semn);
		numere.push(val);
	}
	double valoare = numere.toUP();
	return valoare;
}
EvaluatorEcuatie::~EvaluatorEcuatie() {
	if (this->conversie != NULL)
		delete[]this->conversie;
}


// REZULTAT
Rezultat::Rezultat() : NrRezultat(contor++) { rezultat = 0; }
Rezultat::Rezultat(double rezultat) : NrRezultat(contor++) {
	this->rezultat = rezultat;
}
double Rezultat::getRezultat() {
	return this->rezultat;
}
void Rezultat::setRezultat(double rezultat) {
	this->rezultat = rezultat;
}
Rezultat::Rezultat(const Rezultat& r) : NrRezultat(r.contor++) {
	this->rezultat = r.rezultat;
}
Rezultat& Rezultat:: operator=(const Rezultat& r) {
	if (this != &r) {
		this->rezultat = r.rezultat;
		return *this;
	}
}
int Rezultat::getContor() {
	return Rezultat::contor;
}
void Rezultat::setContor(int contor) {
	Rezultat::contor = contor;
}
void Rezultat::AdaugUnuLaContor(int contor) {
	Rezultat::contor = contor + 1;
}
const int Rezultat::getNrRezultat() {
	return this->NrRezultat;
}
bool Rezultat::operator >(Rezultat& r) {
	return this->rezultat > r.rezultat;
}
double Rezultat::operator--() {
	//postdecrementare deci lucram cu copie
	this->rezultat--;
	return rezultat;
}
ostream& operator<<(ostream& out, Rezultat& r) {
	//cout << r.NrRezultat << " ";
	cout << r.rezultat;
	return out;
}
istream& operator>>(istream& in, Rezultat& r) {
	cin >> r.rezultat;
	return in;
}
Rezultat Rezultat::Adaug1() {
	this->rezultat++;
	return *this;
}
Rezultat Rezultat::Scad1() {
	this->rezultat--;
	return *this;
}
Rezultat::~Rezultat() {}
int Rezultat::contor = 1;



//CALCUL CU 3 OPERANZI
CalculCu3Operanzi::CalculCu3Operanzi() :Calcul() {
	this->c = 0;
}

CalculCu3Operanzi::CalculCu3Operanzi(double a, double b, double c) : Calcul(a, b) {
	this->c = c;
}

CalculCu3Operanzi::CalculCu3Operanzi(const CalculCu3Operanzi& ca) : Calcul(ca) {
	this->c = ca.c;
}

CalculCu3Operanzi& CalculCu3Operanzi::operator=(const CalculCu3Operanzi& ca) {
	Calcul::operator=(ca);
	this->c = ca.c;
	return *this;
}

ostream& operator<<(ostream& out, const CalculCu3Operanzi& ca) {
	out << (Calcul&)ca;
	return out;
}

istream& operator>>(istream& in, const CalculCu3Operanzi& ca) {
	in >> (Calcul&)ca;
	return in;
}
CalculCu3Operanzi::~CalculCu3Operanzi() {
}

double CalculCu3Operanzi::getC() {
	return this->c;
}
void CalculCu3Operanzi::setC(double c) {
	this->c = c;
}

void CalculCu3Operanzi::SetACuB(double a, double b) {
	this->a += 3 * this->b;
}

void CalculCu3Operanzi::MicsoramB(double b) {
	this->b = this->b - 2;
}


void CalculCu3Operanzi::AfisC() {
	cout << c;
}


//FISBIN

FisBin::FisBin() {
	this->RezultatBinar = 0;
}

FisBin::FisBin(double RezultatBinar) {
	this->RezultatBinar = RezultatBinar;
}

ostream& operator<<(ostream& out, FisBin& o) {
	out << o.RezultatBinar;
	return out;
}

ofstream& operator<<(ofstream& out, FisBin& o) {
	out << o.RezultatBinar;
	return out;
}

istream& operator<<(istream& in, FisBin& o) {
	in >> o.RezultatBinar;
	return in;
}

ifstream& operator<<(ifstream& in, FisBin& o) {
	in >> o.RezultatBinar;
	return in;
}

void FisBin::serializare(string numeFisier) {
	ofstream f(numeFisier, ios::out | ios::binary);

	if (f.is_open()) {
		f.write((char*)&RezultatBinar, sizeof(RezultatBinar));
		f.close();
	}
	else
	{
		cout << "Fisierul binar nu a putut sa fie creat";
	}
}

void FisBin::deserializare(string numeFisier) {
	ifstream f(numeFisier, ios::in | ios::binary);
	if (f.is_open()) {
		f.read((char*)&RezultatBinar, sizeof(RezultatBinar));
		f.close();
	}
	else
		cout << "Fisierul nu a putut fi deschis/Nu exista" << endl;
}

FisBin::FisBin(const FisBin& f) {
	this->RezultatBinar = f.RezultatBinar;
}

FisBin FisBin::operator=(const FisBin& f) {
	if (this != &f) {
		this->RezultatBinar = f.RezultatBinar;
		return *this;
	}
}

FisBin::~FisBin() {}