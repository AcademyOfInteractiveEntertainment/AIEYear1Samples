#include "Behaviour.h"



Status Behaviour::tick(Agent* agent, float deltaTime)
{
    if (m_eStatus != BH_RUNNING)
    {
        onInitialize();
    }

    m_eStatus = update(agent, deltaTime);

    if (m_eStatus != BH_RUNNING)
    {
        onTerminate(m_eStatus);
    }
    return m_eStatus;
}

void Behaviour::reset()
{
    m_eStatus = BH_INVALID;
}

void Behaviour::abort()
{
    onTerminate(BH_ABORTED);
    m_eStatus = BH_ABORTED;
}
	
bool Behaviour::isTerminated() const
{
    return m_eStatus == BH_SUCCESS  ||  m_eStatus == BH_FAILURE;
}

bool Behaviour::isRunning() const
{
	return m_eStatus == BH_RUNNING;
}

Status Behaviour::getStatus() const
{
    return m_eStatus;
}