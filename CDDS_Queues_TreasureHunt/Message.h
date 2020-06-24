#pragma once

#include <cassert>

// Represents a message that has a move instruction from a single player
class Message {
public:
	// the list of possible moves
	enum class eMessageId {
		TYPE_MOVE_STAY,
		TYPE_MOVE_NORTH,
		TYPE_MOVE_EAST,
		TYPE_MOVE_SOUTH,
		TYPE_MOVE_WEST,
		TYPE_NUMTYPES,
	};

	Message() = delete; // don't allow default construction

	Message(int playerId, eMessageId messageId) :
		m_playerId(playerId),
		m_messageId(messageId) 
	{}

	// get the id of the player this message came from
	int getPlayerId() const { return m_playerId; }

	// get the MessageId associated with this Message.
	eMessageId getMessageId() const { return m_messageId; }

	// convert the MessageId to a human readable string.
	const char* getMessageName() const {
		switch (m_messageId) {
		case eMessageId::TYPE_MOVE_STAY: return "Stay";
		case eMessageId::TYPE_MOVE_NORTH: return "North";
		case eMessageId::TYPE_MOVE_EAST: return "East";
		case eMessageId::TYPE_MOVE_SOUTH: return "South";
		case eMessageId::TYPE_MOVE_WEST: return "West";
		default: assert(false); return "Unknown"; // we should never get here, fail hard.
		}
	}

private:
	int m_playerId;
	eMessageId m_messageId;
};
