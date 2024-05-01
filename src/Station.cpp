#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
using namespace std;

namespace seneca {

	size_t Station::m_widthField = 0;
	unsigned int Station::id_generator = 0;

	Station::Station(const string& str) {
		Utilities ut;
		bool more = true;
		size_t position = 0;
		m_stationName = ut.extractToken(str, position, more);
		m_serialNumber = stoi(ut.extractToken(str, position, more));
		m_quantityOfStockItems = stoi(ut.extractToken(str, position, more));
		Station::m_widthField = max(Station::m_widthField, ut.getFieldWidth());
		m_stationDescription = ut.extractToken(str, position, more);
		m_stationID = ++Station::id_generator;
	}

	const string& Station::getItemName() const {
		return m_stationName;
	}
	
	size_t Station::getNextSerialNumber() {
		return m_serialNumber++;
	}
	
	size_t Station::getQuantity() const {
		return m_quantityOfStockItems;
	}

	void Station::updateQuantity() {
		if (m_quantityOfStockItems > 0) {
			--m_quantityOfStockItems;
		}
	}

	void Station::display(ostream& os, bool full) const {
		if (full) {
			os << setw(3) << setfill('0') << right << m_stationID << " | ";
			os << setw(Station::m_widthField) << setfill(' ') << left << m_stationName << "| ";
			os << setw(6) << setfill('0') << right << m_serialNumber << " | ";
			os << setw(4) << right << setfill(' ') << m_quantityOfStockItems << " | ";
			os << m_stationDescription << endl;
		}
		else {
			os << setw(3) << setfill('0') << right << m_stationID << " | ";
			os << setw(Station::m_widthField) << setfill(' ') << left << m_stationName << "| ";
			os << setw(6) << setfill('0') << right << m_serialNumber << " | " << endl;
		}
	}

}