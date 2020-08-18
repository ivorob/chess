CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
PROJECT (chess-client)

SET (CMAKE_AUTOMOC ON)
SET (CMAKE_AUTOUIC ON)
SET (CMAKE_AUTORCC ON)
SET (CMAKE_CXX_STANDARD 11)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
SET (RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

SET (SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/ChessBoard.cpp
        ${SRC_DIR}/GameObject.cpp
        # decorators
        ${SRC_DIR}/WhiteDecorator.cpp
        ${SRC_DIR}/BlackDecorator.cpp
        # figures
        ${SRC_DIR}/figures/Pawn.cpp
        ${SRC_DIR}/figures/King.cpp
        ${SRC_DIR}/figures/Queen.cpp
        ${SRC_DIR}/figures/Rook.cpp
        ${SRC_DIR}/figures/Knight.cpp
        ${SRC_DIR}/figures/Bishop.cpp
        #
        ${SRC_DIR}/MemoryStream.cpp
        ${SRC_DIR}/Registry.cpp
        ${SRC_DIR}/NetworkManager.cpp
    )

SET (HEADERS
        ${SRC_DIR}/GameObject.h
        # decorators
        ${SRC_DIR}/WhiteDecorator.h
        ${SRC_DIR}/BlackDecorator.h
        # figures
        ${SRC_DIR}/figures/Pawn.h
        ${SRC_DIR}/figures/King.h
        ${SRC_DIR}/figures/Queen.h
        ${SRC_DIR}/figures/Rook.h
        ${SRC_DIR}/figures/Knight.h
        ${SRC_DIR}/figures/Bishop.h
        #
        ${SRC_DIR}/MemoryStream.h
        ${SRC_DIR}/Registry.h
        ${SRC_DIR}/NetworkManager.h
    )

INCLUDE_DIRECTORIES (. src/)

FIND_PACKAGE (Qt5 COMPONENTS Widgets Network)

ADD_EXECUTABLE (chess-client WIN32 ${SOURCES} ${HEADERS})
TARGET_LINK_LIBRARIES (chess-client Qt5::Widgets Qt5::Network)

ADD_CUSTOM_COMMAND (TARGET chess-client
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/themes
        ${CMAKE_CURRENT_BINARY_DIR}/themes)
