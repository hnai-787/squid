#!/usr/bin/env bash
# Configures and builds bracketsched with CMake + MinGW g++, reusing the
# vcpkg instance at C:/vcpkg (nlohmann-json, Catch2) set up for the
# sibling firewall-rule-engine-cpp project.
set -euo pipefail

cd "$(dirname "$0")"

VCPKG_ROOT="${VCPKG_ROOT:-C:/vcpkg}"

cmake -S . -B build \
    -G "MinGW Makefiles" \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" \
    -DVCPKG_TARGET_TRIPLET=x64-mingw-static \
    -DVCPKG_HOST_TRIPLET=x64-mingw-static \
    -DCMAKE_BUILD_TYPE=Release

cmake --build build --parallel

echo ""
echo "Built: build/bracket.exe, build/libbracketsched_capi.dll"
echo "Test binary: build/bracketsched_tests.exe"
