include(CTest)

add_library(Catch2::Catch IMPORTED INTERFACE)
set(CATCH_INCLUDE_DIR ${objviewer_SOURCE_DIR}/extern/catch)
set_property(TARGET Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")

include_directories(
    ${objviewer_SOURCE_DIR}/src
    ${TEST_SOURCE_DIR}/src
)

add_executable(unit_tests 
    src/test_main.cpp
    src/test_ObjParser.cpp
    src/test_Vector3.cpp
    src/test_StringUtil.cpp
    ${objviewer_SOURCE_DIR}/src/ObjParser.cpp
    ${objviewer_SOURCE_DIR}/src/Vector3.cpp
    ${objviewer_SOURCE_DIR}/src/VertexTexture.cpp
    ${objviewer_SOURCE_DIR}/src/Face.cpp
    ${objviewer_SOURCE_DIR}/src/StringUtil.cpp
)

target_link_libraries(unit_tests
    Catch2::Catch
)

add_test(parse_comments unit_tests ObjParserComments)
add_test(parse_vector unit_tests ObjParserVector)
add_test(parse_texture unit_tests ObjParserVertexTexture)
add_test(parse_normal unit_tests ObjParserVertexNormal)
add_test(parse_faces unit_tests ObjParserFaces)
add_test(parse_integration unit_tests ObjParserIntegration)
add_test(string_split unit_tests StringUtilSplit)