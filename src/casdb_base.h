#pragma once

#define CASDB_UNUSED(x) ((void)x)

#define CASDB_STATIC_ASSERT_PASTE(x, y) CASDB_STATIC_ASSERT_PASTE2(x, y)
#define CASDB_STATIC_ASSERT_PASTE2(x, y) x ## y
#define CASDB_STATIC_ASSERT(x) typedef char CASDB_STATIC_ASSERT_PASTE(compileTimeAssert, __LINE__)[x?1:-1]
