#pragma once

#include <fstream>
#include <map>

class Document
{
public:
	Document();
	Document(const std::string &fileName);
	void GetWordFrequency();
	const int64_t GetInnerProduct(const Document& otherDocument) const;
	~Document();
private:
	std::ifstream m_documentFile;
	std::map<std::string, int64_t> m_wordCountMap;
};

