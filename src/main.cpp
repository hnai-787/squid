#include <fstream>
#include <iostream>
#include <sstream>

#include "bracketsched/generator.hpp"
#include "bracketsched/serialize.hpp"

using namespace bracketsched;

namespace {

void printHelp() {
    std::cout <<
        "bracket -- deterministic bracket generation library CLI\n\n"
        "USAGE:\n"
        "  bracket generate <teams.json> [--format single|double] [--grand-final reset|single]\n"
        "  bracket --help\n\n"
        "  <teams.json>: {\"participants\": [{\"seed\": 1, \"name\": \"...\"}, ...]}\n"
        "  --format/--grand-final override the file's own \"format\"/\"grand_final\" fields if present.\n";
}

}  // namespace

int main(int argc, char* argv[]) {
    if (argc < 2 || std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        printHelp();
        return argc < 2 ? 2 : 0;
    }

    if (std::string(argv[1]) != "generate") {
        std::cerr << "Error: unrecognized command \"" << argv[1] << "\"\n\n";
        printHelp();
        return 2;
    }
    if (argc < 3) {
        std::cerr << "Error: generate requires a <teams.json> argument\n";
        return 2;
    }

    std::ifstream file(argv[2], std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file: " << argv[2] << "\n";
        return 2;
    }
    std::ostringstream ss;
    ss << file.rdbuf();

    ParsedRequest request = parseRequestJson(ss.str());
    if (!request.ok) {
        std::cerr << "Error: " << request.error << "\n";
        return 2;
    }

    for (int i = 3; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--format" && i + 1 < argc) {
            std::string v = argv[++i];
            if (v == "single") request.config.format = Format::Single;
            else if (v == "double") request.config.format = Format::Double;
            else { std::cerr << "Error: --format must be single or double\n"; return 2; }
        } else if (arg == "--grand-final" && i + 1 < argc) {
            std::string v = argv[++i];
            if (v == "reset") request.config.grandFinal = GrandFinalPolicy::ResetIfNecessary;
            else if (v == "single") request.config.grandFinal = GrandFinalPolicy::SingleMatch;
            else { std::cerr << "Error: --grand-final must be reset or single\n"; return 2; }
        } else {
            std::cerr << "Error: unrecognized option \"" << arg << "\"\n";
            return 2;
        }
    }

    try {
        BracketGraph graph = generateBracket(request.participants, request.config);
        std::cout << toCanonicalJson(graph, /*pretty=*/true) << "\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
    }
}
