#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define DECK_SIZE 52
#define CARD_WIDTH 7
#define CARD_HEIGHT 5
#define SLEEP_TIME 50

long long final = 0; //紀錄最後輸贏的錢
const char* face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "t", "J", "Q", "K" }; //定義牌的數值
const char* suit[] = { "H", "B", "C", "D" }; //定義牌的花色
const char* card_back[] = { //定義牌的背面
	"┌─────┐",
	"│─────│",
	"│─────│",
	"│─────│",
	"└─────┘" };

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
	
}

void display_two_card(const char* face1, const char* suit1, const char* face2, const char* suit2) {
	
}

void card_front(const char* face, const char* suit, int show) {
	
}

void draw_card(const char* card[], int y, const char* face1, const char* suit1, const char* face2, const char* suit2) {   // 顯示撲克牌在指定位置
	
}

void card_fly_and_flip(int start_y, const char* face, const char* suit, const char* face1, const char* suit1, const char* face2, const char* suit2) {
	
}

void initializeDeck(Card deck[]) { // 初始化撲克牌
	
}

void shuffle(Card* const wDeck) { // 洗牌
	
}

int rull(Card card1, Card card2, Card dragonCard, int bet, int big_or_small) {
	if (card1.value != card2.value && card2.value != (card1.value + 1) && card2.value != card1.value + 2) {
		if (dragonCard.value > card1.value && dragonCard.value < card2.value) {
			printf("恭喜！落在範圍內，你贏了！\n");
			printf("你拿回了 %d $！\n\n", bet);
			final += bet;
		}
		else if (dragonCard.value == card1.value || dragonCard.value == card2.value) {
			printf("撞柱！你輸了！賠兩倍的錢\n");
			printf("你賠了 %d $！\n", bet * 2);
			final -= bet * 2;
		}
		else {
			printf("你輸了！賠錢\n");
			printf("你賠了 %d $！\n\n", bet);
			final -= bet;
		}
	}
	else if (card1.value == card2.value) {
		if (big_or_small == 1) {
			if (dragonCard.value > card1.value) {
				printf("恭喜！你押對邊了！\n");
				printf("你獲得了 %d $！\n\n", bet);
				final += bet;
			}
			else if (dragonCard.value < card1.value) {
				printf("你輸了！押錯邊摟哈哈\n");
				printf("你賠了 %d $！\n\n", bet);
				final -= bet;
			}
			else {
				printf("撞柱！你輸了！賠三倍的錢\n");
				printf("你賠了 %d $！\n\n", bet * 3);
				final -= bet * 3;
			}
		}
		else {
			if (dragonCard.value < card1.value) {
				printf("恭喜！你押對邊了！\n");
				printf("你獲得了 %d $！\n\n", bet * 2);
				final += bet;
			}
			else if (dragonCard.value > card1.value) {
				printf("你輸了！押錯邊摟哈哈\n");
				printf("你賠了 %d $！\n\n", bet);
				final -= bet;
			}
			else {
				printf("撞柱！你輸了！賠三倍的錢\n");
				printf("你賠了 %d $！\n\n", bet * 3);
				final += bet * 3;
			}
		}
	}
	else if (card2.value == card1.value + 1) {
		if (dragonCard.value == card1.value || dragonCard.value == card2.value) {
			printf("恭喜！撞柱！贏三倍的錢\n");
			printf("你獲得了 %d $！\n\n", bet * 3);
			final += bet * 3;
		}
		else {
			printf("可惜沒中！賭性堅強阿\n");
			printf("你賠了 %d $！\n\n", bet);
			final -= bet;
		}
	}
	else {
		if (dragonCard.value > card1.value && dragonCard.value < card2.value) {
			printf("恭喜！中洞！贏五倍的錢\n");
			printf("你拿回了 %d $！\n\n", bet * 5);
			final += bet * 6;
		}
		else if (dragonCard.value == card1.value || dragonCard.value == card2.value) {
			printf("撞柱！你輸了！賠兩倍的錢\n");
			printf("你賠了 %d $！\n\n", bet * 2);
			final -= bet * 2;
		}
		else {
			printf("你輸了！賠錢\n");
			printf("你賠了 %d $！\n\n", bet);
			final -= bet;
		}
	}

	int choise;
	printf("還要繼續玩嗎？(0：結束 1：繼續)");
	scanf("%d", &choise);
	return choise;
}

int main() {
	
	system("pause");
	return 0;
}