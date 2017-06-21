#ifndef TIMESCALEDB_CHUNK_CONSTRAINT_H
#define TIMESCALEDB_CHUNK_CONSTRAINT_H


#include <postgres.h>
#include <nodes/pg_list.h>

#include "catalog.h"

typedef struct ChunkConstraint
{
	FormData_chunk_constraint fd;
} ChunkConstraint;


typedef struct ChunkConstraintVec
{
	int16 num_constraints;
	ChunkConstraint constraints[0];
} ChunkConstraintVec;

typedef struct Chunk Chunk;
typedef struct DimensionSlice DimensionSlice;
typedef struct ChunkScanState ChunkScanState;

extern Chunk *chunk_constraint_scan(Chunk *chunk);
extern int chunk_constraint_scan_by_dimension_slice(DimensionSlice *slice, ChunkScanState *ctx);

#endif /* TIMESCALEDB_CHUNK_CONSTRAINT_H */
