
#pragma once

#include "DropSpenserEntity.h"





// tolua_begin
class cDispenserEntity :
	public cDropSpenserEntity
{
	typedef cDropSpenserEntity super;

public:

	// tolua_end

	/// Constructor used for normal operation
	cDispenserEntity(int a_BlockX, int a_BlockY, int a_BlockZ, cWorld * a_World);

	static const char * GetClassStatic(void) { return "cDispenserEntity"; }

private:
	// cDropSpenser overrides:
	virtual void DropSpenseFromSlot(cChunk & a_Chunk, int a_SlotNum) override;

	/// If such a bucket can fit, adds it to m_Contents and returns true
	bool ScoopUpLiquid(int a_SlotNum, short a_BucketItemType);

	// Spawns a projectile of the given kind in front of the dispenser
	void SpawnProjectileFromDispenser(cChunk& a_Chunk, int& DispX, int& DispY, int& DispZ, cProjectileEntity::eKind kind);

	// Returns how to aim the projectile
	Vector3d GetProjectileLookVector(cChunk & a_Chunk);

	/// If the a_BlockInFront is liquidable and the empty bucket can fit, does the m_Contents processing and returns true
	bool EmptyLiquidBucket(BLOCKTYPE a_BlockInFront, int a_SlotNum);
} ;  // tolua_export




