add_contract(eosio.vote eosio.vote ${CMAKE_CURRENT_SOURCE_DIR}/src/eosio.vote.cpp)

target_include_directories(eosio.vote
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(eosio.vote
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/ricardian/eosio.vote.contracts.md.in ${CMAKE_CURRENT_BINARY_DIR}/ricardian/eosio.vote.contracts.md @ONLY )

target_compile_options( eosio.vote PUBLIC -R${CMAKE_CURRENT_SOURCE_DIR}/ricardian -R${CMAKE_CURRENT_BINARY_DIR}/ricardian )
