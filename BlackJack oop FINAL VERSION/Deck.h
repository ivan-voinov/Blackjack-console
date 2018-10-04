#pragma once
#include "Card.h"
#include <array>

class Deck
{
private:
	static const int m_deckCapacity{ 52 };
	std::array<Card, m_deckCapacity> m_deck;
	int m_currentCard;

public:
	Deck();
	int getRandomNumber(int min, int max);
	void shuffleDeck();
	void swapCards(Card &card1, Card &card2);
	Card dealCard();
};


