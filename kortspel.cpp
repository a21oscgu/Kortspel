#include <iostream>
#include <ctime>

int confirmation()
{
    std::cout << "\nAre you sure?" << "\nType \"1\" (yes) or \"0\" (no).\nType here: ";
    std::string userConfirmation;
    std::cin >> userConfirmation;
    int positiveConfirmation = 1, negativeConfirmation = 0;
    if (userConfirmation == "1")
    {
        return positiveConfirmation;
    }
    else if(userConfirmation == "0")
    {
        return negativeConfirmation;
    }
    else // Defensiv programmering.
    {
        std::cout << "\nError.\nThe game ends.\n";
        return 0;
    }
}

void shuffleDeck(int deck[], int lengthOfDeck) // En funktion som inte returnerar något men som tar emot kortleken (en array).
{
    int temporary = 0, randomIndex = 0;
    for (int card = 0; card < lengthOfDeck; card++)  // Går igenom alla kort.
    {
        randomIndex = rand() % lengthOfDeck; // Ett slumpmässigt kort väljs ut.
        temporary = deck[card]; // Värdet på det första kortet sparas i en temporär variabel.
        deck[card] = deck[randomIndex]; // Värdet på det första kortet skrivs över med värdet från det andra, slumpmässigt utvalda, kortet.
        deck[randomIndex] = temporary; // Värdet på det andra, slumpmässigt utvalda, kortet skrivs över med värdet från det första kortet.
    }
}

void printCardColor(int playerOneCardValue, int playerOneCardColor, int playerTwoCardValue, int playerTwoCardColor, std::string stringPlayerOneCardColor, std::string stringPlayerTwoCardColor)
{
    // Skriver ut färgen på korten, exempelvis spader, kung, eller ess.
    if (playerOneCardColor == 0)
    {
        stringPlayerOneCardColor = "spades";
    }
    else if (playerOneCardColor == 1)
    {
        stringPlayerOneCardColor = "hearts";
    }
    else if (playerOneCardColor == 2)
    {
        stringPlayerOneCardColor = "diamonds";
    }
    else if (playerOneCardColor == 3)
    {
        stringPlayerOneCardColor = "clubs";
    }
    if (playerTwoCardColor == 0)
    {
        stringPlayerTwoCardColor = "spades";
    }
    else if (playerTwoCardColor == 1)
    {
        stringPlayerTwoCardColor = "hearts";
    }
    else if (playerTwoCardColor == 2)
    {
        stringPlayerTwoCardColor = "diamonds";
    }
    else if (playerTwoCardColor == 3)
    {
        stringPlayerTwoCardColor = "clubs";
    }
    // Resultat som matas ut.
    std::cout << "Player one draw: " << stringPlayerOneCardColor << " ";
    if (playerOneCardValue == 11)
    {
        std::cout << "jack";
    }
    else if (playerOneCardValue == 12)
    {
        std::cout << "queen";
    }
    else if (playerOneCardValue == 13)
    {
        std::cout << "king";
    }
    else if (playerOneCardValue == 14)
    {
        std::cout << "ace";
    }
    else
    {
        std::cout << playerOneCardValue;
    }
    std::cout << ".\nPlayer two draw: " << stringPlayerTwoCardColor << " ";
    if (playerTwoCardValue == 11)
    {
        std::cout << "jack" << ".";
    }
    else if (playerTwoCardValue == 12)
    {
        std::cout << "queen" << ".";
    }
    else if (playerTwoCardValue == 13)
    {
        std::cout << "king" << ".";
    }
    else if (playerTwoCardValue == 14)
    {
        std::cout << "ace" << ".";
    }
    else
    {
        std::cout << playerTwoCardValue << ".";
    }
}

