#include <iostream>
#include <string>

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
	

};









int main() {



	return 0;
}
