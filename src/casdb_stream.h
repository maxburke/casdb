#pragma once

#include "casdb_base.h"

struct casdb_stream_t;

typedef int (*casdb_stream_fill_fn_t)(struct casdb_stream_t *);
typedef void (*casdb_stream_release_fn_t)(struct casdb_stream_t *);
typedef struct casdb_stream_t (*casdb_stream_duplicate_fn_t)(struct casdb_stream_t *);

struct casdb_stream_t
{
    casdb_stream_fill_fn_t fill;
    casdb_stream_release_fn_t release;
    casdb_stream_duplicate_fn_t duplicate;

    void *context;
    void *buffer;
    size_t length;
};

struct casdb_stream_t
casdb_memstream_create(void *, size_t);

struct casdb_stream_t
casdb_filestream_create(const char *);
