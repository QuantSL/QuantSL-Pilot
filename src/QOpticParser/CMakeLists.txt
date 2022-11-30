project(QOpticParser)

CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)
set(CMAKE_POLICY_DEFAULT_CMP0114 NEW)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE DEBUG)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE /usr/local/lib/antlr-4.9.3-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(SampleGrammarLexer QOLexer.g4 LEXER
             LOCATION grammar
             PACKAGE qoptic)
antlr_target(SampleGrammarParser QOParser.g4 PARSER
             VISITOR
             LOCATION grammar
             PACKAGE qoptic
             DEPENDS_ANTLR SampleGrammarLexer
             COMPILE_FLAGS -lib ${ANTLR_SampleGrammarLexer_OUTPUT_DIR})

# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

# add generated grammar to demo binary target
add_executable(QOpticParser src/main.cpp
               src/QOVisitor.cpp src/QOCodeGen.cpp src/DefinitionTree.cpp src/StringTools.cpp
               ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
               ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})
target_link_libraries(QOpticParser antlr4_static)