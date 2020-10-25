#include "stdafx.h"
#include "Document.h"

#include <sstream>
#include <regex>

Document::Document()
{
}
/*
	Constructor with parameter
	Parameter: fileName is the path to the document
	In case cannot open the document, throw a runtime exception
*/
Document::Document(const std::string& fileName)
	: m_documentFile(fileName)
{
	if (!m_documentFile)
	{
		std::ostringstream os;
		os << "Could not open file: " << fileName;
		throw std::runtime_error(os.str());
	}
}

/*
	Build the vector of words and store it in a map
	with key: is the list of words,
	and value: is how many times they are repeated.
	Complexity: O(n2)
*/
void Document::GetWordFrequency()
{
	std::string word;
	while (m_documentFile >> word)
	{
		// Convert word to lowercase
		std::for_each(word.begin(), word.end(), [](char& c) {
			c = ::tolower(c);
		});

		// If this word already existed in the map, increase the repeated times
		if (m_wordCountMap.find(word) != m_wordCountMap.end())
		{
			m_wordCountMap.at(word)++;
		}
		else // If not, add it into the map with the repeated times is one
		{
			m_wordCountMap.insert(std::pair<std::string, int64_t>(word, 1));
		}
	}

}

/*
	Compute the inner-product between two vectors: of this document and other document.
	Parameter: otherDocument
	Complexity: O(n2)
*/
const int64_t Document::GetInnerProduct(const Document& otherDocument) const
{
	int64_t sum = 0;
	for (auto it = m_wordCountMap.begin(); it != m_wordCountMap.end(); ++it)
	{
		if (otherDocument.m_wordCountMap.find(it->first) != otherDocument.m_wordCountMap.end())
		{
			sum += it->second * otherDocument.m_wordCountMap.at(it->first);
		}
	}
	return sum;
}

Document::~Document()
{
}
