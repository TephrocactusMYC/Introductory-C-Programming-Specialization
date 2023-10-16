#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
    for(int i=0;i<hand->n_cards;i++){
        print_card(*hand->cards[i]);
        printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {
    for(int i=0;i<d->n_cards;i++){
        // 底下这样才算是真正学明白指针了
        if((*d->cards[i]).suit==c.suit && d->cards[i]->value==c.value){
            return 1;
        }
    }
  return 0;
}

void shuffle(deck_t * d){
  int remain = d->n_cards;
  int limit = d->n_cards - 1;
  for (int i=0; i < limit; i++) {
    int idx = rand() % remain + i;
    card_t * tmp = (d->cards)[i];
    (d->cards)[i] = (d->cards)[idx];
    (d->cards)[idx] = tmp;
    remain--;
  }
}

void assert_full_deck(deck_t * d) {
    card_t temp;
    for (int i = 0; i <= 51; i++) {
        temp = card_from_num(i);
        assert(deck_contains(d, temp) == 1);
    }
}

void add_card_to(deck_t * deck, card_t c){
    card_t * t = malloc(sizeof(*t));
    t -> value = c.value;
    t -> suit = c.suit;
    deck -> cards = realloc(deck -> cards, ((deck -> n_cards) + 1) * sizeof(card_t *));
    deck -> cards[deck -> n_cards] = t;
    ++ deck -> n_cards;
}

card_t * add_empty_card(deck_t * deck){
    card_t *t=malloc(sizeof(*t));
    t->suit=0;
    t->value=0;
    add_card_to(deck,*t);
    free(t);
    return deck->cards[deck -> n_cards - 1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
    deck_t * d = malloc(sizeof (*d));
    d -> cards = NULL;
    d -> n_cards = 0;
    for (int i = 0; i < 52; i ++) {
        card_t c = card_from_num(i);
        if (deck_contains(excluded_cards, c)){
            continue;
        }
        add_card_to(d, c);
    }
    return d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
    deck_t *tmp=malloc(sizeof(*tmp));
    tmp->cards=NULL;
    tmp->n_cards=0;

    for(int i=0;i<n_hands;i++){
        for(int j=0;j<hands[i]->n_cards;j++){
            if(!deck_contains(tmp, *(hands[i]->cards[j]))){
                add_card_to(tmp, *(hands[i] -> cards[j]));
            }
        }
    }

    deck_t * d = make_deck_exclude(tmp);

    for(int i = 0; i < tmp -> n_cards; i++) {
        free(tmp -> cards[i]);
    }
    free(tmp -> cards);
    free(tmp);
    return d;
}
void free_deck(deck_t * deck){
    for(size_t i = 0; i < deck -> n_cards; i ++) {
        free(deck -> cards[i]);
    }
    free(deck -> cards);
    free(deck);
}
