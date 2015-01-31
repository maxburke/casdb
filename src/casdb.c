#include "casdb.h"

int
casdb_open(struct casdb_stream_t *stream, struct casdb_key_t key)
{
    CASDB_UNUSED(stream);
    CASDB_UNUSED(key);
}

struct casdb_key_t
casdb_write(struct casdb_stream_t *stream)
{
    struct casdb_sha1_hash_t hash;

    {
        struct casdb_stream_t hash_stream;

        hash_stream = stream->duplicate(stream);
        hash = casdb_sha1_hash(&hash_stream);
        hash_stream.release(&hash_stream);
    }
}

void
casdb_delete(struct casdb_key_t key)
{
    CASDB_UNUSED(key);
}

