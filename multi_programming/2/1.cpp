#include <iostream>
#include <string>
#include <map>

std::string derivative(std::string polynomial) {
		std::map <int, int> deg_factor;
		std::string factor = "", degree = "";
		std::string s = polynomial;
		std::string term = "";
		for (auto i = s.begin(); i != s.end(); i++ ) {
				if (*i == '+' || *i == '-') {
						factor = "", degree = "";
						if (term != "") { 
								for (auto j = term.begin(); *j != 'x' && j != term.end(); j++) {
										if (*j != '*' && *j != ' ') {
												factor += *j;
										}	
								}
								for (auto j = term.rbegin(); *j != 'x' && j != term.rend(); j++) {
										if (*j != '^' && *j != ' ') {
												degree = *j + degree;	
										}
								}
								if (factor == "" || factor == "+") {
										factor = "1";
								}
								else if (factor == "-") {
										factor = "-1";
								}

								if (degree == "") {
										degree = "1";
								}
						
								if(deg_factor.find(std::stoi(degree) - 1) != deg_factor.end()) {
										deg_factor[std::stoi(degree) - 1] += (std::stoi(degree) * std::stoi(factor));
								}
								else {
										deg_factor.insert(std::make_pair(std::stoi(degree) - 1, (std::stoi(degree) * std::stoi(factor))));	
								}
								term = "";
						}
				}

				term += *i;
				std::cout << factor << ":" << degree << std::endl;
		}
		
		factor = "", degree = "";
		for (auto j = term.begin(); *j != 'x' && j != term.end(); j++) {
				if (*j != '*' && *j != ' ') {
						factor += *j;
				}	
		}
		for (auto j = term.rbegin(); *j != 'x' && j != term.rend(); j++) {
				if (*j != '^' && *j != ' ') {
						degree = *j + degree;	
				}
		}
		if (factor == "" || factor == "+") {
				factor = "1";
		}
		else if (factor == "-") {
				factor = "-1";
		}
		if (degree == "") {
				degree = "1";
		}
					
		std::cout << factor << ":" << degree << std::endl;
		if(deg_factor.find(std::stoi(degree) - 1) != deg_factor.end()) {
				deg_factor[std::stoi(degree) - 1] += (std::stoi(degree) * std::stoi(factor));
		}
		else {
				deg_factor.insert(std::make_pair(std::stoi(degree) - 1, (std::stoi(degree) * std::stoi(factor))));	
		}


		for (auto i = deg_factor.begin(); i != deg_factor.end(); i++) {
				std::cout << i -> first << ':' << i -> second << std::endl;
		}
		return "";
}

int main(int argc, char **argv) {
		std::string s = "x^10000 + x + 1";
		/*for (auto i = s.rbegin(); i != s.rend(); i++) {
				if (*i != '^')
						std::cout << *i << ' ';
		}*/
		std::cout << derivative(s) << std::endl;
		return 0;
}

