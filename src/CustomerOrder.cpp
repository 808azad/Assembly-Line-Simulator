#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <utility>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"
using namespace std;

namespace seneca {

	size_t CustomerOrder::m_widthField{ 0 };

	CustomerOrder::CustomerOrder() {
		m_name = " ";
		m_product = " ";
		m_cntItem = 0;
		m_lstItems = nullptr;
	}

	CustomerOrder::CustomerOrder(const string& str) {
		Utilities ut;
		bool more = true;
		size_t position = 0;
		m_name = ut.extractToken(str, position, more);
		m_product = ut.extractToken(str, position, more);
		
		size_t tempPosition = position;
		bool tempMore = more;
		while (tempMore) {
			ut.extractToken(str, tempPosition, tempMore);
			++m_cntItem;
		}

		if (m_cntItem >= 1) {
			m_lstItems = new Item * [m_cntItem];
			for (size_t i = 0; i < m_cntItem; ++i) {
				string item = ut.extractToken(str, position, more);
				m_lstItems[i] = new Item(item);
			}
		}
		CustomerOrder::m_widthField = max(CustomerOrder::m_widthField, ut.getFieldWidth());
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& order) {
		throw "No copies are allowed for this class!";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
		*this = move(order);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
		if (this != &order) {
			if (m_lstItems) {
				for (size_t i = 0; i < m_cntItem; ++i) {
					delete m_lstItems[i];
				}
				delete[] m_lstItems;
				m_lstItems = nullptr;
			}
			m_name = move(order.m_name);
			m_product = move(order.m_product);
			m_cntItem = order.m_cntItem;
			if (m_cntItem >= 1) {
				m_lstItems = order.m_lstItems;
				order.m_lstItems = nullptr;
			}
			order.m_name = " ";
			order.m_product = " ";
			order.m_cntItem = 0;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; ++i) {
			delete m_lstItems[i];
		}
		delete[] m_lstItems;
	}

	bool CustomerOrder::isOrderFilled() const {
		bool status = true;
		for (size_t i = 0; i < m_cntItem && status; ++i) {
			if (!m_lstItems[i]->m_isFilled) {
				status = false;
			}
		}
		return status;
	}

	// this method is modified
	bool CustomerOrder::isItemFilled(const string& itemName) const {
		bool status = true;
		for (size_t i = 0; i < m_cntItem && status ; ++i) {
			if (m_lstItems[i]->m_itemName == itemName) {
				if (!m_lstItems[i]->m_isFilled) {
					status = false;
				}
			}
		}
		return status;
	}

	//this method is modified
	void CustomerOrder::fillItem(Station& station, ostream& os) {
		bool done = false;
		for (size_t i = 0; i < m_cntItem && !done; ++i) {
			if (m_lstItems[i]->m_itemName == station.getItemName() && !m_lstItems[i]->m_isFilled) {
				if (station.getQuantity() >= 1) {
					station.updateQuantity();
					m_lstItems[i]->m_isFilled = true;
					m_lstItems[i]->m_serialNumber = station.getNextSerialNumber();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItems[i]->m_itemName << "]" << endl;
					done = true;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItems[i]->m_itemName << "]" << endl;
				}
			}
		}
	}
	
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; ++i) {
			os << "[" << setw(6) << setfill('0') << right << m_lstItems[i]->m_serialNumber << "] ";
			os << setw(CustomerOrder::m_widthField - 1) << setfill(' ') << left << m_lstItems[i]->m_itemName << "- " 
			<< (m_lstItems[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
			os << endl;
		}
	}

}
