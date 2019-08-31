#include <catch2/catch.hpp>

#include <string>

#include "StringUtil.h"

TEST_CASE("StringUtilSplit", "[split]")
{
    SECTION("single delimitter")
    {
        const auto str = "a/b";
        const auto delim = "/";
        const auto result = string_util::splitString(str, delim);

        REQUIRE(result.size() == 2);
        REQUIRE(result[0] == "a");
        REQUIRE(result[1] == "b");
    }

    SECTION("two delimitters")
    {
        const auto str = "a/b/c";
        const auto delim = "/";
        const auto result = string_util::splitString(str, delim);

        REQUIRE(result.size() == 3);
        REQUIRE(result[0] == "a");
        REQUIRE(result[1] == "b");
        REQUIRE(result[2] == "c");
    }

    SECTION("no delimitter")
    {
        const auto str = "a";
        const auto delim = "/";
        const auto result = string_util::splitString(str, delim);

        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == "a");
    }

    SECTION("two delimitters next to each other")
    {
        const auto str = "a//b";
        const auto delim = "/";
        const auto result = string_util::splitString(str, delim);

        REQUIRE(result.size() == 3);
        REQUIRE(result[0] == "a");
        REQUIRE(result[1] == "");
        REQUIRE(result[2] == "b");
    }
}