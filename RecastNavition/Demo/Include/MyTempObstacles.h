//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef MYTEMPOBSTACLES_H
#define MYTEMPOBSTACLES_H

#include "Sample.h"
#include "DetourNavMesh.h"
#include "Recast.h"
#include "ChunkyTriMesh.h"


class MyTempObstacles : public Sample
{
protected:
	bool m_keepInterResults;

	struct LinearAllocator* m_talloc;
	struct FastLZCompressor* m_tcomp;
	struct MeshProcess* m_tmproc;

	class dtTileCache* m_tileCache;

	float m_cacheBuildTimeMs;
	int m_cacheCompressedSize;
	int m_cacheRawSize;
	int m_cacheLayerCount;
	unsigned int m_cacheBuildMemUsage;

	int m_maxTiles;
	int m_maxPolysPerTile;

	int m_gridSize;
	float m_tileSize;
	

public:
	MyTempObstacles();
	virtual ~MyTempObstacles();
	virtual void handleSettings();
	virtual void handleMeshChanged(class InputGeom* geom);
	virtual bool handleBuild();
	virtual void handleUpdate(const float dt);

	void getTilePos(const float* pos, int& tx, int& ty);

	void addTempObstacle(const float* pos);
	void removeTempObstacle(const float* sp, const float* sq);
	void clearAllTempObstacles();

	void saveAll(const char* path);
	bool loadAll(const char* path);

private:
	// Explicitly disabled copy constructor and copy assignment operator.
	MyTempObstacles(const MyTempObstacles&);
	MyTempObstacles& operator=(const MyTempObstacles&);

	int rasterizeTileLayers(const int tx, const int ty, const rcConfig& cfg, struct TileCacheData* tiles, const int maxTiles);
};


#endif 
