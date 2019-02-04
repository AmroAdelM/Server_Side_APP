#include "Server.hpp"
using namespace Serverlayer;

server::server()
{
	pugi::xml_parse_result result = config_file.load_file("Server_config.xml");
	if (result.status != pugi::xml_parse_status::status_ok)
	{
		//throw error or send email
	}
}

pugi::xml_node server::findClient(std::string id)
{
	return config_file.child("config").child("clients").find_child_by_attribute("id", id.c_str());
}

std::vector<itemData> server::getClientConfiguredItemsByID(std::string id)
{
	auto clientNode = findClient(id);

	if (clientNode == pugi::xml_node())
	{
		//error = Serverlayer::ERROR_TYPE::MISCONFIGURED;
	}

	auto type = clientNode.attribute("information_items_Type").value();
	auto items = getTypeItems(type);

	return items;
}

std::vector<itemData> server::getTypeItems(std::string type_Name)
{
	std::vector<itemData> items;
	pugi::xml_node item = config_file.child("config").child("information_items_Type").child(type_Name.c_str()).child("item");
	for (item; item != pugi::xml_node(); item = item.next_sibling())
	{
		itemData temp;
		temp.name = item.attribute("name").value();
		temp.min_value = item.attribute("lowest_value").value();
		temp.max_value = item.attribute("highest_value").value();

		items.push_back(temp);
	}
	return items;
}

std::vector<itemData> server::geClientItems(std::string itemsString)
{
	std::vector<itemData> items;
	pugi::xml_document client_msg;

	// get a test document
	client_msg.load_string(itemsString.c_str());

	pugi::xml_node item = client_msg.child("client").child("item");
	for (item; item != pugi::xml_node(); item = item.next_sibling())
	{
		itemData temp;
		temp.name = item.attribute("name").value();
		temp.client_value = item.attribute("value").value();

		items.push_back(temp);
	}
	return items;
}

ERROR_TYPE server::validateClientItems(std::vector<itemData> itemsConfigured, std::vector<itemData> itemsfromClient)
{
	if (itemsConfigured.size() != itemsfromClient.size())
		return ERROR_TYPE::MISCONFIGURED;

	for (auto item : itemsfromClient)
	{
		auto found = std::find(itemsConfigured.begin(), itemsConfigured.end(), item);
		if (found == itemsConfigured.end())
		{
			return ERROR_TYPE::MISCONFIGURED;
		}

		if (!item.in_the_range(*found))
		{
			return ERROR_TYPE::OUT_OF_RANGE;
		}
	}
	return ERROR_TYPE::NONE;
}
