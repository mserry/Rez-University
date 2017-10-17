// BombTile.cpp
#include "BombTile.h"
#include "Player.h"
#include <iostream>
#include "DamageInteraction.h"

const BombTile::DamageRange BombTile::s_damageRange(3, 6);

BombTile::BombTile()
{
	m_state = State::k_active;
	m_interaction = new DamageInteraction(this,s_damageRange);
}

Tile::TileType BombTile::GetType() const
{
	return TileType::k_bomb;
}


void BombTile::Render()
{
    if (m_state == State::k_active)
        std::cout << "*";
    else
        std::cout << "#";
}

void BombTile::OnEnter(Player* pPlayer)
{
	switch (m_state)
	{
		case State::k_active:
			m_interaction->ExecuteOn(pPlayer);
			m_state = State::k_dead;
	    break;

		case State::k_dead:
			break;

		default:
			break;
	}
}



