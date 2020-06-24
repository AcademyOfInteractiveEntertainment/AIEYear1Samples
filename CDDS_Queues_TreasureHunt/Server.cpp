#include "Server.h"
#include "Message.h"
#include <cstdlib>

Message* Server::getNextMessage() {
	// a simple move generator. This simluates messages from clients sent over a network

	// if we've moved all the players just return null to indicate the end of the move list.
	// sometimes we allow a few more moves to give a variable number of moves to the client.
	if (m_currentPlayer >= m_numPlayers && (rand() % 5)==0 ) {
		m_currentPlayer = 0;
		return nullptr;
	}

	// get the playerId, make sure we dont give a number that doesn't exist.
	int playerId = m_currentPlayer % m_numPlayers;

	// move to the next player.
	m_currentPlayer++;

	// choose a random move
	Message::eMessageId messageId = (Message::eMessageId) (rand() % (int)Message::eMessageId::TYPE_NUMTYPES);

	// create the message, the caller is reposnsible for deleteing the Message
	return new Message(playerId, messageId);

}