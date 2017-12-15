/*
Daniel Pinedo
CS2, Final Exam
12/13/2017
Compiler: Visual Studio 2017
*/

#pragma once
#ifndef CHARACTERFREQUENCY_H
#define CHARACTERFREQUENCY_H
#include <iostream>
#include <string>
#include <fstream>

class CharacterFrequency
{
private:
	char m_letter;
	int m_frequency;
public:
	CharacterFrequency(char ch = ' ', int frequency = 1);
	
	//Friend functions
	//Overloaded operators
	friend bool operator < (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.m_letter < right.m_letter;
	}
	friend bool operator > (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.m_letter > right.m_letter;
	}
	friend bool operator == (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.m_letter == right.m_letter;
	}
	friend bool operator != (const CharacterFrequency & left, const CharacterFrequency & right)
	{
		return left.m_letter != right.m_letter;
	}
	
	//Overloaded ostream 

	friend ostream & operator << (ostream & out, const CharacterFrequency & CF)
	{
		out << CF.m_letter << " : " << CF.m_frequency << " times";
		return out;
	}

	static void convertToUpperCase(char & ch);
	void updateFrequency();

	//non-mutator functions
	int getFrequency() const;
	char getLetter() const;

	virtual ~CharacterFrequency();
};
#endif

