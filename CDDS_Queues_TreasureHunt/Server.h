#pragma once

class Message;

// represents a hypothetical server that receives 
// messages over a network from multiple players.
// server provides an interface for getting the received messages.
class Server {
public:
	// construct a new Server that will service the given number of players
	Server(int numPlayers) :
		m_currentPlayer(0),
		m_numPlayers(numPlayers)
	{}

	// get the next message in the queue of messages received from clients
	// the caller takes ownership of the Message is responsible for deleting it
	Message* getNextMessage();

private:
	// internal use only, keep track of what player we should generate a move for
	int m_currentPlayer;  

	// the total number of player the server will generate moves for
	int m_numPlayers;
};
