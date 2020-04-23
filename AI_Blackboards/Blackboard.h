#pragma once

#include <string>
#include <map>
#include <list>
#include "BlackboardQuestion.h"

enum class eBlackboardDataType {
	UNKNOWN = 0,
	INT,
	UINT,
	BOOL,
	FLOAT,
	POINTER,
	OWNEDPOINTER,
};

class Blackboard {
public:

	Blackboard() {}
	~Blackboard() { ClearData(); }

	void ClearData();

	void Remove(const std::string& name);

	bool Contains(const std::string& name) const;

	eBlackboardDataType	GetType(const std::string& name) const;

	// returns false if exists but different type
	bool Set(const std::string& name, int value);
	bool Set(const std::string& name, unsigned int value);
	bool Set(const std::string& name, bool value);
	bool Set(const std::string& name, float value);

	// return false if doesn't exist or wrong type
	bool Get(const std::string& name, int& value);
	bool Get(const std::string& name, unsigned int& value);
	bool Get(const std::string& name, bool& value);
	bool Get(const std::string& name, float& value);

	template <typename T>
	bool Set(const std::string& name, T* value, bool own = false) {
		auto iter = m_data.find(name);

		if (iter == m_data.end()) {
			BlackboardData data;
			data.type = own ? eBlackboardDataType::OWNEDPOINTER : eBlackboardDataType::POINTER;
			data.p = value;

			m_data.insert(std::make_pair(name, data));
		}
		else {
			// make sure we're replacing a pointer
			// if it was an owned pointer, delete it first
			if (iter->second.type != eBlackboardDataType::POINTER &&
				iter->second.type != eBlackboardDataType::OWNEDPOINTER)
				return false;

			if (iter->second.type == eBlackboardDataType::OWNEDPOINTER)
				delete iter->second.p;

			iter->second.type = own ? eBlackboardDataType::OWNEDPOINTER : eBlackboardDataType::POINTER;
			iter->second.p = value;
		}

		return true;
	}

	template <typename T>
	bool Get(const std::string& name, T** value) {
		auto iter = m_data.find(name);

		if (iter == m_data.end() ||
			!(iter->second.type == eBlackboardDataType::POINTER ||
				iter->second.type == eBlackboardDataType::OWNEDPOINTER))
			return false;

		*value = (T*)iter->second.p;
		return true;
	}

	// arbitration
	void AddQuestion(BlackboardQuestion* question) { m_questions.push_back(question); }
	void RemoveQuestion(BlackboardQuestion* question) { m_questions.remove(question); }
	void ClearQuestions() { m_questions.clear(); }

	std::list<BlackboardQuestion*>& GetQuestions() { return m_questions; }

	void RunArbitration();

private:

	struct BlackboardData {
		eBlackboardDataType type;

		union {
			float f;
			int i;
			unsigned int ui;
			bool b;

			void* p;
		};
	};

	std::map<std::string, BlackboardData>	m_data;

	std::list<BlackboardQuestion*>	m_questions;
};
