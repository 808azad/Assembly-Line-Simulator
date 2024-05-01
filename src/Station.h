/*
	Name: Azad Zeynalov
	StudentID: 112217229
	Email: azeynalov1@myseneca.ca
	Date of Completion: 2024-03-10

	I confirm that I am the only author of this file
	and the content was created entirely by me.
*/
#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <string>

namespace seneca {
	
	class Station {
		unsigned int m_stationID{};
		std::string m_stationName{};
		std::string m_stationDescription{};
		size_t m_serialNumber{};
		unsigned int m_quantityOfStockItems{};

		static size_t m_widthField;
		static unsigned int id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif // !SENECA_STATION_H
