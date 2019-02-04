#pragma once

#include "pugixml.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Utilities.hpp"

namespace Serverlayer {
	class server
	{
		pugi::xml_document config_file;
		pugi::xml_node findClient(std::string id);
		std::vector<itemData> getTypeItems(std::string type_Name);

	public:
		server();
		std::vector<itemData> getClientConfiguredItemsByID(std::string id);
		std::vector<itemData> geClientItems(std::string itemsString);
		ERROR_TYPE validateClientItems(std::vector<itemData> itemsConfigured, std::vector<itemData> itemsfromClient);
	};
}
