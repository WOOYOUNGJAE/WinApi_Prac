#pragma once
#include  "Obj.h"
class CEnemy : public CObj
{
public:
	CEnemy();
	virtual ~CEnemy() override;

public:
	// getter

	//setter
	void Set_BulletSlot(list<CObj*>* _pBulletSlot);
	void Set_Player(CObj* _pPlayer);

	// I U R R
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _dc) override;
	virtual void Release() override;

	void CheckWall();
	virtual void CheckCollision(CObj* _pObjType);// override;


	void TargetPlayer();
private:
	list<CObj*>* m_pBullet_FromPlayer;
	CObj* m_pPlayer;
	float m_fDistanceToPlayer;
	float m_fTargetX;
	float m_fTargetY;
};
