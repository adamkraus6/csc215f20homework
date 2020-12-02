#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

enum gameEnd {WIN, PUSH, LOSS, DEALERBUST, PLAYERBUST};

gameEnd play(stack<int> cards, int& dealer, int& player);

int main(int argc, char** argv)
{
    ifstream fin;
    stack<int> cards;
    int card, dealer = 0, player = 0;
    gameEnd ending;

    if (argc != 2)
    {
        cout << "Usage: m0111.exe data" << endl;
        exit(0);
    }

    fin.open(argv[1], ios::in);
    if (!fin.is_open())
    {
        cout << "Unable to open file: " << argv[1] << endl;
        exit(0);
    }

    while (fin >> card)
    {
        cards.push(card);
    }

    ending = play(cards, dealer, player);

    switch (ending)
    {
    case WIN:
        cout << "You win! You had " << player << " and the dealer had " 
            << dealer << endl;
        break;
    case PUSH:
        cout << "Tie! You both had " << player << endl;
        break;
    case LOSS:
        cout << "You lose! Dealer had " << dealer << " and you had "
            << player << endl;
        break;
    case DEALERBUST:
        cout << "You win! Dealer had more than 21!" << endl;
        break;
    case PLAYERBUST:
        cout << "You lose! You had more than 21!" << endl;
        break;
    }
}

gameEnd play(stack<int> cards, int& dealer, int& player)
{
    int i;

    // deal player 2 cards
    for (i = 0; i < 2; i++)
    {
        player += cards.top();
        cards.pop();
    }

    // deal dealer 2 cards
    for (i = 0; i < 2; i++)
    {
        dealer += cards.top();
        cards.pop();
    }

    // determine if dealer gets blackjack
    if (dealer == 21)
    {
        if (player == 21)
        {
            return PUSH;
        }

        return LOSS;
    }

    // deal cards to player until reaching 17
    while (player < 17)
    {
        player += cards.top();
        cards.pop();
    }

    // check if player bust
    if (player > 21)
    {
        return PLAYERBUST;
    }

    // deal cards to player until reaching 17
    while (dealer < 17)
    {
        dealer += cards.top();
        cards.pop();
    }

    // check if dealer bust
    if (dealer > 21)
    {
        return DEALERBUST;
    }

    // determine outcome
    if (dealer == player)
    {
        return PUSH;
    }
    else if (dealer > player)
    {
        return LOSS;
    }
    else {
        return WIN;
    }
}