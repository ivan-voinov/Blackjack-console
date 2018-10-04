#pragma once
#include <string>

class Card
{
public:
	enum Suit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEARTS,
		SUIT_SPADE,
		MAX_SUITES
	};

	enum Rank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};

private:
	Rank m_rank;
	Suit m_suit;

public:
	Card();
	Card(Rank rank, Suit suit);
	std::string getRank() const;
	std::string getSuit() const;
	int getValue() const;
	void printCard() const;
};

