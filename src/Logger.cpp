//
// Created by Gegel85 on 15/01/2019.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include "Logger.hpp"

namespace DungeonIntern
{
	Logger::Logger(const std::string &filepath, LogLevel level) noexcept :
		_file(filepath, std::ios::out),
		_level(level)
	{
	}

	Logger::~Logger() noexcept
	{
		this->_file.close();
	}

	void Logger::msg(const std::string &content, const std::string &prepend) noexcept
	{
		std::stringstream logged_str;
		time_t timestamp = std::time(nullptr);
		struct tm *tm = std::localtime(&timestamp);

		logged_str << std::put_time(tm, "[%d-%m-%Y][%H:%M:%S]") << prepend << ": " << content << std::endl;
		this->_file << logged_str.str();
		std::cout << logged_str.str();
	}

	void Logger::debug(const std::string &content) noexcept
	{
		if (this->_level <= DEBUG)
			this->msg(content, "[DEBUG]");
	}

	void Logger::warn(const std::string &content) noexcept
	{
		if (this->_level <= WARNING)
			this->msg(content, "[WARNING]");
	}

	void Logger::info(const std::string &content) noexcept
	{
		if (this->_level <= INFO)
			this->msg(content, "[INFO]");
	}

	void Logger::error(const std::string &content) noexcept
	{
		if (this->_level <= ERROR)
			this->msg(content, "[ERROR]");
	}

	void Logger::fatal(const std::string &content) noexcept
	{
		if (this->_level <= CRITICAL)
			this->msg(content, "[FATAL]");
	}
}
