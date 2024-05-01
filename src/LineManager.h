/*
	Name: Azad Zeynalov
	StudentID: 112217229
	Email: azeynalov1@myseneca.ca
	Date of Completion: 2024-04-06

	I confirm that I am the only author of this file
	and the content was created entirely by me.
*/
#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include <vector>
#include <string>
#include "Workstation.h"

namespace seneca {

	class LineManager {
		std::vector<Workstation*> m_activeLine{};
		size_t m_cntCustomerOrder{ 0 };
		Workstation* m_firstWorkstation{ nullptr };
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& station);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}


#endif // !SENECA_LINEMANAGER_H

