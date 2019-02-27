#include<iostream>
#include<vector>
#include<string>


int main(){
	std::string input;
	std::getline(std::cin, input);
	input.push_back(' ');

	std::vector<std::string> elements;

	std::string temp;
	for(std::string::iterator it = input.begin(); it != input.end(); ++it) {
		if (not isspace(*it)) {
			temp.push_back(*it);
		} else {
			if (temp != "")
				elements.push_back(temp);
			temp = "";
		}
	}


	int result = 0;
	bool wait_for_number = true, error = false;
	for ( std::vector<std::string>::iterator it = elements.begin(); it != elements.end(); ++it ) {
		bool is_number = true;
		bool negative = false;
		for ( std::string::iterator cit = it->begin(); cit != it->end(); ++cit)
			if (not isdigit(*cit)){
				if( (cit == it->begin() && *cit != '-') || cit != it->begin() ){
					is_number = false;
				}else{
					negative = true;
				}
				
			}

		if (is_number) {
			if (wait_for_number) {
				result += std::atoi(it->c_str());
				wait_for_number = false;
			} else {
				std::cout << "ERROR" << std::endl;
				return -1;
			}
		} else {
			if (wait_for_number) {
				std::cout << "ERROR" << std::endl;
				return -1;
			} else {
				if ((*it) == "+"){
					wait_for_number = true;
				} else {
					std::cout << "ERROR" << std::endl;
					return -1;
				}
			}
		}
	}

	std::cout << result << std::endl;
}
