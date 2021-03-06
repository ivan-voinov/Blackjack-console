#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Deck.h"
#include "Card.h"

enum class GameOutcome
{
	PLAYER_WIN,
	DEALER_WIN,
	TIE
};

char getPlayerChoice()
{
	char choice;
	do
	{
		std::cout << "Do you want to hit or stand? (H/S) ";
		std::cin >> choice;
		if (choice != 'H' && choice != 'S')
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
	} while (choice != 'H' && choice != 'S');
	return choice;
}

GameOutcome playBlackjack(Deck &deck)
{
	int dealerScore = 0;
	int playerScore = 0;
	int deckIndex = 0;
	int playerAces = 0;
	int dealerAces = 0;
	char playerChoice;

	Card cardDrawn = deck.dealCard();
	int cardValue = cardDrawn.getValue();
	if (cardValue == 11) dealerAces++;
	dealerScore += cardValue;
	std::cout << "Dealer got ";
	cardDrawn.printCard();

	cardDrawn = deck.dealCard();
	cardValue = cardDrawn.getValue();
	if (cardValue == 11) playerAces++;
	playerScore += cardValue;
	std::cout << "You got ";
	cardDrawn.printCard();

	cardDrawn = deck.dealCard();
	cardValue = cardDrawn.getValue();
	if (cardValue == 11) playerAces++;
	playerScore += cardValue;
	std::cout << "You got ";
	cardDrawn.printCard();

	if (dealerAces==0) std::cout << "Dealer has a score of " << dealerScore << '\n';
	else std::cout << "Dealer has a score of (11/1)\n";

	if (playerAces==0) std::cout << "You got a total score of " << playerScore << '\n';
	else if (playerAces == 1) std::cout << "You got a total score of (" << playerScore << "/" << playerScore - 10 << ")\n";
	else std::cout << "You got a total score of (12/2)\n";
	do
	{
		playerChoice = getPlayerChoice();
		if (playerChoice == 'H')
		{
			cardDrawn = deck.dealCard();
			cardValue = cardDrawn.getValue();
			if (cardValue == 11) playerAces++;
			playerScore += cardValue;
			std::cout << "You got ";
			cardDrawn.printCard();
		}
		if (playerAces > 0 && playerScore > 21)
		{
			playerScore -= 10;
			--playerAces;
		}
		std::cout << "You got a total score of " << playerScore << '\n';
	} while (playerChoice == 'H' && playerScore <= 21);
	if (playerScore > 21) return GameOutcome::DEALER_WIN;
	else
	{
		do
		{
			cardDrawn = deck.dealCard();
			cardValue = cardDrawn.getValue();
			if (cardValue == 11) dealerAces++;
			dealerScore += cardValue;
			std::cout << "Dealer got ";
			cardDrawn.printCard();

			if (dealerAces > 0 && dealerScore > 21)
			{
				dealerScore -= 10;
				--dealerAces;
			}
			std::cout << "Dealer got a score of " << dealerScore << '\n';
		} while (dealerScore < 17);
		if (dealerScore > 21) return GameOutcome::PLAYER_WIN;
		if (dealerScore > playerScore) return GameOutcome::DEALER_WIN;
		if (dealerScore = playerScore) return GameOutcome::TIE;
		return GameOutcome::PLAYER_WIN;
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Deck deck;
	deck.shuffleDeck();
	//deck.printDeck();	      debug function
	GameOutcome result = playBlackjack(deck);
	if (result == GameOutcome::PLAYER_WIN)
		std::cout << "You won!\n";

	else if (result == GameOutcome::DEALER_WIN)
		std::cout << "You lost!\n";

	else if (result == GameOutcome::TIE)
		std::cout << "Tie!\n";

	return 0;
}