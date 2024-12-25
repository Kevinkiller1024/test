#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define DECK_SIZE 52
#define CARD_WIDTH 7
#define CARD_HEIGHT 5
#define SLEEP_TIME 50

long long final = 0; //�����̫��Ĺ����
const char* face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "t", "J", "Q", "K" }; //�w�q�P���ƭ�
const char* suit[] = { "H", "B", "C", "D" }; //�w�q�P�����
const char* card_back[] = { //�w�q�P���I��
	"�z�w�w�w�w�w�{",
	"�x�w�w�w�w�w�x",
	"�x�w�w�w�w�w�x",
	"�x�w�w�w�w�w�x",
	"�|�w�w�w�w�w�}" };

void clear_screen() {
	system("cls");
}

int rull();

struct card {
	const char* face;
	const char* suit;
	int value;
};
typedef struct card Card;

Card drawCard(Card deck[], int* deckIndex) { 
	
}

void display_two_card(const char* face1, const char* suit1, const char* face2, const char* suit2) {
	printf("�z�w�w�w�w�w�{\t\t�z�w�w�w�w�w�{\n");
	printf("�x%s    �x\t\t�x%s    �x\n", suit1, suit2);
	printf("�x  %s  �x\t\t�x  %s  �x\n", face1, face2);
	printf("�x    %s�x\t\t�x    %s�x\n", suit1, suit2);
	printf("�|�w�w�w�w�w�}\t\t�|�w�w�w�w�w�}\n\n");
}

void card_front(const char* face, const char* suit, int show) {
	switch (show) {
	case 4:
		printf("\t�z�w�w�w�w�w�{\n");
	case 3:
		printf("\t�x%s    �x\n", suit);
	case 2:
		printf("\t�x  %s  �x\n", face);
	case 1:
		printf("\t�x    %s�x\n", suit);
	case 0:
		printf("\t�|�w�w�w�w�w�}\n");
	}
}

void draw_card(const char* card[], int y, const char* face1, const char* suit1, const char* face2, const char* suit2) {   // ��ܼ��J�P�b���w��m
	clear_screen();
	display_two_card(face1, suit1, face2, suit2);
	for (int i = 0; i < y; i++) {
		printf("\n");
	}
	for (int i = 0; i < CARD_HEIGHT; i++) {
		printf("\t%s\n", card[i]);
	}
}

void card_fly_and_flip(int start_y, const char* face, const char* suit, const char* face1, const char* suit1, const char* face2, const char* suit2) {
	for (int y = start_y; y >= CARD_HEIGHT; y--) {
		draw_card(card_back, y, face1, suit1, face2, suit2);
		Sleep(SLEEP_TIME);
	}
	for (int step = 0; step < CARD_HEIGHT; step++) {
		for (int i = 0; i < CARD_HEIGHT; i++) {
			printf("\n");
		}
		for (int j = 0; j < CARD_HEIGHT; j++) {
			clear_screen();
			display_two_card(face1, suit1, face2, suit2);
			card_front(face, suit, step);
		}
		Sleep(SLEEP_TIME / 5);
	}
}

void initializeDeck(Card deck[]) { // ��l�Ƽ��J�P
	
}

void shuffle(Card* const wDeck) { // �~�P
	
}

int rull() {
	return 1;
}

int main() {
	srand(time(NULL));
	Card deck[DECK_SIZE];
	int deckIndex = 0;
	int choise, count = 0;

	do {
		clear_screen();
		printf("�w��Ө�g�s���C���I\n\n");

		initializeDeck(deck);
		shuffle(deck);
		Card card1 = drawCard(deck, &deckIndex);
		Card card2 = drawCard(deck, &deckIndex);

		if (card1.value > card2.value) {
			Card temp = card1;
			card1 = card2;
			card2 = temp;
		}
		display_two_card(card1.face, card1.suit, card2.face, card2.suit);

		int play_or_fault = 0;
		int bet;
		while (play_or_fault == 0) {
			printf("�n���٬O��P(0��P�A1�U�`)�G");
			scanf("%d", &play_or_fault);
			if (play_or_fault == 1)
				break;
			card1 = drawCard(deck, &deckIndex);
			card2 = drawCard(deck, &deckIndex);
			if (card1.value > card2.value) {
				Card temp = card1;
				card1 = card2;
				card2 = temp;
			}
			clear_screen();
			display_two_card(card1.face, card1.suit, card2.face, card2.suit);
		}
		count++;
		int big_or_small;
		if (card1.value == card2.value) {
			printf("�A�n��j�٬O��p(0��p�A1��j)�G");
			scanf("%d", &big_or_small);
		}
		printf("�ФU�`���B�G");
		scanf("%d", &bet);

		Card dragonCard = drawCard(deck, &deckIndex);
		card_fly_and_flip(20, dragonCard.face, dragonCard.suit, card1.face, card1.suit, card2.face, card2.suit);
		printf("�s���P�O�G%s %s\n\n", dragonCard.face, dragonCard.suit);

		choise = rull(card1, card2, dragonCard, bet, big_or_small);


	} while (choise);
	printf("\n�P�¹C��! \n�A�@�@�g�F%d��\n", count);
	if (final > 0)
		printf("�A�@�@Ĺ�F%ld $\n\n", final);
	else if (final < 0)
		printf("�@�@�ߤF%d $ ����\n\n", -final);
	else
		printf("�A�@��SĹ\n\n");
	system("pause");
	return 0;
}