#include "pch.h"
#include "Deck.h"
#include <array>
#include <cassert>

Deck::Deck() : m_currentCard{ 0 }
{
	int cardIndex = 0;
	for (int i = 0; i < Card::MAX_RANKS; i++)
		for (int j = 0; j < Card::MAX_SUITES; j++)
		{
			Card card{ static_cast<Card::Rank>(i), static_cast<Card::Suit>(j) };
			m_deck[cardIndex] = card;
			cardIndex++;
		}
}

int Deck::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::shuffleDeck()
{
	for (int i = 0; i < m_deckCapacity; i++)
	{
		swapCards(m_deck[i], m_deck[getRandomNumber(0, m_deckCapacity - 1)]);
	}
}

void Deck::swapCards(Card &card1, Card &card2)
{
	Card temp;
	temp = card1;
	card1 = card2;
	card2 = temp;
}

Card Deck::dealCard()
{
	assert(m_currentCard < 52 && "Out of cards");
	return m_deck[m_currentCard++];
}