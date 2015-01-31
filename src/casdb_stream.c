#include <stddef.h>
#include "casdb_base.h"
#include "casdb_stream.h"

static int
casdb_memstream_fill(struct casdb_stream_t *stream)
{
    CASDB_UNUSED(stream);

    return 0;
}


static void
casdb_memstream_release(struct casdb_stream_t *stream)
{
    CASDB_UNUSED(stream);
}


static struct casdb_stream_t
casdb_memstream_duplicate(struct casdb_stream_t *stream)
{
    struct casdb_stream_t new_stream;

    new_stream = *stream;

    return new_stream;
}


struct casdb_stream_t
casdb_stream_create_from_mem(void *address, size_t size)
{
    struct casdb_stream_t stream;

    stream.fill = casdb_memstream_fill;
    stream.release = casdb_memstream_release;
    stream.duplicate = casdb_memstream_duplicate;
    stream.context = NULL;
    stream.buffer = address;
    stream.length = size;

    return stream;
}
