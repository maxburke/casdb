#pragma once

#include <stdint.h>
#include "casdb_stream.h"

struct casdb_sha1_hash_t
{
    uint32_t h[5];
};

struct casdb_sha1_hash_context_t
{
    char buf[64];
    size_t buf_idx;
    struct casdb_sha1_hash_t hash;
};

void
casdb_sha1_hash_init(struct casdb_sha1_hash_context_t *);

void
casdb_sha1_hash_update(struct casdb_sha1_hash_context_t *, struct casdb_stream_t *);

struct casdb_sha1_hash_t
casdb_sha1_hash_finalize(struct casdb_sha1_hash_context_t *);

struct casdb_sha1_hash_t
casdb_sha1_hash(struct casdb_stream_t *);

