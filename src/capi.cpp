#include "bracketsched_capi.h"

#include <cstdlib>
#include <cstring>
#include <string>

#include "bracketsched/generator.hpp"
#include "bracketsched/serialize.hpp"

namespace {
thread_local std::string g_lastError;
}

extern "C" {

int bracketsched_generate_json(const char* requestJson, char** outJson) {
    if (requestJson == nullptr || outJson == nullptr) {
        g_lastError = "requestJson and outJson must not be null";
        return 1;
    }

    bracketsched::ParsedRequest request = bracketsched::parseRequestJson(requestJson);
    if (!request.ok) {
        g_lastError = request.error;
        return 2;
    }

    try {
        bracketsched::BracketGraph graph = bracketsched::generateBracket(request.participants, request.config);
        std::string json = bracketsched::toCanonicalJson(graph, /*pretty=*/false);

        char* buffer = static_cast<char*>(std::malloc(json.size() + 1));
        if (buffer == nullptr) {
            g_lastError = "allocation failure";
            return 3;
        }
        std::memcpy(buffer, json.c_str(), json.size() + 1);
        *outJson = buffer;
        return 0;
    } catch (const std::exception& e) {
        g_lastError = e.what();
        return 4;
    }
}

void bracketsched_string_free(char* s) { std::free(s); }

const char* bracketsched_last_error(void) { return g_lastError.c_str(); }

}  // extern "C"
