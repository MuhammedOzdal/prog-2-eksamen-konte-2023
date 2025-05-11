#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class kjoretoy {
private:
	std::string m_reg_nr, m_merke, m_modell, m_eier;

public:
	kjoretoy(std::string reg_nr, std::string merke, std::string modell, std::string eier) :
		m_reg_nr{ reg_nr }, m_merke{ merke }, m_modell{ modell }, m_eier{ eier } {};
	
	virtual void f() = 0;
};

class bil : public kjoretoy {
private:
	unsigned int m_antall_seter;

public:
	bil(std::string reg_nr, std::string merke, std::string modell, std::string eier, unsigned int antall_seter) :
		kjoretoy{ reg_nr, merke, modell, eier }, m_antall_seter{ antall_seter } {};
	
	virtual void f() {};
};

class motorsykkel : public kjoretoy {
private:
	bool m_sidevogn;

public:
	motorsykkel(std::string reg_nr, std::string merke, std::string modell, std::string eier, bool sidevogn) :
		kjoretoy{ reg_nr, merke, modell, eier }, m_sidevogn{ sidevogn } {};

	virtual void f() {};
};

class person {
private:
	std::string m_person_nr;
	std::string m_navn;
	std::vector<std::shared_ptr<kjoretoy>> m_kjoretoy;

public:
	person(std::string person_nr, std::string navn) :
		m_person_nr{ person_nr }, m_navn{ navn } {};

	void legg_til_kjoretoy(std::shared_ptr<kjoretoy> kjrt) {
		m_kjoretoy.push_back(kjrt);

	}
	std::string get_person_nr(){
		return m_person_nr;

	}
	friend person;
};

class unntak : public std::exception {}; // oppgave 7

class kjoretoy_register {
private:
	std::vector<std::shared_ptr<person>> m_eiere;

public:
	void legg_til_person(std::string person_nr, std::string navn) {
		std::shared_ptr<person> eier = std::make_shared<person>(person_nr, navn);
		m_eiere.push_back(eier);
	}

	void legg_til_bil(std::string person_nr, std::string merke, std::string modell, unsigned int antall_seter) {
		for (auto it = m_eiere.begin(); it != m_eiere.end(); it++) {
			if ((*it)->get_person_nr() == person_nr) {
				auto ny_bil = std::make_shared<bil>(person_nr, merke, modell, antall_seter);
				(*it)->legg_til_kjoretoy(ny_bil);
				return;
			}

		}

		throw unntak();
	}

	void legg_til_motorsykkel(std::string person_nr, std::string merke, std::string modell, bool sidevogn) {
		for (auto it = m_eiere.begin(); it != m_eiere.end(); it++) {
			if ((*it)->get_person_nr() == person_nr) {
				auto ny_motorsykkel = std::make_shared<motorsykkel>(person_nr, merke, modell, sidevogn);
				(*it)->legg_til_kjoretoy(ny_motorsykkel);
				return;
			}
		}
		throw unntak();
	}

	void beregn_avgifter(double avgift_pr_bil, double avgift_pr_motorsykkel) {
		//lager fil med øsnket navn
		std::ofstream file("avgifter.txt");
		for (auto it = m_eiere.begin(); it != m_eiere.end(); it++) {
			

		}


	}
};







int main() {



	return 0;
}
