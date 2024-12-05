#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52
#define FACES 13
struct card {
	const char* face;
	const char* suit;
};
typedef struct card Card;
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal(const Card* const wDeck);
int main(void)
{
	Card deck[CARDS];
	const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five",
			"Six", "Seven", "Eight", "Nine",
			"Ten","Jack", "Queen", "King" };
	const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	srand(time(NULL));
	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
	system("pause");
	return 0;
}
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[])
{
	for (int i = 0; i < CARDS; ++i)
	{
		wDeck[i].face = wFace[i % FACES];
		wDeck[i].suit = wSuit[i / FACES];
	}
}
void shuffle(Card* const wDeck)
{
	for (int i = 0; i < CARDS; ++i)
	{
		int j = rand() % CARDS;
		Card temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}
void deal(const Card* const wDeck)
{
	for (int i = 0; i < CARDS; ++i)
	{
		printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? "  " : "\n");
	}
}