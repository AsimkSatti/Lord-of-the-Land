#include <iostream>
#include <string>

using namespace std;

class Protector {
public:
	void set_name(string myname) { name = myname; }
	string  get_name() { return name; }
	void set_power(int num) { power = num; }
	friend int combine_strength(const Protector &caliber, const Protector& archie);
	friend int yourbeingemployeed(const Protector &caliber, const Protector& archie);
	 int get_power() { return power; }
	 virtual void war () {

		fight();
		name;
		cout << " Take that in the name of my lord, ";

	  
	//	loss();
		cout << endl;
	}
	virtual void fight()const = 0;
//	virtual void loss()const = 0;
private:
	//Nobels* nobptr;
	string name;
	int power;
};


//wizards is a protector
class wizards :public Protector {
public:
	void fight()const { cout << "Poof"; }
//	void loss()const{}
private:
};

//warriors is a protector
class warriors : public Protector {
public:
	void fight()const { cry(); };
	virtual void cry()const = 0;


private:

};

//archers is a warrior
class archers :public warriors {
public:
	void cry()const { cout << "TWANG"; }
private:
};

//swordsmen is a warrior
class swordsman : public warriors {
public:
	void cry()const { cout << "CLANG"; }
private:
};


//adds the combined strength for a lord of land nobel
int combine_strength(Protector&caliber, Protector&archie) {
	int temp;
	temp = caliber.get_power() + archie.get_power();
	//cout << temp<<endl;
	return temp;

}


//Nobels are...
class Nobels {
public:
	void set_name(string my_name) { name = my_name; }
	string get_name() { return name; }
	void set_strength(int num) { strength = num; }
	int get_strength() { return strength; }
	

	virtual void how_strong() { 
									cout << "I am " << name; 
									status();
									how_much_power();
									cout<<strength;
									cout << " pts of strength ";
									cout << endl;
							
	}
	string opponent;
	void battle(string whom) {
		opponent = whom;
		
	}

	friend void war(string opponent,const Nobels &noblemike, const Nobels& nobelsam);



		
	

	virtual void how_much_power()const = 0;
	virtual void status()const = 0;
	virtual void personal_str()const = 0;
private:
	archers archie;

	Protector*arc=&archie;
	Protector*swor;
	Protector*wiz;
	string name;
	int strength;

};
//declaring war
void war(string who,Nobels &noblemike, Nobels &nobelsam) {

	archers archie;
	wizards caliber;
	Protector*wiz = &caliber;

	Protector*arc = &archie;

	cout <<  " battle has begun " << endl;
	if(nobelsam.get_strength()>noblemike.get_strength()){
		nobelsam.get_name();
		
		cout << endl;
		arc->war();
		wiz->war();
		cout<<nobelsam.get_name();
			cout << " won"<<endl;
			cout << noblemike.get_name() << " has died " << endl<<endl;
			int newstr = nobelsam.get_strength() - noblemike.get_strength();
			//This accounts for loss of lige
			nobelsam.set_strength(newstr);
			
	}
}

//lord of land is a nobel
class LordOfLand :public Nobels {
public:
	
	void personal_str()const { cout << "[This is where I add the strengths of all my procters]"; };
	void status()const { cout << " I am a Lord of the Land Noble: "; }
	void how_much_power()const { cout << " My army has "; }
	void hire(string emp){}

private:
	
	string employed;
	
};

//strenght to fight nobels are nobel
class StrengthToFight :public Nobels {
public:
	void status()const { cout << " I am a Noble with the strength to fight: "; }
	void personal_str()const {}
	void how_much_power()const { cout << " I have "; }

private:
};

int main() {
	LordOfLand noblemike;
	Nobels*nobptr;
	Nobels* lolptr=&noblemike;
	noblemike.set_name("Mike");


	noblemike.how_strong();

	StrengthToFight nobelsam;
	Nobels* NSTF = &nobelsam;
	nobelsam.set_name("Sam");
	NSTF->set_strength(2000);
	nobelsam.how_strong();

	wizards caliber;
	caliber.set_name("Caliber");
	caliber.set_power(500);


	archers archie; 
	archie.set_name("Archie");
	archie.set_power(500);


	swordsman smith;
	smith.set_name("Smith");
	smith.set_power(250);


	int lolstr=combine_strength(caliber, archie);
	noblemike.set_strength(lolstr);
	noblemike.get_strength();
	noblemike.how_strong();

	noblemike.hire("Caliber");
	noblemike.hire("Archie");

	string oppnent;
	war("Sam",noblemike, nobelsam);

	////
	///
	///
	///
	
	StrengthToFight nobelkyle;
	Nobels* KSTF = &nobelkyle;
	nobelkyle.set_name("Kyle");
	KSTF->set_strength(2000);
	nobelkyle.how_strong();

	war("Kyle", nobelsam, nobelkyle);



	system("pause");
	return 0;
}