#pragma once

#include "IState.h"

class Tile;

class WanderState : public IState 
{
public:
	WanderState();
	virtual ~WanderState();

	virtual EntityStateName GetStateName() override;
	virtual void OnUpdate(AIEntity* pOwnerEntity) override;
	
	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual bool ShouldExitState(AIEntity* pOwnerEntity) override;

private:
	void Wander(AIEntity* pThisEntity);
};
