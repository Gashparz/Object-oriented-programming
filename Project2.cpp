#include <iostream>

using namespace std;

class masina
{
protected:
	int tip;  ///TIP: 1 oras 2 afara 
	float lungime;
public:
	static int cntMasini;
	static int nrMici, nrMini, nrC, nrMono;
	masina()
	{
		tip = 0;
		lungime = 0;
		cntMasini = 0;
	}
	masina(masina& x)
	{
		tip = x.tip;
	///	lungime = x.setLungime;
	}
	~masina() {}
	int getTip()
	{
		return tip;
	}
	void setTip(int x)
	{
		tip = x;
	}
	float getLungime()
	{
		return lungime;
	}
	void setLungime(float x)
	{
		lungime = x;
	}
	virtual void afisare()
	{
		cout << "\nAfisarea pentru masina standard";
	}
	friend istream& operator>>(istream& input, masina& M);
	masina& operator=(const masina&);
};
masina& masina::operator=(const masina& p)
{
	if (this == &p)
		return (*this);
	this->lungime = p.lungime;
	this->tip = p.tip;
	return (*this);
}
class mini : public masina
{
public:
	mini() :masina()
	{
		setTip(0);
		setLungime(0);
	}
	mini(mini& x)
	{
		tip = x.tip;
		lungime = x.lungime;
	}
	~mini() {}
	void afisare()
	{
		cout << "Masina de oras, cu litraj mic, are dimensiunea de:" <<lungime;
	}
	friend istream& operator>>(istream& input, mini& MINI)
	{
		float len;
		cout << "\nLungimea:";
		input >> len;
		if(len>3.85)
		{
			cout << "\nMai mica ca 3.85!";
			input >> len;
		}
		MINI.setLungime(len);
		MINI.setTip(1);
		MINI.cntMasini++;
		MINI.nrMini++;
		return input;
	}
	mini& operator=(const mini&);
};
mini& mini::operator=(const mini& p)
{
	if (this == &p)
		return (*this);
	this->lungime = p.lungime;
	this->tip = p.tip;
	return (*this);
}
class mica : public masina
{
public:
	mica():masina()
	{
		setTip(0);
		setLungime(0);
	}
	mica(mica& x)
	{
		tip = x.tip;
		lungime = x.lungime;
	}
	~mica(){}
	void afisare()
	{
			cout << "Masina de oras, cu spatiul interior mai mare decat al unui Mini si dimensiunea de:" <<lungime;
			cout << endl;
	}
	friend istream& operator>>(istream& input, mica& MICA)
	{
		float len;
		cout << "\nLungime=";
		input >> len;
		if (len > 4.1 || len < 3.85)
		{
			cout << "\nIntre 4.1 si 3.85!";
			input >> len;
		}
		MICA.setLungime(len);
		MICA.setTip(1);
		MICA.cntMasini++;
		MICA.nrMici++;
		return input;
	}
	mica& operator=(const mica&);
};
mica& mica::operator=(const mica& p)
{
	if (this == &p)
		return(*this);
	this->tip = p.tip;
	this->lungime = p.lungime;
	return (*this);
}
class compacta : public masina
{
protected:
	int model; /// TIP: 1 hatckback 2 Combi 3 sedan
public:
	compacta():masina()
	{
		setTip(0);
		setLungime(0);
		model = 0;
	}
	compacta(compacta& p)
	{
		model = p.model;
		lungime = p.lungime;
		tip = p.tip;
	}
	~compacta(){}
	void setModel(int y)
	{
		model = y;
	} 
	int getModel() { return model; }
	void afisare(compacta C[])
	{
		int aux,aux2;
			cout << "Model:";
			aux = model;
			if (aux == 1)
				cout << "hatckback";
			if (aux == 2)
				cout << "combi";
			if (aux == 3)
				cout << "sedan";
			cout << "cu dimensiunea de:" << lungime << "folosita de preferabil:";
			aux2 = tip;
			if (aux2 == 1)
				cout << "in oras.";
			if (aux2 == 2)
				cout << "la drum lung.";
			cout << endl;
	}
	friend istream& operator>>(istream& input, compacta& C)
	{
		float len;
		int tipp, modell;
		cout << "\nLungime=";
		input >> len;
		if (len > 4.5 || len < 4.2)
		{
			cout << "\nLungime intre 3.85 si 4.1!";
			input >> len;
		}
		else
			C.setLungime(len);
		cout << "\n1 pentru oras 2 pentru afara \nTipul=";
		input >> tipp;
		C.setTip(tipp);
		cout << "\n1 pentru hackback 2 combi 3 sedan\nModel=";
		input >> modell;
		C.setModel(modell);
		C.cntMasini++;
		C.nrC++;
	return input;
	}
	compacta& operator=(const compacta&);
};
compacta& compacta::operator=(const compacta& p)
{
	if (this == &p)
		return (*this);
	this->model = p.model;
	this->lungime = p.lungime;
	this->tip = p.tip;
	return (*this);
}
class monovolume : public masina
{
protected:
	int locuri; ///TIP: 1 5 locuri 2 7 locuri
	int vechime;
	int discount;
	int luna;
public:
	monovolume():masina()
	{
		setTip(0);
		setLungime(0);
		locuri = 0;
		vechime = 0;
		discount = 0;
		luna = 0;
	}
	monovolume(monovolume& x)
	{
		locuri = x.locuri;
		vechime = x.vechime;
		discount = x.discount;
		luna = x.luna;
	}
	~monovolume(){}
	// set get locuri
	void setLocuri(int y) { locuri = y; }
	int getLocuri() { return locuri; }
	// set get vechime
	void setVechime(int z) { vechime = z; }
	int getVechime() { return vechime; }
	//set get luna 
	void setLuna(int x)
	{
		luna = x;
	}
	int getLuna()
	{
		return luna;
	}
	void discnt(int luna)
	{/// 6 7 8
		if (vechime == 0)
			discount = 0;
		else {
			discount = vechime;
			if (luna == 6 || luna == 7 || luna == 8)
				discount = 10;
		}
		cout << "Primiti un discount de:" << discount;
	}
	void afisare()
	{
			cout << "\nModel van, cu " << locuri << "locuri.";
			if (vechime == 0)
				cout << "Masina este noua!";
			if (vechime > 0)
				cout << " Masina SH cu vechimea de:" << vechime;
	}
	friend istream& operator>>(istream& input, monovolume& MONO)
	{
		int tipp, loc, vech, lun;
		cout << "\nVechimea=";
		input >> vech;
		MONO.setVechime(vech);
		cout << "\n5 sau 7 locuri?";
		input >> loc;
		MONO.setLocuri(loc);
		cout << "\n1 pentru oras 2 pentru afara\nTipul=";
		input >> tipp;
		cout << "\nLuna:";
		input >> lun;
		MONO.setLuna(lun);
		MONO.setTip(tipp);
		MONO.cntMasini++;
		MONO.nrMono++;
		return input;
	}