int main()
{
    srand((unsigned int)time(0));

    int play = 1, currentRound = 0, roundsPlayed = 0, currentGame = 0, gamesPlayed = 0, totalScorePlayerOne = 0, totalScorePlayerTwo = 0;
    std::cout << "\nHi!\n";
    do // Loop som används för att kunna spela mer.
    {
        int exitConfirmation = 0;
        while (exitConfirmation == 0)
        {
            std::cout << "\nIn this multiplayergame you can play cards against each other.\nEach player will draw one card from a shuffled deck and the player with the highest number wins the round."
                << "\nIf a player wins three rounds, then he has won the game.\n\nIf both players draw the same number, the color of the card will determine who wins the round.\nThe ranking order of colors is: spades, hearts,"
                << " diamonds and clubs.\nThere are no joker cards included in this cardgame.\n\nType in \"1\" in order to play the game.\nType in \"0\" in order to cancel and exit the game.\nType here: ";
            std::cin >> play;
            if (play == 0)
            {
                // Bekräftelse från användarna att de antingen vill avsluta spelet eller starta spelet.
                int cpuConfirmationPlayGame = confirmation();
                if (cpuConfirmationPlayGame == 1)
                {
                    std::cout << "\nThe game ends.\n";
                    return 0;
                }
                else if (cpuConfirmationPlayGame == 0)
                {
                    std::cout << "\n\nHi!\n";
                }
                else // Defensiv programmering.
                {
                    std::cout << "\nError.\nThe game ends.\n";
                    return 0;
                }
            }
            else // Spelet startar här.
            {
                int scorePlayerOne = 0, scorePlayerTwo = 0;
                currentGame++;
                int continueTheGame = 0;
                while ((scorePlayerOne | scorePlayerTwo) < 2)
                {
                    currentRound++;
                    // Array för kortleken
                    int deck[52] = { 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
                        33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 };

                    shuffleDeck(deck, 52); // Anropar funktionen shuffleDeck för att blanda deck.
                    // Spelarna drar kort.
                    std::string playerOneDrawCard, playerTwoDrawCard;
                    std::cout << "\n------------------------\n" << "Game: " << currentGame << " Round: " << currentRound << "\n------------------------\n" << "Player one. Draw a card by typing \"l\".\nType here: ";
                    std::cin >> playerOneDrawCard;
                    if (playerOneDrawCard == "0")
                    {
                    std::cout << "\nThe game ends.\n";
                    return 0;
                    }
                    else
                    {
                        std::cout << "Player two. Draw a card by typing \"a\".\nType here: ";
                        std::cin >> playerTwoDrawCard;

                        if (playerOneDrawCard == "l" && playerTwoDrawCard == "a")
                        {
                            int playerOneCardValue = deck[0] / 4, playerTwoCardValue = deck[1] / 4;
                            int playerOneCardColor = deck[0] % 4, playerTwoCardColor = deck[1] % 4;
                            std::string stringPlayerOneCardColor, stringPlayerTwoCardColor;
                            // Anropar funktionen printCardColor för att skriva ut spelarnas kort.
                            std::cout << "\n-------------------------------------\n";
                            printCardColor(playerOneCardValue, playerOneCardColor, playerTwoCardValue, playerTwoCardColor, stringPlayerOneCardColor, stringPlayerTwoCardColor);
                            std::cout << "\n-------------------------------------\n" << "\nType \"1\" in order to display results.\nType here: ";
                            std::cin >> continueTheGame;
                            continueTheGame = 0;
                            // Resultat beräknas
                            if (playerOneCardValue > playerTwoCardValue)
                            {
                                scorePlayerOne++;
                                std::cout << "\n-----------------------------------\n" << "Player one won the round!\nScore: " << scorePlayerOne << ":" << scorePlayerTwo << "\n-----------------------------------\n";
                            }
                            else if (playerOneCardValue < playerTwoCardValue)
                            {
                                scorePlayerTwo++;
                                std::cout << "\n-----------------------------------\n" << "Player two won the round!\nScore: " << scorePlayerOne << ":" << scorePlayerTwo << "\n-----------------------------------\n";
                            }
                            else if (playerOneCardValue == playerTwoCardValue)
                            {
                                if (playerOneCardColor < playerTwoCardColor)
                                {
                                    scorePlayerOne++;
                                    std::cout << "\n-----------------------------------\n" << "Player one won the round!\nScore: " << scorePlayerOne << ":" << scorePlayerTwo << "\n-----------------------------------\n";
                                }
                                else if (playerOneCardColor > playerTwoCardColor)
                                {
                                    scorePlayerTwo++;
                                    std::cout << "\n-----------------------------------\n" << "Player two won the round!\nScore: " << scorePlayerOne << ":" << scorePlayerTwo << "\n-----------------------------------\n";
                                }
                            }
                        }
                        else if (playerTwoDrawCard == "0")
                        {
                            std::cout << "\nThe game ends.\n";
                            return 0;
                        }
                        else // Defensiv programmering.
                        {
                            std::cout << "\nError.\nThe game ends.\n";
                            return 0;
                        }
                        roundsPlayed++;
                    }
                }
                // Statistik beräknas.
                gamesPlayed++;
                roundsPlayed = currentRound;
                currentRound = 0;
                // Spelresultat matas ut.
                if (scorePlayerOne == 2)
                {
                    totalScorePlayerOne++;
                    std::cout << "\n---------------------------------------------------------------\n" << "Player one won game number: " << gamesPlayed  << "\nTotal score: " << totalScorePlayerOne << ":" << totalScorePlayerTwo << " (counting the total amount of games won)" << "\n---------------------------------------------------------------\n";

                }
                else if (scorePlayerTwo == 2)
                {
                    totalScorePlayerTwo++;
                    std::cout << "\n---------------------------------------------------------------\n" << "Player two won game number: " << gamesPlayed  << "\nTotal score: " << totalScorePlayerOne << ":" << totalScorePlayerTwo << " (counting the total amount of games won)" << "\n---------------------------------------------------------------\n";
                }
                else // Defensiv programmering.
                {
                    std::cout << "\nError.\nThe game ends.\n";
                    return 0;
                }
                std::cout << "\nType \"1\" in order to continue.\nType here: ";
                std::cin >> continueTheGame;
                continueTheGame = 0;
                int playMore = 1, userConfirms = 0;
                while (userConfirms == 0)
                {
                    std::cout << "\nDo you want to play game " << currentGame + 1 << "?\nType in \"1\" in order to play game " << currentGame + 1 << ".\nType in \"0\" in order to cancel and exit the game.\nType here: ";
                    std::cin >> playMore;
                    if (playMore == 0)
                    {
                        // Bekräftelse från användarna att de antingen vill spela mer eller avsluta spelet.
                        int cpuConfirmationPlayMore = confirmation();
                        if (cpuConfirmationPlayMore == 1)
                        {
                            std::cout << "\nThe game ends.\n";
                            return 0;
                        }
                        else if (cpuConfirmationPlayMore == 0) // Frågar användarna igen om de vill spela ett till spel.
                        {
                        }
                        else // Defensiv programmering.
                        {
                            std::cout << "\nError.\nThe game ends.\n";
                            return 0;
                        }
                    }
                    else if (playMore == 1)
                    {
                        userConfirms++;
                        std::cout << "\n----------------------------------------------------------------------------------------------------------\n" << "\nHi, again!\n";

                    }
                    else // Defensiv programmering.
                    {
                        std::cout << "\nError.\nThe game ends.\n";
                        return 0;
                    }
                }
            }
        }
    }
    while (play == 1);
}