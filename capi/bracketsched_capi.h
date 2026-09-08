#ifndef BRACKETSCHED_CAPI_H
#define BRACKETSCHED_CAPI_H

/* A deliberately small, JSON-based C ABI: no C++ STL types and no
 * exceptions cross this boundary (see README "Design decisions" for why
 * this is preferred over a fully typed struct ABI for v1 -- it trades a
 * small amount of marshaling overhead for a much smaller, safer surface
 * that's trivial to bind from Python/C#/Rust/Go/etc via plain C FFI). */

#ifdef _WIN32
#ifdef BRACKETSCHED_EXPORTS
#define BRACKETSCHED_API __declspec(dllexport)
#else
#define BRACKETSCHED_API __declspec(dllimport)
#endif
#else
#define BRACKETSCHED_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Returns 0 on success. On failure, returns nonzero and *outJson (if non-null
 * on success) is left untouched; call bracketsched_last_error for details. */
BRACKETSCHED_API int bracketsched_generate_json(const char* requestJson, char** outJson);

/* Frees a string previously returned by bracketsched_generate_json. */
BRACKETSCHED_API void bracketsched_string_free(char* s);

/* Returns a pointer to a description of the last error on this thread.
 * Valid until the next bracketsched_* call on the same thread. */
BRACKETSCHED_API const char* bracketsched_last_error(void);

#ifdef __cplusplus
}
#endif

#endif
