#include "pch.h"
#include "Card.h"
#include <iostream>
#include <string>

Card::Card()
{}

Card::Card(Rank rank, Suit suit) :m_rank{ rank }, m_suit{ suit }
{}

std::string Card::getRank() const
{
	switch (m_rank)
	{
	case RANK_2:	return "2";
	case RANK_3:	return "3";
	case RANK_4:	return "4";
	case RANK_5:	return "5";
	case RANK_6:	return "6";
	case RANK_7:    return "7";
	case RANK_8:    return "8";
	case RANK_9:    return "9";
	case RANK_10:   return "Ten";
	case RANK_JACK: return "Jack";
	case RANK_QUEEN:return "Queen";
	case RANK_KING: return "King";
	case RANK_ACE:  return "Ace";
	}
}

std::string Card::getSuit() const
{
	switch (m_suit)
	{
	case SUIT_SPADE:  return "Spades";
	case SUIT_CLUB:   return "Clubs";
	case SUIT_DIAMOND:return "Diamonds";
	case SUIT_HEARTS: return "Hearts";
	}
}

int Card::getValue() const
{
	switch (m_rank)
	{
	case RANK_2:  return 2;
	case RANK_3:  return 3;
	case RANK_4:  return 4;
	case RANK_5:  return 5;
	case RANK_6:  return 6;
	case RANK_7:  return 7;
	case RANK_8:  return 8;
	case RANK_9:  return 9;
	case RANK_ACE:return 11;
	default:	  return 10;
	}
}

void Card::printCard() const
{
	std::cout << getRank() << " of " << getSuit() << '\n';
}