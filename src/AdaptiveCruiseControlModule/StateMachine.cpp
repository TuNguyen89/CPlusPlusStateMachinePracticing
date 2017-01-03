#include "StateMachine.h"

//----------------------------------------------------------------------------
// StateMachine
//----------------------------------------------------------------------------
StateMachine::StateMachine(BYTE maxStates, BYTE initialState) :
	MAX_STATES(maxStates),
	m_currentState(initialState),
	m_newState(FALSE),
	m_eventGenerated(FALSE),
	m_pEventData(NULL)
{
	ASSERT_TRUE(MAX_STATES < EVENT_IGNORED);
}  

//----------------------------------------------------------------------------
// processExternalEvent
//----------------------------------------------------------------------------
void StateMachine::processExternalEvent(BYTE newState, const EventData* pData)
{
	// If we are supposed to ignore this event
	if (newState == EVENT_IGNORED)
	{
		// Just delete the event data, if any
		if (pData != NULL)
			delete pData;
	}
	else
	{
		// TODO - capture software lock here for thread-safety if necessary

		// Generate the event
		processInternalEvent(newState, pData);

		// Execute the state engine. This function call will only return
		// when all state machine events are processed.
		stateEngine();

		// TODO - release software lock here 
	}
}

//----------------------------------------------------------------------------
// processInternalEvent
//----------------------------------------------------------------------------
void StateMachine::processInternalEvent(BYTE newState, const EventData* pData)
{
	if (pData == NULL)
		pData = new NoEventData();

	m_pEventData = pData;
	m_eventGenerated = TRUE;
	m_newState = newState;
}

//----------------------------------------------------------------------------
// stateEngine
//----------------------------------------------------------------------------
void StateMachine::stateEngine(void)
{
	const StateMapRow* pStateMap = getStateMap();
	if (pStateMap != NULL)
		stateEngine(pStateMap);
	else
	{
		const StateMapRowEx* pStateMapEx = getStateMapEx();
		if (pStateMapEx != NULL)
			stateEngine(pStateMapEx);
		else
			ASSERT();
	}
}

//----------------------------------------------------------------------------
// stateEngine
//----------------------------------------------------------------------------
void StateMachine::stateEngine(const StateMapRow* const pStateMap)
{
	const EventData* pDataTemp = NULL;	

	// While events are being generated keep executing states
	while (m_eventGenerated)
	{
		// Error check that the new state is valid before proceeding
		ASSERT_TRUE(m_newState < MAX_STATES);

		// Get the pointer from the state map
		const StateBase* state = pStateMap[m_newState].State;

		// Copy of event data pointer
		pDataTemp = m_pEventData;

		// Event data used up, reset the pointer
		m_pEventData = NULL;

		// Event used up, reset the flag
		m_eventGenerated = FALSE;

		// Execute the state action passing in event data
		ASSERT_TRUE(state != NULL);
		state->invokeStateAction(this, pDataTemp);

      // Switch to the new current state
      setCurrentState(m_newState);

		// If event data was used, then delete it
		if (pDataTemp)
		{
			delete pDataTemp;
			pDataTemp = NULL;
		}
	}
}

//----------------------------------------------------------------------------
// stateEngine
//----------------------------------------------------------------------------
void StateMachine::stateEngine(const StateMapRowEx* const pStateMapEx)
{
	const EventData* pDataTemp = NULL;

	// While events are being generated keep executing states
	while (m_eventGenerated)
	{
		// Error check that the new state is valid before proceeding
		ASSERT_TRUE(m_newState < MAX_STATES);

		// Get the pointers from the state map
		const StateBase* state = pStateMapEx[m_newState].State;
		const GuardBase* guard = pStateMapEx[m_newState].Guard;
		const EntryBase* entry = pStateMapEx[m_newState].Entry;
		const ExitBase* exit = pStateMapEx[m_currentState].Exit;

		// Copy of event data pointer
		pDataTemp = m_pEventData;

		// Event data used up, reset the pointer
		m_pEventData = NULL;

		// Event used up, reset the flag
		m_eventGenerated = FALSE;

		// Execute the guard condition
		BOOL guardResult = TRUE;
		if (guard != NULL)
			guardResult = guard->InvokeGuardCondition(this, pDataTemp);

		// If the guard condition succeeds
		if (guardResult == TRUE)
		{
			// Transitioning to a new state?
			if (m_newState != m_currentState)
			{
				// Execute the state exit action on current state before switching to new state
				if (exit != NULL)
					exit->invokeExitAction(this);

				// Execute the state entry action on the new state
				if (entry != NULL)
					entry->invokeEntryAction(this, pDataTemp);

				// Ensure exit/entry actions didn't call processInternalEvent by accident 
				ASSERT_TRUE(m_eventGenerated == FALSE);
			}
         // Execute the state action passing in event data
         ASSERT_TRUE(state != NULL);
         state->invokeStateAction(this, pDataTemp);

			// Switch to the new current state
			setCurrentState(m_newState);
		}

		// If event data was used, then delete it
		if (pDataTemp)
		{
			delete pDataTemp;
			pDataTemp = NULL;
		}
	}
}



