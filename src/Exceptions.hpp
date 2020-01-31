//
// Created by Gegel85 on 26/09/2019.
//

#ifndef THFGAME_EXCEPTIONS_HPP
#define THFGAME_EXCEPTIONS_HPP

#include <string>

namespace DungeonIntern
{
	//! @brief The base exception.
	class BaseException : public std::exception {
	private:
		std::string _msg;

	public:
		explicit BaseException(const std::string &&msg) :
			_msg(msg)
		{};
		const char *what() const noexcept override {
			return this->_msg.c_str();
		};
	};

	//! @brief The assets list is corrupted or invalid.
	class CorruptedAssetsListException : public BaseException {
	public:
		explicit CorruptedAssetsListException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief The card tree given is corrupted or invalid.
	class CorruptedCardTreeException : public BaseException {
	public:
		explicit CorruptedCardTreeException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief The map is corrupted.
	class CorruptedMapException : public BaseException {
	public:
		explicit CorruptedMapException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief The map is not loaded.
	class MapNotLoadedException : public BaseException {
	public:
		explicit MapNotLoadedException() :
			BaseException("This map isn't loaded")
		{};
	};

	//! @brief The map couldn't be saved.
	class MapSavingFailureException : public BaseException {
	public:
		explicit MapSavingFailureException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief This file is not a valid saved map.
	class InvalidSavedMap : public BaseException {
	public:
		explicit InvalidSavedMap(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief The folder couldn't be created.
	class FolderCreationErrorException : public BaseException {
	public:
		explicit FolderCreationErrorException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief This Item cannot be found
	class ItemNotFoundException : public BaseException {
	public:
		explicit ItemNotFoundException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief This dialog wasn't found.
	class DialogNotFoundException : public BaseException {
	public:
		explicit DialogNotFoundException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief Dialog file is invalid.
	class InvalidDialogFileException : public BaseException {
	public:
		explicit InvalidDialogFileException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief Dialog string is invalid.
	class InvalidDialogStringException : public BaseException {
	public:
		explicit InvalidDialogStringException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief A dialog command has no end.
	class UnfinishedCommandException : public BaseException {
	public:
		explicit UnfinishedCommandException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief A string literal has no end.
	class UnfinishedStringLiteralException : public BaseException {
	public:
		explicit UnfinishedStringLiteralException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief An unknown command was requested.
	class BadCommandException : public BaseException {
	public:
		explicit BadCommandException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief Invalid arguments were given.
	class InvalidArgumentsException : public BaseException {
	public:
		explicit InvalidArgumentsException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief This object cannot find this procedure.
	class ProcedureNotFoundException : public BaseException {
	public:
		explicit ProcedureNotFoundException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};

	//! @brief The dynamic library wasn't valid.
	class InvalidDllException : public BaseException {
	public:
		explicit InvalidDllException(const std::string &&msg) :
			BaseException(static_cast<const std::string &&>(msg))
		{};
	};
}

std::string getLastExceptionName();

#endif //THFGAME_EXCEPTIONS_HPP
