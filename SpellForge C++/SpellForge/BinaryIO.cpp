#include "pch.h"
#include "BinaryIO.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
//#include <sstream>
using namespace std;

void FileIO::BinaryIO::BinaryReader(const std::wstring& binaryFile)
{
	m_Reader.open(binaryFile.c_str(), std::ios::in | std::ios::binary);
	if (!m_Reader.is_open()) 
		std::wcout << L" [ERROR] Binary File: "<< binaryFile .c_str() << " failed to open" << std::endl;
}

void FileIO::BinaryIO::CloseRead()
{
	if (m_Reader.is_open())
		m_Reader.close();
}


wstring FileIO::BinaryIO::ReadString()
{
	wstring wstr;
	if (m_Reader.is_open())
	{
		const auto stringSize = static_cast<char>(Read<char>());
		const auto buf = new char[stringSize];		
		m_Reader.read(buf, stringSize);
		string str;
		str.append(buf, stringSize);
		wstr.assign(str.begin(), str.end());
		delete[] buf;
	}
	else
	{
		std::wcout << " [ERROR] binaryFile failed to open!\n";
	}

	return wstr;
}

std::wstring FileIO::BinaryIO::ReadNullString()
{
	wstring wstr;
	if (m_Reader.is_open())
	{
		string str;
		getline(m_Reader, str, '\0');
		wstr.append(str.begin(), str.end());
	}
	else
	{
		std::wcout << " [ERROR] binaryFile failed to open!\n";
	}

	return wstr;
}

int FileIO::BinaryIO::FindString(const std::wstring& fstring)
{
	wstring wstr;
	auto off = 0;
	if (m_Reader.is_open())
	{
		string str;
		getline(m_Reader, str);
		off = static_cast<unsigned int>(str.find((char*)(fstring.c_str())));
		wstr.append(str.begin(), str.end());
	}
	else
	{
		std::wcout << " [ERROR] binaryFile failed to open!\n";
	}

	return off;
}


int FileIO::BinaryIO::GetReadPosition()
{
	if (m_Reader.is_open())
		return static_cast<int>(m_Reader.tellg());
	else
		std::wcout << " [ERROR] binaryFile failed to open!\n";
	return -1;
}

bool FileIO::BinaryIO::SetReadPosition(int pos)
{		
	if (m_Reader.is_open())
	{
		m_Reader.seekg(pos);
		return true;
	}
	else
	{
		std::wcout << " [ERROR] binaryFile failed to open!\n";
		return false;
	}
}


bool FileIO::BinaryIO::MoveReadPosition(int offset)
{
	const auto currPos = static_cast<int>(m_Reader.tellg());
	if (m_Reader.is_open() && currPos > 0)
	{
		 m_Reader.seekg(currPos + offset);
		 return true;
	}
	return false;
}


void FileIO::BinaryIO::BinaryWriter(const std::wstring& binaryFile)
{
	m_Writer.open(binaryFile, std::ios::out | std::ios::binary);
	if (!m_Writer.is_open())
		std::wcout << " [ERROR] binaryFile: " << binaryFile.c_str() << " failed to open!\n";
}

void FileIO::BinaryIO::CloseWrite()
{
	if (m_Writer.is_open())
		m_Writer.close();
}

void FileIO::BinaryIO::WriteSting(std::wstring str)
{
	auto stringSize = static_cast<char>(str.size());
	if (m_Writer.is_open())
	{
		string s;
		s.assign(str.begin(), str.end());
		m_Writer.write(reinterpret_cast<char *>(&stringSize), sizeof(char));
		m_Writer.write(s.c_str(), stringSize);
	}
	else
	{
		std::wcout << " [ERROR] binaryFile failed to open!\n";
	}
}

int FileIO::BinaryIO::GetWritePosition()
{
	if (m_Writer.is_open())
		return static_cast<int>(m_Writer.tellp());
	else
		std::wcout << " [ERROR] binaryFile failed to open!\n";
	return -1;
}

bool FileIO::BinaryIO::SetWritePosition(int pos)
{
	if (m_Writer.is_open())
	{
		m_Writer.seekp(pos);
		return true;
	}
	else
	{
		std::wcout << " [ERROR] binaryFile failed to open!\n";
		return false;
	}
}

bool FileIO::BinaryIO::MoveWritePosition(int offset)
{
	const auto currPos = static_cast<int>(m_Writer.tellp());
	if (m_Writer.is_open() && currPos > 0)
	{
		m_Writer.seekp(currPos + offset);
		return true;
	}
	return false;
}
