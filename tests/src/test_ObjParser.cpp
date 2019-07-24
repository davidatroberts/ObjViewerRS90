#include <catch2/catch.hpp>

#include <sstream>
#include <string>

#include "ObjParser.h"
#include "Vector3.h"
#include "Face.h"

TEST_CASE("ObjParserVector", "[vector]")
{
    SECTION("can read a vector with x,y,z")
    {
        std::string input_str("v 1 2 3\n");
        std::istringstream iss(input_str);
        const auto model = obj_parser::parserObjectStream(iss);
        REQUIRE(model.vectors.size() == 1);

        const auto v = model.vectors.front();
        CHECK(v.x == Approx(1.0));
        CHECK(v.y == Approx(2.0));
        CHECK(v.z == Approx(3.0));
        CHECK(v.w == Approx(1.0));
    }

    SECTION("can read a vector with x,y,z,w floats")
    {
        std::string input_str("v 1.1 2.2 3.3 4.4\n");
        std::istringstream iss(input_str);
        const auto model = obj_parser::parserObjectStream(iss);
        REQUIRE(model.vectors.size() == 1);

        const auto v = model.vectors.front();
        CHECK(v.x == Approx(1.1));
        CHECK(v.y == Approx(2.2));
        CHECK(v.z == Approx(3.3));
        CHECK(v.w == Approx(4.4));
    }

    SECTION("can read a vector with x,y,z,w")
    {
        std::string input_str("v 1 2 3 4\n");
        std::istringstream iss(input_str);
        const auto model = obj_parser::parserObjectStream(iss);
        REQUIRE(model.vectors.size() == 1);

        const auto v = model.vectors.front();
        CHECK(v.x == Approx(1.0));
        CHECK(v.y == Approx(2.0));
        CHECK(v.z == Approx(3.0));
        CHECK(v.w == Approx(4.0));
    }

    SECTION("can read a vector with x,y,z floats")
    {
        std::string input_str("v 1.1 2.2 3.3\n");
        std::istringstream iss(input_str);
        const auto model = obj_parser::parserObjectStream(iss);
        REQUIRE(model.vectors.size() == 1);

        const auto v = model.vectors.front();
        CHECK(v.x == Approx(1.1));
        CHECK(v.y == Approx(2.2));
        CHECK(v.z == Approx(3.3));
        CHECK(v.w == Approx(1.0));
    }
}

TEST_CASE("ObjParserComments", "[comments]")
{
    SECTION("can read and ignore comments")
    {
        std::string input_str("# this is a test\n");
        std::istringstream iss(input_str);
        const auto model = obj_parser::parserObjectStream(iss);
        REQUIRE(model.vectors.empty());
    }
}

TEST_CASE("ObjParserFaces", "[faces]")
{
    SECTION("can read a face with 3 vertices")
    {
        std::string input_str("f 1 2 3");
        std::istringstream iss(input_str);
        const auto model = obj_parser::parserObjectStream(iss);
        REQUIRE(model.faces.size() == 1);

        // const auto face = model.faces.front();
        // std::vector<size_t> expected = {0, 1, 2};
        
        // REQUIRE(face.vertex_indices == expected);
    }
}