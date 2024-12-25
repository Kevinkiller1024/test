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

struct card {
	const char* face;
	const char* suit;
	int value;
};
typedef struct card Card;

Card drawCard(Card deck[], int* deckIndex) { 
	if (*deckIndex >= DECK_SIZE) {
		printf("\n�P�w�g�⧹�F�I\n");
		exit(1);
	}
	return deck[(*deckIndex)++];
}

void display_two_card(const char* face1, const char* suit1, const char* face2, const char* suit2) {
	
}

void card_front(const char* face, const char* suit, int show) {
	
}

void draw_card(const char* card[], int y, const char* face1, const char* suit1, const char* face2, const char* suit2) {   // ��ܼ��J�P�b���w��m
	
}

void card_fly_and_flip(int start_y, const char* face, const char* suit, const char* face1, const char* suit1, const char* face2, const char* suit2) {
	
}

void initializeDeck(Card deck[]) { // ��l�Ƽ��J�P
	int index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[index].face = (char*)face[j];
			deck[index].suit = (char*)suit[i];
			deck[index].value = j + 1;
			index++;
		}
	}
}

void shuffle(Card* const wDeck) { // �~�P
	int i;
	int j;
	Card temp;

	for (i = 0; i < DECK_SIZE; i++) {
		j = rand() % DECK_SIZE;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

int rull() {
	return 1;
}

int main() {
	
	system("pause");
	return 0;
}