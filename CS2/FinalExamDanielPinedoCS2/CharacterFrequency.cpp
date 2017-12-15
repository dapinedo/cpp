/*
Daniel Pinedo
CS2, Final Exam
12/13/2017
Compiler: Visual Studio 2017
*/

#include "CharacterFrequency.h"

CharacterFrequency::CharacterFrequency(char ch, int frequency) : m_letter(ch), m_frequency(1)
{
	char copy = ch;
	convertToUpperCase(copy);
	this->m_letter = copy;
}

void CharacterFrequency::updateFrequency()
{
	this->m_frequency++;
}

int CharacterFrequency::getFrequency() const
{
	return m_frequency;
}
char CharacterFrequency::getLetter() const
{
	return m_letter;
}

void CharacterFrequency::convertToUpperCase(char & ch)
{
	char temp = ' ';
	temp = toupper(ch);
	ch = temp;
}

CharacterFrequency::~CharacterFrequency()
{
}
