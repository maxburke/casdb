#pragma once

#include "casdb_sha1.h"

struct casdb_key_t
{
    struct casdb_sha1_hash_t hash;
};

struct casdb_context_t;

struct casdb_context_t *
casdb_initialize(const char *);

int
casdb_open(struct casdb_context_t *, struct casdb_stream_t *, struct casdb_key_t);

struct casdb_key_t
casdb_write(struct casdb_context_t *, struct casdb_stream_t *);

void
casdb_delete(struct casdb_context_t *, struct casdb_key_t);
