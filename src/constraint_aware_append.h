/*
 * Copyright (c) 2016-2018  Timescale, Inc. All Rights Reserved.
 *
 * This file is licensed under the Apache License,
 * see LICENSE-APACHE at the top level directory.
 */
#ifndef TIMESCALEDB_CONSTRAINT_AWARE_APPEND_H
#define TIMESCALEDB_CONSTRAINT_AWARE_APPEND_H

#include <postgres.h>
#include <nodes/relation.h>
#include <nodes/extensible.h>

typedef struct ConstraintAwareAppendPath
{
	CustomPath	cpath;
} ConstraintAwareAppendPath;

typedef struct ConstraintAwareAppendState
{
	CustomScanState csstate;
	Plan	   *subplan;
	Size		num_append_subplans;
} ConstraintAwareAppendState;

typedef struct Hypertable Hypertable;

Path	   *constraint_aware_append_path_create(PlannerInfo *root, Hypertable *ht, Path *subpath);


#endif							/* TIMESCALEDB_CONSTRAINT_AWARE_APPEND_H */
