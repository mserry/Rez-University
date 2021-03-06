#pragma once




class Entity
{
public:
	static const int k_maxHitPoints;

	Entity();
	Entity(int x, int y);
	virtual ~Entity();

	virtual void Render() = 0;
	virtual bool Update() = 0;

	virtual void Damage(int amount);

	void AddGold(int amount);
	void Kill() { m_hitPoints = 0; }

	int GetX() const { return m_x; }
	int GetY() const { return m_y; }

	bool IsDead() const { return (m_hitPoints <= 0); }

protected:
	virtual void Move(int xPos, int yPos) = 0;

protected:
	int m_x;
	int m_y;
	int m_hitPoints;
	int m_gold;
};

