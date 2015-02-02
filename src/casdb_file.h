#pragma once

void
casdb_internal_create_directory(const char *);

void *
casdb_internal_mmap(const char *);

void *
casdb_internal_mresize(void *, size_t);
