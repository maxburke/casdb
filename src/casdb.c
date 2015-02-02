#include "casdb.h"
#include "casdb_file.h"

// TODO: possibly detect page size at compile time?
#define CASDB_PAGE_SIZE 4096

struct casdb_page
{
    char data[CASDB_PAGE_SIZE];
};

struct casdb_freelist_entry
{
    uint64_t size;
};

CASDB_STATIC_ASSERT(sizeof(struct casdb_bitmap_page) == sizeof(struct casdb_page));

struct casdb_initial_page
{
    uint64_t freelist;
    uint64_t index;
    char padding[CASDB_PAGE_SIZE - 16];
};

CASDB_STATIC_ASSERT(sizeof(struct casdb_initial_page) == sizeof(struct casdb_page));

#define CASDB_BITMAP(ctx) (struct casdb_bitmap_page *)(((char *)(ctx)->casdb_root)+(ctx->bitmap))

struct casdb_context_t
{
    struct casdb_initial_page *casdb_root;
};


struct casdb_context_t *
casdb_initialize(const char *directory, const char *db_name)
{
    casdb_internal_create_directory(directory);
    casdb_data = casdb_internal_mmap(db_name);
}


void *
casdb_page_allocate(struct casdb_context_t *context, size_t num_pages)
{
    /*
     * Scan bitmap to find contiguous region.
     */

    /*
     * Allocate a new page and resize the backing file
     */
}


void *
casdb_allocate(struct casdb_context_t *context, size_t size)
{
    size_t aligned_size;

    aligned_size = (size + 511) & (~511);

    /*
     * Scan free list for block of sufficient size.
     */

    casdb_page_allocate(context, aligned_size);

    return casdb_allocate(context, size);
}


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

