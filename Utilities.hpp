#pragma once
#include "string"
namespace Serverlayer {
	enum ERROR_TYPE
	{
		NONE = 0,
		CLIENT_NOT_CONFIGURED,
		MISCONFIGURED,
		OUT_OF_RANGE
	};

	struct itemData
	{
		std::string name;
		std::string client_value;
		std::string min_value;
		std::string max_value;

		itemData()
		{
			name = "";
			client_value = "";
			min_value = "";
			max_value = "";
		}
		bool in_the_range(itemData& config)
		{
			return (this->client_value >= config.min_value && this->client_value <= config.max_value);
		}
		bool operator== (const itemData& rhs) const
		{
			return this->name == rhs.name;
		}
	};
}