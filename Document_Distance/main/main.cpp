// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Document.h"
#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please input 2 documents." << std::endl;
		return 1;
	}
	
	Document doc1(argv[1]);
	Document doc2(argv[2]);
	

	//Document doc1("doc1.txt");
	//Document doc2("doc2.txt");

	doc1.GetWordFrequency();
	doc2.GetWordFrequency();

	int64_t numerator = doc1.GetInnerProduct(doc2);

	double denominator = sqrt((double)doc1.GetInnerProduct(doc1) * (double)doc2.GetInnerProduct(doc2));

	double documentDistance = acos(numerator / denominator);

	std::cout << "Document distance is " << documentDistance << std::endl;
    return 0;
}

