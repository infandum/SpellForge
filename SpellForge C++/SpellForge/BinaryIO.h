#pragma once
#include "string"
#include <fstream>

namespace FileIO
{
	class BinaryIO
	{
	public:
		BinaryIO() = default;
		virtual ~BinaryIO() = default;

		void BinaryReader(const std::wstring& binaryFile);
		void CloseRead();
		std::wstring ReadString();
		std::wstring ReadNullString();
		int FindString(const std::wstring& fstring);
		int GetReadPosition();
		bool SetReadPosition(int pos);
		bool MoveReadPosition(int offset);
		bool IsReadOpen() const{ return m_Reader.is_open(); }

		void BinaryWriter(const std::wstring& binaryFile);
		bool IsWriteOpen() const { return m_Writer.is_open(); }
		void CloseWrite();
		void WriteSting(std::wstring str);
		int GetWritePosition();
		bool SetWritePosition(int pos);
		bool MoveWritePosition(int offset);

		template<typename T>
		T Read()
		{
			T value;
			m_Reader.read((char*)&value, sizeof(T));
			if (!m_Reader.is_open()) std::wcout << L" [ERROR] Binary File failed to open!!" << std::endl;
			return value;
		}

		template<typename T>
		T Write(T value)
		{		
			m_Writer.write((char*)&value, sizeof(T));
			if (!m_Writer.is_open()) std::wcout << L" [ERROR] Binary File failed to open!!" << std::endl;
			return value;
		}

	private:
		std::ifstream m_Reader;
		std::ofstream m_Writer;
	};
}