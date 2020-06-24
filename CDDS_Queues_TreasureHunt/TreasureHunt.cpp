#include "Message.h"
#include "Server.h"
#include "TreasureMap.h"
#include <iostream>

int main(int argc, char* argv[]) {

	const int numPlayers = 5;

	// Create a new sqaure TreasureMap that is 100 units wide and high
	TreasureMap map(100);

	// Create a new Server that will get the moves of the given number of players
	Server server(numPlayers);

	// Store the player positions, we'll up this as move messages come in
	Position playerPositions[numPlayers];

	// Keep going until the treasure is found
	while (true) {

		// Get the first message
		Message* message = server.getNextMessage();

		// Process all the messages the server has for us
		while (message) {

			std::cout << "Player " << message->getPlayerId() << " made move " << message->getMessageName() << std::endl;

			// TODO: Instead of deleting the old message here, you should be storing it in your queue!
			delete message;

			// Get the next message
			message = server.getNextMessage();
		}

		// TODO: Here, you should handled the first 5 messages in your queue (if you have that many)
		// move the player in the direction specified and test to see if they found the treasure.
		// If the treause is found print out the finder and exit.
		// Once you have handled the message, it will need to be deleted!

		std::cout << "End turn" << std::endl;
	}

	return 0;
}
