/*
	Name: Azad Zeynalov
	StudentID: 112217229
	Email: azeynalov1@myseneca.ca
	Date of Completion: 2024-03-10

	I confirm that I am the only author of this file
    and the content was created entirely by me.
*/

#include <iostream>
#include <string>
#include <sstream>
#include "Utilities.h"
using namespace std;

namespace seneca {

	char Utilities::m_delimiter{ '#' };

	void Utilities::setFieldWidth(size_t newFieldWidth) {
		m_widthField = newFieldWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	// THIS METHOD WILL BE MODIFIED IN LATER MILESTONES IN CASE IF THERE IS A NEED
	string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string token{};
		if (str[next_pos] == m_delimiter) {
			more = false;
			throw ("Delimiter found at next_pos: " + to_string(next_pos));
		}
		else {
			stringstream sso(str.substr(next_pos));
			if (getline(sso, token, m_delimiter)) {
				if (token.length() > m_widthField) m_widthField = token.length();
				next_pos += token.length() + 1;
				token.erase(0, token.find_first_not_of(" "));
				token.erase(token.find_last_not_of(" ") + 1);
				if (next_pos > str.length()) {
					more = false;
				}
			}
			else more = false;
		}
		return token;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

}