	monovolume& operator=(const monovolume&);
};
monovolume& monovolume::operator=(const monovolume& p)
{
	if (this == &p)
		return (*this);
	this->discount = p.discount;
	this->locuri = p.locuri;
	this->vechime = p.vechime;
	this->lungime = p.lungime;
	this->tip = p.lungime;
	this->luna = p.luna;
	return (*this);
}
template <class T>
class Vanzare: public masina
{
public:
	int nrMasiniStoc;
	int nrMasiniVandute;
	int nrStocMono;
	masina** arrVanz = new masina * [cntMasini];
	masina** arrStoc = new masina * [cntMasini];
	masina** arrMono = new masina * [nrMono];
	Vanzare() :masina()
	{
		nrMasiniStoc = 0;
		nrMasiniVandute = 0;
		nrStocMono = 0;
	}
	~Vanzare() {}
	void Sell(T );
	void Stoc(T );
	void StocMONO(const T &x);
};
template<class T>
void Vanzare<T>::Sell(T x) {
	nrMasiniStoc--;
	arrVanz[nrMasiniVandute] = &x;
	nrMasiniVandute++;
	cout << "ceva1";
}
template<class T>
void Vanzare<T>::Stoc(T x)
{
	arrStoc[nrMasiniStoc] = &x;
	nrMasiniStoc++;
	cout << "ceva2";
}
template<>
void Vanzare<unsigned>::StocMONO(const unsigned &x)
{
}
int masina::cntMasini = 0;
int masina::nrC = 0;
int masina::nrMici = 0;
int masina::nrMini = 0;
int masina::nrMono = 0;
int main()
{
	Vanzare<masina> Vanzari;
	mini mini1;
	mica mica1;
	compacta comp1;
	monovolume mono1;
	cin >> mono1;
	cin >> mini1;
	Vanzari.Stoc(mono1);
	Vanzari.Stoc(mini1);
	Vanzari.Sell(mono1);
}
